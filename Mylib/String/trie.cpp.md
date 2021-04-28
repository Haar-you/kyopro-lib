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
  bundledCode: "#line 2 \"Mylib/String/trie.cpp\"\n#include <map>\n#include <string>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  class trie_node\
    \ {\n    std::map<char, trie_node*> children_;\n    T val_;\n\n  public:\n   \
    \ trie_node() {}\n    trie_node(T val) : val_(val) {}\n\n    const T& value()\
    \ const { return val_; }\n    T& value() { return val_; }\n\n    trie_node* insert(char\
    \ c, const T& v) {\n      if (children_.find(c) != children_.end()) {\n      \
    \  children_[c]->val_ = v;\n      } else {\n        children_[c] = new trie_node<T>(v);\n\
    \      }\n\n      return children_[c];\n    }\n\n    template <typename Iter>\n\
    \    trie_node* insert(Iter first, Iter last, const T& v) {\n      if (first ==\
    \ last) {\n        val_ = v;\n        return this;\n      } else {\n        const\
    \ auto c = *first;\n        if (children_.find(c) == children_.end()) {\n    \
    \      children_[c] = new trie_node(T());\n        }\n\n        return children_[c]->insert(first\
    \ + 1, last, v);\n      }\n    }\n\n    trie_node* find(char c) {\n      if (children_.find(c)\
    \ != children_.end())\n        return children_[c];\n      else\n        return\
    \ nullptr;\n    }\n  };\n\n  template <typename T>\n  struct trie {\n    using\
    \ node = trie_node<T>;\n\n  private:\n    node* root_;\n\n  public:\n    trie()\
    \ : root_(new node(T())) {}\n\n    node* root() const { return root; }\n\n   \
    \ template <typename Iter>\n    node* insert(Iter first, Iter last, const T& v)\
    \ {\n      return root->insert(first, last, v);\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <map>\n#include <string>\n#include <vector>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class trie_node {\n    std::map<char,\
    \ trie_node*> children_;\n    T val_;\n\n  public:\n    trie_node() {}\n    trie_node(T\
    \ val) : val_(val) {}\n\n    const T& value() const { return val_; }\n    T& value()\
    \ { return val_; }\n\n    trie_node* insert(char c, const T& v) {\n      if (children_.find(c)\
    \ != children_.end()) {\n        children_[c]->val_ = v;\n      } else {\n   \
    \     children_[c] = new trie_node<T>(v);\n      }\n\n      return children_[c];\n\
    \    }\n\n    template <typename Iter>\n    trie_node* insert(Iter first, Iter\
    \ last, const T& v) {\n      if (first == last) {\n        val_ = v;\n       \
    \ return this;\n      } else {\n        const auto c = *first;\n        if (children_.find(c)\
    \ == children_.end()) {\n          children_[c] = new trie_node(T());\n      \
    \  }\n\n        return children_[c]->insert(first + 1, last, v);\n      }\n  \
    \  }\n\n    trie_node* find(char c) {\n      if (children_.find(c) != children_.end())\n\
    \        return children_[c];\n      else\n        return nullptr;\n    }\n  };\n\
    \n  template <typename T>\n  struct trie {\n    using node = trie_node<T>;\n\n\
    \  private:\n    node* root_;\n\n  public:\n    trie() : root_(new node(T()))\
    \ {}\n\n    node* root() const { return root; }\n\n    template <typename Iter>\n\
    \    node* insert(Iter first, Iter last, const T& v) {\n      return root->insert(first,\
    \ last, v);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/trie.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/String/trie.cpp
layout: document
title: Trie
---

## Operations

## Requirements

## Notes

## Problems

- [C - たんごたくさん](https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c)
- [Codeforces Round #542 (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C)
- [dna - DNAの合成 (DNA Synthesizer)](https://atcoder.jp/contests/joisc2010/tasks/joisc2010_dna)
- [E - 宝くじ](https://atcoder.jp/contests/utpc2014/tasks/utpc2014_e)

## References

