#pragma once
#include <memory>
#include <vector>
#include <iostream>

namespace haar_lib {
  template <typename T>
  class persistent_array {
  public:
    using value_type = T;

  private:
    struct node {
      bool is_terminal;
      int size = 1;
      node *left = nullptr, *right = nullptr;
      std::unique_ptr<T> value;

      node(): is_terminal(false){}
      node(T v): is_terminal(true), value(new T(v)){}
    };

    size_t size_;
    int depth_;
    node* root_ = nullptr;

    int get_size(node *t) const {
      return t ? t->size : 0;
    }

    node* init(int s, int d){
      if(s == 0) return nullptr;
      if(d == depth_){
        return new node(T());
      }else{
        node *t = new node();
        t->left = init(s / 2, d + 1);
        t->right = init(s - s / 2, d + 1);
        t->size = get_size(t->left) + get_size(t->right);
        return t;
      }
    }

    void apply_init(node *t, const std::vector<T> &ret, int &i) {
      if(not t) return;

      if(t->is_terminal){
        *(t->value) = ret[i];
        ++i;
        return;
      }

      apply_init(t->left, ret, i);
      apply_init(t->right, ret, i);
    }

    persistent_array(node *root): root_(root){}

    void calc_depth(){
      depth_ = 1;
      while((int)size_ > (1 << depth_)) depth_ += 1;
      depth_ += 1;
    }

  public:
    persistent_array(){}
    persistent_array(size_t size): size_(size){
      calc_depth();
      root_ = init(size_, 1);
    }

    persistent_array(const std::vector<T> &v): size_(v.size()){
      calc_depth();
      root_ = init(size_, 1);

      int i = 0;
      apply_init(root_, v, i);
    }

    persistent_array(const persistent_array &v){
      this->root_ = v.root_;
      this->size_ = v.size_;
      this->depth_ = v.depth_;
    }

  protected:
    T get(node *t, int i) const {
      if(t->is_terminal) return *(t->value);

      int k = get_size(t->left);
      if(i < k) return get(t->left, i);
      else return get(t->right, i - k);
    }

  public:
    T operator[](int i) const {
      return get(root_, i);
    }

  protected:
    node* set(node *prev, int i, const T &val) const {
      if(prev->is_terminal) return new node(val);

      int k = get_size(prev->left);

      node *t = new node();
      if(i < k){
        t->right = prev->right;
        t->left = set(prev->left, i, val);
        t->size = get_size(t->right) + get_size(t->left);
      }else{
        t->left = prev->left;
        t->right = set(prev->right, i - k, val);
        t->size = get_size(t->right) + get_size(t->left);
      }
      return t;
    }

  public:
    persistent_array set(int i, const T &val) const {
      node *ret = set(root_, i, val);
      return persistent_array(ret);
    }

  protected:
    void traverse(node *t, std::vector<T> &ret) const {
      if(not t) return;

      if(t->is_terminal){
        ret.push_back(*(t->value));
        return;
      }

      traverse(t->left, ret);
      traverse(t->right, ret);
    }

  public:
    std::vector<T> traverse() const {
      std::vector<T> ret;
      traverse(root_, ret);
      return ret;
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_array &a){
      auto v = a.traverse();
      s << "{";
      for(auto it = v.begin(); it != v.end(); ++it){
        if(it != v.begin()) s << ", ";
        s << *it;
      }
      s << "}";
      return s;
    }
  };
}
