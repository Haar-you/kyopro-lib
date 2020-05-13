#pragma once
#include <functional>
#include <utility>

/**
 * @title SkewHeap
 * @docs skew_heap.md
 */
template <typename T, class Compare = std::less<T>>
class SkewHeap{
  struct node{
    T val;
    node *left, *right;
    int size;
    node(const T &val): val(val), left(nullptr), right(nullptr), size(1){}
  };

  node *root;
  Compare compare;

public:
  SkewHeap(): root(nullptr), compare(Compare()){}
  SkewHeap(const Compare &compare): root(nullptr), compare(compare){}

protected:
  node* meld(node *a, node *b){
    if(!a) return b;
    if(!b) return a;

    if(compare(a->val, b->val)) std::swap(a, b);

    a->size += b->size;
    a->right = meld(a->right, b);
    std::swap(a->left, a->right);

    return a;
  }

public:
  void meld(SkewHeap &heap){root = meld(root, heap.root); heap.root = nullptr;}
  void push(const T &val){root = meld(root, new node(val));}
  const T& top() const {return root->val;}
  void pop(){node *temp = root; root = meld(root->left, root->right); delete temp;}
  bool empty() const {return root == nullptr;}
  size_t size() const {return root ? root->size : 0;}
};
