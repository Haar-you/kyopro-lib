---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/tree_distance.cpp
    title: Tree distance
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/tree_height.cpp
    title: Tree height
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"test/aoj/GRL_5_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/TreeUtils/tree_height.cpp\"\
    \n#include <algorithm>\n#line 3 \"Mylib/Graph/TreeUtils/tree_distance.cpp\"\n\
    #include <stack>\n#line 5 \"Mylib/Graph/TreeUtils/tree_distance.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> tree_distance(const tree<T>\
    \ &tr, int root){\n    const int n = tr.size();\n    std::vector<T> ret(n);\n\
    \    std::vector<bool> visited(n);\n\n    std::stack<int> st;\n    st.push(root);\n\
    \    ret[root] = 0;\n\n    while(not st.empty()){\n      int cur = st.top(); st.pop();\n\
    \      visited[cur] = true;\n\n      for(auto &e : tr[cur]){\n        if(not visited[e.to]){\n\
    \          ret[e.to] = ret[cur] + e.cost;\n          st.push(e.to);\n        }\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n#line 6 \"Mylib/Graph/TreeUtils/tree_height.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> tree_height(const\
    \ tree<T> &tr){\n    const int n = tr.size();\n\n    auto d = tree_distance(tr,\
    \ 0);\n    int a = std::max_element(d.begin(), d.end()) - d.begin();\n    auto\
    \ d1 = tree_distance(tr, a);\n    int b = std::max_element(d1.begin(), d1.end())\
    \ - d1.begin();\n    auto d2 = tree_distance(tr, b);\n\n    std::vector<T> h(n);\n\
    \    for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);\n\n    return h;\n\
    \  }\n}\n#line 6 \"test/aoj/GRL_5_B/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int n; std::cin >> n;\n\n  hl::tree<int> tree(n);\n  tree.read<0,\
    \ false>(n - 1);\n\n  auto ans = hl::tree_height(tree);\n\n  for(auto x : ans)\
    \ std::cout << x << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/TreeUtils/tree_height.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main(){\n  int n; std::cin >> n;\n\n  hl::tree<int> tree(n);\n  tree.read<0,\
    \ false>(n - 1);\n\n  auto ans = hl::tree_height(tree);\n\n  for(auto x : ans)\
    \ std::cout << x << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/tree_height.cpp
  - Mylib/Graph/TreeUtils/tree_distance.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_B/main.test.cpp
- /verify/test/aoj/GRL_5_B/main.test.cpp.html
title: test/aoj/GRL_5_B/main.test.cpp
---
