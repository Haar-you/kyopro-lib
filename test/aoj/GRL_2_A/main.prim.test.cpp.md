---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/Graph/MinimumSpanningTree/prim.cpp
    title: Prim algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A/main.prim.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#include\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\
    \n#include <queue>\n#line 5 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<edge<T>> prim(const graph<T>\
    \ &graph){\n    const int n = graph.size();\n    std::vector<bool> visit(n, false);\n\
    \    std::vector<edge<T>> ret;\n\n    auto cmp = [](const auto &a, const auto\
    \ &b){return a.cost > b.cost;};\n    std::priority_queue<edge<T>, std::vector<edge<T>>,\
    \ decltype(cmp)> pq(cmp);\n\n    visit[0] = true;\n    for(auto &e : graph[0])\
    \ pq.push(e);\n\n    while(not pq.empty()){\n      auto t = pq.top(); pq.pop();\n\
    \n      if(visit[t.from] == visit[t.to]) continue;\n\n      int i = visit[t.from]\
    \ ? t.to : t.from;\n      for(auto &e : graph[i]){\n        pq.push(e);\n    \
    \  }\n\n      visit[i] = true;\n      ret.push_back(t);\n    }\n\n    return ret;\n\
    \  }\n}\n#line 6 \"test/aoj/GRL_2_A/main.prim.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int V, E; std::cin >> V >> E;\n\n  hl::graph<int64_t> g(V);\n\
    \  g.read<0, false>(E);\n\n  auto res = hl::prim(g);\n\n  int64_t ans = 0;\n \
    \ for(auto &e : res) ans += e.cost;\n  std::cout << ans << std::endl;\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int V, E; std::cin >> V >> E;\n\n  hl::graph<int64_t> g(V);\n \
    \ g.read<0, false>(E);\n\n  auto res = hl::prim(g);\n\n  int64_t ans = 0;\n  for(auto\
    \ &e : res) ans += e.cost;\n  std::cout << ans << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/MinimumSpanningTree/prim.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A/main.prim.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A/main.prim.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A/main.prim.test.cpp
- /verify/test/aoj/GRL_2_A/main.prim.test.cpp.html
title: test/aoj/GRL_2_A/main.prim.test.cpp
---
