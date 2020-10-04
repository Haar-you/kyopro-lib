---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Flow/ford_fulkerson.cpp
    title: Ford-Fulkerson algorithm
  - icon: ':question:'
    path: Mylib/Graph/project_selection_problem.cpp
    title: Project selection problem
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
  bundledCode: "#line 1 \"test/aoj/2903/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903\"\
    \n\n#include <iostream>\n#include <vector>\n#include <string>\n#line 3 \"Mylib/Graph/project_selection_problem.cpp\"\
    \n#include <utility>\n#include <cassert>\n#include <limits>\n#include <tuple>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Flow>\n  class project_selection_problem\
    \ {\n    int N_, s_, t_;\n    std::vector<std::tuple<int, int, T>> g_;\n    T\
    \ default_gain_;\n    int nodes_;\n\n    constexpr static T INF = std::numeric_limits<T>::max();\n\
    \n  public:\n    project_selection_problem(){}\n    project_selection_problem(int\
    \ N): N_(N), s_(N), t_(N + 1), default_gain_(0), nodes_(N + 2){}\n\n    void penalty_if_red(int\
    \ i, T c){\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n      g_.emplace_back(i,\
    \ t_, c);\n    }\n\n    void gain_if_red(int i, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      default_gain_ += c;\n      penalty_if_blue(i,\
    \ c);\n    }\n\n    void penalty_if_blue(int i, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      g_.emplace_back(s_, i, c);\n    }\n\n\
    \    void gain_if_blue(int i, T c){\n      assert(c >= 0);\n      assert(0 <=\
    \ i and i < N_);\n      default_gain_ += c;\n      penalty_if_red(i, c);\n   \
    \ }\n\n    void penalty_if_red_blue(int i, int j, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n      g_.emplace_back(i,\
    \ j, c);\n    }\n\n    void penalty_if_different(int i, int j, T c){\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      g_.emplace_back(i, j, c);\n      g_.emplace_back(j, i, c);\n    }\n\n \
    \   void must_be_red(int i){\n      assert(0 <= i and i < N_);\n      penalty_if_blue(i,\
    \ INF);\n    }\n\n    void must_be_blue(int i){\n      assert(0 <= i and i < N_);\n\
    \      penalty_if_red(i, INF);\n    }\n\n    void if_red_then_must_be_red(int\
    \ i, int j){\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      penalty_if_red_blue(i, j, INF);\n    }\n\n    void gain_if_red_red(int\
    \ i, int j, T c){\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n \
    \     assert(0 <= j and j < N_);\n      default_gain_ += c;\n      int w = nodes_++;\n\
    \n      g_.emplace_back(s_, w, c);\n      g_.emplace_back(w, i, INF);\n      g_.emplace_back(w,\
    \ j, INF);\n    }\n\n    void gain_if_blue_blue(int i, int j, T c){\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      default_gain_ += c;\n      int w = nodes_++;\n\n      g_.emplace_back(w,\
    \ t_, c);\n      g_.emplace_back(i, w, INF);\n      g_.emplace_back(j, w, INF);\n\
    \    }\n\n    T solve(){\n      Flow flow(nodes_);\n      for(auto [i, j, w] :\
    \ g_) flow.add_edge(i, j, w);\n      return default_gain_ - flow.max_flow(s_,\
    \ t_);\n    }\n  };\n}\n#line 3 \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n#include\
    \ <algorithm>\n\nnamespace haar_lib {\n  namespace ford_fulkerson_impl {\n   \
    \ template <typename T>\n    struct edge {\n      int from, to, rev;\n      T\
    \ cap;\n      bool is_rev;\n      edge(int from, int to, int rev, T cap, bool\
    \ is_rev):\n        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n\
    \    };\n  }\n\n  template <typename T>\n  class ford_fulkerson {\n  public:\n\
    \    using edge = ford_fulkerson_impl::edge<T>;\n    using capacity_type = T;\n\
    \n  private:\n    int size_;\n    std::vector<std::vector<edge>> g_;\n    std::vector<bool>\
    \ visit_;\n\n    T dfs(int from, int to, T flow){\n      if(from == to) return\
    \ flow;\n      visit_[from] = true;\n\n      for(auto &e : g_[from]){\n      \
    \  if(not visit_[e.to] and e.cap > 0){\n          T d = dfs(e.to, to, std::min(flow,\
    \ e.cap));\n          if(d > 0){\n            e.cap -= d;\n            g_[e.to][e.rev].cap\
    \ += d;\n            return d;\n          }\n        }\n      }\n      return\
    \ 0;\n    }\n\n  public:\n    ford_fulkerson(){}\n    ford_fulkerson(int size):\
    \ size_(size), g_(size), visit_(size){}\n\n    void add_edge(int from, int to,\
    \ T c){\n      g_[from].emplace_back(from, to, (int)g_[to].size(), c, false);\n\
    \      g_[to].emplace_back(to, from, (int)g_[from].size() - 1, 0, true);\n   \
    \ }\n\n    void reset_flow(){\n      for(auto &v : g_){\n        for(auto &e :\
    \ v){\n          if(e.is_rev){\n            g_[e.to][e.rev].cap += e.cap;\n  \
    \          e.cap = 0;\n          }\n        }\n      }\n    }\n\n    T max_flow(int\
    \ s, int t){\n      T ret = 0;\n\n      while(1){\n        visit_.assign(size_,\
    \ false);\n        T flow = dfs(s, t, std::numeric_limits<T>::max());\n      \
    \  if(flow == 0) return ret;\n        ret += flow;\n      }\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for(auto &v : g_) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 9 \"test/aoj/2903/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int R, C; std::cin >> R >> C;\n\n  auto S = hl::input_vector<std::string>(R);\n\
    \n  hl::project_selection_problem<int, hl::ford_fulkerson<int>> psp(R * C);\n\
    \  // red: horizontal\n  // blue: vertical\n\n  for(int i = 0; i < R; ++i){\n\
    \    for(int j = 0; j < C; ++j){\n      if(S[i][j] == '#'){\n        int k = i\
    \ * C + j;\n        psp.penalty_if_red(k, 1);\n        psp.penalty_if_blue(k,\
    \ 1);\n      }\n    }\n  }\n\n  for(int i = 1; i < R; ++i){\n    for(int j = 0;\
    \ j < C; ++j){\n      if(S[i][j] == '#' and S[i - 1][j] == '#'){\n        psp.gain_if_blue_blue(i\
    \ * C + j, (i - 1) * C + j, 1);\n      }\n    }\n  }\n\n  for(int i = 0; i < R;\
    \ ++i){\n    for(int j = 1; j < C; ++j){\n      if(S[i][j] == '#' and S[i][j -\
    \ 1] == '#'){\n        psp.gain_if_red_red(i * C + j, i * C + (j - 1), 1);\n \
    \     }\n    }\n  }\n\n  auto ans = -psp.solve();\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903\"\
    \n\n#include <iostream>\n#include <vector>\n#include <string>\n#include \"Mylib/Graph/project_selection_problem.cpp\"\
    \n#include \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int R, C; std::cin >> R >> C;\n\
    \n  auto S = hl::input_vector<std::string>(R);\n\n  hl::project_selection_problem<int,\
    \ hl::ford_fulkerson<int>> psp(R * C);\n  // red: horizontal\n  // blue: vertical\n\
    \n  for(int i = 0; i < R; ++i){\n    for(int j = 0; j < C; ++j){\n      if(S[i][j]\
    \ == '#'){\n        int k = i * C + j;\n        psp.penalty_if_red(k, 1);\n  \
    \      psp.penalty_if_blue(k, 1);\n      }\n    }\n  }\n\n  for(int i = 1; i <\
    \ R; ++i){\n    for(int j = 0; j < C; ++j){\n      if(S[i][j] == '#' and S[i -\
    \ 1][j] == '#'){\n        psp.gain_if_blue_blue(i * C + j, (i - 1) * C + j, 1);\n\
    \      }\n    }\n  }\n\n  for(int i = 0; i < R; ++i){\n    for(int j = 1; j <\
    \ C; ++j){\n      if(S[i][j] == '#' and S[i][j - 1] == '#'){\n        psp.gain_if_red_red(i\
    \ * C + j, i * C + (j - 1), 1);\n      }\n    }\n  }\n\n  auto ans = -psp.solve();\n\
    \  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/project_selection_problem.cpp
  - Mylib/Graph/Flow/ford_fulkerson.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/2903/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2903/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2903/main.test.cpp
- /verify/test/aoj/2903/main.test.cpp.html
title: test/aoj/2903/main.test.cpp
---
