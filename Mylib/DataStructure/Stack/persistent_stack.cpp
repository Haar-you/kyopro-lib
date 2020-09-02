#pragma once

/**
 * @title Persistent stack
 * @docs persistent_stack.md
 */
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
};
