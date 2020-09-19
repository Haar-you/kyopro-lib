---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':x:'
    path: Mylib/Graph/TopologicalSort/topological_sort.cpp
    title: Topological sort
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: Mylib/IO/join.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo-judge/scc/main.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n#include <vector>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include <algorithm>\n#line 5 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<bool> visit(n);\n\
    \    std::vector<int> check(n);\n    std::vector<int> result(n, -1);\n\n    auto\
    \ dfs =\n      [&](auto &f, int cur) -> void {\n        visit[cur] = true;\n \
    \       for(const auto &e : g[cur]){\n          if(not visit[e.to]) f(f, e.to);\n\
    \        }\n        check.push_back(cur);\n      };\n\n    for(int i = 0; i <\
    \ n; ++i) if(not visit[i]) dfs(dfs, i);\n\n    std::reverse(check.begin(), check.end());\n\
    \n    graph<T> rg(n);\n\n    auto rdfs =\n      [&](auto &f, int cur, int i) ->\
    \ void {\n        result[cur] = i;\n        for(const auto &e : rg[cur]){\n  \
    \        if(result[e.to] == -1) f(f, e.to, i);\n        }\n      };\n\n    for(int\
    \ i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from,\
    \ e.cost);\n\n    int i = 0;\n    for(auto c : check) if(result[c] == -1) rdfs(rdfs,\
    \ c, i), ++i;\n\n    return std::make_pair(result, i);\n  }\n}\n#line 3 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n#include <optional>\n#include <queue>\n#line 6 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ topological_sort(const graph<T> &g){\n    const int n = g.size();\n    std::vector<int>\
    \ indeg(n);\n\n    for(int i = 0; i < n; ++i){\n      for(auto &e : g[i]){\n \
    \       ++indeg[e.to];\n      }\n    }\n\n    std::queue<int> q;\n    for(int\
    \ i = 0; i < n; ++i){\n      if(indeg[i] == 0) q.push(i);\n    }\n\n    std::vector<int>\
    \ ret;\n    while(not q.empty()){\n      int cur = q.front(); q.pop();\n     \
    \ ret.push_back(cur);\n      for(auto &e : g[cur]){\n        --indeg[e.to];\n\
    \        if(indeg[e.to] == 0){\n          q.push(e.to);\n        }\n      }\n\
    \    }\n\n    if((int)ret.size() == n){\n      return {ret};\n    }else{\n   \
    \   return std::nullopt;\n    }\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include\
    \ <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n\
    \  std::string join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 9 \"test/yosupo-judge/scc/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n\n  hl::graph<int> g(N);\n  g.read<0, true,\
    \ false>(M);\n\n  auto [scc, K] = hl::strongly_connected_components(g);\n  std::vector<std::vector<int>>\
    \ ans(K);\n  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);\n\n  hl::graph<int>\
    \ g2(K);\n  for(auto &v : g){\n    for(auto &e : v){\n      if(scc[e.from] !=\
    \ scc[e.to]) g2.add_edge(scc[e.from], scc[e.to], 1);\n    }\n  }\n\n  auto ts\
    \ = hl::topological_sort(g2).value();\n\n  std::cout << K << \"\\n\";\n\n  for(auto\
    \ i : ts){\n    auto &t = ans[i];\n    std::cout << t.size() << \" \" << hl::join(t.begin(),\
    \ t.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n\n  hl::graph<int> g(N);\n  g.read<0, true,\
    \ false>(M);\n\n  auto [scc, K] = hl::strongly_connected_components(g);\n  std::vector<std::vector<int>>\
    \ ans(K);\n  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);\n\n  hl::graph<int>\
    \ g2(K);\n  for(auto &v : g){\n    for(auto &e : v){\n      if(scc[e.from] !=\
    \ scc[e.to]) g2.add_edge(scc[e.from], scc[e.to], 1);\n    }\n  }\n\n  auto ts\
    \ = hl::topological_sort(g2).value();\n\n  std::cout << K << \"\\n\";\n\n  for(auto\
    \ i : ts){\n    auto &t = ans[i];\n    std::cout << t.size() << \" \" << hl::join(t.begin(),\
    \ t.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  - Mylib/Graph/TopologicalSort/topological_sort.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/scc/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/scc/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/scc/main.test.cpp
- /verify/test/yosupo-judge/scc/main.test.cpp.html
title: test/yosupo-judge/scc/main.test.cpp
---
