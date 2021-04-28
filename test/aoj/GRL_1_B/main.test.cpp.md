---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/ShortestPath/bellman_ford.cpp
    title: Bellman-Ford algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Math/unbounded.cpp
    title: Number with infinity
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/ShortestPath/bellman_ford.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from, int to,\
    \ T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\
    \n  template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n  \
    \  auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
    \ i) const { return data[i]; }\n\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n\n    graph() {}\n    graph(int\
    \ N) : data(N) {}\n\n    bool empty() const { return data.empty(); }\n    int\
    \ size() const { return data.size(); }\n\n    void add_edge(int i, int j, T w,\
    \ int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n    }\n\n  \
    \  void add_undirected(int i, int j, T w, int index = -1) {\n      add_edge(i,\
    \ j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template <size_t\
    \ I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M) {\n   \
    \   for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 3 \"\
    Mylib/Math/unbounded.cpp\"\n\ntemplate <typename T>\nstruct unbounded {\nprivate:\n\
    \  enum class tag_t { POSITIVE_INFINITY,\n                     NEGATIVE_INFINITY,\n\
    \                     FINITE } tag_;\n  T value_;\n\n  unbounded(tag_t tag_) :\
    \ tag_(tag_) {}\n\npublic:\n  using value_type = T;\n\n  unbounded() : tag_(tag_t::FINITE),\
    \ value_(T()) {}\n  unbounded(T value_) : tag_(tag_t::FINITE), value_(value_)\
    \ {}\n  unbounded(const unbounded<T>& that) : tag_(that.tag_), value_(that.value_)\
    \ {}\n\n  bool is_positive_inf() const { return tag_ == tag_t::POSITIVE_INFINITY;\
    \ }\n  bool is_negative_inf() const { return tag_ == tag_t::NEGATIVE_INFINITY;\
    \ }\n  bool is_finite() const { return tag_ == tag_t::FINITE; }\n\n  T value()\
    \ const { return value_; }\n  T& value() { return value_; }\n\n  static auto positive_inf()\
    \ {\n    return unbounded(tag_t::POSITIVE_INFINITY);\n  }\n\n  static auto negative_inf()\
    \ {\n    return unbounded(tag_t::NEGATIVE_INFINITY);\n  }\n\n  friend std::ostream&\
    \ operator<<(std::ostream& s, const unbounded& a) {\n    switch (a.tag_) {\n \
    \     case tag_t::POSITIVE_INFINITY: s << \"\u221E\"; break;\n      case tag_t::NEGATIVE_INFINITY:\
    \ s << \"-\u221E\"; break;\n      case tag_t::FINITE: s << a.value_;\n    }\n\
    \    return s;\n  }\n\n  unbounded operator-() const {\n    if (is_finite())\n\
    \      return -value_;\n    else if (is_positive_inf())\n      return unbounded::negative_inf();\n\
    \    return unbounded::positive_inf();\n  }\n\n  auto& operator+=(unbounded that)\
    \ {\n    if (is_finite()) {\n      if (that.is_finite())\n        value_ += that.value_;\n\
    \      else\n        tag_ = that.tag_;\n    }\n    return *this;\n  }\n\n  auto\
    \ operator+(unbounded that) const {\n    return unbounded(*this) += that;\n  }\n\
    \n  auto& operator-=(unbounded that) {\n    return (*this) += (-that);\n  }\n\n\
    \  auto operator-(unbounded that) const {\n    return unbounded(*this) -= that;\n\
    \  }\n\n  int compare(unbounded that) const {\n    if (is_positive_inf()) {\n\
    \      if (that.is_positive_inf())\n        return 0;\n      else\n        return\
    \ 1;\n    } else if (is_negative_inf()) {\n      if (that.is_negative_inf())\n\
    \        return 0;\n      else\n        return -1;\n    } else {\n      if (that.is_positive_inf())\n\
    \        return -1;\n      else if (that.is_negative_inf())\n        return 1;\n\
    \      else\n        return (value_ > that.value_) - (value_ < that.value_);\n\
    \    }\n  }\n\n  bool operator==(unbounded that) const { return compare(that)\
    \ == 0; }\n  bool operator!=(unbounded that) const { return compare(that) != 0;\
    \ }\n  bool operator<(unbounded that) const { return compare(that) < 0; }\n  bool\
    \ operator<=(unbounded that) const { return compare(that) <= 0; }\n  bool operator>(unbounded\
    \ that) const { return compare(that) > 0; }\n  bool operator>=(unbounded that)\
    \ const { return compare(that) >= 0; }\n};\n#line 7 \"Mylib/Graph/ShortestPath/bellman_ford.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto bellman_ford(const graph<T>\
    \ &g, int src) {\n    using type = unbounded<T>;\n\n    const int n = g.size();\n\
    \    std::vector<type> dist(n, type::positive_inf());\n\n    dist[src] = 0;\n\n\
    \    for (int i = 0; i < n; ++i) {\n      for (int s = 0; s < n; ++s) {\n    \
    \    for (auto &e : g[s]) {\n          int t = e.to;\n          T d   = e.cost;\n\
    \n          if (dist[s].is_finite() and\n              dist[t].is_finite() and\n\
    \              dist[s].value() + d < dist[t].value() and i == n - 1) {\n     \
    \       dist[t] = type::negative_inf();\n          } else {\n            if (dist[s].is_finite())\
    \ {\n              if (dist[t].is_positive_inf()) {\n                dist[t] =\
    \ dist[s].value() + d;\n              } else if (dist[t].is_finite()) {\n    \
    \            dist[t] = std::min(dist[t].value(), dist[s].value() + d);\n     \
    \         }\n            }\n          }\n        }\n      }\n    }\n\n    for\
    \ (int i = 0; i < n; ++i) {\n      for (int s = 0; s < n; ++s) {\n        for\
    \ (auto &e : g[s]) {\n          if (dist[s].is_negative_inf()) {\n           \
    \ dist[e.to] = type::negative_inf();\n          }\n        }\n      }\n    }\n\
    \n    return dist;\n  }\n}  // namespace haar_lib\n#line 6 \"test/aoj/GRL_1_B/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int V, E, r;\n  std::cin >> V >> E >> r;\n\n  hl::graph<int64_t> g(V);\n \
    \ g.read<0>(E);\n\n  auto res = hl::bellman_ford(g, r);\n\n  bool neg_cycle =\
    \ std::any_of(res.begin(), res.end(), [](const auto &a) { return a.is_negative_inf();\
    \ });\n\n  if (neg_cycle) {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n\
    \  } else {\n    for (auto &x : res) {\n      if (x.is_positive_inf()) {\n   \
    \     std::cout << \"INF\" << std::endl;\n      } else {\n        std::cout <<\
    \ x.value() << std::endl;\n      }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/ShortestPath/bellman_ford.cpp\"\
    \n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ V, E, r;\n  std::cin >> V >> E >> r;\n\n  hl::graph<int64_t> g(V);\n  g.read<0>(E);\n\
    \n  auto res = hl::bellman_ford(g, r);\n\n  bool neg_cycle = std::any_of(res.begin(),\
    \ res.end(), [](const auto &a) { return a.is_negative_inf(); });\n\n  if (neg_cycle)\
    \ {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n  } else {\n    for (auto\
    \ &x : res) {\n      if (x.is_positive_inf()) {\n        std::cout << \"INF\"\
    \ << std::endl;\n      } else {\n        std::cout << x.value() << std::endl;\n\
    \      }\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/ShortestPath/bellman_ford.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Math/unbounded.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B/main.test.cpp
- /verify/test/aoj/GRL_1_B/main.test.cpp.html
title: test/aoj/GRL_1_B/main.test.cpp
---
