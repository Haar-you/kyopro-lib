---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/lca_doubling.cpp
    title: Lowest common ancestor (Doubling)
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_tuples_with_index.cpp
    title: Input tuples with index
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C/main.doubling.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\n\n#include\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\
    \n#include <cmath>\n#line 5 \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class lowest_common_ancestor_doubling\
    \ {\n    int n_, log2n_;\n    std::vector<std::vector<int>> parent_;\n    std::vector<int>\
    \ depth_;\n\n    void dfs(const tree<T> &tr, int cur, int par, int d){\n     \
    \ parent_[cur][0] = par;\n      depth_[cur] = d;\n\n      for(auto &e : tr[cur]){\n\
    \        if(e.to != par){\n          dfs(tr, e.to, cur, d + 1);\n        }\n \
    \     }\n    }\n\n  public:\n    lowest_common_ancestor_doubling(){}\n    lowest_common_ancestor_doubling(const\
    \ tree<T> &tr, int root):\n      n_(tr.size()), log2n_((int)ceil(log2(n_)) + 1),\
    \ parent_(n_, std::vector<int>(log2n_)), depth_(n_)\n    {\n      dfs(tr, root,\
    \ -1, 0);\n      for(int k = 0; k < log2n_ - 1; ++k){\n        for(int v = 0;\
    \ v < n_; ++v){\n          if(parent_[v][k] == -1) parent_[v][k + 1] = -1;\n \
    \         else parent_[v][k + 1] = parent_[parent_[v][k]][k];\n        }\n   \
    \   }\n    }\n\n    int lca(int a, int b) const {\n      if(depth_[a] >= depth_[b])\
    \ std::swap(a, b);\n      for(int k = 0; k < log2n_; ++k){\n        if((depth_[b]\
    \ - depth_[a]) >> k & 1) b = parent_[b][k];\n      }\n      if(a == b) return\
    \ a;\n      for(int k = log2n_; --k >= 0;){\n        if(parent_[a][k] != parent_[b][k]){a\
    \ = parent_[a][k]; b = parent_[b][k];}\n      }\n      return parent_[a][0];\n\
    \    }\n\n    int operator()(int a, int b) const {return lca(a, b);}\n\n    T\
    \ distance(int u, int v, const std::vector<T> &dist) const {\n      return dist[u]\
    \ + dist[v] - 2 * dist[lca(u, v)];\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"\
    Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename T, size_t\
    \ ... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)\
    \ ...};\n  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
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
    \ ...>(N);\n  }\n}\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename ... Args>\n  class InputTuplesWithIndex {\n\
    \    struct iter {\n      using value_type = std::tuple<int, Args ...>;\n    \
    \  value_type value;\n      bool fetched = false;\n      int N;\n      int c =\
    \ 0;\n\n      value_type operator*(){\n        if(not fetched){\n          std::tuple<Args\
    \ ...> temp; std::cin >> temp;\n          value = std::tuple_cat(std::make_tuple(c),\
    \ temp);\n        }\n        return value;\n      }\n\n      void operator++(){\n\
    \        ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter\
    \ &) const {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n  \
    \  };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int N): N(N){}\n\n\
    \    iter begin() const {return iter(N);}\n    iter end() const {return iter(N);}\n\
    \  };\n\n  template <typename ... Args>\n  auto input_tuples_with_index(int N){\n\
    \    return InputTuplesWithIndex<Args ...>(N);\n  }\n}\n#line 8 \"test/aoj/GRL_5_C/main.doubling.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  hl::tree<int>\
    \ tree(n);\n  for(auto [i, k] : hl::input_tuples_with_index<int>(n)){\n    for(auto\
    \ [c] : hl::input_tuples<int>(k)){\n      tree.add_edge(i, c, 1);\n    }\n  }\n\
    \n  auto lca = hl::lowest_common_ancestor_doubling(tree, 0);\n\n  int q; std::cin\
    \ >> q;\n\n  for(auto [u, v] : hl::input_tuples<int, int>(q)){\n    std::cout\
    \ << lca(u, v) << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int n; std::cin >> n;\n\n  hl::tree<int> tree(n);\n  for(auto\
    \ [i, k] : hl::input_tuples_with_index<int>(n)){\n    for(auto [c] : hl::input_tuples<int>(k)){\n\
    \      tree.add_edge(i, c, 1);\n    }\n  }\n\n  auto lca = hl::lowest_common_ancestor_doubling(tree,\
    \ 0);\n\n  int q; std::cin >> q;\n\n  for(auto [u, v] : hl::input_tuples<int,\
    \ int>(q)){\n    std::cout << lca(u, v) << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/lca_doubling.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuples_with_index.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C/main.doubling.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C/main.doubling.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C/main.doubling.test.cpp
- /verify/test/aoj/GRL_5_C/main.doubling.test.cpp.html
title: test/aoj/GRL_5_C/main.doubling.test.cpp
---
