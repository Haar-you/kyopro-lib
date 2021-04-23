#pragma once
#include <cstdint>

namespace haar_lib {
  template <typename Monoid>
  class dynamic_segment_tree {
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

    value_type eval(node *t) const {
      return t ? t->val : M_();
    }

    node *update(node *t, int64_t l, int64_t r, int64_t pos, const value_type &val) {
      if (r - l == 1) {
        if (t)
          t->val = val;
        else
          t = new node(val);
      } else {
        const int64_t m = (l + r) / 2;
        if (not t) t = new node(val);
        if (pos < m)
          t->left = update(t->left, l, m, pos, val);
        else
          t->right = update(t->right, m, r, pos, val);
        t->val = M_(eval(t->left), eval(t->right));
      }
      return t;
    }

    value_type get(node *t, int64_t l, int64_t r, int64_t x, int64_t y) const {
      if (not t) return M_();
      if (x <= l and r <= y) return t ? t->val : M_();
      if (r < x or y < l) return M_();
      int64_t m = (l + r) >> 1;
      return M_(get(t->left, l, m, x, y), get(t->right, m, r, x, y));
    }

  public:
    dynamic_segment_tree() {}
    dynamic_segment_tree(int64_t n) : depth_(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
                                      size_(1LL << depth_),
                                      hsize_(size_ / 2) {
      root_ = new node(M_());
    }

    void set(int64_t i, const value_type &x) {
      update(root_, 0, hsize_, i, x);
    }

    void update(int64_t i, const value_type &x) {
      set(i, M_((*this)[i], x));
    }

    value_type fold(int64_t l, int64_t r) const {
      return get(root_, 0, hsize_, l, r);
    }

    value_type operator[](int64_t i) const {
      return fold(i, i + 1);
    }
  };
}  // namespace haar_lib
