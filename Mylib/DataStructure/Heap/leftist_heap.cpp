#pragma once
#include <functional>
#include <utility>

namespace haar_lib {
  template <typename T, class Compare = std::less<T>>
  class leftist_heap {
    struct node {
      T val;
      node *left, *right;
      int s, size;
      node(const T &val): val(val), left(nullptr), right(nullptr), s(0), size(1){}
    };

    node *root;
    Compare compare;

  public:
    leftist_heap(): root(nullptr), compare(Compare()){}
    leftist_heap(const Compare &compare): root(nullptr), compare(compare){}

  protected:
    node* meld(node *a, node *b){
      if(!a) return b;
      if(!b) return a;

      if(compare(a->val, b->val)) std::swap(a, b);

      a->right = meld(a->right, b);
      if(!a->left or a->left->s < a->right->s) std::swap(a->left, a->right);

      a->s = (a->right ? a->right->s : 0) + 1;
      a->size = 1 + (a->left ? a->left->size : 0) + (a->right ? a->right->size : 0);
      return a;
    }

  public:
    void meld(leftist_heap &heap){root = meld(root, heap.root); heap.root = nullptr;}
    void push(const T &val){root = meld(root, new node(val));}
    const T& top() const {return root->val;}
    void pop(){node *temp = root; root = meld(root->left, root->right); delete temp;}
    bool empty() const {return root == nullptr;}
    size_t size() const {return root ? root->size : 0;}
  };
}
