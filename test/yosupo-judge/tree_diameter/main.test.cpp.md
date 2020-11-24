---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/TreeUtils/tree_diameter.cpp
    title: Tree diameter
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo-judge/tree_diameter/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <iostream>\n\
    #line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/TreeUtils/tree_diameter.cpp\"\
    \n#include <utility>\n#include <stack>\n#include <algorithm>\n#line 7 \"Mylib/Graph/TreeUtils/tree_diameter.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::pair<T, std::vector<int>>\
    \ tree_diameter(const tree<T> &tr){\n    const int N = tr.size();\n\n    std::vector<bool>\
    \ check(N);\n    std::vector<T> dp(N);\n    std::stack<int> st;\n\n    st.push(0);\n\
    \    while(st.size()){\n      int i = st.top(); st.pop();\n\n      check[i] =\
    \ true;\n\n      for(const auto &e : tr[i]){\n        if(not check[e.to]){\n \
    \         dp[e.to] = dp[i] + e.cost;\n          st.push(e.to);\n        }\n  \
    \    }\n    }\n\n    const int u = std::max_element(dp.begin(), dp.end()) - dp.begin();\n\
    \n    dp.assign(N, 0);\n    check.assign(N, false);\n\n    std::vector<int> prev(N);\n\
    \n    st.push(u);\n    while(st.size()){\n      int i = st.top(); st.pop();\n\n\
    \      check[i] = true;\n\n      for(const auto &e : tr[i]){\n        if(not check[e.to]){\n\
    \          dp[e.to] = dp[i] + e.cost;\n          st.push(e.to);\n          prev[e.to]\
    \ = i;\n        }\n      }\n    }\n\n    const int v = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n\n    std::vector<int> ret;\n\n    int cur = v;\n \
    \   while(1){\n      ret.push_back(cur);\n      if(cur == u) break;\n      cur\
    \ = prev[cur];\n    }\n\n    return std::make_pair(dp[v], ret);\n  }\n}\n#line\
    \ 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\nnamespace\
    \ haar_lib {\n  template <typename Iter>\n  std::string join(Iter first, Iter\
    \ last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 7 \"test/yosupo-judge/tree_diameter/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  hl::tree<int64_t> tree(N);\n  tree.read<0, false>(N\
    \ - 1);\n\n  auto [cost, path] = hl::tree_diameter(tree);\n\n  std::cout\n   \
    \ << cost << \" \" << path.size() << \"\\n\"\n    << hl::join(path.begin(), path.end())\
    \ << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/TreeUtils/tree_diameter.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N; std::cin\
    \ >> N;\n\n  hl::tree<int64_t> tree(N);\n  tree.read<0, false>(N - 1);\n\n  auto\
    \ [cost, path] = hl::tree_diameter(tree);\n\n  std::cout\n    << cost << \" \"\
    \ << path.size() << \"\\n\"\n    << hl::join(path.begin(), path.end()) << \"\\\
    n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/tree_diameter.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/tree_diameter/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/tree_diameter/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/tree_diameter/main.test.cpp
- /verify/test/yosupo-judge/tree_diameter/main.test.cpp.html
title: test/yosupo-judge/tree_diameter/main.test.cpp
---
