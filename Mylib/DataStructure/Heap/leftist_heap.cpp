#pragma once
#include <functional>
#include <utility>

namespace haar_lib {
  template <typename T, class Compare = std::less<T>>
  class leftist_heap {
  public:
    using value_type = T;

  private:
    struct node {
      T val;
      node *left, *right;
      int s, size;
      node(const T &val): val(val), left(nullptr), right(nullptr), s(0), size(1){}
    };

    node *root_;
    Compare compare_;

  public:
    leftist_heap(): root_(nullptr), compare_(Compare()){}
    leftist_heap(const Compare &compare_): root_(nullptr), compare_(compare_){}

  protected:
    node* meld(node *a, node *b){
      if(not a) return b;
      if(not b) return a;

      if(compare_(a->val, b->val)) std::swap(a, b);

      a->right = meld(a->right, b);
      if(not a->left or a->left->s < a->right->s) std::swap(a->left, a->right);

      a->s = (a->right ? a->right->s : 0) + 1;
      a->size = 1 + (a->left ? a->left->size : 0) + (a->right ? a->right->size : 0);
      return a;
    }

  public:
    void meld(leftist_heap &heap){root_ = meld(root_, heap.root_); heap.root_ = nullptr;}
    void push(const T &val){root_ = meld(root_, new node(val));}
    const T& top() const {return root_->val;}
    void pop(){node *temp = root_; root_ = meld(root_->left, root_->right); delete temp;}
    bool empty() const {return root_ == nullptr;}
    size_t size() const {return root_ ? root_->size : 0;}
  };
}
