---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ k);\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 8 \"test/yosupo-judge/scc/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n\n  hl::graph<int> g(N);\n  g.read<0, true,\
    \ false>(M);\n\n  auto [scc, K] = hl::strongly_connected_components(g);\n  std::vector<std::vector<int>>\
    \ ans(K);\n  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);\n\n  std::cout\
    \ << K << \"\\n\";\n\n  for(auto &t : ans){\n    std::cout << t.size() << \" \"\
    \ << hl::join(t.begin(), t.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M; std::cin\
    \ >> N >> M;\n\n  hl::graph<int> g(N);\n  g.read<0, true, false>(M);\n\n  auto\
    \ [scc, K] = hl::strongly_connected_components(g);\n  std::vector<std::vector<int>>\
    \ ans(K);\n  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);\n\n  std::cout\
    \ << K << \"\\n\";\n\n  for(auto &t : ans){\n    std::cout << t.size() << \" \"\
    \ << hl::join(t.begin(), t.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/scc/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 06:13:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/scc/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/scc/main.test.cpp
- /verify/test/yosupo-judge/scc/main.test.cpp.html
title: test/yosupo-judge/scc/main.test.cpp
---
