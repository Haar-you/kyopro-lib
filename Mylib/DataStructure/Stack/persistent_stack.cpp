#pragma once

/**
 * @title 永続Stack
 */
template <typename T> struct PersistentStack{
protected:
  struct node{
    T value;
    node *next = nullptr;
  };

  node *root;

  PersistentStack(node *root): root(root){}

public:
  PersistentStack(): root(nullptr){}
  
  bool empty() const {
    return root == nullptr;
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
