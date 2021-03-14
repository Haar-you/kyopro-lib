---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/two_sat.cpp
    title: 2-SAT
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> ret(n), low(n,\
    \ -1), ord(n, -1), S;\n    std::vector<bool> check(n);\n    S.reserve(n);\n  \
    \  int t = 0;\n    int k = 0;\n\n    auto dfs =\n      [&](auto &dfs, int cur)\
    \ -> void {\n        low[cur] = ord[cur] = t++;\n        S.push_back(cur);\n \
    \       check[cur] = true;\n\n        for(auto &e : g[cur]){\n          if(ord[e.to]\
    \ == -1){\n            dfs(dfs, e.to);\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }else if(check[e.to]){\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }\n        }\n\n        if(low[cur] == ord[cur]){\n \
    \         while(true){\n            int u = S.back(); S.pop_back();\n        \
    \    check[u] = false;\n            ret[u] = k;\n            if(cur == u) break;\n\
    \          }\n          ++k;\n        }\n      };\n\n    for(int i = 0; i < n;\
    \ ++i){\n      if(ord[i] == -1){\n        t = 0;\n        dfs(dfs, i);\n     \
    \ }\n    }\n\n    for(auto &x : ret) x = k - 1 - x;\n\n    return std::make_pair(ret,\
    \ k);\n  }\n}\n#line 7 \"Mylib/Graph/two_sat.cpp\"\n\nnamespace haar_lib {\n \
    \ class two_sat {\n    int n_;\n    graph<int> g_;\n\n    int f(int i){\n    \
    \  assert(i != 0);\n      assert(std::abs(i) <= n_);\n      if(i > 0) return i\
    \ - 1;\n      else return std::abs(i) - 1 + n_;\n    }\n\n  public:\n    two_sat(){}\n\
    \    two_sat(int n): n_(n), g_(2 * n){}\n\n    /**\n     * @note a\u2192b\u3092\
    \u5C0E\u5165\u3059\u308B\n     */\n    void add_if(int a, int b){\n      g_.add_edge(f(a),\
    \ f(b), 1);\n    }\n\n    /**\n     * @note a\u2228b\u3092\u5C0E\u5165\u3059\u308B\
    \n     * @note a \u2228 b <=> (!a => b) \u2227 (!b => a)\n     */\n    void add_or(int\
    \ a, int b){\n      add_if(-a, b);\n      add_if(-b, a);\n    }\n\n    /**\n \
    \    * @note \xAC(a\u2227b)\u3092\u5C0E\u5165\u3059\u308B\n     * @note !(A \u2227\
    \ B) <=> (!A \u2228 !B)\n     */\n    void not_coexist(int a, int b){\n      add_or(-a,\
    \ -b);\n    }\n\n  public:\n    std::optional<std::vector<bool>> solve() const\
    \ {\n      auto [scc, m] = strongly_connected_components(g_);\n\n      for(int\
    \ i = 0; i < n_; ++i){\n        if(scc[i] == scc[i + n_]) return std::nullopt;\n\
    \      }\n\n      std::vector<bool> ret(n_);\n      for(int i = 0; i < n_; ++i)\
    \ ret[i] = scc[i] > scc[i + n_];\n\n      return ret;\n    }\n  };\n}\n#line 3\
    \ \"Mylib/IO/join.cpp\"\n#include <sstream>\n#line 5 \"Mylib/IO/join.cpp\"\n\n\
    namespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
  - Mylib/IO/join.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/two_sat/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/two_sat/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/two_sat/main.test.cpp
- /verify/test/yosupo-judge/two_sat/main.test.cpp.html
title: test/yosupo-judge/two_sat/main.test.cpp
---
