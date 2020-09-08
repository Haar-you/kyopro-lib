#pragma once
#include <vector>
#include <array>
#include <functional>
#include <cassert>

/**
 * @title Binomial heap
 * @docs binomial_heap.md
 */
namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class binomial_heap {
    struct node {
      T value;
      std::vector<node*> children;
      node(T value): value(value){}
    };

    constexpr static int MAX = 31;

    std::array<node*, MAX> roots;
    Compare compare;
    int top_index = -1;
    int heap_size = 0;

    node* merge(node *a, node *b){
      if(compare(a->value, b->value)) std::swap(a, b);
      a->children.push_back(b);
      return a;
    }

    template <typename Container>
    void meld(Container c){
      node *s = nullptr;

      for(int i = 0; i < MAX; ++i){
        std::vector<node*> temp;
        if(s){temp.push_back(s); s = nullptr;}
        if(roots[i]){temp.push_back(roots[i]); roots[i] = nullptr;}
        if(i < (int)c.size() and c[i]){temp.push_back(c[i]); c[i] = nullptr;}

        switch(temp.size()){
        case 1: roots[i] = temp[0]; break;
        case 2: s = merge(temp[0], temp[1]); break;
        case 3: roots[i] = temp[0]; s = merge(temp[1], temp[2]); break;
        }
      }

      top_index = -1;
      for(int i = 0; i < MAX; ++i){
        if(roots[i]){
          if(top_index == -1 or compare(roots[top_index]->value, roots[i]->value)){
            top_index = i;
          }
        }
      }
    }

  public:
    binomial_heap(){
      roots.fill(nullptr);
      compare = Compare();
    }

    int size() const {
      return heap_size;
    }

    bool empty() const {
      return heap_size == 0;
    }

    void push(const T &value){
      heap_size += 1;
      node *t = new node(value);

      meld(std::vector<node*>({t}));
    }

    const T& top() const {
      return roots[top_index]->value;
    }

    void pop(){
      heap_size -= 1;

      node *t = roots[top_index];
      roots[top_index] = nullptr;
      meld(t->children);

      delete t;
    }

    void meld(binomial_heap &rhs){
      heap_size += rhs.heap_size;
      meld(rhs.roots);
      rhs.roots.fill(nullptr);
    }
  };
}
