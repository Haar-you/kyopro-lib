#pragma once
#include <array>
#include <iostream>
#include <vector>

namespace haar_lib {
  template <typename T>
  class persistent_queue {
    constexpr static int MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2

    struct node {
      T value;
      std::array<node*, MAX_SIZE_2> ancestors;
      int depth = 0;
    };

    node *front_node = nullptr, *back_node = nullptr;

    persistent_queue(node* front_node, node* back_node): front_node(front_node), back_node(back_node){}

  public:
    persistent_queue(){}
    persistent_queue(const T &value){
      node *t = new node();
      t->value = value;
      back_node = front_node = t;
    }

    persistent_queue push(const T &value) const {
      node *t = new node();

      t->value = value;

      t->ancestors[0] = back_node;
      for(int i = 1; i < MAX_SIZE_2; ++i){
        node *s = t->ancestors[i - 1];
        if(s) t->ancestors[i] = s->ancestors[i - 1];
        else break;
      }

      t->depth = back_node ? back_node->depth + 1 : 0;

      return persistent_queue(front_node ? front_node : t, t);
    }

    persistent_queue pop() const {
      if(back_node->depth == front_node->depth){
        return persistent_queue(nullptr, nullptr);
      }

      int d = back_node->depth - front_node->depth - 1;

      node *t = back_node;

      for(int i = MAX_SIZE_2 - 1; i >= 0; --i){
        if(d >= (1 << i)){
          d -= (1 << i);
          t = t->ancestors[i];
        }
        if(d == 0) break;
      }

      return persistent_queue(t, back_node);
    }

    T front() const {
      return front_node->value;
    }

    T back() const {
      return back_node->value;
    }

    bool empty() const {
      return not front_node;
    }

    int size() const {
      return front_node ? back_node->depth - front_node->depth + 1 : 0;
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_queue &a){
      s << "{";
      std::vector<T> temp;
      node *t = a.back_node;
      while(t){
        if(t == a.front_node){
          temp.push_back(t->value);
          break;
        }
        temp.push_back(t->value);
        t = t->ancestors[0];
      }

      for(auto it = temp.begin(); it != temp.end(); ++it){
        if(it != temp.begin()) s << ", ";
        s << *it;
      }

      s << "}";
      return s;
    }
  };
}
