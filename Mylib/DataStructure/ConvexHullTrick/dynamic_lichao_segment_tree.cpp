#pragma once
#include <utility>
#include <optional>

/**
 * @title Dynamic LiChao segment tree
 * @docs dynamic_lichao_segment_tree.md
 */
namespace haar_lib {
  template <typename T, typename Comparator>
  class dynamic_lichao_segment_tree {
    using line = std::pair<T, T>;

    const Comparator cmp = Comparator();

    struct node {
      std::optional<line> value;
      int64_t l, r;
      node *l_child = nullptr, *r_child = nullptr;
      node(std::optional<line> value, int64_t l, int64_t r): value(value), l(l), r(r){}
    };

    int64_t MIN, MAX;
    node *root = nullptr;

    T chm(const T &a, const T &b) const {
      return cmp(a, b) ? a : b;
    }

  public:
    dynamic_lichao_segment_tree(int64_t MIN, int64_t MAX): MIN(MIN), MAX(MAX){}

    T apply(const line &l, const T &x) const {
      return l.first * x + l.second;
    }

  private:
    node* update(node *t, line new_line, int64_t l, int64_t r){
      if(not t){
        return t = new node(new_line, l, r);
      }

      if(not t->value){
        t->value = new_line;
        return t;
      }

      if(l + 1 == r){
        if(cmp(apply(new_line, l), apply(*(t->value), l))){
          t->value = new_line;
        }
        return t;
      }

      const auto m = (l + r) / 2;

      bool left = cmp(apply(new_line, l), apply(*(t->value), l));
      bool mid = cmp(apply(new_line, m), apply(*(t->value), m));
      bool right = cmp(apply(new_line, r), apply(*(t->value), r));

      if(left and right){
        t->value = new_line;
        return t;
      }

      if(not left and not right){
        return t;
      }

      if(mid){
        std::swap(*(t->value), new_line);
      }

      if(left != mid){
        t->l_child = update(t->l_child, new_line, l, m);
      }else{
        t->r_child = update(t->r_child, new_line, m, r);
      }

      return t;
    }

    node* update_segment(node *t, line new_line, int64_t l, int64_t r, int64_t sl, int64_t sr){
      if(r < sl or sr < l) return t;
      if(sl <= l and r <= sr){
        return t = update(t, new_line, l, r);
      }

      if(l + 1 == r){
        return t;
      }

      if(not t) t = new node(std::nullopt, l, r);
      else{
        if(t->value){
          if(
            cmp(apply(*(t->value), l), apply(new_line, l)) and
            cmp(apply(*(t->value), r), apply(new_line, r))
          ){
            return t;
          }
        }
      }

      const auto m = (l + r) / 2;

      t->l_child = update_segment(t->l_child, new_line, l, m, sl, sr);
      t->r_child = update_segment(t->r_child, new_line, m, r, sl, sr);

      return t;
    }

  public:
    void add_line(T a, T b){
      root = update(root, std::make_pair(a, b), MIN, MAX);
    }

    void add_segment(int64_t l, int64_t r, T a, T b){
      root = update_segment(root, std::make_pair(a, b), MIN, MAX, l, r);
    }

    auto operator()(const int64_t &x) const {
      std::optional<T> ret;
      node *cur = root;

      while(cur){
        if(cur->value){
          if(not ret) ret = apply(*(cur->value), x);
          else ret = chm(*ret, apply(*(cur->value), x));
        }

        const auto m = (cur->l + cur->r) / 2;
        if(x < m) cur = cur->l_child;
        else cur = cur->r_child;
      }

      return ret;
    }
  };
}
