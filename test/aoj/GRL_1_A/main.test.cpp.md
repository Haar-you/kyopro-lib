---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/ShortestPath/dijkstra.cpp
    title: Dijkstra algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj/GRL_1_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n  \
    \  int index = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from),\
    \ to(to), cost(cost){}\n    edge(int from, int to, T cost, int index): from(from),\
    \ to(to), cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct\
    \ graph {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
    \ i) const {return data[i];}\n\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\
    \n#include <optional>\n#include <queue>\n#include <utility>\n#include <functional>\n\
    #line 8 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  auto dijkstra(const graph<T> &graph, std::vector<int> src){\n\
    \    using P = std::pair<T, int>;\n\n    const int n = graph.size();\n    std::vector<std::optional<T>>\
    \ dist(n);\n\n    std::vector<bool> check(n, false);\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n\n    for(auto s : src){\n      dist[s]\
    \ = 0;\n      pq.emplace(0, s);\n    }\n\n    while(not pq.empty()){\n      const\
    \ auto [d, i] = pq.top(); pq.pop();\n\n      if(check[i]) continue;\n      check[i]\
    \ = true;\n\n      for(auto &e : graph[i]){\n        if(not dist[e.to]){\n   \
    \       dist[e.to] = d + e.cost;\n          pq.emplace(*dist[e.to], e.to);\n \
    \       }else{\n          if(*dist[e.to] > d + e.cost){\n            dist[e.to]\
    \ = d + e.cost;\n            if(not check[e.to]) pq.emplace(*dist[e.to], e.to);\n\
    \          }\n        }\n      }\n    }\n\n    return dist;\n  }\n}\n#line 6 \"\
    test/aoj/GRL_1_A/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int V, E, r; std::cin\
    \ >> V >> E >> r;\n\n  hl::graph<int64_t> g(V);\n  g.read<0>(E);\n\n  auto res\
    \ = hl::dijkstra(g, {r});\n\n  for(auto x : res){\n    if(not x){\n      std::cout\
    \ << \"INF\" << std::endl;\n    }else{\n      std::cout << *x << std::endl;\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int V,\
    \ E, r; std::cin >> V >> E >> r;\n\n  hl::graph<int64_t> g(V);\n  g.read<0>(E);\n\
    \n  auto res = hl::dijkstra(g, {r});\n\n  for(auto x : res){\n    if(not x){\n\
    \      std::cout << \"INF\" << std::endl;\n    }else{\n      std::cout << *x <<\
    \ std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/ShortestPath/dijkstra.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A/main.test.cpp
- /verify/test/aoj/GRL_1_A/main.test.cpp.html
title: test/aoj/GRL_1_A/main.test.cpp
---
