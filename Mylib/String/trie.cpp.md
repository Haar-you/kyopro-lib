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
  bundledCode: "#line 2 \"Mylib/String/trie.cpp\"\n#include <string>\n#include <vector>\n\
    #include <map>\n\nnamespace haar_lib {\n  template <typename T>\n  struct trie_node\
    \ {\n    std::map<char, trie_node*> children;\n    T val;\n\n  public:\n    trie_node(){}\n\
    \    trie_node(T val): val(val){}\n\n    const T& value() const {return val;}\n\
    \    T& value(){return val;}\n\n    trie_node* insert(char c, const T &v){\n \
    \     if(children.find(c) != children.end()){\n        children[c]->val = v;\n\
    \      }else{\n        children[c] = new trie_node<T>(v);\n      }\n\n      return\
    \ children[c];\n    }\n\n    template <typename Iter>\n    trie_node* insert(Iter\
    \ first, Iter last, const T &v){\n      if(first == last){\n        val = v;\n\
    \        return this;\n      }else{\n        const auto c = *first;\n        if(children.find(c)\
    \ == children.end()){\n          children[c] = new trie_node(T());\n        }\n\
    \n        return children[c]->insert(first + 1, last, v);\n      }\n    }\n\n\
    \    trie_node* find(char c){\n      if(children.find(c) != children.end()) return\
    \ children[c];\n      else return nullptr;\n    }\n  };\n\n  template <typename\
    \ T>\n  struct trie {\n    using node = trie_node<T>;\n\n    node *root;\n\n \
    \   trie(){\n      root = new node(T());\n    }\n\n    template <typename Iter>\n\
    \    node* insert(Iter first, Iter last, const T &v){\n      return root->insert(first,\
    \ last, v);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include <map>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct trie_node {\n    std::map<char,\
    \ trie_node*> children;\n    T val;\n\n  public:\n    trie_node(){}\n    trie_node(T\
    \ val): val(val){}\n\n    const T& value() const {return val;}\n    T& value(){return\
    \ val;}\n\n    trie_node* insert(char c, const T &v){\n      if(children.find(c)\
    \ != children.end()){\n        children[c]->val = v;\n      }else{\n        children[c]\
    \ = new trie_node<T>(v);\n      }\n\n      return children[c];\n    }\n\n    template\
    \ <typename Iter>\n    trie_node* insert(Iter first, Iter last, const T &v){\n\
    \      if(first == last){\n        val = v;\n        return this;\n      }else{\n\
    \        const auto c = *first;\n        if(children.find(c) == children.end()){\n\
    \          children[c] = new trie_node(T());\n        }\n\n        return children[c]->insert(first\
    \ + 1, last, v);\n      }\n    }\n\n    trie_node* find(char c){\n      if(children.find(c)\
    \ != children.end()) return children[c];\n      else return nullptr;\n    }\n\
    \  };\n\n  template <typename T>\n  struct trie {\n    using node = trie_node<T>;\n\
    \n    node *root;\n\n    trie(){\n      root = new node(T());\n    }\n\n    template\
    \ <typename Iter>\n    node* insert(Iter first, Iter last, const T &v){\n    \
    \  return root->insert(first, last, v);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/trie.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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

