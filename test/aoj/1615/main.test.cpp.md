---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Flow/dinic.cpp
    title: Dinic algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Flow/max_flow_with_lower_bound.cpp
    title: Maximum flow with lower bound
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
  bundledCode: "#line 1 \"test/aoj/1615/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\"\
    \n\n#include <iostream>\n#line 3 \"Mylib/IO/input_tuple_vector.cpp\"\n#include\
    \ <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    \nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 2 \"Mylib/Graph/Flow/max_flow_with_lower_bound.cpp\"\
    \n#include <optional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename Flow>\n  class max_flow_with_lower_bound {\n    using edge = typename\
    \ Flow::edge;\n    using capacity_type = typename Flow::capacity_type;\n\n   \
    \ int N_, S_, T_;\n    Flow flow_;\n    capacity_type min_sum_;\n\n  public:\n\
    \    max_flow_with_lower_bound(){}\n    max_flow_with_lower_bound(int N): N_(N),\
    \ S_(N), T_(N + 1), flow_(N + 2), min_sum_(0){}\n\n    void add_edge(int from,\
    \ int to, capacity_type lb, capacity_type ub){\n      assert(0 <= from and from\
    \ < N_);\n      assert(0 <= to and to < N_);\n      assert(0 <= lb and lb <= ub);\n\
    \n      flow_.add_edge(from, to, ub - lb);\n      flow_.add_edge(from, T_, lb);\n\
    \      flow_.add_edge(S_, to, lb);\n\n      min_sum_ += lb;\n    }\n\n    std::optional<capacity_type>\
    \ max_flow(int s, int t){\n      assert(0 <= s and s < N_);\n      assert(0 <=\
    \ t and t < N_);\n\n      auto a = flow_.max_flow(S_, T_);\n      auto b = flow_.max_flow(s,\
    \ T_);\n      auto c = flow_.max_flow(S_, t);\n      auto d = flow_.max_flow(s,\
    \ t);\n\n      if(a + b == min_sum_ and a + c == min_sum_) return b + d;\n   \
    \   return std::nullopt;\n    }\n  };\n}\n#line 4 \"Mylib/Graph/Flow/dinic.cpp\"\
    \n#include <queue>\n#include <algorithm>\n#line 7 \"Mylib/Graph/Flow/dinic.cpp\"\
    \n\nnamespace haar_lib {\n  namespace dinic_impl {\n    template <typename T>\n\
    \    struct edge {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n\
    \      edge(int from, int to, int rev, T cap, bool is_rev):\n        from(from),\
    \ to(to), rev(rev), cap(cap), is_rev(is_rev){}\n    };\n  }\n\n  template <typename\
    \ T>\n  class dinic {\n  public:\n    using edge = dinic_impl::edge<T>;\n    using\
    \ capacity_type = T;\n\n  private:\n    int size_;\n    std::vector<std::vector<edge>>\
    \ g_;\n    std::vector<int> level_;\n\n    bool build_level(int s, int t){\n \
    \     std::fill(level_.begin(), level_.end(), 0);\n      level_[s] = 1;\n    \
    \  std::queue<int> q;\n      q.push(s);\n      while(not q.empty()){\n       \
    \ int cur = q.front(); q.pop();\n        for(auto &e : g_[cur]){\n          if(level_[e.to]\
    \ == 0 and e.cap > 0){\n            level_[e.to] = level_[e.from] + 1;\n     \
    \       q.push(e.to);\n          }\n        }\n      }\n      return level_[t]\
    \ != 0;\n    }\n\n    void dfs(std::vector<edge*> &path, T &flow, int cur, int\
    \ t){\n      if(cur == t){\n        T f = std::numeric_limits<T>::max();\n\n \
    \       for(auto e : path){\n          f = std::min(f, (*e).cap);\n        }\n\
    \n        for(auto e : path){\n          (*e).cap -= f;\n          g_[e->to][e->rev].cap\
    \ += f;\n        }\n\n        flow += f;\n      }else{\n        for(auto &e :\
    \ g_[cur]){\n          if(e.cap > 0 and level_[e.to] > level_[e.from]){\n    \
    \        path.emplace_back(&e);\n            dfs(path, flow, e.to, t);\n     \
    \       path.pop_back();\n          }\n        }\n      }\n    }\n\n  public:\n\
    \    dinic(){}\n    dinic(int size): size_(size), g_(size), level_(size){}\n\n\
    \    void add_edge(int from, int to, T c){\n      assert(0 <= from and from <\
    \ size_);\n      assert(0 <= to and to < size_);\n      g_[from].emplace_back(from,\
    \ to, (int)g_[to].size(), c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size()\
    \ - 1, 0, true);\n    }\n\n    T max_flow(int s, int t){\n      assert(0 <= s\
    \ and s < size_);\n      assert(0 <= t and t < size_);\n\n      T f = 0;\n   \
    \   while(build_level(s, t)){\n        T a = 0;\n        std::vector<edge*> path;\n\
    \        dfs(path, a, s, t);\n        f += a;\n      }\n      return f;\n    }\n\
    \n    std::vector<edge> edges() const {\n      std::vector<edge> ret;\n      for(auto\
    \ &v : g_) ret.insert(ret.end(), v.begin(), v.end());\n      return ret;\n   \
    \ }\n  };\n}\n#line 7 \"test/aoj/1615/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ n, m;\n\n  while(std::cin >> n >> m, n){\n    auto [u, v] = hl::input_tuple_vector<int,\
    \ int>(m);\n    for(auto &x : u) --x;\n    for(auto &x : v) --x;\n\n    auto check\
    \ =\n      [&](int lb, int ub) -> bool {\n        hl::max_flow_with_lower_bound<hl::dinic<int>>\
    \ flow(n + m + 2);\n\n        const int s = n + m, t = s + 1;\n\n        for(int\
    \ i = 0; i < m; ++i){\n          flow.add_edge(s, i, 1, 1);\n          flow.add_edge(i,\
    \ m + u[i], 0, 1);\n          flow.add_edge(i, m + v[i], 0, 1);\n        }\n\n\
    \        for(int i = 0; i < n; ++i){\n          flow.add_edge(m + i, t, lb, ub);\n\
    \        }\n\n        return flow.max_flow(s, t).value_or(-1) == m;\n      };\n\
    \n    int lb = 0, ub = n;\n    for(int l = 0, r = 0; r <= n; ++r){\n      while(l\
    \ <= r and check(l, r)){\n        lb = l;\n        ub = r;\n        ++l;\n   \
    \   }\n    }\n\n    std::cout << lb << \" \" << ub << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\"\
    \n\n#include <iostream>\n#include \"Mylib/IO/input_tuple_vector.cpp\"\n#include\
    \ \"Mylib/Graph/Flow/max_flow_with_lower_bound.cpp\"\n#include \"Mylib/Graph/Flow/dinic.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n, m;\n\n  while(std::cin >> n >> m, n){\n    auto [u, v] = hl::input_tuple_vector<int,\
    \ int>(m);\n    for(auto &x : u) --x;\n    for(auto &x : v) --x;\n\n    auto check\
    \ =\n      [&](int lb, int ub) -> bool {\n        hl::max_flow_with_lower_bound<hl::dinic<int>>\
    \ flow(n + m + 2);\n\n        const int s = n + m, t = s + 1;\n\n        for(int\
    \ i = 0; i < m; ++i){\n          flow.add_edge(s, i, 1, 1);\n          flow.add_edge(i,\
    \ m + u[i], 0, 1);\n          flow.add_edge(i, m + v[i], 0, 1);\n        }\n\n\
    \        for(int i = 0; i < n; ++i){\n          flow.add_edge(m + i, t, lb, ub);\n\
    \        }\n\n        return flow.max_flow(s, t).value_or(-1) == m;\n      };\n\
    \n    int lb = 0, ub = n;\n    for(int l = 0, r = 0; r <= n; ++r){\n      while(l\
    \ <= r and check(l, r)){\n        lb = l;\n        ub = r;\n        ++l;\n   \
    \   }\n    }\n\n    std::cout << lb << \" \" << ub << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/Graph/Flow/max_flow_with_lower_bound.cpp
  - Mylib/Graph/Flow/dinic.cpp
  isVerificationFile: true
  path: test/aoj/1615/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1615/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1615/main.test.cpp
- /verify/test/aoj/1615/main.test.cpp.html
title: test/aoj/1615/main.test.cpp
---
