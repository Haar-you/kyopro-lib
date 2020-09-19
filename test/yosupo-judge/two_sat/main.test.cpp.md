---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/two_sat.cpp
    title: 2-SAT
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':x:'
    path: Mylib/Graph/TopologicalSort/topological_sort.cpp
    title: Topological sort
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: Mylib/IO/join.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo-judge/two_sat/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <vector>\n#line 3 \"Mylib/Graph/two_sat.cpp\"\n#include <optional>\n\
    #include <cassert>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include <algorithm>\n#line 5 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<bool> visit(n);\n\
    \    std::vector<int> check(n);\n    std::vector<int> result(n, -1);\n\n    auto\
    \ dfs =\n      [&](auto &f, int cur) -> void {\n        visit[cur] = true;\n \
    \       for(const auto &e : g[cur]){\n          if(not visit[e.to]) f(f, e.to);\n\
    \        }\n        check.push_back(cur);\n      };\n\n    for(int i = 0; i <\
    \ n; ++i) if(not visit[i]) dfs(dfs, i);\n\n    std::reverse(check.begin(), check.end());\n\
    \n    graph<T> rg(n);\n\n    auto rdfs =\n      [&](auto &f, int cur, int i) ->\
    \ void {\n        result[cur] = i;\n        for(const auto &e : rg[cur]){\n  \
    \        if(result[e.to] == -1) f(f, e.to, i);\n        }\n      };\n\n    for(int\
    \ i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from,\
    \ e.cost);\n\n    int i = 0;\n    for(auto c : check) if(result[c] == -1) rdfs(rdfs,\
    \ c, i), ++i;\n\n    return std::make_pair(result, i);\n  }\n}\n#line 4 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n#include <queue>\n#line 6 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ topological_sort(const graph<T> &g){\n    const int n = g.size();\n    std::vector<int>\
    \ indeg(n);\n\n    for(int i = 0; i < n; ++i){\n      for(auto &e : g[i]){\n \
    \       ++indeg[e.to];\n      }\n    }\n\n    std::queue<int> q;\n    for(int\
    \ i = 0; i < n; ++i){\n      if(indeg[i] == 0) q.push(i);\n    }\n\n    std::vector<int>\
    \ ret;\n    while(not q.empty()){\n      int cur = q.front(); q.pop();\n     \
    \ ret.push_back(cur);\n      for(auto &e : g[cur]){\n        --indeg[e.to];\n\
    \        if(indeg[e.to] == 0){\n          q.push(e.to);\n        }\n      }\n\
    \    }\n\n    if((int)ret.size() == n){\n      return {ret};\n    }else{\n   \
    \   return std::nullopt;\n    }\n  }\n}\n#line 8 \"Mylib/Graph/two_sat.cpp\"\n\
    \nnamespace haar_lib {\n  class two_sat {\n    const int n;\n    graph<int> g;\n\
    \n    int f(int i){\n      assert(i != 0);\n      assert(std::abs(i) <= n);\n\
    \      if(i > 0) return i - 1;\n      else return std::abs(i) - 1 + n;\n    }\n\
    \n  public:\n    two_sat(int n): n(n), g(2 * n){}\n\n    /**\n     * @note a\u2192\
    b\u3092\u5C0E\u5165\u3059\u308B\n     */\n    void add_if(int a, int b){\n   \
    \   g.add_edge(f(a), f(b), 1);\n    }\n\n    /**\n     * @note a\u2228b\u3092\u5C0E\
    \u5165\u3059\u308B\n     * @note a \u2228 b <=> (!a => b) \u2227 (!b => a)\n \
    \    */\n    void add_or(int a, int b){\n      add_if(-a, b);\n      add_if(-b,\
    \ a);\n    }\n\n    /**\n     * @note \xAC(a\u2227b)\u3092\u5C0E\u5165\u3059\u308B\
    \n     * @note !(A \u2227 B) <=> (!A \u2228 !B)\n     */\n    void not_coexist(int\
    \ a, int b){\n      add_or(-a, -b);\n    }\n\n  public:\n    std::optional<std::vector<bool>>\
    \ solve() const {\n      auto [scc, m] = strongly_connected_components(g);\n\n\
    \      for(int i = 0; i < n; ++i){\n        if(scc[i] == scc[i + n]) return {};\n\
    \      }\n\n      graph<int> g2(m);\n\n      for(int i = 0; i < 2 * n; ++i){\n\
    \        for(auto &e : g[i]){\n          if(scc[e.from] != scc[e.to]){\n     \
    \       g2.add_edge(scc[e.from], scc[e.to], 1);\n          }\n        }\n    \
    \  }\n\n      auto ts = *topological_sort(g2);\n\n      std::vector<int> r(m);\n\
    \      for(int i = 0; i < m; ++i) r[ts[i]] = i;\n\n      std::vector<bool> ret(n);\n\
    \      for(int i = 0; i < n; ++i) ret[i] = r[scc[i]] > r[scc[i + n]];\n\n    \
    \  return {ret};\n    }\n  };\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n\
    #line 5 \"Mylib/IO/join.cpp\"\n\nnamespace haar_lib {\n  template <typename Iter>\n\
    \  std::string join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 9 \"test/yosupo-judge/two_sat/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::string p, cnf;\n  int N, M;\n  std::cin\
    \ >> p >> cnf >> N >> M;\n\n  hl::two_sat sat(N);\n\n  for(auto [a, b, c] : hl::input_tuples<int,\
    \ int, int>(M)){\n    sat.add_or(a, b);\n  }\n\n  if(auto res = sat.solve(); res){\n\
    \    std::vector<int> ans(N);\n    for(int i = 0; i < N; ++i) ans[i] = (*res)[i]\
    \ ? i + 1 : -(i + 1);\n\n    std::cout\n      << \"s SATISFIABLE\" << std::endl\n\
    \      << \"v \" << hl::join(ans.begin(), ans.end()) << \" \" << 0 << std::endl;\n\
    \  }else{\n    std::cout << \"s UNSATISFIABLE\" << std::endl;\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <iostream>\n\
    #include <string>\n#include <vector>\n#include \"Mylib/Graph/two_sat.cpp\"\n#include\
    \ \"Mylib/IO/join.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  std::string p, cnf;\n  int N, M;\n  std::cin >>\
    \ p >> cnf >> N >> M;\n\n  hl::two_sat sat(N);\n\n  for(auto [a, b, c] : hl::input_tuples<int,\
    \ int, int>(M)){\n    sat.add_or(a, b);\n  }\n\n  if(auto res = sat.solve(); res){\n\
    \    std::vector<int> ans(N);\n    for(int i = 0; i < N; ++i) ans[i] = (*res)[i]\
    \ ? i + 1 : -(i + 1);\n\n    std::cout\n      << \"s SATISFIABLE\" << std::endl\n\
    \      << \"v \" << hl::join(ans.begin(), ans.end()) << \" \" << 0 << std::endl;\n\
    \  }else{\n    std::cout << \"s UNSATISFIABLE\" << std::endl;\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Graph/two_sat.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  - Mylib/Graph/TopologicalSort/topological_sort.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/two_sat/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/two_sat/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/two_sat/main.test.cpp
- /verify/test/yosupo-judge/two_sat/main.test.cpp.html
title: test/yosupo-judge/two_sat/main.test.cpp
---
