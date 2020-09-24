#pragma once
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class persistent_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type value;
      node *left = nullptr, *right = nullptr;
      node(const value_type &value): value(value){}
    };

    int depth;
    node *root = nullptr;

    persistent_segment_tree(int depth, node *root): depth(depth), root(root){}

    node* init(node *t, const std::vector<value_type> &init_list, int d, int &pos){
      if(d == depth){
        t = new node(pos < (int)init_list.size() ? init_list[pos] : M());
        ++pos;
      }else{
        t = new node(M());
        t->left = init(t->left, init_list, d + 1, pos);
        t->right = init(t->right, init_list, d + 1, pos);
        t->value = M(t->left->value, t->right->value);
      }
      return t;
    }

  public:
    persistent_segment_tree(const std::vector<value_type> &init_list){
      const int size = init_list.size();
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, init_list, 1, pos);
    }

    persistent_segment_tree(int size, const value_type &value = M()){
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, std::vector<value_type>(size, value), 1, pos);
    }

  protected:
    node* set(node *t, int l, int r, int pos, const value_type &val) const {
      if(r <= pos or pos + 1 <= l){
        return t;
      }else if(pos <= l and r <= pos + 1){
        return new node(val);
      }else{
        const int m = (l + r) >> 1;
        auto lp = set(t->left, l, m, pos, val);
        auto rp = set(t->right, m, r, pos, val);

        node *s = new node(M(lp->value, rp->value));

        s->left = lp;
        s->right = rp;

        return s;
      }
    }

  public:
    persistent_segment_tree set(int i, const value_type &val) const {
      node *t = set(root, 0, 1 << (depth - 1), i, val);
      return persistent_segment_tree(depth, t);
    }

    persistent_segment_tree update(int i, const value_type &val) const {
      return set(i, M((*this)[i], val));
    }

  protected:
    value_type get(node *t, int i, int j, int l, int r) const {
      if(i <= l and r <= j) return t->value;
      if(r <= i or j <= l) return M();
      const int m = (l + r) >> 1;
      return M(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
    }

  public:
    value_type fold(int i, int j) const {
      return get(root, i, j, 0, 1 << (depth - 1));
    }

    value_type operator[](int i) const {
      return fold(i, i + 1);
    }
  };
}
