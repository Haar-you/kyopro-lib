---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Stack/persistent_stack.cpp\"\n#include\
    \ <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  struct persistent_stack\
    \ {\n  protected:\n    struct node {\n      T value;\n      node *next = nullptr;\n\
    \    };\n\n    node *root;\n\n    persistent_stack(node *root): root(root){}\n\
    \n  public:\n    persistent_stack(): root(nullptr){}\n\n    bool empty() const\
    \ {\n      return not root;\n    }\n\n    const T& top() const {\n      return\
    \ root->value;\n    }\n\n    persistent_stack push(const T &value) const {\n \
    \     node *t = new node({value, root});\n      return persistent_stack(t);\n\
    \    }\n\n    persistent_stack pop() const {\n      node *t = root->next;\n  \
    \    return persistent_stack(t);\n    }\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const persistent_stack &a){\n      s << \"{\";\n      node *t = a.root;\n\
    \      while(t){\n        if(t != a.root) s << \", \";\n        s << t->value;\n\
    \        t = t->next;\n      }\n\n      s << \"}\";\n      return s;\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <iostream>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct persistent_stack {\n  protected:\n    struct node {\n      T value;\n\
    \      node *next = nullptr;\n    };\n\n    node *root;\n\n    persistent_stack(node\
    \ *root): root(root){}\n\n  public:\n    persistent_stack(): root(nullptr){}\n\
    \n    bool empty() const {\n      return not root;\n    }\n\n    const T& top()\
    \ const {\n      return root->value;\n    }\n\n    persistent_stack push(const\
    \ T &value) const {\n      node *t = new node({value, root});\n      return persistent_stack(t);\n\
    \    }\n\n    persistent_stack pop() const {\n      node *t = root->next;\n  \
    \    return persistent_stack(t);\n    }\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const persistent_stack &a){\n      s << \"{\";\n      node *t = a.root;\n\
    \      while(t){\n        if(t != a.root) s << \", \";\n        s << t->value;\n\
    \        t = t->next;\n      }\n\n      s << \"}\";\n      return s;\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Stack/persistent_stack.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
