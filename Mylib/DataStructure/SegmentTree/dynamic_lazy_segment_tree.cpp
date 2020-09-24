#pragma once
#include <cstdint>

namespace haar_lib {
  template <typename MonoidGet, typename MonoidUpdate, template <typename, typename> typename Connector>
  class dynamic_lazy_segment_tree {
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;
    Connector<MonoidGet, MonoidUpdate> M;
    MonoidGet M_get;
    MonoidUpdate M_update;

    struct node {
      value_type_get value;
      value_type_update lazy;
      node *left = nullptr, *right = nullptr;
      node(){}
      node(const value_type_get &value, const value_type_update &lazy): value(value), lazy(lazy){}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    void propagate(node *t, int64_t l, int64_t r){
      if(t->lazy == M_update()) return;
      if(r - l > 1){
        if(not t->left) t->left = new node(M_get(), M_update());
        t->left->lazy = M_update(t->lazy, t->left->lazy);
        if(not t->right) t->right = new node(M_get(), M_update());
        t->right->lazy = M_update(t->lazy, t->right->lazy);
      }
      int64_t len = r - l;
      t->value = M(t->value, t->lazy, len);
      t->lazy = M_update();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){
      if(not t) t = new node(M_get(), M_update());

      propagate(t, l, r);
      if(r - l == 1){
        if(x <= l and r <= y) t->lazy = M_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      if(r < x or y < l) return t;
      if(x <= l and r <= y){
        t->lazy = M_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      t->left = update(t->left, l, (l + r) / 2, x, y, value);
      t->right = update(t->right, (l + r) / 2, r, x, y, value);
      t->value = M_get(t->left->value, t->right->value);

      return t;
    }

    value_type_get get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){
      if(not t) return M_get();

      propagate(t, l, r);
      if(r <= x or y <= l) return M_get();
      if(x <= l and r <= y) return t->value;

      return M_get(
        get(t->left, l, (l + r) / 2, x, y),
        get(t->right, (l + r) / 2, r, x, y)
      );
    }

  public:
    dynamic_lazy_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M_get(), M_update());
    }

    void update(int64_t l, int64_t r, value_type_update value){
      update(root, 0, hsize, l, r, value);
    }

    value_type_get fold(int64_t l, int64_t r){
      return get(root, 0, hsize, l, r);
    }

    value_type_get operator[](int64_t i){
      return fold(i, i + 1);
    }
  };
}
