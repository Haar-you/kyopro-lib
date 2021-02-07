---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Stack/persistent_stack.cpp\"\n#include\
    \ <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  struct persistent_stack\
    \ {\n  protected:\n    struct node {\n      T value;\n      node *next = nullptr;\n\
    \    };\n\n    node *root_;\n\n    persistent_stack(node *root): root_(root){}\n\
    \n  public:\n    persistent_stack(): root_(nullptr){}\n\n    bool empty() const\
    \ {\n      return not root_;\n    }\n\n    const T& top() const {\n      return\
    \ root_->value;\n    }\n\n    persistent_stack push(const T &value) const {\n\
    \      node *t = new node({value, root_});\n      return persistent_stack(t);\n\
    \    }\n\n    persistent_stack pop() const {\n      node *t = root_->next;\n \
    \     return persistent_stack(t);\n    }\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const persistent_stack &a){\n      s << \"{\";\n      node *t = a.root_;\n\
    \      while(t){\n        if(t != a.root_) s << \", \";\n        s << t->value;\n\
    \        t = t->next;\n      }\n\n      s << \"}\";\n      return s;\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <iostream>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct persistent_stack {\n  protected:\n    struct node {\n      T value;\n\
    \      node *next = nullptr;\n    };\n\n    node *root_;\n\n    persistent_stack(node\
    \ *root): root_(root){}\n\n  public:\n    persistent_stack(): root_(nullptr){}\n\
    \n    bool empty() const {\n      return not root_;\n    }\n\n    const T& top()\
    \ const {\n      return root_->value;\n    }\n\n    persistent_stack push(const\
    \ T &value) const {\n      node *t = new node({value, root_});\n      return persistent_stack(t);\n\
    \    }\n\n    persistent_stack pop() const {\n      node *t = root_->next;\n \
    \     return persistent_stack(t);\n    }\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const persistent_stack &a){\n      s << \"{\";\n      node *t = a.root_;\n\
    \      while(t){\n        if(t != a.root_) s << \", \";\n        s << t->value;\n\
    \        t = t->next;\n      }\n\n      s << \"}\";\n      return s;\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Stack/persistent_stack.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/Stack/persistent_stack.cpp
layout: document
title: Persistent stack
---

## Operations

## Requirements

## Notes

## Problems

## References
