#pragma once
#include <functional>
#include <utility>

namespace haar_lib {
  template <typename T, class Compare = std::less<T>>
  class lazy_skew_heap {
  public:
    using value_type = T;

  private:
    struct node {
      T val, lazy;
      node *left, *right;
      int size;
      node(const T &val): val(val), lazy(0), left(nullptr), right(nullptr), size(1){}
    };

    node *root_;
    Compare compare_;

  public:
    lazy_skew_heap(): root_(nullptr), compare_(Compare()){}
    lazy_skew_heap(const Compare &compare_): root_(nullptr), compare_(compare_){}

  protected:
    node* propagate(node *a){
      if(a){
        a->val += a->lazy;
        if(a->left) a->left->lazy += a->lazy;
        if(a->right) a->right->lazy += a->lazy;
        a->lazy = 0;
      }

      return a;
    }

    node* meld(node *a, node *b){
      if(not a) return propagate(b);
      if(not b) return propagate(a);

      propagate(a);
      propagate(b);

      if(compare_(a->val, b->val)) std::swap(a, b);

      a->size += b->size;
      a->right = meld(a->right, b);
      std::swap(a->left, a->right);

      return a;
    }

  public:
    void meld(lazy_skew_heap &heap){root_ = meld(root_, heap.root_); heap.root_ = nullptr;}
    void push(const T &val){root_ = meld(root_, new node(val));}
    const T& top() const {return root_->val;}
    void pop(){propagate(root_); node *temp = root_; root_ = meld(root_->left, root_->right); delete temp;}
    bool empty() const {return root_ == nullptr;}
    size_t size() const {return root_ ? root_->size : 0;}
    void add(T v){if(root_){root_->lazy += v; propagate(root_);}}
  };
}
