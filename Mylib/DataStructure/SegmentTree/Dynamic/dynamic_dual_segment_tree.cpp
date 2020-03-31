#pragma once
#include <unordered_map>

template <typename Monoid>
class DynamicDualSegmentTree{
  using value_type = typename Monoid::value_type;

  struct Node{
    value_type val;
    Node *left = nullptr, *right = nullptr;
    Node(const value_type &val): val(val) {}
  };
  
  const int64_t depth, size;
  Node *root = nullptr;
  std::unordered_map<int64_t, Node*> umap;

  Node* propagate(Node *node, int64_t l, int64_t r){
    if(r-l > 1){
      if(not node->left) node->left = new Node(Monoid::id());
      node->left->val = Monoid::op(node->val, node->left->val);

      if(not node->right) node->right = new Node(Monoid::id());
      node->right->val = Monoid::op(node->val, node->right->val);

      node->val = Monoid::id();
    }
    return node;
  }

  void update(Node *node, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
    if(r-l == 1){
      if(x <= l && r <= y) node->val = Monoid::op(node->val, val);
      umap[l] = node;
      return;
    }
    if(r < x || y < l) return;
    else if(x <= l && r <= y) node->val = Monoid::op(node->val, val);
    else{
      int64_t m = (l+r)/2;
      propagate(node, l, r);
      update(node->left, l, m, x, y, val);
      update(node->right, m, r, x, y, val);
    }
  }

  void get(Node* node, int64_t l, int64_t r, int64_t x){
    if(r-l == 1){
      umap[l] = node;
      return;
    }
    propagate(node, l, r);
    int m = (l + r) / 2;
    if(x < m) get(node->left, l, m, x);
    else get(node->right, m, r, x);
  }

public:
  DynamicDualSegmentTree(int64_t n):
    depth(n > 1 ? 64-__builtin_clzll(n-1) + 1 : 1),
    size(1LL << depth)
  {
    root = new Node(Monoid::id());
  }

  void update(int64_t s, int64_t t, value_type &x){
    update(root, 0, size, s, t, x);
  }

  value_type get(int64_t x){
    get(root, 0, size, x);
    return umap[x]->val;
  }
};
