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

    node *root;

    persistent_stack(node *root): root(root){}

  public:
    persistent_stack(): root(nullptr){}

    bool empty() const {
      return not root;
    }

    const T& top() const {
      return root->value;
    }

    persistent_stack push(const T &value) const {
      node *t = new node({value, root});
      return persistent_stack(t);
    }

    persistent_stack pop() const {
      node *t = root->next;
      return persistent_stack(t);
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_stack &a){
      s << "{";
      node *t = a.root;
      while(t){
        if(t != a.root) s << ", ";
        s << t->value;
        t = t->next;
      }

      s << "}";
      return s;
    }
  };
}
