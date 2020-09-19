---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/GraphUtils/bridges.cpp
    title: Bridges
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <utility>\n#line 2 \"\
    Mylib/Graph/Template/graph.cpp\"\n#include <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge(){}\n    edge(int from, int\
    \ to, T cost): from(from), to(to), cost(cost){}\n    edge(int from, int to, T\
    \ cost, int index): from(from), to(to), cost(cost), index(index){}\n  };\n\n \
    \ template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto&\
    \ operator[](size_t i){return data[i];}\n    const auto& operator[](size_t i)\
    \ const {return data[i];}\n\n    auto begin() const {return data.begin();}\n \
    \   auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/GraphUtils/bridges.cpp\"\
    \n\nnamespace haar_lib {\n  namespace bridges_impl {\n    template <typename T>\n\
    \    int dfs(\n      const graph<T> &graph,\n      int cur,\n      int par,\n\
    \      std::vector<int> &visit,\n      std::vector<int> &low,\n      std::vector<edge<T>>\
    \ &ret,\n      int &v\n    ){\n      if(visit[cur] != -1) return visit[cur];\n\
    \      visit[cur] = v;\n      int temp = v;\n      ++v;\n      for(auto &e : graph[cur]){\n\
    \        if(e.to == par) continue;\n        int t = dfs(graph, e.to, cur, visit,\
    \ low, ret, v);\n        temp = std::min(temp, t);\n        if(low[e.to] > visit[cur])\
    \ ret.push_back(e);\n      }\n      return low[cur] = temp;\n    }\n  }\n\n  template\
    \ <typename T>\n  auto bridges(const graph<T> &graph){\n    const int n = graph.size();\n\
    \    std::vector<int> visit(n, -1), low(n, -1);\n    std::vector<edge<T>> ret;\n\
    \    int v = 0;\n\n    for(int i = 0; i < n; ++i) if(visit[i] == -1) bridges_impl::dfs(graph,\
    \ i, -1, visit, low, ret, v);\n    return ret;\n  }\n}\n#line 8 \"test/aoj/GRL_3_B/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int V, E; std::cin >> V >> E;\n\
    \n  hl::graph<int> g(V);\n  g.read<0, false, false>(E);\n\n  auto ans = hl::bridges(g);\n\
    \  for(auto &e : ans) if(e.from > e.to) std::swap(e.from, e.to);\n\n  std::sort(\n\
    \    ans.begin(), ans.end(),\n    [](const auto &a, const auto &b){\n      if(a.from\
    \ != b.from) return a.from < b.from;\n      return a.to < b.to;\n    }\n  );\n\
    \n  for(auto &e :ans) std::cout << e.from << \" \" << e.to << std::endl;\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <utility>\n#include \"\
    Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/GraphUtils/bridges.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int V, E; std::cin >> V >> E;\n\
    \n  hl::graph<int> g(V);\n  g.read<0, false, false>(E);\n\n  auto ans = hl::bridges(g);\n\
    \  for(auto &e : ans) if(e.from > e.to) std::swap(e.from, e.to);\n\n  std::sort(\n\
    \    ans.begin(), ans.end(),\n    [](const auto &a, const auto &b){\n      if(a.from\
    \ != b.from) return a.from < b.from;\n      return a.to < b.to;\n    }\n  );\n\
    \n  for(auto &e :ans) std::cout << e.from << \" \" << e.to << std::endl;\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/bridges.cpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B/main.test.cpp
- /verify/test/aoj/GRL_3_B/main.test.cpp.html
title: test/aoj/GRL_3_B/main.test.cpp
---
