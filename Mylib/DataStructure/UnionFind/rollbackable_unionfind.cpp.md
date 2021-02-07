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
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/rollbackable_unionfind.cpp\"\
    \n#include <vector>\n#include <utility>\n\nnamespace haar_lib {\n  class rollbackable_unionfind\
    \ {\n    int n_;\n    std::vector<int> parent_, size_;\n    std::vector<std::pair<int,\
    \ int>> history_;\n\n  public:\n    rollbackable_unionfind(){}\n    rollbackable_unionfind(int\
    \ n): n_(n), parent_(n, -1), size_(n, 1){}\n\n    int root_of(int i) const {\n\
    \      if(parent_[i] == -1) return i;\n      return root_of(parent_[i]);\n   \
    \ }\n\n    bool is_same(int i, int j) const {\n      return root_of(i) == root_of(j);\n\
    \    }\n\n    int merge(int i, int j){\n      const int ri = root_of(i), rj =\
    \ root_of(j);\n\n      history_.emplace_back(ri, size_[i]);\n      history_.emplace_back(rj,\
    \ size_[rj]);\n\n      if(ri == rj) return ri;\n\n      if(size_[ri] < size_[rj]){\n\
    \        parent_[ri] = rj;\n        size_[rj] += size_[ri];\n        return rj;\n\
    \      }else{\n        parent_[rj] = ri;\n        size_[ri] += size_[rj];\n  \
    \      return ri;\n      }\n    }\n\n    void roll_back(){\n      for(int k =\
    \ 0; k < 2; ++k){\n        auto [i, s] = history_.back();\n        parent_[i]\
    \ = -1;\n        size_[i] = s;\n        history_.pop_back();\n      }\n    }\n\
    \n    bool rollbackable() const {\n      return not history_.empty();\n    }\n\
    \n    int size_of(int i) const {\n      return size_[root_of(i)];\n    }\n\n \
    \   void set_base(){\n      history_.clear();\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  class rollbackable_unionfind {\n    int n_;\n    std::vector<int> parent_,\
    \ size_;\n    std::vector<std::pair<int, int>> history_;\n\n  public:\n    rollbackable_unionfind(){}\n\
    \    rollbackable_unionfind(int n): n_(n), parent_(n, -1), size_(n, 1){}\n\n \
    \   int root_of(int i) const {\n      if(parent_[i] == -1) return i;\n      return\
    \ root_of(parent_[i]);\n    }\n\n    bool is_same(int i, int j) const {\n    \
    \  return root_of(i) == root_of(j);\n    }\n\n    int merge(int i, int j){\n \
    \     const int ri = root_of(i), rj = root_of(j);\n\n      history_.emplace_back(ri,\
    \ size_[i]);\n      history_.emplace_back(rj, size_[rj]);\n\n      if(ri == rj)\
    \ return ri;\n\n      if(size_[ri] < size_[rj]){\n        parent_[ri] = rj;\n\
    \        size_[rj] += size_[ri];\n        return rj;\n      }else{\n        parent_[rj]\
    \ = ri;\n        size_[ri] += size_[rj];\n        return ri;\n      }\n    }\n\
    \n    void roll_back(){\n      for(int k = 0; k < 2; ++k){\n        auto [i, s]\
    \ = history_.back();\n        parent_[i] = -1;\n        size_[i] = s;\n      \
    \  history_.pop_back();\n      }\n    }\n\n    bool rollbackable() const {\n \
    \     return not history_.empty();\n    }\n\n    int size_of(int i) const {\n\
    \      return size_[root_of(i)];\n    }\n\n    void set_base(){\n      history_.clear();\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/rollbackable_unionfind.cpp
  requiredBy: []
  timestamp: '2020-11-06 05:05:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/UnionFind/rollbackable_unionfind.cpp
layout: document
title: Rollbackable union-find
---

## Operations

## Requirements

## Notes

## Problems

- [C. Team-Building](https://codeforces.com/contest/1444/problem/C)

## References
