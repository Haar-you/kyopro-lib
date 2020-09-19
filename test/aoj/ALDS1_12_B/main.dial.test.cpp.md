---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/ShortestPath/dial_algorithm.cpp
    title: Dial's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_12_B/main.dial.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\"\n\n\
    #include <iostream>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <vector>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/ShortestPath/dial_algorithm.cpp\"\
    \n#include <optional>\n#include <stack>\n#line 6 \"Mylib/Graph/ShortestPath/dial_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  auto dial_algorithm(const graph<int> &g, std::vector<int>\
    \ src, int MAX){\n    const int N = g.size();\n    std::vector<std::stack<int>>\
    \ buckets(MAX + 1);\n    std::vector<std::optional<int>> ret(N);\n    std::vector<bool>\
    \ check(N);\n\n    for(int i : src){\n      ret[i] = 0;\n      buckets[0].push(i);\n\
    \    }\n\n    for(int i = 0; i <= MAX; ++i){\n      while(not buckets[i].empty()){\n\
    \        int cur = buckets[i].top(); buckets[i].pop();\n\n        if(check[cur])\
    \ continue;\n        check[cur] = true;\n\n        for(auto &e : g[cur]){\n  \
    \        if(not ret[e.to] or *ret[cur] + e.cost < *ret[e.to]){\n            ret[e.to]\
    \ = *ret[cur] + e.cost;\n            buckets[*ret[e.to] % (MAX + 1)].push(e.to);\n\
    \          }\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n#line 6 \"\
    test/aoj/ALDS1_12_B/main.dial.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int n; std::cin\
    \ >> n;\n  hl::graph<int> g(n);\n\n  for(int i = 0; i < n; ++i){\n    int u, k;\
    \ std::cin >> u >> k;\n    for(int j = 0; j < k; ++j){\n      int v, c; std::cin\
    \ >> v >> c;\n      g.add_edge(u, v, c);\n    }\n  }\n\n  auto ans = hl::dial_algorithm(g,\
    \ {0}, 100000);\n\n  for(int i = 0; i < n; ++i) std::cout << i << \" \" << *ans[i]\
    \ << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/ShortestPath/dial_algorithm.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ n; std::cin >> n;\n  hl::graph<int> g(n);\n\n  for(int i = 0; i < n; ++i){\n\
    \    int u, k; std::cin >> u >> k;\n    for(int j = 0; j < k; ++j){\n      int\
    \ v, c; std::cin >> v >> c;\n      g.add_edge(u, v, c);\n    }\n  }\n\n  auto\
    \ ans = hl::dial_algorithm(g, {0}, 100000);\n\n  for(int i = 0; i < n; ++i) std::cout\
    \ << i << \" \" << *ans[i] << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/ShortestPath/dial_algorithm.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_12_B/main.dial.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_12_B/main.dial.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_12_B/main.dial.test.cpp
- /verify/test/aoj/ALDS1_12_B/main.dial.test.cpp.html
title: test/aoj/ALDS1_12_B/main.dial.test.cpp
---
