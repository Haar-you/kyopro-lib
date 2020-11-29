---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/ShortestPath/spfa.cpp
    title: SPFA
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B/main.spfa.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#include\
    \ <iostream>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <vector>\n\
    #line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n    int index\
    \ = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from), to(to),\
    \ cost(cost){}\n    edge(int from, int to, T cost, int index): from(from), to(to),\
    \ cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct graph\
    \ {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/ShortestPath/spfa.cpp\"\
    \n#include <optional>\n#include <queue>\n#line 6 \"Mylib/Graph/ShortestPath/spfa.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<std::optional<T>>>\
    \ spfa(const graph<T> &g, int src){\n    const int N = g.size();\n\n    std::vector<std::optional<T>>\
    \ dist(N);\n    std::vector<bool> check(N);\n    std::vector<int> count(N);\n\
    \    std::queue<int> q;\n\n    q.push(src);\n    dist[src] = 0;\n    check[src]\
    \ = true;\n    count[src] = 1;\n\n    while(not q.empty()){\n      auto cur =\
    \ q.front(); q.pop();\n      check[cur] = false;\n\n      for(auto &e : g[cur]){\n\
    \        if(not dist[e.to] or dist[cur].value() + e.cost < dist[e.to].value()){\n\
    \          dist[e.to] = dist[cur].value() + e.cost;\n          if(not check[e.to]){\n\
    \            count[e.to] += 1;\n            if(count[e.to] >= N) return std::nullopt;\n\
    \            q.push(e.to);\n          }\n        }\n      }\n    }\n\n    return\
    \ dist;\n  };\n}\n#line 6 \"test/aoj/GRL_1_B/main.spfa.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int V, E, r; std::cin >> V >> E >> r;\n\n  hl::graph<int64_t> g(V);\n  g.read<0>(E);\n\
    \n  auto res = hl::spfa(g, r);\n\n  if(res){\n    for(auto &x : res.value()){\n\
    \      if(x) std::cout << x.value() << \"\\n\";\n      else std::cout << \"INF\\\
    n\";\n    }\n  }else{\n    std::cout << \"NEGATIVE CYCLE\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/ShortestPath/spfa.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int V, E, r; std::cin\
    \ >> V >> E >> r;\n\n  hl::graph<int64_t> g(V);\n  g.read<0>(E);\n\n  auto res\
    \ = hl::spfa(g, r);\n\n  if(res){\n    for(auto &x : res.value()){\n      if(x)\
    \ std::cout << x.value() << \"\\n\";\n      else std::cout << \"INF\\n\";\n  \
    \  }\n  }else{\n    std::cout << \"NEGATIVE CYCLE\\n\";\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/ShortestPath/spfa.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B/main.spfa.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 20:16:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B/main.spfa.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B/main.spfa.test.cpp
- /verify/test/aoj/GRL_1_B/main.spfa.test.cpp.html
title: test/aoj/GRL_1_B/main.spfa.test.cpp
---
