---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Matching/weighted_bipartite_matching.cpp
    title: Weighted maximum bipartite matching
  - icon: ':question:'
    path: Mylib/Graph/Flow/minimum_cost_flow.cpp
    title: Minimum cost flow
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: Mylib/IO/join.cpp
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/yosupo-judge/assignment/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/assignment\"\n\n#include <iostream>\n#include\
    \ <vector>\n#line 3 \"Mylib/Graph/Matching/weighted_bipartite_matching.cpp\"\n\
    #include <tuple>\n\nnamespace haar_lib {\n  template <typename T, typename MinCostFlow,\
    \ bool MIN_MATCHING = false>\n  class weighted_bipartite_matching {\n  public:\n\
    \    int L, R, s, t;\n    MinCostFlow f;\n\n    weighted_bipartite_matching(int\
    \ L, int R, bool arbitrary_flow = false):\n      L(L), R(R), s(L + R), t(s + 1),\
    \ f(L + R + 2)\n    {\n      for(int i = 0; i < L; ++i) f.add_edge(s, i, 1, 0);\n\
    \      for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1, 0);\n      if(arbitrary_flow)\
    \ f.add_edge(s, t, std::numeric_limits<int>::max(), 0);\n    }\n\n    void add_edge(int\
    \ from, int to, T gain){\n      f.add_edge(from, L + to, 1, gain * (MIN_MATCHING\
    \ ? 1 : -1));\n    }\n\n    T solve(int flow){\n      T ret = f.solve(s, t, flow).second;\n\
    \      return ret * (MIN_MATCHING ? 1 : -1);\n    }\n\n    auto get_matching(){\n\
    \      const auto g = f.edges();\n      std::vector<std::tuple<int, int, T>> ret;\n\
    \n      for(auto &e : g){\n        if(not e.is_rev and e.from != s and e.to !=\
    \ t and e.cap == 0){\n          ret.emplace_back(e.from, e.to - L, e.cost * (MIN_MATCHING\
    \ ? 1 : -1));\n        }\n      }\n\n      return ret;\n    }\n  };\n}\n#line\
    \ 3 \"Mylib/Graph/Flow/minimum_cost_flow.cpp\"\n#include <queue>\n#include <utility>\n\
    #include <functional>\n#include <algorithm>\n#line 8 \"Mylib/Graph/Flow/minimum_cost_flow.cpp\"\
    \n\nnamespace haar_lib {\n  namespace minimum_cost_flow_impl {\n    template <typename\
    \ T, typename U>\n    struct edge {\n      int from, to, rev;\n      T cap;\n\
    \      U cost;\n      bool is_rev;\n      edge(int from, int to, int rev, T cap,\
    \ U cost, bool is_rev):\n        from(from), to(to), rev(rev), cap(cap), cost(cost),\
    \ is_rev(is_rev){}\n    };\n  }\n\n  template <typename Capacity, typename Cost>\n\
    \  class minimum_cost_flow {\n    using edge = minimum_cost_flow_impl::edge<Capacity,\
    \ Cost>;\n\n    int size;\n    std::vector<std::vector<edge>> g;\n\n  public:\n\
    \    minimum_cost_flow(){}\n    minimum_cost_flow(int size): size(size), g(size){}\n\
    \n    void add_edge(int from, int to, Capacity cap, Cost cost){\n      g[from].emplace_back(from,\
    \ to, g[to].size(), cap, cost, false);\n      g[to].emplace_back(to, from, g[from].size()\
    \ - 1, 0, -cost, true);\n    }\n\n    std::pair<Capacity, Cost> solve(int src,\
    \ int dst, const Capacity &f){\n      using P = std::pair<Cost, int>;\n      Cost\
    \ ret = 0;\n      Capacity flow = f;\n      std::vector<Cost> h(size, 0), cost(size);\n\
    \      std::vector<bool> is_inf(size, true);\n      std::vector<int> prev_node(size),\
    \ prev_edge(size);\n      std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n      while(flow > 0){\n        std::fill(is_inf.begin(), is_inf.end(),\
    \ true);\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF\
    \u3092\u63A2\u7D22\u3059\u308B\u3002 (dijkstra algorithm)\n        cost[src] =\
    \ 0;\n        pq.emplace(0, src);\n        is_inf[src] = false;\n\n        while(!pq.empty()){\n\
    \          Cost c;\n          int v;\n          std::tie(c, v) = pq.top(); pq.pop();\n\
    \n          if(cost[v] < c) continue;\n          for(int i = 0; i < (int)g[v].size();\
    \ ++i){\n            edge &e = g[v][i];\n            int w = e.to;\n         \
    \   Capacity cap = e.cap;\n            Cost cst = e.cost;\n            if(cap\
    \ > 0){\n              if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){\n\
    \                is_inf[w] = false;\n                cost[w] = cost[v] + cst +\
    \ h[v] - h[w];\n                prev_node[w] = v;\n                prev_edge[w]\
    \ = i;\n                pq.emplace(cost[w], w);\n              }\n           \
    \ }\n          }\n        }\n\n        if(is_inf[dst]) return {f - flow, ret};\
    \ // dst\u3078\u5230\u9054\u4E0D\u53EF\u80FD\n\n        for(int i = 0; i < size;\
    \ ++i) h[i] += cost[i];\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u7D4C\u8DEF\u3078\u6D41\u305B\u308B\u91CF(df)\u3092\u6C7A\u5B9A\u3059\u308B\
    \u3002\n        Capacity df = flow;\n        for(int cur = dst; cur != src; cur\
    \ = prev_node[cur]){\n          df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);\n\
    \        }\n\n        flow -= df;\n        ret += df * h[dst];\n\n        // cap\u306E\
    \u66F4\u65B0\n        for(int cur = dst; cur != src; cur = prev_node[cur]){\n\
    \          edge &e = g[prev_node[cur]][prev_edge[cur]];\n          e.cap -= df;\n\
    \          g[cur][e.rev].cap += df;\n        }\n      }\n\n      return {f - flow,\
    \ ret};\n    }\n\n    std::vector<edge> edges() const {\n      std::vector<edge>\
    \ ret;\n      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());\n  \
    \    return ret;\n    }\n  };\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n\
    #include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 9 \"test/yosupo-judge/assignment/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n  hl::weighted_bipartite_matching<int64_t, hl::minimum_cost_flow<int,\
    \ int64_t>, true> m(N, N);\n\n  auto a = hl::input_vector<int64_t>(N, N);\n\n\
    \  for(int i = 0; i < N; ++i){\n    for(int j = 0; j < N; ++j){\n      m.add_edge(i,\
    \ j, a[i][j]);\n    }\n  }\n\n  auto ans = m.solve(N);\n  std::cout << ans <<\
    \ std::endl;\n\n  auto matching = m.get_matching();\n\n  std::vector<int> p(N);\n\
    \  for(auto [i, j, c] : matching){\n    p[i] = j;\n  }\n\n  std::cout << hl::join(p.begin(),\
    \ p.end()) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"Mylib/Graph/Matching/weighted_bipartite_matching.cpp\"\
    \n#include \"Mylib/Graph/Flow/minimum_cost_flow.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N; std::cin\
    \ >> N;\n  hl::weighted_bipartite_matching<int64_t, hl::minimum_cost_flow<int,\
    \ int64_t>, true> m(N, N);\n\n  auto a = hl::input_vector<int64_t>(N, N);\n\n\
    \  for(int i = 0; i < N; ++i){\n    for(int j = 0; j < N; ++j){\n      m.add_edge(i,\
    \ j, a[i][j]);\n    }\n  }\n\n  auto ans = m.solve(N);\n  std::cout << ans <<\
    \ std::endl;\n\n  auto matching = m.get_matching();\n\n  std::vector<int> p(N);\n\
    \  for(auto [i, j, c] : matching){\n    p[i] = j;\n  }\n\n  std::cout << hl::join(p.begin(),\
    \ p.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Matching/weighted_bipartite_matching.cpp
  - Mylib/Graph/Flow/minimum_cost_flow.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yosupo-judge/assignment/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 19:52:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/assignment/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/assignment/main.test.cpp
- /verify/test/yosupo-judge/assignment/main.test.cpp.html
title: test/yosupo-judge/assignment/main.test.cpp
---
