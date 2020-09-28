#pragma once
#include <vector>
#include <array>
#include <functional>
#include <cassert>

namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class binomial_heap {
  public:
    using value_type = T;

  private:
    struct node {
      T value;
      std::vector<node*> children;
      node(T value): value(value){}
    };

    constexpr static int MAX = 31;

    std::array<node*, MAX> roots_;
    Compare compare_;
    int top_index_ = -1;
    int heap_size_ = 0;

    node* merge(node *a, node *b){
      if(compare_(a->value, b->value)) std::swap(a, b);
      a->children.push_back(b);
      return a;
    }

    template <typename Container>
    void meld(Container c){
      node *s = nullptr;

      for(int i = 0; i < MAX; ++i){
        std::vector<node*> temp;
        if(s){temp.push_back(s); s = nullptr;}
        if(roots_[i]){temp.push_back(roots_[i]); roots_[i] = nullptr;}
        if(i < (int)c.size() and c[i]){temp.push_back(c[i]); c[i] = nullptr;}

        switch(temp.size()){
        case 1: roots_[i] = temp[0]; break;
        case 2: s = merge(temp[0], temp[1]); break;
        case 3: roots_[i] = temp[0]; s = merge(temp[1], temp[2]); break;
        }
      }

      top_index_ = -1;
      for(int i = 0; i < MAX; ++i){
        if(roots_[i]){
          if(top_index_ == -1 or compare_(roots_[top_index_]->value, roots_[i]->value)){
            top_index_ = i;
          }
        }
      }
    }

  public:
    binomial_heap(){
      roots_.fill(nullptr);
      compare_ = Compare();
    }

    int size() const {
      return heap_size_;
    }

    bool empty() const {
      return heap_size_ == 0;
    }

    void push(const T &value){
      heap_size_ += 1;
      node *t = new node(value);

      meld(std::vector<node*>({t}));
    }

    const T& top() const {
      return roots_[top_index_]->value;
    }

    void pop(){
      heap_size_ -= 1;

      node *t = roots_[top_index_];
      roots_[top_index_] = nullptr;
      meld(t->children);

      delete t;
    }

    void meld(binomial_heap &rhs){
      heap_size_ += rhs.heap_size_;
      meld(rhs.roots_);
      rhs.roots_.fill(nullptr);
    }
  };
}
