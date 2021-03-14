---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp
    title: Chu-Liu/Edmonds algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B
  bundledCode: "#line 1 \"test/aoj/GRL_2_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp\"\
    \n#include <algorithm>\n#line 5 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> ret(n), low(n,\
    \ -1), ord(n, -1), S;\n    std::vector<bool> check(n);\n    S.reserve(n);\n  \
    \  int t = 0;\n    int k = 0;\n\n    auto dfs =\n      [&](auto &dfs, int cur)\
    \ -> void {\n        low[cur] = ord[cur] = t++;\n        S.push_back(cur);\n \
    \       check[cur] = true;\n\n        for(auto &e : g[cur]){\n          if(ord[e.to]\
    \ == -1){\n            dfs(dfs, e.to);\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }else if(check[e.to]){\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }\n        }\n\n        if(low[cur] == ord[cur]){\n \
    \         while(true){\n            int u = S.back(); S.pop_back();\n        \
    \    check[u] = false;\n            ret[u] = k;\n            if(cur == u) break;\n\
    \          }\n          ++k;\n        }\n      };\n\n    for(int i = 0; i < n;\
    \ ++i){\n      if(ord[i] == -1){\n        t = 0;\n        dfs(dfs, i);\n     \
    \ }\n    }\n\n    for(auto &x : ret) x = k - 1 - x;\n\n    return std::make_pair(ret,\
    \ k);\n  }\n}\n#line 6 \"Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp\"\
    \n\nnamespace haar_lib {\n  namespace chu_liu_edmonds_impl {\n    template <typename\
    \ T>\n    graph<T> rec(graph<T> g, int r){\n      const int N = g.size();\n\n\
    \      graph<T> in_edges(N);\n\n      for(int i = 0; i < N; ++i){\n        if(i\
    \ != r){\n          auto e = *std::min_element(\n            g[i].begin(), g[i].end(),\n\
    \            [](const auto &a, const auto &b){\n              return a.cost <\
    \ b.cost;\n            }\n          );\n\n          in_edges[i].push_back(e);\n\
    \        }\n      }\n\n      const auto [s, m] = strongly_connected_components(in_edges);\n\
    \n      std::vector<std::vector<int>> v(m);\n      for(int i = 0; i < N; ++i){\n\
    \        v[s[i]].push_back(i);\n      }\n\n      int count_cycle = 0;\n      for(int\
    \ i = 0; i < m; ++i){\n        if(v[i].size() > 1){\n          for(int j : v[i]){\n\
    \            auto c =\n              *std::min_element(\n                g[j].begin(),\
    \ g[j].end(),\n                [](const auto &a, const auto &b){return a.cost\
    \ < b.cost;}\n              );\n\n            for(auto &e : g[j]){\n         \
    \     e.cost -= c.cost;\n            }\n          }\n          ++count_cycle;\n\
    \        }\n      }\n\n      if(count_cycle == 0){\n        return in_edges;\n\
    \      }\n\n      graph<T> G(m);\n      const int R = s[r];\n      for(int i =\
    \ 0; i < N; ++i){\n        for(auto &e : g[i]){\n          if(s[e.from] == s[e.to])\
    \ continue;\n          G.add_edge(s[e.from], s[e.to], e.cost);\n        }\n  \
    \    }\n\n      auto res = rec(G, R);\n\n      for(int i = 0; i < m; ++i){\n \
    \       if(i == R) continue;\n\n        int j = res[i][0].to;\n\n        std::vector<edge<T>>\
    \ c;\n\n        for(int x : v[i]){\n          for(auto &e : g[x]){\n         \
    \   if(s[e.to] == j){\n              c.push_back(e);\n            }\n        \
    \  }\n        }\n\n        auto e =\n          *std::min_element(\n          \
    \  c.begin(), c.end(),\n            [](const auto &a, const auto &b){return a.cost\
    \ < b.cost;}\n          );\n\n        in_edges[e.from][0] = e;\n      }\n\n  \
    \    return in_edges;\n    }\n  }\n\n  template <typename T>\n  auto chu_liu_edmonds(graph<T>\
    \ g, int r){\n    std::vector<edge<T>> ret;\n\n    const int N = g.size();\n\n\
    \    graph<T> rg(N);\n    for(int i = 0; i < N; ++i){\n      for(auto &e : g[i]){\n\
    \        rg.add_edge(e.to, e.from, e.cost);\n      }\n    }\n\n    auto res =\
    \ chu_liu_edmonds_impl::rec(rg, r);\n\n    for(int i = 0; i < N; ++i){\n     \
    \ if(i != r){\n\n        std::vector<T> c;\n\n        for(auto &e : rg[i]){\n\
    \          if(e.to == res[i][0].to){\n            c.push_back(e.cost);\n     \
    \     }\n        }\n\n        ret.emplace_back(res[i][0].to, i, *std::min_element(c.begin(),\
    \ c.end()));\n      }\n    }\n\n    return ret;\n  }\n}\n#line 6 \"test/aoj/GRL_2_B/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int V, E, r; std::cin >> V >> E\
    \ >> r;\n\n  hl::graph<int> g(V);\n  g.read<0>(E);\n\n  auto res = hl::chu_liu_edmonds(g,\
    \ r);\n\n  int ans = 0;\n\n  for(auto &e : res){\n    ans += e.cost;\n  }\n\n\
    \  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int V, E, r; std::cin >> V >> E >> r;\n\n  hl::graph<int> g(V);\n\
    \  g.read<0>(E);\n\n  auto res = hl::chu_liu_edmonds(g, r);\n\n  int ans = 0;\n\
    \n  for(auto &e : res){\n    ans += e.cost;\n  }\n\n  std::cout << ans << \"\\\
    n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp
  - Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 06:13:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_B/main.test.cpp
- /verify/test/aoj/GRL_2_B/main.test.cpp.html
title: test/aoj/GRL_2_B/main.test.cpp
---
