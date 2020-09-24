#pragma once
#include <cstdint>

namespace haar_lib {
  template <typename Monoid>
  class dynamic_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    value_type eval(node *t) const {
      return t ? t->val : M();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t pos, const value_type &val){
      if(r - l == 1){
        if(t) t->val = val;
        else t = new node(val);
      }else{
        const int64_t m = (l + r) / 2;
        if(not t) t = new node(val);
        if(pos < m) t->left = update(t->left, l, m, pos, val);
        else t->right = update(t->right, m, r, pos, val);
        t->val = M(eval(t->left), eval(t->right));
      }
      return t;
    }

    value_type get(node* t, int64_t l, int64_t r, int64_t x, int64_t y) const {
      if(not t) return M();
      if(x <= l && r <= y) return t ? t->val : M();
      if(r < x || y < l) return M();
      int64_t m = (l + r) >> 1;
      return M(get(t->left, l, m, x, y), get(t->right, m, r, x, y));
    }

  public:
    dynamic_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void set(int64_t i, const value_type &x){
      update(root, 0, hsize, i, x);
    }

    void update(int64_t i, const value_type &x){
      set(i, M((*this)[i], x));
    }

    value_type fold(int64_t l, int64_t r) const {
      return get(root, 0, hsize, l, r);
    }

    value_type operator[](int64_t i) const {
      return fold(i, i + 1);
    }
  };
}
