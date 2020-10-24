---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/persistent_queue/main.test.cpp
    title: test/yosupo-judge/persistent_queue/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Queue/persistent_queue.cpp\"\n#include\
    \ <array>\n#include <iostream>\n#include <vector>\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  class persistent_queue {\n  public:\n    using value_type =\
    \ T;\n\n  private:\n    constexpr static int MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2\n\
    \n    struct node {\n      T value;\n      std::array<node*, MAX_SIZE_2> ancestors;\n\
    \      int depth = 0;\n    };\n\n    node *front_node_ = nullptr, *back_node_\
    \ = nullptr;\n\n    persistent_queue(node* front_node, node* back_node):\n   \
    \   front_node_(front_node), back_node_(back_node){}\n\n  public:\n    persistent_queue(){}\n\
    \    persistent_queue(const T &value){\n      node *t = new node();\n      t->value\
    \ = value;\n      back_node_ = front_node_ = t;\n    }\n\n    persistent_queue\
    \ push(const T &value) const {\n      node *t = new node();\n\n      t->value\
    \ = value;\n\n      t->ancestors[0] = back_node_;\n      for(int i = 1; i < MAX_SIZE_2;\
    \ ++i){\n        node *s = t->ancestors[i - 1];\n        if(s) t->ancestors[i]\
    \ = s->ancestors[i - 1];\n        else break;\n      }\n\n      t->depth = back_node_\
    \ ? back_node_->depth + 1 : 0;\n\n      return persistent_queue(front_node_ ?\
    \ front_node_ : t, t);\n    }\n\n    persistent_queue pop() const {\n      if(back_node_->depth\
    \ == front_node_->depth){\n        return persistent_queue(nullptr, nullptr);\n\
    \      }\n\n      int d = back_node_->depth - front_node_->depth - 1;\n\n    \
    \  node *t = back_node_;\n\n      for(int i = MAX_SIZE_2 - 1; i >= 0; --i){\n\
    \        if(d >= (1 << i)){\n          d -= (1 << i);\n          t = t->ancestors[i];\n\
    \        }\n        if(d == 0) break;\n      }\n\n      return persistent_queue(t,\
    \ back_node_);\n    }\n\n    T front() const {\n      return front_node_->value;\n\
    \    }\n\n    T back() const {\n      return back_node_->value;\n    }\n\n   \
    \ bool empty() const {\n      return not front_node_;\n    }\n\n    int size()\
    \ const {\n      return front_node_ ? back_node_->depth - front_node_->depth +\
    \ 1 : 0;\n    }\n\n    friend std::ostream& operator<<(std::ostream &s, const\
    \ persistent_queue &a){\n      s << \"{\";\n      std::vector<T> temp;\n     \
    \ node *t = a.back_node_;\n      while(t){\n        if(t == a.front_node_){\n\
    \          temp.push_back(t->value);\n          break;\n        }\n        temp.push_back(t->value);\n\
    \        t = t->ancestors[0];\n      }\n\n      for(auto it = temp.begin(); it\
    \ != temp.end(); ++it){\n        if(it != temp.begin()) s << \", \";\n       \
    \ s << *it;\n      }\n\n      s << \"}\";\n      return s;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <array>\n#include <iostream>\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  class persistent_queue {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    constexpr static int MAX_SIZE_2\
    \ = 20; // size <= 2 ^ MAX_SIZE_2\n\n    struct node {\n      T value;\n     \
    \ std::array<node*, MAX_SIZE_2> ancestors;\n      int depth = 0;\n    };\n\n \
    \   node *front_node_ = nullptr, *back_node_ = nullptr;\n\n    persistent_queue(node*\
    \ front_node, node* back_node):\n      front_node_(front_node), back_node_(back_node){}\n\
    \n  public:\n    persistent_queue(){}\n    persistent_queue(const T &value){\n\
    \      node *t = new node();\n      t->value = value;\n      back_node_ = front_node_\
    \ = t;\n    }\n\n    persistent_queue push(const T &value) const {\n      node\
    \ *t = new node();\n\n      t->value = value;\n\n      t->ancestors[0] = back_node_;\n\
    \      for(int i = 1; i < MAX_SIZE_2; ++i){\n        node *s = t->ancestors[i\
    \ - 1];\n        if(s) t->ancestors[i] = s->ancestors[i - 1];\n        else break;\n\
    \      }\n\n      t->depth = back_node_ ? back_node_->depth + 1 : 0;\n\n     \
    \ return persistent_queue(front_node_ ? front_node_ : t, t);\n    }\n\n    persistent_queue\
    \ pop() const {\n      if(back_node_->depth == front_node_->depth){\n        return\
    \ persistent_queue(nullptr, nullptr);\n      }\n\n      int d = back_node_->depth\
    \ - front_node_->depth - 1;\n\n      node *t = back_node_;\n\n      for(int i\
    \ = MAX_SIZE_2 - 1; i >= 0; --i){\n        if(d >= (1 << i)){\n          d -=\
    \ (1 << i);\n          t = t->ancestors[i];\n        }\n        if(d == 0) break;\n\
    \      }\n\n      return persistent_queue(t, back_node_);\n    }\n\n    T front()\
    \ const {\n      return front_node_->value;\n    }\n\n    T back() const {\n \
    \     return back_node_->value;\n    }\n\n    bool empty() const {\n      return\
    \ not front_node_;\n    }\n\n    int size() const {\n      return front_node_\
    \ ? back_node_->depth - front_node_->depth + 1 : 0;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_queue &a){\n      s << \"{\";\n\
    \      std::vector<T> temp;\n      node *t = a.back_node_;\n      while(t){\n\
    \        if(t == a.front_node_){\n          temp.push_back(t->value);\n      \
    \    break;\n        }\n        temp.push_back(t->value);\n        t = t->ancestors[0];\n\
    \      }\n\n      for(auto it = temp.begin(); it != temp.end(); ++it){\n     \
    \   if(it != temp.begin()) s << \", \";\n        s << *it;\n      }\n\n      s\
    \ << \"}\";\n      return s;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Queue/persistent_queue.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/persistent_queue/main.test.cpp
documentation_of: Mylib/DataStructure/Queue/persistent_queue.cpp
layout: document
title: Persistent queue
---

## Operations

- `push`
	- キューの末尾に値を追加したキューを返す。
	- Time complexity $O(\log N)$
- `pop`
	- キューの先頭を削除したキューを返す。
	- Time complexity $O(\log N)$
- `front`
	- キューの先頭を得る。
	- Time complexity $O(1)$
- `back`
	- キューの末尾を得る。
	- Time complexity $O(1)$
- `empty`
	- キューが空かどうかを判定する。
	- Time complexity $O(1)$
- `size()`
	- キューのサイズを得る。
	- Time complexity $O(1)$

## Requirements

## Notes

## Problems

## References

- [Persistent Queue](https://judge.yosupo.jp/problem/persistent_queue)
