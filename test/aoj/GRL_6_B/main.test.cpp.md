---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Flow/minimum_cost_flow.cpp
    title: Minimum cost flow
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/Flow/minimum_cost_flow.cpp\"\n\
    #include <algorithm>\n#include <cassert>\n#include <functional>\n#include <queue>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  namespace minimum_cost_flow_impl {\n    template <typename T, typename\
    \ U>\n    struct edge {\n      int from, to, rev;\n      T cap;\n      U cost;\n\
    \      bool is_rev;\n      edge(int from, int to, int rev, T cap, U cost, bool\
    \ is_rev) : from(from), to(to), rev(rev), cap(cap), cost(cost), is_rev(is_rev)\
    \ {}\n    };\n  }  // namespace minimum_cost_flow_impl\n\n  template <typename\
    \ Capacity, typename Cost>\n  class minimum_cost_flow {\n  public:\n    using\
    \ edge          = minimum_cost_flow_impl::edge<Capacity, Cost>;\n    using capacity_type\
    \ = Capacity;\n    using cost_type     = Cost;\n\n  private:\n    int size_;\n\
    \    std::vector<std::vector<edge>> g_;\n\n  public:\n    minimum_cost_flow()\
    \ {}\n    minimum_cost_flow(int size) : size_(size), g_(size) {}\n\n    void add_edge(int\
    \ from, int to, Capacity cap, Cost cost) {\n      assert(0 <= from and from <\
    \ size_);\n      assert(0 <= to and to < size_);\n      g_[from].emplace_back(from,\
    \ to, g_[to].size(), cap, cost, false);\n      g_[to].emplace_back(to, from, g_[from].size()\
    \ - 1, 0, -cost, true);\n    }\n\n    std::pair<Capacity, Cost> min_cost_flow(int\
    \ src, int dst, const Capacity &f) {\n      assert(0 <= src and src < size_);\n\
    \      assert(0 <= dst and dst < size_);\n\n      using P       = std::pair<Cost,\
    \ int>;\n      Cost ret      = 0;\n      Capacity flow = f;\n      std::vector<Cost>\
    \ h(size_, 0), cost(size_);\n      std::vector<bool> is_inf(size_, true);\n  \
    \    std::vector<int> prev_node(size_), prev_edge(size_);\n      std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n\n      while (flow > 0) {\n        std::fill(is_inf.begin(),\
    \ is_inf.end(), true);\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u7D4C\u8DEF\u3092\u63A2\u7D22\u3059\u308B\u3002 (dijkstra algorithm)\n\
    \        cost[src] = 0;\n        pq.emplace(0, src);\n        is_inf[src] = false;\n\
    \n        while (not pq.empty()) {\n          Cost c;\n          int v;\n    \
    \      std::tie(c, v) = pq.top();\n          pq.pop();\n\n          if (cost[v]\
    \ < c) continue;\n          for (int i = 0; i < (int) g_[v].size(); ++i) {\n \
    \           edge &e      = g_[v][i];\n            int w        = e.to;\n     \
    \       Capacity cap = e.cap;\n            Cost cst     = e.cost;\n          \
    \  if (cap > 0) {\n              if (is_inf[w] or cost[w] + h[w] > cost[v] + h[v]\
    \ + cst) {\n                is_inf[w]    = false;\n                cost[w]   \
    \   = cost[v] + cst + h[v] - h[w];\n                prev_node[w] = v;\n      \
    \          prev_edge[w] = i;\n                pq.emplace(cost[w], w);\n      \
    \        }\n            }\n          }\n        }\n\n        if (is_inf[dst])\
    \ return {f - flow, ret};  // dst\u3078\u5230\u9054\u4E0D\u53EF\u80FD\n\n    \
    \    for (int i = 0; i < size_; ++i) h[i] += cost[i];\n\n        // src -> dst\
    \ \u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF\u3078\u6D41\u305B\u308B\u91CF\
    (df)\u3092\u6C7A\u5B9A\u3059\u308B\u3002\n        Capacity df = flow;\n      \
    \  for (int cur = dst; cur != src; cur = prev_node[cur]) {\n          df = std::min(df,\
    \ g_[prev_node[cur]][prev_edge[cur]].cap);\n        }\n\n        flow -= df;\n\
    \        ret += df * h[dst];\n\n        // cap\u306E\u66F4\u65B0\n        for\
    \ (int cur = dst; cur != src; cur = prev_node[cur]) {\n          edge &e = g_[prev_node[cur]][prev_edge[cur]];\n\
    \          e.cap -= df;\n          g_[cur][e.rev].cap += df;\n        }\n    \
    \  }\n\n      return {f - flow, ret};\n    }\n\n    std::vector<edge> edges()\
    \ const {\n      std::vector<edge> ret;\n      for (auto &v : g_) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n\
    #line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 6 \"\
    Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename T, size_t...\
    \ I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>)\
    \ {\n    (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream &operator>>(std::istream\
    \ &s, std::pair<T, U> &value) {\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename... Args>\n  std::istream &operator>>(std::istream\
    \ &s, std::tuple<Args...> &value) {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
    \    return s;\n  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuples {\n\
    \    struct iter {\n      using value_type = std::tuple<Args...>;\n      value_type\
    \ value;\n      bool fetched = false;\n      int N, c = 0;\n\n      value_type\
    \ operator*() {\n        if (not fetched) {\n          std::cin >> value;\n  \
    \      }\n        return value;\n      }\n\n      void operator++() {\n      \
    \  ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N) : N(N) {}\n    };\n\n\
    \    int N;\n\n  public:\n    InputTuples(int N) : N(N) {}\n\n    iter begin()\
    \ const { return iter(N); }\n    iter end() const { return iter(N); }\n  };\n\n\
    \  template <typename... Args>\n  auto input_tuples(int N) {\n    return InputTuples<Args...>(N);\n\
    \  }\n}  // namespace haar_lib\n#line 6 \"test/aoj/GRL_6_B/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main() {\n  int V, E, F;\n  std::cin >> V >> E\
    \ >> F;\n\n  hl::minimum_cost_flow<int, int> f(V);\n\n  for (auto [u, v, c, d]\
    \ : hl::input_tuples<int, int, int, int>(E)) {\n    f.add_edge(u, v, c, d);\n\
    \  }\n\n  auto [flow, ret] = f.min_cost_flow(0, V - 1, F);\n  if (flow == F) {\n\
    \    std::cout << ret << std::endl;\n  } else {\n    std::cout << -1 << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Flow/minimum_cost_flow.cpp\"\n\
    #include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main()\
    \ {\n  int V, E, F;\n  std::cin >> V >> E >> F;\n\n  hl::minimum_cost_flow<int,\
    \ int> f(V);\n\n  for (auto [u, v, c, d] : hl::input_tuples<int, int, int, int>(E))\
    \ {\n    f.add_edge(u, v, c, d);\n  }\n\n  auto [flow, ret] = f.min_cost_flow(0,\
    \ V - 1, F);\n  if (flow == F) {\n    std::cout << ret << std::endl;\n  } else\
    \ {\n    std::cout << -1 << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Flow/minimum_cost_flow.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B/main.test.cpp
- /verify/test/aoj/GRL_6_B/main.test.cpp.html
title: test/aoj/GRL_6_B/main.test.cpp
---
