---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_A/main.push_relabel.test.cpp
    title: test/aoj/GRL_6_A/main.push_relabel.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Flow/push_relabel.cpp\"\n#include <vector>\n\
    #include <queue>\n#include <utility>\n#include <limits>\n\nnamespace haar_lib\
    \ {\n  namespace push_relabel_impl {\n    template <typename T>\n    struct edge\
    \ {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n      edge(int\
    \ from, int to, int rev, T cap, bool is_rev):\n        from(from), to(to), rev(rev),\
    \ cap(cap), is_rev(is_rev){}\n    };\n  }\n\n  template <typename T>\n  class\
    \ push_relabel {\n  public:\n    using edge = push_relabel_impl::edge<T>;\n  \
    \  using capacity_type = T;\n\n  private:\n    int N_;\n    std::vector<std::vector<edge>>\
    \ g_;\n    std::vector<T> excess_;\n    std::vector<int> height_;\n    std::queue<int>\
    \ next_active_vertex_;\n    constexpr static T inf = std::numeric_limits<T>::max();\n\
    \n    void init(int s, int t){\n      excess_[s] = inf;\n\n      for(auto &e :\
    \ g_[s]){\n        push(e, s, t);\n      }\n\n      {\n        for(int i = 0;\
    \ i < N_; ++i){\n          height_[i] = N_;\n        }\n\n        std::queue<int>\
    \ q;\n        std::vector<bool> check(N_);\n        q.push(t);\n        height_[t]\
    \ = 0;\n\n        while(not q.empty()){\n          const int i = q.front(); q.pop();\n\
    \n          if(check[i]) continue;\n          check[i] = true;\n\n          for(auto\
    \ &e : g_[i]){\n            if(not e.is_rev) continue;\n            if(height_[e.from]\
    \ + 1 < height_[e.to]){\n              height_[e.to] = height_[e.from] + 1;\n\
    \              q.push(e.to);\n            }\n          }\n        }\n\n      \
    \  height_[s] = N_;\n      }\n    }\n\n    bool is_pushable(const edge &e){\n\
    \      if(excess_[e.from] == 0) return false;\n      if(height_[e.from] != height_[e.to]\
    \ + 1) return false;\n      if(e.cap == 0) return false;\n      return true;\n\
    \    }\n\n    void push(edge &e, int, int){\n      auto &r = g_[e.to][e.rev];\n\
    \n      T flow = std::min(e.cap, excess_[e.from]);\n\n      e.cap -= flow;\n \
    \     r.cap += flow;\n\n      excess_[e.from] -= flow;\n      excess_[e.to] +=\
    \ flow;\n\n      if(excess_[e.to] == flow) next_active_vertex_.push(e.to);\n \
    \   }\n\n    void relabel(int i, int, int){\n      int a = std::numeric_limits<int>::max()\
    \ / 2;\n      for(auto &e : g_[i]){\n        if(e.cap > 0) a = std::min(a, height_[e.to]);\n\
    \      }\n\n      height_[i] = a + 1;\n    }\n\n  public:\n    push_relabel(){}\n\
    \    push_relabel(int N): N_(N), g_(N), excess_(N), height_(N){}\n\n    void add_edge(int\
    \ from, int to, T c){\n      g_[from].emplace_back(from, to, (int)g_[to].size(),\
    \ c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size() - 1, 0,\
    \ true);\n    }\n\n    T max_flow(int s, int t){\n      init(s, t);\n\n      while(true){\n\
    \        int index = -1;\n\n        while(not next_active_vertex_.empty()){\n\
    \          int i = next_active_vertex_.front();\n          if(i != s and i !=\
    \ t and excess_[i] > 0){\n            index = i;\n            break;\n       \
    \   }\n          next_active_vertex_.pop();\n        }\n\n        if(index ==\
    \ -1) break;\n\n        bool ok = false;\n        for(auto &e : g_[index]){\n\
    \          if(is_pushable(e)){\n            push(e, s, t);\n            ok = true;\n\
    \            break;\n          }\n        }\n\n        if(not ok){\n         \
    \ relabel(index, s, t);\n        }\n      }\n\n      return excess_[t];\n    }\n\
    \n    std::vector<edge> edges() const {\n      std::vector<edge> ret;\n      for(auto\
    \ &v : g_) ret.insert(ret.end(), v.begin(), v.end());\n      return ret;\n   \
    \ }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <utility>\n#include\
    \ <limits>\n\nnamespace haar_lib {\n  namespace push_relabel_impl {\n    template\
    \ <typename T>\n    struct edge {\n      int from, to, rev;\n      T cap;\n  \
    \    bool is_rev;\n      edge(int from, int to, int rev, T cap, bool is_rev):\n\
    \        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n    };\n  }\n\
    \n  template <typename T>\n  class push_relabel {\n  public:\n    using edge =\
    \ push_relabel_impl::edge<T>;\n    using capacity_type = T;\n\n  private:\n  \
    \  int N_;\n    std::vector<std::vector<edge>> g_;\n    std::vector<T> excess_;\n\
    \    std::vector<int> height_;\n    std::queue<int> next_active_vertex_;\n   \
    \ constexpr static T inf = std::numeric_limits<T>::max();\n\n    void init(int\
    \ s, int t){\n      excess_[s] = inf;\n\n      for(auto &e : g_[s]){\n       \
    \ push(e, s, t);\n      }\n\n      {\n        for(int i = 0; i < N_; ++i){\n \
    \         height_[i] = N_;\n        }\n\n        std::queue<int> q;\n        std::vector<bool>\
    \ check(N_);\n        q.push(t);\n        height_[t] = 0;\n\n        while(not\
    \ q.empty()){\n          const int i = q.front(); q.pop();\n\n          if(check[i])\
    \ continue;\n          check[i] = true;\n\n          for(auto &e : g_[i]){\n \
    \           if(not e.is_rev) continue;\n            if(height_[e.from] + 1 < height_[e.to]){\n\
    \              height_[e.to] = height_[e.from] + 1;\n              q.push(e.to);\n\
    \            }\n          }\n        }\n\n        height_[s] = N_;\n      }\n\
    \    }\n\n    bool is_pushable(const edge &e){\n      if(excess_[e.from] == 0)\
    \ return false;\n      if(height_[e.from] != height_[e.to] + 1) return false;\n\
    \      if(e.cap == 0) return false;\n      return true;\n    }\n\n    void push(edge\
    \ &e, int, int){\n      auto &r = g_[e.to][e.rev];\n\n      T flow = std::min(e.cap,\
    \ excess_[e.from]);\n\n      e.cap -= flow;\n      r.cap += flow;\n\n      excess_[e.from]\
    \ -= flow;\n      excess_[e.to] += flow;\n\n      if(excess_[e.to] == flow) next_active_vertex_.push(e.to);\n\
    \    }\n\n    void relabel(int i, int, int){\n      int a = std::numeric_limits<int>::max()\
    \ / 2;\n      for(auto &e : g_[i]){\n        if(e.cap > 0) a = std::min(a, height_[e.to]);\n\
    \      }\n\n      height_[i] = a + 1;\n    }\n\n  public:\n    push_relabel(){}\n\
    \    push_relabel(int N): N_(N), g_(N), excess_(N), height_(N){}\n\n    void add_edge(int\
    \ from, int to, T c){\n      g_[from].emplace_back(from, to, (int)g_[to].size(),\
    \ c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size() - 1, 0,\
    \ true);\n    }\n\n    T max_flow(int s, int t){\n      init(s, t);\n\n      while(true){\n\
    \        int index = -1;\n\n        while(not next_active_vertex_.empty()){\n\
    \          int i = next_active_vertex_.front();\n          if(i != s and i !=\
    \ t and excess_[i] > 0){\n            index = i;\n            break;\n       \
    \   }\n          next_active_vertex_.pop();\n        }\n\n        if(index ==\
    \ -1) break;\n\n        bool ok = false;\n        for(auto &e : g_[index]){\n\
    \          if(is_pushable(e)){\n            push(e, s, t);\n            ok = true;\n\
    \            break;\n          }\n        }\n\n        if(not ok){\n         \
    \ relabel(index, s, t);\n        }\n      }\n\n      return excess_[t];\n    }\n\
    \n    std::vector<edge> edges() const {\n      std::vector<edge> ret;\n      for(auto\
    \ &v : g_) ret.insert(ret.end(), v.begin(), v.end());\n      return ret;\n   \
    \ }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Flow/push_relabel.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_A/main.push_relabel.test.cpp
documentation_of: Mylib/Graph/Flow/push_relabel.cpp
layout: document
title: Push-relabel
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Push%E2%80%93relabel_maximum_flow_algorithm](https://en.wikipedia.org/wiki/Push%E2%80%93relabel_maximum_flow_algorithm)
- [https://qiita.com/a-lilas/items/3bf338c7929f6951fa41](https://qiita.com/a-lilas/items/3bf338c7929f6951fa41)
- [https://qiita.com/nariaki3551/items/65baee3c6ef0a6ffa136](https://qiita.com/nariaki3551/items/65baee3c6ef0a6ffa136)
