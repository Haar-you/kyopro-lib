---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/ShortestPath/warshall_floyd.cpp
    title: Warshall-Floyd algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/ShortestPath/warshall_floyd.cpp\"\
    \n#include <optional>\n#include <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 5 \"\
    Mylib/Graph/ShortestPath/warshall_floyd.cpp\"\n\nnamespace haar_lib {\n  namespace\
    \ warshall_floyd_impl {\n    template <typename T>\n    struct result {\n    \
    \  std::vector<std::vector<std::optional<T>>> dist;\n      bool has_negative_cycle;\n\
    \      const auto &operator[](int i) const { return dist[i]; }\n    };\n  }  //\
    \ namespace warshall_floyd_impl\n\n  template <typename T>\n  auto warshall_floyd(const\
    \ graph<T> &g) {\n    const int n = g.size();\n    auto dist   = std::vector(n,\
    \ std::vector<std::optional<T>>(n));\n\n    for (int i = 0; i < n; ++i) dist[i][i]\
    \ = 0;\n\n    for (int i = 0; i < n; ++i) {\n      for (auto &e : g[i]) {\n  \
    \      dist[e.from][e.to] = e.cost;\n      }\n    }\n\n    for (int k = 0; k <\
    \ n; ++k) {\n      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j <\
    \ n; ++j) {\n          if (dist[i][k] and dist[k][j]) {\n            if (not dist[i][j])\
    \ {\n              dist[i][j] = *dist[i][k] + *dist[k][j];\n            } else\
    \ {\n              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);\n\
    \            }\n          }\n        }\n      }\n    }\n\n    bool has_negative_cycle\
    \ = false;\n    for (int i = 0; i < n; ++i)\n      if (*dist[i][i] < 0) has_negative_cycle\
    \ = true;\n\n    return warshall_floyd_impl::result<T>{dist, has_negative_cycle};\n\
    \  }\n}  // namespace haar_lib\n#line 6 \"test/aoj/GRL_1_C/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main() {\n  int V, E;\n  std::cin >> V >> E;\n\
    \n  hl::graph<int> g(V);\n  g.read<0>(E);\n\n  auto res = hl::warshall_floyd(g);\n\
    \n  if (res.has_negative_cycle) {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n\
    \  } else {\n    for (int i = 0; i < V; ++i) {\n      for (int j = 0; j < V; ++j)\
    \ {\n        if (j) std::cout << \" \";\n        auto &ans = res[i][j];\n    \
    \    if (ans) {\n          std::cout << *ans;\n        } else {\n          std::cout\
    \ << \"INF\";\n        }\n      }\n      std::cout << std::endl;\n    }\n  }\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/ShortestPath/warshall_floyd.cpp\"\
    \n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main() {\n  int V, E;\n  std::cin >> V >> E;\n\n  hl::graph<int> g(V);\n \
    \ g.read<0>(E);\n\n  auto res = hl::warshall_floyd(g);\n\n  if (res.has_negative_cycle)\
    \ {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n  } else {\n    for (int\
    \ i = 0; i < V; ++i) {\n      for (int j = 0; j < V; ++j) {\n        if (j) std::cout\
    \ << \" \";\n        auto &ans = res[i][j];\n        if (ans) {\n          std::cout\
    \ << *ans;\n        } else {\n          std::cout << \"INF\";\n        }\n   \
    \   }\n      std::cout << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/ShortestPath/warshall_floyd.cpp
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C/main.test.cpp
- /verify/test/aoj/GRL_1_C/main.test.cpp.html
title: test/aoj/GRL_1_C/main.test.cpp
---