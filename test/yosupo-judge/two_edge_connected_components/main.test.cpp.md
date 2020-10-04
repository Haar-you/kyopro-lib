---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/GraphUtils/two_edge_connected_components.cpp
    title: Two edge connected components
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo-judge/two_edge_connected_components/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/GraphUtils/two_edge_connected_components.cpp\"\
    \n#include <stack>\n#line 5 \"Mylib/Graph/GraphUtils/two_edge_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  namespace two_edge_connected_components_impl {\n \
    \   template <typename T>\n    int dfs(\n      const graph<T> &g,\n      int cur,\n\
    \      int par,\n      std::vector<int> &low,\n      std::vector<int> &order,\n\
    \      std::vector<std::vector<int>> &ret,\n      std::stack<int> &st,\n     \
    \ int &v\n    ){\n      if(order[cur] != -1) return order[cur];\n      order[cur]\
    \ = v;\n      int temp = v++;\n      st.push(cur);\n\n      int count = 0;\n\n\
    \      for(const auto &e : g[cur]){\n        if(e.to == par){\n          ++count;\n\
    \          if(count == 1) continue;\n        }\n\n        const int t = dfs(g,\
    \ e.to, cur, low, order, ret, st, v);\n        temp = std::min(temp, t);\n\n \
    \       if(low[e.to] > order[cur]){ // e is a bridge\n          std::vector<int>\
    \ cc;\n          while(true){\n            int c = st.top();\n            cc.emplace_back(c);\n\
    \            st.pop();\n            if(c == e.to) break;\n          }\n      \
    \    ret.emplace_back(cc);\n        }\n      }\n\n      return low[cur] = temp;\n\
    \    }\n  }\n\n  template <typename T>\n  auto two_edge_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> low(n, -1),\
    \ order(n, -1);\n    std::vector<std::vector<int>> ret;\n    std::stack<int> st;\n\
    \    int v = 0;\n\n    for(int i = 0; i < n; ++i){\n      if(order[i] == -1){\n\
    \        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st,\
    \ v);\n        if(not st.empty()){\n          std::vector<int> cc;\n         \
    \ while(not st.empty()) cc.emplace_back(st.top()), st.pop();\n          ret.emplace_back(cc);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\
    \n#include <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename\
    \ Iter>\n  std::string join(Iter first, Iter last, std::string delim = \" \"){\n\
    \    std::stringstream s;\n\n    for(auto it = first; it != last; ++it){\n   \
    \   if(it != first) s << delim;\n      s << *it;\n    }\n\n    return s.str();\n\
    \  }\n}\n#line 7 \"test/yosupo-judge/two_edge_connected_components/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n\n  hl::graph<int> g(N);\n  g.read<0, false,\
    \ false>(M);\n\n  auto res = hl::two_edge_connected_components(g);\n\n  std::cout\
    \ << res.size() << std::endl;\n  for(auto &v : res){\n    std::cout << v.size()\
    \ << \" \" << hl::join(v.begin(), v.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/GraphUtils/two_edge_connected_components.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n\n  hl::graph<int> g(N);\n  g.read<0, false,\
    \ false>(M);\n\n  auto res = hl::two_edge_connected_components(g);\n\n  std::cout\
    \ << res.size() << std::endl;\n  for(auto &v : res){\n    std::cout << v.size()\
    \ << \" \" << hl::join(v.begin(), v.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/two_edge_connected_components.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/two_edge_connected_components/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/two_edge_connected_components/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp
- /verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html
title: test/yosupo-judge/two_edge_connected_components/main.test.cpp
---
