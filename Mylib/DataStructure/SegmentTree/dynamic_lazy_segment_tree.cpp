#pragma once
#include <cstdint>

namespace haar_lib {
  template <typename Monoid>
  class dynamic_lazy_segment_tree {
  public:
    using monoid_get        = typename Monoid::monoid_get;
    using monoid_update     = typename Monoid::monoid_update;
    using value_type_get    = typename monoid_get::value_type;
    using value_type_update = typename monoid_update::value_type;

  private:
    struct node {
      value_type_get value;
      value_type_update lazy;
      node *left = nullptr, *right = nullptr;
      node() {}
      node(const value_type_get &value, const value_type_update &lazy) : value(value), lazy(lazy) {}
    };

    Monoid M_;
    monoid_get M_get_;
    monoid_update M_update_;

    int64_t depth_, size_, hsize_;
    node *root_ = nullptr;

    void propagate(node *t, int64_t l, int64_t r) {
      if (t->lazy == M_update_()) return;
      if (r - l > 1) {
        if (not t->left) t->left = new node(M_get_(), M_update_());
        t->left->lazy = M_update_(t->lazy, t->left->lazy);
        if (not t->right) t->right = new node(M_get_(), M_update_());
        t->right->lazy = M_update_(t->lazy, t->right->lazy);
      }
      const int64_t len = r - l;
      t->value          = M_(t->value, t->lazy, len);
      t->lazy           = M_update_();
    }

    node *update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value) {
      if (not t) t = new node(M_get_(), M_update_());

      propagate(t, l, r);
      if (r - l == 1) {
        if (x <= l and r <= y) t->lazy = M_update_(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      if (r < x or y < l) return t;
      if (x <= l and r <= y) {
        t->lazy = M_update_(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      t->left  = update(t->left, l, (l + r) / 2, x, y, value);
      t->right = update(t->right, (l + r) / 2, r, x, y, value);
      t->value = M_get_(t->left->value, t->right->value);

      return t;
    }

    value_type_get get(node *t, int64_t l, int64_t r, int64_t x, int64_t y) {
      if (not t) return M_get_();

      propagate(t, l, r);
      if (r <= x or y <= l) return M_get_();
      if (x <= l and r <= y) return t->value;

      return M_get_(
          get(t->left, l, (l + r) / 2, x, y),
          get(t->right, (l + r) / 2, r, x, y));
    }

  public:
    dynamic_lazy_segment_tree() {}
    dynamic_lazy_segment_tree(int64_t n) : depth_(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
                                           size_(1LL << depth_),
                                           hsize_(size_ / 2) {
      root_ = new node(M_get_(), M_update_());
    }

    void update(int64_t l, int64_t r, value_type_update value) {
      update(root_, 0, hsize_, l, r, value);
    }

    value_type_get fold(int64_t l, int64_t r) {
      return get(root_, 0, hsize_, l, r);
    }

    value_type_get operator[](int64_t i) {
      return fold(i, i + 1);
    }
  };
}  // namespace haar_lib
