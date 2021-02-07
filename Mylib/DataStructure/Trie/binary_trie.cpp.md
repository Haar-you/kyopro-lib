---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/set_xor_min/main.test.cpp
    title: test/yosupo-judge/set_xor_min/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Trie/binary_trie.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, unsigned int B>\n  class binary_trie\
    \ {\n  public:\n    using value_type = T;\n\n  protected:\n    struct node {\n\
    \      int count;\n      node *ch[2];\n      node(): count(0){\n        ch[0]\
    \ = ch[1] = nullptr;\n      }\n    };\n\n    node *root_ = nullptr;\n\n  protected:\n\
    \    int count(node *t) const {return t ? t->count : 0;}\n\n    int count(node\
    \ *t, T val, unsigned int depth = 1) const {\n      if(not t) return 0;\n\n  \
    \    if(depth > B) return t->count;\n\n      int b = (val >> (B - depth)) & 1;\n\
    \      return count(t->ch[b], val, depth + 1);\n    }\n\n  public:\n    int count(T\
    \ val) const {\n      return count(root_, val);\n    }\n\n  public:\n    int size()\
    \ const {return root_ ? root_->count : 0;}\n    bool empty() const {return not\
    \ root_;}\n\n  protected:\n    void to_list(node *t, T val, std::vector<T> &ret)\
    \ const {\n      if(not t) return;\n      if(not t->ch[0] and not t->ch[1]) for(int\
    \ i = 0; i < t->count; ++i) ret.push_back(val);\n\n      if(t->ch[0]) to_list(t->ch[0],\
    \ val << 1, ret);\n      if(t->ch[1]) to_list(t->ch[1], (val << 1) | 1, ret);\n\
    \    }\n\n  public:\n    std::vector<T> to_list() const {\n      std::vector<T>\
    \ ret;\n      to_list(root_, 0, ret);\n      return ret;\n    }\n\n  protected:\n\
    \    node* insert(node *t, T val, unsigned int depth = 1){\n      if(not t) t\
    \ = new node();\n\n      ++(t->count);\n      if(depth > B) return t;\n\n    \
    \  int b = (val >> (B - depth)) & 1;\n      t->ch[b] = insert(t->ch[b], val, depth\
    \ + 1);\n      return t;\n    }\n\n  public:\n    void insert(T val){\n      root_\
    \ = insert(root_, val);\n    }\n\n  protected:\n    node* erase(node *t, T val,\
    \ unsigned int depth = 1){\n      if(not t) return t;\n\n      --(t->count);\n\
    \      if(t->count == 0) return nullptr;\n      if(depth > B) return t;\n\n  \
    \    int b = (val >> (B - depth)) & 1;\n      t->ch[b] = erase(t->ch[b], val,\
    \ depth + 1);\n      return t;\n    }\n\n  public:\n    void erase(T val){\n \
    \     root_ = erase(root_, val);\n    }\n\n  protected:\n    T min_element(node\
    \ *t, T diff, unsigned int depth = 1) const {\n      if(depth > B) return 0;\n\
    \      int b = (diff >> (B - depth)) & 1;\n      b ^= not t->ch[b];\n      return\
    \ min_element(t->ch[b], diff, depth + 1) | (b << (B - depth));\n    }\n\n  public:\n\
    \    T min_element(T diff = 0) const {\n      return min_element(root_, diff);\n\
    \    }\n\n  protected:\n    T max_element(node *t, T diff, unsigned int depth\
    \ = 1) const {\n      if(depth > B) return 0;\n      int b = not ((diff >> (B\
    \ - depth)) & 1);\n      b ^= not t->ch[b];\n      return max_element(t->ch[b],\
    \ diff, depth + 1) | (b << (B - depth));\n    }\n\n  public:\n    T max_element(T\
    \ diff = 0) const {\n      return max_element(root_, diff);\n    }\n\n  protected:\n\
    \    T at(node *t, int index, unsigned int depth = 1) const {\n      if(depth\
    \ > B) return 0;\n\n      int c = count(t->ch[0]);\n      if(t->ch[0] and index\
    \ < c) return at(t->ch[0], index, depth + 1);\n      else return at(t->ch[1],\
    \ index - c, depth + 1) | ((T)1 << (B - depth));\n    }\n\n  public:\n    T at(int\
    \ index) const {\n      return at(index);\n    }\n\n  protected:\n    int lower_bound(node\
    \ *t, T val, unsigned int depth = 1) const {\n      if(not t) return 0;\n    \
    \  int b = (val >> (B - depth)) & 1;\n      return (b ? count(t->ch[0]) : 0) +\
    \ lower_bound(t->ch[b], val, depth + 1);\n    }\n\n  public:\n    int lower_bound(T\
    \ val) const {\n      return lower_bound(root_, val);\n    }\n\n    int upper_bound(T\
    \ val) const {\n      return lower_bound(root_, val + 1);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T, unsigned int B>\n  class binary_trie {\n  public:\n    using value_type =\
    \ T;\n\n  protected:\n    struct node {\n      int count;\n      node *ch[2];\n\
    \      node(): count(0){\n        ch[0] = ch[1] = nullptr;\n      }\n    };\n\n\
    \    node *root_ = nullptr;\n\n  protected:\n    int count(node *t) const {return\
    \ t ? t->count : 0;}\n\n    int count(node *t, T val, unsigned int depth = 1)\
    \ const {\n      if(not t) return 0;\n\n      if(depth > B) return t->count;\n\
    \n      int b = (val >> (B - depth)) & 1;\n      return count(t->ch[b], val, depth\
    \ + 1);\n    }\n\n  public:\n    int count(T val) const {\n      return count(root_,\
    \ val);\n    }\n\n  public:\n    int size() const {return root_ ? root_->count\
    \ : 0;}\n    bool empty() const {return not root_;}\n\n  protected:\n    void\
    \ to_list(node *t, T val, std::vector<T> &ret) const {\n      if(not t) return;\n\
    \      if(not t->ch[0] and not t->ch[1]) for(int i = 0; i < t->count; ++i) ret.push_back(val);\n\
    \n      if(t->ch[0]) to_list(t->ch[0], val << 1, ret);\n      if(t->ch[1]) to_list(t->ch[1],\
    \ (val << 1) | 1, ret);\n    }\n\n  public:\n    std::vector<T> to_list() const\
    \ {\n      std::vector<T> ret;\n      to_list(root_, 0, ret);\n      return ret;\n\
    \    }\n\n  protected:\n    node* insert(node *t, T val, unsigned int depth =\
    \ 1){\n      if(not t) t = new node();\n\n      ++(t->count);\n      if(depth\
    \ > B) return t;\n\n      int b = (val >> (B - depth)) & 1;\n      t->ch[b] =\
    \ insert(t->ch[b], val, depth + 1);\n      return t;\n    }\n\n  public:\n   \
    \ void insert(T val){\n      root_ = insert(root_, val);\n    }\n\n  protected:\n\
    \    node* erase(node *t, T val, unsigned int depth = 1){\n      if(not t) return\
    \ t;\n\n      --(t->count);\n      if(t->count == 0) return nullptr;\n      if(depth\
    \ > B) return t;\n\n      int b = (val >> (B - depth)) & 1;\n      t->ch[b] =\
    \ erase(t->ch[b], val, depth + 1);\n      return t;\n    }\n\n  public:\n    void\
    \ erase(T val){\n      root_ = erase(root_, val);\n    }\n\n  protected:\n   \
    \ T min_element(node *t, T diff, unsigned int depth = 1) const {\n      if(depth\
    \ > B) return 0;\n      int b = (diff >> (B - depth)) & 1;\n      b ^= not t->ch[b];\n\
    \      return min_element(t->ch[b], diff, depth + 1) | (b << (B - depth));\n \
    \   }\n\n  public:\n    T min_element(T diff = 0) const {\n      return min_element(root_,\
    \ diff);\n    }\n\n  protected:\n    T max_element(node *t, T diff, unsigned int\
    \ depth = 1) const {\n      if(depth > B) return 0;\n      int b = not ((diff\
    \ >> (B - depth)) & 1);\n      b ^= not t->ch[b];\n      return max_element(t->ch[b],\
    \ diff, depth + 1) | (b << (B - depth));\n    }\n\n  public:\n    T max_element(T\
    \ diff = 0) const {\n      return max_element(root_, diff);\n    }\n\n  protected:\n\
    \    T at(node *t, int index, unsigned int depth = 1) const {\n      if(depth\
    \ > B) return 0;\n\n      int c = count(t->ch[0]);\n      if(t->ch[0] and index\
    \ < c) return at(t->ch[0], index, depth + 1);\n      else return at(t->ch[1],\
    \ index - c, depth + 1) | ((T)1 << (B - depth));\n    }\n\n  public:\n    T at(int\
    \ index) const {\n      return at(index);\n    }\n\n  protected:\n    int lower_bound(node\
    \ *t, T val, unsigned int depth = 1) const {\n      if(not t) return 0;\n    \
    \  int b = (val >> (B - depth)) & 1;\n      return (b ? count(t->ch[0]) : 0) +\
    \ lower_bound(t->ch[b], val, depth + 1);\n    }\n\n  public:\n    int lower_bound(T\
    \ val) const {\n      return lower_bound(root_, val);\n    }\n\n    int upper_bound(T\
    \ val) const {\n      return lower_bound(root_, val + 1);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Trie/binary_trie.cpp
  requiredBy: []
  timestamp: '2020-09-29 00:55:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/set_xor_min/main.test.cpp
documentation_of: Mylib/DataStructure/Trie/binary_trie.cpp
layout: document
title: Binary trie
---

## Operations

## Requirements

## Notes

## Problems

- [第5回 ドワンゴからの挑戦状 本選 B - XOR Spread](https://beta.atcoder.jp/contests/dwacon5th-final-open/tasks/dwacon5th_final_b)

## References

- [https://kazuma8128.hatenablog.com/entry/2018/05/06/022654](https://kazuma8128.hatenablog.com/entry/2018/05/06/022654)
