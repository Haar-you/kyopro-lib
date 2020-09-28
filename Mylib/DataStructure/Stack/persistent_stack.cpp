#pragma once
#include <iostream>

namespace haar_lib {
  template <typename T>
  struct persistent_stack {
  protected:
    struct node {
      T value;
      node *next = nullptr;
    };

    node *root_;

    persistent_stack(node *root): root_(root){}

  public:
    persistent_stack(): root_(nullptr){}

    bool empty() const {
      return not root_;
    }

    const T& top() const {
      return root_->value;
    }

    persistent_stack push(const T &value) const {
      node *t = new node({value, root_});
      return persistent_stack(t);
    }

    persistent_stack pop() const {
      node *t = root_->next;
      return persistent_stack(t);
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_stack &a){
      s << "{";
      node *t = a.root_;
      while(t){
        if(t != a.root_) s << ", ";
        s << t->value;
        t = t->next;
      }

      s << "}";
      return s;
    }
  };
}
