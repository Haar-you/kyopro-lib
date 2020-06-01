#pragma once

/**
 * @title Dynamic segment tree
 * @docs dynamic_segment_tree.md
 */
template <typename Monoid>
class DynamicSegmentTree{
  using value_type = typename Monoid::value_type;
  
  struct Node{
    value_type val;
    Node *left = nullptr, *right = nullptr;
    Node(const value_type &val): val(val) {}
  };
  
  int64_t depth, size;
  Node *root = nullptr;

  value_type eval(Node *t) const {
    return t ? t->val : Monoid::id();
  }

  Node* update_aux(Node *node, int64_t l, int64_t r, int64_t pos, const value_type &val){
    if(r-l == 1){
      if(node) node->val = val;
      else node = new Node(val);
    }else{
      int64_t m = (l+r)/2;
      if(!node) node = new Node(val);
      if(pos < m) node->left = update_aux(node->left, l, m, pos, val);
      else node->right = update_aux(node->right, m, r, pos, val);
      node->val = Monoid::op(eval(node->left), eval(node->right));
    }
    return node;
  }

  value_type get_aux(Node* node, int64_t l, int64_t r, int64_t x, int64_t y) const {
    if(!node) return Monoid::id();
    if(x <= l && r <= y) return node ? node->val : Monoid::id();
    if(r < x || y < l) return Monoid::id();
    int64_t m = (l + r) >> 1;
    return Monoid::op(get_aux(node->left, l, m, x, y), get_aux(node->right, m, r, x, y));
  }

public:
  DynamicSegmentTree(int64_t n):
    depth(n > 1 ? 64-__builtin_clzll(n-1) + 1 : 1),
    size(1LL << depth)
  {
    root = new Node(Monoid::id());
  }

  void update(int64_t i, const value_type &x){
    update_aux(root, 0, size, i, x);
  }

  value_type get(int64_t l, int64_t r) const {
    return get_aux(root, 0, size, l, r);
  }

  value_type operator[](int64_t i) const {
    return get(i, i+1);
  }
};
