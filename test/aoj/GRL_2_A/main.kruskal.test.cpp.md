---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
    title: Kruskal algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A/main.kruskal.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#include\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 2 \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\
    \n#include <algorithm>\n#line 3 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include <numeric>\n#line 5 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n\
    \nnamespace haar_lib {\n  class unionfind {\n    int n_, count_;\n    mutable\
    \ std::vector<int> parent_;\n    std::vector<int> depth_, size_;\n\n  public:\n\
    \    unionfind(){}\n    unionfind(int n): n_(n), count_(n), parent_(n), depth_(n,\
    \ 1), size_(n, 1){\n      std::iota(parent_.begin(), parent_.end(), 0);\n    }\n\
    \n    int root_of(int i) const {\n      if(parent_[i] == i) return i;\n      else\
    \ return parent_[i] = root_of(parent_[i]);\n    }\n\n    bool is_same(int i, int\
    \ j) const {return root_of(i) == root_of(j);}\n\n    int merge(int i, int j){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        --count_;\n        if(depth_[ri] < depth_[rj]){\n\
    \          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n          return\
    \ rj;\n        }else{\n          parent_[rj] = ri;\n          size_[ri] += size_[rj];\n\
    \          if(depth_[ri] == depth_[rj]) ++depth_[ri];\n          return ri;\n\
    \        }\n      }\n    }\n\n    int size_of(int i) const {return size_[root_of(i)];}\n\
    \n    int count_groups() const {return count_;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n_);\n\n      for(int i = 0; i <\
    \ n_; ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n#line 6 \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<edge<T>> kruskal(const\
    \ graph<T> &graph){\n    const int n = graph.size();\n    std::vector<edge<T>>\
    \ edges;\n    for(auto &v : graph){\n      for(auto &e : v){\n        edges.push_back(e);\n\
    \      }\n    }\n\n    std::sort(\n      edges.begin(), edges.end(),\n      [](const\
    \ auto &a, const auto &b){return a.cost < b.cost;}\n    );\n\n    unionfind uf(n);\n\
    \n    std::vector<edge<T>> ret;\n\n    for(auto &e : edges){\n      if(not uf.is_same(e.from,\
    \ e.to)){\n        uf.merge(e.from, e.to);\n        ret.push_back(e);\n      }\n\
    \    }\n\n    return ret;\n  }\n}\n#line 6 \"test/aoj/GRL_2_A/main.kruskal.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int V, E; std::cin >> V >> E;\n\
    \n  hl::graph<int64_t> g(V);\n  g.read<0, false>(E);\n\n  auto res = hl::kruskal(g);\n\
    \n  int64_t ans = 0;\n  for(auto &e : res) ans += e.cost;\n  std::cout << ans\
    \ << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int V, E; std::cin >> V >> E;\n\n  hl::graph<int64_t> g(V);\n\
    \  g.read<0, false>(E);\n\n  auto res = hl::kruskal(g);\n\n  int64_t ans = 0;\n\
    \  for(auto &e : res) ans += e.cost;\n  std::cout << ans << std::endl;\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A/main.kruskal.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A/main.kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A/main.kruskal.test.cpp
- /verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html
title: test/aoj/GRL_2_A/main.kruskal.test.cpp
---
