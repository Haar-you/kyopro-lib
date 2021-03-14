---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/GraphUtils/decompose_pseudotree.cpp
    title: Decompose pseudotree
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891
  bundledCode: "#line 1 \"test/aoj/2891/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891\"\
    \n\n#include <iostream>\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"\
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
    \ ...>(N);\n  }\n}\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n\
    \    int index = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from),\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/GraphUtils/decompose_pseudotree.cpp\"\
    \n#include <queue>\n#line 5 \"Mylib/Graph/GraphUtils/decompose_pseudotree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class pseudo_tree {\n   \
    \ int n_;\n    std::vector<bool> in_loop_;\n    std::vector<int> group_;\n\n \
    \   void dfs(int cur, int par, const graph<T> &g){\n      group_[cur] = group_[par];\n\
    \n      for(auto &e : g[cur]){\n        if(e.to == par) continue;\n        dfs(e.to,\
    \ cur, g);\n      }\n    }\n\n  public:\n    pseudo_tree(){}\n    pseudo_tree(const\
    \ graph<T> &g): n_(g.size()), in_loop_(n_, true), group_(n_){\n      std::vector<int>\
    \ indeg(n_);\n      std::vector<bool> visited(n_);\n      std::queue<int> q;\n\
    \n      for(int i = 0; i < n_; ++i){\n        for(auto &e : g[i]){\n         \
    \ ++indeg[e.to];\n        }\n      }\n\n      for(int i = 0; i < n_; ++i){\n \
    \       if(indeg[i] == 1){\n          q.push(i);\n        }\n      }\n\n     \
    \ while(not q.empty()){\n        int cur = q.front(); q.pop();\n\n        in_loop_[cur]\
    \ = false;\n\n        if(visited[cur]) continue;\n        visited[cur] = true;\n\
    \n        for(auto &e : g[cur]){\n          if(not visited[e.to]){\n         \
    \   --indeg[e.to];\n            if(indeg[e.to] == 1){\n              q.push(e.to);\n\
    \            }\n          }\n        }\n      }\n\n      for(int i = 0; i < n_;\
    \ ++i){\n        if(in_loop_[i]){\n          group_[i] = i;\n          for(auto\
    \ &e : g[i]){\n            if(not in_loop_[e.to]){\n              dfs(e.to, i,\
    \ g);\n            }\n          }\n        }\n      }\n    }\n\n    bool in_loop(int\
    \ i) const {return in_loop_[i];}\n    int group(int i) const {return group_[i];}\n\
    \  };\n}\n#line 7 \"test/aoj/2891/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int N; std::cin >> N;\n\n  hl::graph<int> g(N);\n  g.read<1,\
    \ false, false>(N);\n\n  auto res = hl::pseudo_tree<int>(g);\n\n  int Q; std::cin\
    \ >> Q;\n  for(auto [a, b] : hl::input_tuples<int, int>(Q)){\n    --a, --b;\n\n\
    \    if(res.in_loop(a) and res.in_loop(b)){\n      std::cout << 2 << \"\\n\";\n\
    \    }else{\n      std::cout << 1 << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891\"\
    \n\n#include <iostream>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Graph/GraphUtils/decompose_pseudotree.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n\n  hl::graph<int> g(N);\n\
    \  g.read<1, false, false>(N);\n\n  auto res = hl::pseudo_tree<int>(g);\n\n  int\
    \ Q; std::cin >> Q;\n  for(auto [a, b] : hl::input_tuples<int, int>(Q)){\n   \
    \ --a, --b;\n\n    if(res.in_loop(a) and res.in_loop(b)){\n      std::cout <<\
    \ 2 << \"\\n\";\n    }else{\n      std::cout << 1 << \"\\n\";\n    }\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/decompose_pseudotree.cpp
  isVerificationFile: true
  path: test/aoj/2891/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-25 02:11:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2891/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2891/main.test.cpp
- /verify/test/aoj/2891/main.test.cpp.html
title: test/aoj/2891/main.test.cpp
---
