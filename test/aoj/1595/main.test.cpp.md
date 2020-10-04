---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/Graph/TreeUtils/rerooting.cpp
    title: Rerooting DP
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595
  bundledCode: "#line 1 \"test/aoj/1595/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/TreeUtils/rerooting.cpp\"\n#include\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 4 \"Mylib/Graph/TreeUtils/rerooting.cpp\"\
    \n\nnamespace haar_lib {\n  namespace rerooting_impl {\n    template <typename\
    \ T, typename U, typename Merge, typename EdgeF, typename VertexF>\n    T rec1(\n\
    \      tree<U> &tr,\n      T id,\n      const Merge &merge,\n      const EdgeF\
    \ &f,\n      const VertexF &g,\n      std::vector<std::vector<T>> &dp,\n     \
    \ int cur,\n      int par = -1\n    ){\n      T acc = id;\n\n      for(int i =\
    \ 0; i < (int)tr[cur].size(); ++i){\n        auto &e = tr[cur][i];\n        if(e.to\
    \ == par) continue;\n        dp[cur][i] = rec1(tr, id, merge, f, g, dp, e.to,\
    \ cur);\n        acc = merge(acc, f(dp[cur][i], e));\n      }\n\n      return\
    \ g(acc, cur);\n    }\n\n    template <typename T, typename U, typename Merge,\
    \ typename EdgeF, typename VertexF>\n    void rec2(\n      const tree<U> &tr,\n\
    \      T id,\n      const Merge &merge,\n      const EdgeF &f,\n      const VertexF\
    \ &g,\n      std::vector<std::vector<T>> &dp,\n      int cur,\n      int par,\n\
    \      T value\n    ){\n      const int l = tr[cur].size();\n\n      for(int i\
    \ = 0; i < l; ++i){\n        if(tr[cur][i].to == par){\n          dp[cur][i] =\
    \ value;\n        }\n      }\n\n      std::vector<T> left(l + 1, id), right(l\
    \ + 1, id);\n\n      for(int i = 0; i < l - 1; ++i){\n        const auto &e =\
    \ tr[cur][i];\n        left[i + 1] = merge(left[i], f(dp[cur][i], e));\n     \
    \ }\n\n      for(int i = l - 1; i >= 1; --i){\n        const auto &e = tr[cur][i];\n\
    \        right[i - 1] = merge(right[i], f(dp[cur][i], e));\n      }\n\n      for(int\
    \ i = 0; i < l; ++i){\n        const auto &e = tr[cur][i];\n        if(e.to ==\
    \ par) continue;\n\n        rec2(tr, id, merge, f, g, dp, e.to, cur, g(merge(left[i],\
    \ right[i]), cur));\n      }\n    }\n  }\n\n  template <typename T, typename U,\
    \ typename Merge, typename EdgeF, typename VertexF>\n  auto rerooting(tree<U>\
    \ tr, T id, Merge merge, EdgeF f, VertexF g){\n    const int N = tr.size();\n\
    \    std::vector<std::vector<T>> dp(N);\n    std::vector<T> ret(N, id);\n\n  \
    \  for(int i = 0; i < N; ++i) dp[i].assign(tr[i].size(), id);\n    rerooting_impl::rec1(tr,\
    \ id, merge, f, g, dp, 0);\n    rerooting_impl::rec2(tr, id, merge, f, g, dp,\
    \ 0, -1, id);\n    for(int i = 0; i < N; ++i){\n      for(int j = 0; j < (int)tr[i].size();\
    \ ++j){\n        ret[i] = merge(ret[i], f(dp[i][j], tr[i][j]));\n      }\n\n \
    \     ret[i] = g(ret[i], i);\n    }\n\n    return ret;\n  }\n}\n#line 6 \"test/aoj/1595/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n\n  hl::tree<int>\
    \ tree(N);\n  tree.read<1, false, false>(N - 1);\n\n  auto r = hl::rerooting<int>(\n\
    \    tree,\n    0,\n    [](const auto &a, const auto &b){\n      return std::max(a,\
    \ b);\n    },\n    [](const auto &a, const auto &){\n      return a + 1;\n   \
    \ },\n    [](const auto &a, int){\n      return a;\n    }\n  );\n\n  for(auto\
    \ &x : r){\n    std::cout << 2 * (N - 1) - x << std::endl;\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/TreeUtils/rerooting.cpp\"\n#include\
    \ \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N; std::cin >> N;\n\n  hl::tree<int> tree(N);\n  tree.read<1, false, false>(N\
    \ - 1);\n\n  auto r = hl::rerooting<int>(\n    tree,\n    0,\n    [](const auto\
    \ &a, const auto &b){\n      return std::max(a, b);\n    },\n    [](const auto\
    \ &a, const auto &){\n      return a + 1;\n    },\n    [](const auto &a, int){\n\
    \      return a;\n    }\n  );\n\n  for(auto &x : r){\n    std::cout << 2 * (N\
    \ - 1) - x << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/TreeUtils/rerooting.cpp
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: true
  path: test/aoj/1595/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1595/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1595/main.test.cpp
- /verify/test/aoj/1595/main.test.cpp.html
title: test/aoj/1595/main.test.cpp
---
