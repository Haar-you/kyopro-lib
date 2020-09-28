#pragma once
#include <utility>
#include <optional>

namespace haar_lib {
  template <typename T, typename Comparator>
  class dynamic_lichao_segment_tree {
  public:
    using value_type = T;

  private:
    using line = std::pair<T, T>;

    struct node {
      std::optional<line> value;
      int64_t l, r;
      node *l_child = nullptr, *r_child = nullptr;
      node(std::optional<line> value, int64_t l, int64_t r): value(value), l(l), r(r){}
    };

    Comparator cmp_ = Comparator();
    int64_t MIN_, MAX_;
    node *root_ = nullptr;

    T chm(const T &a, const T &b) const {
      return cmp_(a, b) ? a : b;
    }

  public:
    dynamic_lichao_segment_tree(){}
    dynamic_lichao_segment_tree(int64_t MIN, int64_t MAX): MIN_(MIN), MAX_(MAX){}

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
        if(cmp_(apply(new_line, l), apply(*(t->value), l))){
          t->value = new_line;
        }
        return t;
      }

      const auto m = (l + r) / 2;

      bool left = cmp_(apply(new_line, l), apply(*(t->value), l));
      bool mid = cmp_(apply(new_line, m), apply(*(t->value), m));
      bool right = cmp_(apply(new_line, r), apply(*(t->value), r));

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
            cmp_(apply(*(t->value), l), apply(new_line, l)) and
            cmp_(apply(*(t->value), r), apply(new_line, r))
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
      root_ = update(root_, std::make_pair(a, b), MIN_, MAX_);
    }

    void add_segment(int64_t l, int64_t r, T a, T b){
      root_ = update_segment(root_, std::make_pair(a, b), MIN_, MAX_, l, r);
    }

    auto operator()(const int64_t &x) const {
      std::optional<T> ret;
      node *cur = root_;

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
