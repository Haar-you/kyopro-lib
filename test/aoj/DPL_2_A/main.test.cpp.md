---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/travelling_salesman_problem.cpp
    title: Travelling salesman problem
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"test/aoj/DPL_2_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#include <iostream>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n\
    \    int from, to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int\
    \ from, int to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from,\
    \ int to, T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n\
    \  };\n\n  template <typename T>\n  struct graph {\n    using weight_type = T;\n\
    \    using edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\
    \n    auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
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
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 2 \"\
    Mylib/Graph/travelling_salesman_problem.cpp\"\n#include <algorithm>\n#include\
    \ <optional>\n#line 6 \"Mylib/Graph/travelling_salesman_problem.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::optional<T> travelling_salesman_problem(const\
    \ graph<T> &g, int src) {\n    const int n = g.size();\n\n    std::vector<std::vector<std::optional<T>>>\
    \ dp(n, std::vector<std::optional<T>>(1 << n));\n\n    for (auto &e : g[src])\
    \ {\n      if (not dp[e.to][1 << e.to]) {\n        dp[e.to][1 << e.to] = e.cost;\n\
    \      } else {\n        dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to],\
    \ e.cost);\n      }\n    }\n\n    for (int s = 1; s < (1 << n); ++s) {\n     \
    \ for (int i = 0; i < n; ++i) {\n        if (not(s & (1 << i))) continue;\n\n\
    \        for (auto &e : g[i]) {\n          if (s & (1 << e.to)) continue;\n\n\
    \          if (dp[i][s]) {\n            if (not dp[e.to][s | (1 << e.to)]) {\n\
    \              dp[e.to][s | (1 << e.to)] = *dp[i][s] + e.cost;\n            }\
    \ else {\n              dp[e.to][s | (1 << e.to)] = std::min(*dp[e.to][s | (1\
    \ << e.to)], *dp[i][s] + e.cost);\n            }\n          }\n        }\n   \
    \   }\n    }\n\n    return dp[src][(1 << n) - 1];\n  }\n}  // namespace haar_lib\n\
    #line 6 \"test/aoj/DPL_2_A/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main() {\n  int V, E;\n  std::cin >> V >> E;\n\n  hl::graph<int> g(V);\n  g.read<0>(E);\n\
    \n  std::cout << hl::travelling_salesman_problem(g, 0).value_or(-1) << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/travelling_salesman_problem.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int V, E;\n  std::cin >> V >> E;\n\n  hl::graph<int> g(V);\n\
    \  g.read<0>(E);\n\n  std::cout << hl::travelling_salesman_problem(g, 0).value_or(-1)\
    \ << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/travelling_salesman_problem.cpp
  isVerificationFile: true
  path: test/aoj/DPL_2_A/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_2_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_2_A/main.test.cpp
- /verify/test/aoj/DPL_2_A/main.test.cpp.html
title: test/aoj/DPL_2_A/main.test.cpp
---
