#pragma once
#include <unordered_map>

namespace haar_lib {
  template <typename Monoid>
  class dynamic_dual_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    const int64_t depth, size, hsize;
    node *root = nullptr;
    std::unordered_map<int64_t, node*> umap;

    void propagate(node *t, int64_t l, int64_t r){
      if(r - l > 1){
        if(not t->left) t->left = new node(M());
        t->left->val = M(t->val, t->left->val);

        if(not t->right) t->right = new node(M());
        t->right->val = M(t->val, t->right->val);

        t->val = M();
      }
    }

    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
      if(r - l == 1){
        if(x <= l && r <= y) t->val = M(t->val, val);
        umap[l] = t;
        return;
      }
      if(r < x || y < l) return;
      else if(x <= l && r <= y) t->val = M(t->val, val);
      else{
        const int64_t m = (l + r) / 2;
        propagate(t, l, r);
        update(t->left, l, m, x, y, val);
        update(t->right, m, r, x, y, val);
      }
    }

    void get(node* t, int64_t l, int64_t r, int64_t x){
      if(r - l == 1){
        umap[l] = t;
        return;
      }
      propagate(t, l, r);
      int m = (l + r) / 2;
      if(x < m) get(t->left, l, m, x);
      else get(t->right, m, r, x);
    }

  public:
    dynamic_dual_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t s, int64_t t, value_type &x){
      update(root, 0, hsize, s, t, x);
    }

    value_type operator[](int64_t x){
      get(root, 0, hsize, x);
      return umap[x]->val;
    }
  };
}
