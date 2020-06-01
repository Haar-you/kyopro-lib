#pragma once
#include <vector>

/**
 * @title Persistent segment tree
 * @docs persistent_segment_tree.md
 */
template <typename Monoid>
class PersistentSegmentTree{
  using value_type = typename Monoid::value_type;
  
  struct node{
    value_type value;
    node *left = nullptr, *right = nullptr;
    node(const value_type &value): value(value){}
  };

  int depth;
  node *root = nullptr;

  PersistentSegmentTree(int depth, node *root): depth(depth), root(root){}
  
  node* init(node *t, const std::vector<value_type> &init_list, int d, int &pos){
    if(d == depth){
      t = new node(pos < (int)init_list.size() ? init_list[pos] : Monoid::id());
      ++pos;
    }else{
      t = new node(Monoid::id());
      t->left = init(t->left, init_list, d+1, pos);
      t->right = init(t->right, init_list, d+1, pos);
      t->value = Monoid::op(t->left->value, t->right->value);
    }
    return t;
  }
  
public:
  PersistentSegmentTree(const std::vector<value_type> &init_list){
    const int size = init_list.size();
    depth = size == 1 ? 1 : 32 - __builtin_clz(size-1) + 1;
    int pos = 0;
    root = init(root, init_list, 1, pos);
  }
  
  PersistentSegmentTree(int size, const value_type &value = Monoid::id()){
    depth = size == 1 ? 1 : 32 - __builtin_clz(size-1) + 1;
    int pos = 0;
    root = init(root, std::vector<value_type>(size, value), 1, pos);
  }
  
protected:
  node* update(node *t, int l, int r, int pos, const value_type &val) const {
    if(r <= pos or pos + 1 <= l){
      return t;
    }else if(pos <= l and r <= pos + 1){
      return new node(val);
    }else{
      const int m = (l + r) >> 1;
      auto lp = update(t->left, l, m, pos, val);
      auto rp = update(t->right, m, r, pos, val);

      node *s = new node(Monoid::op(lp->value, rp->value));

      s->left = lp;
      s->right = rp;
      
      return s;
    }
  }

public:
  PersistentSegmentTree update(int i, const value_type &val) const {
    node *t = update(root, 0, 1 << (depth-1), i, val);
    return PersistentSegmentTree(depth, t);
  }

protected:
  value_type get(node *t, int i, int j, int l, int r) const {
    if(i <= l and r <= j) return t->value;
    if(r <= i or j <= l) return Monoid::id();
    const int m = (l + r) >> 1;
    return Monoid::op(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
  }

public:
  value_type get(int i, int j) const {
    return get(root, i, j, 0, 1 << (depth-1));
  }

  value_type at(int i) const {
    return get(i, i+1);
  }
};
