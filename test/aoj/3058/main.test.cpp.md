---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Flow/ford_fulkerson.cpp
    title: Ford-Fulkerson algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/project_selection_problem.cpp
    title: Project selection problem
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058
  bundledCode: "#line 1 \"test/aoj/3058/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058\"\
    \n\n#include <iostream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    #line 2 \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#line 5 \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n\nnamespace haar_lib\
    \ {\n  namespace ford_fulkerson_impl {\n    template <typename T>\n    struct\
    \ edge {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n      edge(int\
    \ from, int to, int rev, T cap, bool is_rev) : from(from), to(to), rev(rev), cap(cap),\
    \ is_rev(is_rev) {}\n    };\n  }  // namespace ford_fulkerson_impl\n\n  template\
    \ <typename T>\n  class ford_fulkerson {\n  public:\n    using edge          =\
    \ ford_fulkerson_impl::edge<T>;\n    using capacity_type = T;\n\n  private:\n\
    \    int size_;\n    std::vector<std::vector<edge>> g_;\n    std::vector<bool>\
    \ visit_;\n\n    T dfs(int from, int to, T flow) {\n      if (from == to) return\
    \ flow;\n      visit_[from] = true;\n\n      for (auto &e : g_[from]) {\n    \
    \    if (not visit_[e.to] and e.cap > 0) {\n          T d = dfs(e.to, to, std::min(flow,\
    \ e.cap));\n          if (d > 0) {\n            e.cap -= d;\n            g_[e.to][e.rev].cap\
    \ += d;\n            return d;\n          }\n        }\n      }\n      return\
    \ 0;\n    }\n\n  public:\n    ford_fulkerson() {}\n    ford_fulkerson(int size)\
    \ : size_(size), g_(size), visit_(size) {}\n\n    void add_edge(int from, int\
    \ to, T c) {\n      assert(0 <= from and from < size_);\n      assert(0 <= to\
    \ and to < size_);\n      g_[from].emplace_back(from, to, (int) g_[to].size(),\
    \ c, false);\n      g_[to].emplace_back(to, from, (int) g_[from].size() - 1, 0,\
    \ true);\n    }\n\n    void reset_flow() {\n      for (auto &v : g_) {\n     \
    \   for (auto &e : v) {\n          if (e.is_rev) {\n            g_[e.to][e.rev].cap\
    \ += e.cap;\n            e.cap = 0;\n          }\n        }\n      }\n    }\n\n\
    \    T max_flow(int s, int t) {\n      assert(0 <= s and s < size_);\n      assert(0\
    \ <= t and t < size_);\n\n      T ret = 0;\n\n      while (1) {\n        visit_.assign(size_,\
    \ false);\n        T flow = dfs(s, t, std::numeric_limits<T>::max());\n      \
    \  if (flow == 0) return ret;\n        ret += flow;\n      }\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for (auto &v : g_) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n\
    #line 3 \"Mylib/Graph/project_selection_problem.cpp\"\n#include <limits>\n#include\
    \ <tuple>\n#line 7 \"Mylib/Graph/project_selection_problem.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, typename Flow>\n  class project_selection_problem\
    \ {\n    int N_, s_, t_;\n    std::vector<std::tuple<int, int, T>> g_;\n    T\
    \ default_gain_;\n    int nodes_;\n\n    constexpr static T INF = std::numeric_limits<T>::max();\n\
    \n  public:\n    project_selection_problem() {}\n    project_selection_problem(int\
    \ N) : N_(N), s_(N), t_(N + 1), default_gain_(0), nodes_(N + 2) {}\n\n    void\
    \ penalty_if_red(int i, T c) {\n      assert(c >= 0);\n      assert(0 <= i and\
    \ i < N_);\n      g_.emplace_back(i, t_, c);\n    }\n\n    void gain_if_red(int\
    \ i, T c) {\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n      default_gain_\
    \ += c;\n      penalty_if_blue(i, c);\n    }\n\n    void penalty_if_blue(int i,\
    \ T c) {\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n      g_.emplace_back(s_,\
    \ i, c);\n    }\n\n    void gain_if_blue(int i, T c) {\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      default_gain_ += c;\n      penalty_if_red(i,\
    \ c);\n    }\n\n    void penalty_if_red_blue(int i, int j, T c) {\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      g_.emplace_back(i, j, c);\n    }\n\n    void penalty_if_different(int i,\
    \ int j, T c) {\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n   \
    \   assert(0 <= j and j < N_);\n      g_.emplace_back(i, j, c);\n      g_.emplace_back(j,\
    \ i, c);\n    }\n\n    void must_be_red(int i) {\n      assert(0 <= i and i <\
    \ N_);\n      penalty_if_blue(i, INF);\n    }\n\n    void must_be_blue(int i)\
    \ {\n      assert(0 <= i and i < N_);\n      penalty_if_red(i, INF);\n    }\n\n\
    \    void if_red_then_must_be_red(int i, int j) {\n      assert(0 <= i and i <\
    \ N_);\n      assert(0 <= j and j < N_);\n      penalty_if_red_blue(i, j, INF);\n\
    \    }\n\n    void gain_if_red_red(int i, int j, T c) {\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n      default_gain_\
    \ += c;\n      int w = nodes_++;\n\n      g_.emplace_back(s_, w, c);\n      g_.emplace_back(w,\
    \ i, INF);\n      g_.emplace_back(w, j, INF);\n    }\n\n    void gain_if_blue_blue(int\
    \ i, int j, T c) {\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n\
    \      assert(0 <= j and j < N_);\n      default_gain_ += c;\n      int w = nodes_++;\n\
    \n      g_.emplace_back(w, t_, c);\n      g_.emplace_back(i, w, INF);\n      g_.emplace_back(j,\
    \ w, INF);\n    }\n\n    T solve() {\n      Flow flow(nodes_);\n      for (auto\
    \ [i, j, w] : g_) flow.add_edge(i, j, w);\n      return default_gain_ - flow.max_flow(s_,\
    \ t_);\n    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0)...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream &operator>>(std::istream &s, std::pair<T, U> &value) {\n    s\
    \ >> value.first >> value.second;\n    return s;\n  }\n\n  template <typename...\
    \ Args>\n  std::istream &operator>>(std::istream &s, std::tuple<Args...> &value)\
    \ {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
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
    \  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N) {\n\
    \    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 11 \"test/aoj/3058/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  int N, M;\n  std::cin >> N >> M;\n  std::string\
    \ U;\n  std::cin >> U;\n\n  auto A = hl::input_vector<int>(N);\n\n  hl::project_selection_problem<int,\
    \ hl::ford_fulkerson<int>> psp(N);\n  // red: right, blue: left\n\n  for (int\
    \ i = 0; i < N; ++i) {\n    if (U[i] == 'R') {\n      psp.penalty_if_blue(i, A[i]);\n\
    \    } else {\n      psp.penalty_if_red(i, A[i]);\n    }\n  }\n\n  for (auto [s,\
    \ t, b] : hl::input_tuples<int, int, int>(M)) {\n    --s, --t;\n    if (s > t)\
    \ std::swap(s, t);\n    psp.penalty_if_red_blue(s, t, b);\n  }\n\n  auto ans =\
    \ -psp.solve();\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058\"\
    \n\n#include <iostream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    #include \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n#include \"Mylib/Graph/project_selection_problem.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int N, M;\n  std::cin >> N >>\
    \ M;\n  std::string U;\n  std::cin >> U;\n\n  auto A = hl::input_vector<int>(N);\n\
    \n  hl::project_selection_problem<int, hl::ford_fulkerson<int>> psp(N);\n  //\
    \ red: right, blue: left\n\n  for (int i = 0; i < N; ++i) {\n    if (U[i] == 'R')\
    \ {\n      psp.penalty_if_blue(i, A[i]);\n    } else {\n      psp.penalty_if_red(i,\
    \ A[i]);\n    }\n  }\n\n  for (auto [s, t, b] : hl::input_tuples<int, int, int>(M))\
    \ {\n    --s, --t;\n    if (s > t) std::swap(s, t);\n    psp.penalty_if_red_blue(s,\
    \ t, b);\n  }\n\n  auto ans = -psp.solve();\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Flow/ford_fulkerson.cpp
  - Mylib/Graph/project_selection_problem.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/3058/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3058/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3058/main.test.cpp
- /verify/test/aoj/3058/main.test.cpp.html
title: test/aoj/3058/main.test.cpp
---
