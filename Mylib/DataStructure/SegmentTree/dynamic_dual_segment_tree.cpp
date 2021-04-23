#pragma once
#include <unordered_map>

namespace haar_lib {
  template <typename Monoid>
  class dynamic_dual_segment_tree {
  public:
    using value_type = typename Monoid::value_type;

  private:
    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val) : val(val) {}
    };

    Monoid M_;
    int64_t depth_, size_, hsize_;
    node *root_ = nullptr;
    std::unordered_map<int64_t, node *> umap_;

    void propagate(node *t, int64_t l, int64_t r) {
      if (r - l > 1) {
        if (not t->left) t->left = new node(M_());
        t->left->val = M_(t->val, t->left->val);

        if (not t->right) t->right = new node(M_());
        t->right->val = M_(t->val, t->right->val);

        t->val = M_();
      }
    }

    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val) {
      if (r - l == 1) {
        if (x <= l and r <= y) t->val = M_(t->val, val);
        umap_[l] = t;
        return;
      }
      if (r < x or y < l)
        return;
      else if (x <= l and r <= y)
        t->val = M_(t->val, val);
      else {
        const int64_t m = (l + r) / 2;
        propagate(t, l, r);
        update(t->left, l, m, x, y, val);
        update(t->right, m, r, x, y, val);
      }
    }

    void get(node *t, int64_t l, int64_t r, int64_t x) {
      if (r - l == 1) {
        umap_[l] = t;
        return;
      }
      propagate(t, l, r);
      int m = (l + r) / 2;
      if (x < m)
        get(t->left, l, m, x);
      else
        get(t->right, m, r, x);
    }

  public:
    dynamic_dual_segment_tree() {}
    dynamic_dual_segment_tree(int64_t n) : depth_(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
                                           size_(1LL << depth_),
                                           hsize_(size_ / 2) {
      root_ = new node(M_());
    }

    void update(int64_t s, int64_t t, value_type &x) {
      update(root_, 0, hsize_, s, t, x);
    }

    value_type operator[](int64_t x) {
      get(root_, 0, hsize_, x);
      return umap_[x]->val;
    }
  };
}  // namespace haar_lib
