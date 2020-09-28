#pragma once
#include <array>
#include <iostream>
#include <vector>

namespace haar_lib {
  template <typename T>
  class persistent_queue {
  public:
    using value_type = T;

  private:
    constexpr static int MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2

    struct node {
      T value;
      std::array<node*, MAX_SIZE_2> ancestors;
      int depth = 0;
    };

    node *front_node_ = nullptr, *back_node_ = nullptr;

    persistent_queue(node* front_node, node* back_node):
      front_node_(front_node), back_node_(back_node){}

  public:
    persistent_queue(){}
    persistent_queue(const T &value){
      node *t = new node();
      t->value = value;
      back_node_ = front_node_ = t;
    }

    persistent_queue push(const T &value) const {
      node *t = new node();

      t->value = value;

      t->ancestors[0] = back_node_;
      for(int i = 1; i < MAX_SIZE_2; ++i){
        node *s = t->ancestors[i - 1];
        if(s) t->ancestors[i] = s->ancestors[i - 1];
        else break;
      }

      t->depth = back_node_ ? back_node_->depth + 1 : 0;

      return persistent_queue(front_node_ ? front_node_ : t, t);
    }

    persistent_queue pop() const {
      if(back_node_->depth == front_node_->depth){
        return persistent_queue(nullptr, nullptr);
      }

      int d = back_node_->depth - front_node_->depth - 1;

      node *t = back_node_;

      for(int i = MAX_SIZE_2 - 1; i >= 0; --i){
        if(d >= (1 << i)){
          d -= (1 << i);
          t = t->ancestors[i];
        }
        if(d == 0) break;
      }

      return persistent_queue(t, back_node_);
    }

    T front() const {
      return front_node_->value;
    }

    T back() const {
      return back_node_->value;
    }

    bool empty() const {
      return not front_node_;
    }

    int size() const {
      return front_node_ ? back_node_->depth - front_node_->depth + 1 : 0;
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_queue &a){
      s << "{";
      std::vector<T> temp;
      node *t = a.back_node_;
      while(t){
        if(t == a.front_node_){
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
