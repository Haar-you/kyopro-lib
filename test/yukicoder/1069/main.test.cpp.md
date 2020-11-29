---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/ShortestPath/yen_algorithm.cpp
    title: Yen's algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://yukicoder.me/problems/no/1069
    links:
    - https://yukicoder.me/problems/no/1069
  bundledCode: "#line 1 \"test/yukicoder/1069/main.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1069\"\n#define ERROR 1e-4\n\n#include <iostream>\n\
    #include <iomanip>\n#include <cmath>\n#line 3 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    \nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 4 \"Mylib/Graph/ShortestPath/yen_algorithm.cpp\"\n#include\
    \ <optional>\n#include <queue>\n#include <functional>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 8 \"Mylib/Graph/ShortestPath/yen_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  namespace yen_algorithm_impl {\n    template <typename\
    \ T>\n    auto shortest_path(\n      const graph<T> &g,\n      int from,\n   \
    \   int t,\n      const std::vector<bool> &usable,\n      const std::vector<std::vector<bool>>\
    \ &valid\n    ){\n      using Path = std::pair<T, std::vector<int>>;\n      using\
    \ P = std::pair<T, int>;\n\n      const int N = g.size();\n      std::vector<bool>\
    \ visited(N, false);\n      std::vector<std::optional<T>> dist(N);\n      std::vector<std::pair<int,\
    \ int>> restore(N);\n\n      std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n      dist[from] = 0;\n      pq.emplace(0, from);\n\n      while(not\
    \ pq.empty()){\n        auto [d, i] = pq.top(); pq.pop();\n\n        if(visited[i])\
    \ continue;\n        visited[i] = true;\n\n        for(int k = 0; k < (int)g[i].size();\
    \ ++k){\n          if(not valid[i][k] or not usable[g[i][k].to]) continue;\n \
    \         auto &e = g[i][k];\n\n          if(not dist[e.to] or *dist[e.to] > d\
    \ + e.cost){\n            dist[e.to] = d + e.cost;\n            restore[e.to]\
    \ = std::make_pair(i, k);\n            if(not visited[e.to]) pq.emplace(*dist[e.to],\
    \ e.to);\n          }\n        }\n      }\n\n      std::optional<Path> ret;\n\n\
    \      if(dist[t]){\n        std::vector<int> p;\n\n        int cur = t;\n   \
    \     while(cur != from){\n          auto [i, j] = restore[cur];\n          p.push_back(j);\n\
    \          cur = i;\n        }\n\n        std::reverse(p.begin(), p.end());\n\n\
    \        ret = std::make_pair(*dist[t], p);\n      }\n\n      return ret;\n  \
    \  }\n  }\n\n  template <typename T>\n  auto yen_algorithm(const graph<T> &g,\
    \ int s, int t, int K){\n    using Path = std::pair<T, std::vector<int>>;\n\n\
    \    const int N = g.size();\n\n    std::vector<std::vector<bool>> valid(N);\n\
    \    std::vector<std::optional<Path>> result(K);\n    std::priority_queue<Path,\
    \ std::vector<Path>, std::greater<Path>> stock;\n\n    for(int i = 0; i < N; ++i){\n\
    \      valid[i].assign(g[i].size(), true);\n    }\n\n    for(int i = 0; i < K;\
    \ ++i){\n      if(i == 0){\n        std::vector<bool> usable(N, true);\n     \
    \   if(auto res = yen_algorithm_impl::shortest_path(g, s, t, usable, valid); res)\
    \ stock.push(*res);\n      }else{\n        std::vector<int> prev_path;\n\n   \
    \     {\n          int cur = s;\n          for(auto u : result[i - 1]->second){\n\
    \            prev_path.push_back(cur);\n            cur = g[cur][u].to;\n    \
    \      }\n          prev_path.push_back(t);\n        }\n\n        std::vector<bool>\
    \ check(i, true);\n        std::vector<bool> usable(N, true);\n\n        for(int\
    \ k = 0; k < (int)prev_path.size() - 1; ++k){\n          const int u = prev_path[k];\n\
    \n          for(int j = 0; j < i; ++j){\n            if(check[j]){\n         \
    \     valid[prev_path[k]][result[j]->second[k]] = false;\n            }\n    \
    \      }\n\n          if(auto res = yen_algorithm_impl::shortest_path(g, u, t,\
    \ usable, valid); res){\n            auto [c, p] = *res;\n\n            std::vector<int>\
    \ temp;\n            for(int j = 0; j < k; ++j){\n              int v = result[i\
    \ - 1]->second[j];\n\n              c += g[prev_path[j]][v].cost;\n          \
    \    temp.push_back(v);\n            }\n\n            temp.insert(temp.end(),\
    \ p.begin(), p.end());\n            stock.emplace(c, temp);\n          }\n\n \
    \         usable[u] = false;\n\n          for(int j = 0; j < i; ++j){\n      \
    \      if(check[j]){\n              valid[prev_path[k]][result[j]->second[k]]\
    \ = true;\n            }\n          }\n\n          for(int j = 0; j < i; ++j){\n\
    \            if(check[j]){\n              if(prev_path[k + 1] != g[prev_path[k]][result[j]->second[k]].to){\n\
    \                check[j] = false;\n              }\n            }\n         \
    \ }\n        }\n      }\n\n      if(stock.empty()) break;\n\n      result[i] =\
    \ stock.top(); stock.pop();\n\n      while(not stock.empty() and stock.top() ==\
    \ result[i]){\n        stock.pop();\n      }\n    }\n\n    return result;\n  }\n\
    }\n#line 10 \"test/yukicoder/1069/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, M, K, X, Y; std::cin >> N >> M >> K >> X >> Y;\n  --X, --Y;\n\n  auto [p,\
    \ q] = hl::input_tuple_vector<long double, long double>(N);\n\n  hl::graph<long\
    \ double> g(N);\n  for(auto [P, Q] : hl::input_tuples<int, int>(M)){\n    --P,\
    \ --Q;\n\n    long double dx = p[P] - p[Q];\n    long double dy = q[P] - q[Q];\n\
    \n    long double L = std::sqrt(dx * dx + dy * dy);\n\n    g.add_undirected(P,\
    \ Q, L);\n  }\n\n  auto res = hl::yen_algorithm(g, X, Y, K);\n\n  for(auto x :\
    \ res){\n    if(not x){\n      std::cout << -1 << \"\\n\";\n    }else{\n     \
    \ std::cout << std::fixed << std::setprecision(12) << x->first << \"\\n\";\n \
    \   }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1069\"\n#define ERROR\
    \ 1e-4\n\n#include <iostream>\n#include <iomanip>\n#include <cmath>\n#include\
    \ \"Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\
    #include \"Mylib/Graph/ShortestPath/yen_algorithm.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, M, K, X, Y; std::cin >> N >> M >> K >> X >> Y;\n  --X, --Y;\n\n  auto [p,\
    \ q] = hl::input_tuple_vector<long double, long double>(N);\n\n  hl::graph<long\
    \ double> g(N);\n  for(auto [P, Q] : hl::input_tuples<int, int>(M)){\n    --P,\
    \ --Q;\n\n    long double dx = p[P] - p[Q];\n    long double dy = q[P] - q[Q];\n\
    \n    long double L = std::sqrt(dx * dx + dy * dy);\n\n    g.add_undirected(P,\
    \ Q, L);\n  }\n\n  auto res = hl::yen_algorithm(g, X, Y, K);\n\n  for(auto x :\
    \ res){\n    if(not x){\n      std::cout << -1 << \"\\n\";\n    }else{\n     \
    \ std::cout << std::fixed << std::setprecision(12) << x->first << \"\\n\";\n \
    \   }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Graph/ShortestPath/yen_algorithm.cpp
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: true
  path: test/yukicoder/1069/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/1069/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1069/main.test.cpp
- /verify/test/yukicoder/1069/main.test.cpp.html
title: test/yukicoder/1069/main.test.cpp
---
