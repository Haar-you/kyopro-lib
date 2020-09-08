#pragma once
#include <iostream>

/**
 * @title Persistent stack
 * @docs persistent_stack.md
 */
namespace haar_lib {
  template <typename T>
  struct PersistentStack {
  protected:
    struct node {
      T value;
      node *next = nullptr;
    };

    node *root;

    PersistentStack(node *root): root(root){}

  public:
    PersistentStack(): root(nullptr){}

    bool empty() const {
      return not root;
    }

    const T& top() const {
      return root->value;
    }

    PersistentStack push(const T &value) const {
      node *t = new node({value, root});
      return PersistentStack(t);
    }

    PersistentStack pop() const {
      node *t = root->next;
      return PersistentStack(t);
    }

    friend std::ostream& operator<<(std::ostream &s, const PersistentStack &a){
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
