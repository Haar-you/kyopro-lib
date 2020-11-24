---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/Search/parallel_binary_search.cpp
    title: Parallel binary search
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/ShortestPath/dijkstra.cpp
    title: Dijkstra algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575
  bundledCode: "#line 1 \"test/aoj/0575/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #line 3 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\n#include <optional>\n#include\
    \ <queue>\n#line 6 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\n#include <functional>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 8 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto dijkstra(const graph<T>\
    \ &graph, std::vector<int> src){\n    using P = std::pair<T, int>;\n\n    const\
    \ int n = graph.size();\n    std::vector<std::optional<T>> dist(n);\n\n    std::vector<bool>\
    \ check(n, false);\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n    for(auto s : src){\n      dist[s] = 0;\n      pq.emplace(0, s);\n\
    \    }\n\n    while(not pq.empty()){\n      const auto [d, i] = pq.top(); pq.pop();\n\
    \n      if(check[i]) continue;\n      check[i] = true;\n\n      for(auto &e :\
    \ graph[i]){\n        if(not dist[e.to]){\n          dist[e.to] = d + e.cost;\n\
    \          pq.emplace(*dist[e.to], e.to);\n        }else{\n          if(*dist[e.to]\
    \ > d + e.cost){\n            dist[e.to] = d + e.cost;\n            if(not check[e.to])\
    \ pq.emplace(*dist[e.to], e.to);\n          }\n        }\n      }\n    }\n\n \
    \   return dist;\n  }\n}\n#line 3 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
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
    \   return ret;\n    }\n  };\n}\n#line 3 \"Mylib/Algorithm/Search/parallel_binary_search.cpp\"\
    \n#include <cmath>\n\nnamespace haar_lib {\n  template <typename Init, typename\
    \ Process, typename Checker>\n  auto parallel_binary_search(int M, int Q, Init\
    \ init, Process process, Checker checker){\n    std::vector<int> lb(Q, -1), ub(Q,\
    \ M);\n\n    while(1){\n      bool check = true;\n      std::vector<std::vector<int>>\
    \ mids(M);\n      for(int i = 0; i < Q; ++i){\n        if(std::abs(lb[i] - ub[i])\
    \ > 1){\n          check = false;\n          int mid = (lb[i] + ub[i]) / 2;\n\
    \          mids[mid].push_back(i);\n        }\n      }\n\n      if(check) break;\n\
    \n      init();\n\n      for(int i = 0; i < M; ++i){\n        process(i);\n  \
    \      for(int j : mids[i]){\n          if(checker(j)){\n            ub[j] = i;\n\
    \          }else{\n            lb[j] = i;\n          }\n        }\n      }\n \
    \   }\n\n    return ub;\n  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n\
    #include <tuple>\n#line 6 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <initializer_list>\n\
    \nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 13 \"test/aoj/0575/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M, K, Q;\
    \ std::cin >> N >> M >> K >> Q;\n\n  hl::graph<int> g(N);\n  g.read<1, false>(M);\n\
    \n  auto F = hl::input_vector<int>(K);\n  for(auto &x : F) x -= 1;\n\n  auto [S,\
    \ T] = hl::input_tuple_vector<int, int>(Q);\n  for(auto &x : S) x -= 1;\n  for(auto\
    \ &x : T) x -= 1;\n\n  auto dist = hl::dijkstra(g, {F});\n\n  std::vector<int>\
    \ dist_list;\n  for(auto &x : dist){\n    dist_list.push_back(*x);\n  }\n\n  std::sort(dist_list.begin(),\
    \ dist_list.end());\n  dist_list.erase(std::unique(dist_list.begin(), dist_list.end()),\
    \ dist_list.end());\n\n  const int C = dist_list.size();\n\n  std::vector<std::vector<std::pair<int,\
    \ int>>> edges(C);\n  for(int i = 0; i < N; ++i){\n    for(auto &e : g[i]){\n\
    \      if(*dist[e.from] <= *dist[e.to]){\n        int x = std::lower_bound(dist_list.begin(),\
    \ dist_list.end(), *dist[e.from]) - dist_list.begin();\n        edges[x].emplace_back(e.from,\
    \ e.to);\n      }\n    }\n  }\n\n  hl::unionfind uf;\n\n  auto res =\n    hl::parallel_binary_search(\n\
    \      C,\n      Q,\n      [&](){uf = hl::unionfind(N);},\n      [&](int i){\n\
    \        for(auto [x, y] : edges[C - 1 - i]){\n          uf.merge(x, y);\n   \
    \     }\n      },\n      [&](int i) -> bool {\n        return uf.is_same(S[i],\
    \ T[i]);\n      }\n    );\n\n  for(auto x : res){\n    std::cout << dist_list[C\
    \ - x - 1] << \"\\n\";\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include \"Mylib/Algorithm/Search/parallel_binary_search.cpp\"\n#include \"\
    Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\n#include\
    \ \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M, K, Q;\
    \ std::cin >> N >> M >> K >> Q;\n\n  hl::graph<int> g(N);\n  g.read<1, false>(M);\n\
    \n  auto F = hl::input_vector<int>(K);\n  for(auto &x : F) x -= 1;\n\n  auto [S,\
    \ T] = hl::input_tuple_vector<int, int>(Q);\n  for(auto &x : S) x -= 1;\n  for(auto\
    \ &x : T) x -= 1;\n\n  auto dist = hl::dijkstra(g, {F});\n\n  std::vector<int>\
    \ dist_list;\n  for(auto &x : dist){\n    dist_list.push_back(*x);\n  }\n\n  std::sort(dist_list.begin(),\
    \ dist_list.end());\n  dist_list.erase(std::unique(dist_list.begin(), dist_list.end()),\
    \ dist_list.end());\n\n  const int C = dist_list.size();\n\n  std::vector<std::vector<std::pair<int,\
    \ int>>> edges(C);\n  for(int i = 0; i < N; ++i){\n    for(auto &e : g[i]){\n\
    \      if(*dist[e.from] <= *dist[e.to]){\n        int x = std::lower_bound(dist_list.begin(),\
    \ dist_list.end(), *dist[e.from]) - dist_list.begin();\n        edges[x].emplace_back(e.from,\
    \ e.to);\n      }\n    }\n  }\n\n  hl::unionfind uf;\n\n  auto res =\n    hl::parallel_binary_search(\n\
    \      C,\n      Q,\n      [&](){uf = hl::unionfind(N);},\n      [&](int i){\n\
    \        for(auto [x, y] : edges[C - 1 - i]){\n          uf.merge(x, y);\n   \
    \     }\n      },\n      [&](int i) -> bool {\n        return uf.is_same(S[i],\
    \ T[i]);\n      }\n    );\n\n  for(auto x : res){\n    std::cout << dist_list[C\
    \ - x - 1] << \"\\n\";\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - Mylib/Graph/ShortestPath/dijkstra.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  - Mylib/Algorithm/Search/parallel_binary_search.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/0575/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0575/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0575/main.test.cpp
- /verify/test/aoj/0575/main.test.cpp.html
title: test/aoj/0575/main.test.cpp
---
