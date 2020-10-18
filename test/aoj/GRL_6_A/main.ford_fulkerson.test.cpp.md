---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Flow/ford_fulkerson.cpp
    title: Ford-Fulkerson algorithm
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n#include <climits>\n#line 2 \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  namespace ford_fulkerson_impl {\n    template <typename T>\n    struct\
    \ edge {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n      edge(int\
    \ from, int to, int rev, T cap, bool is_rev):\n        from(from), to(to), rev(rev),\
    \ cap(cap), is_rev(is_rev){}\n    };\n  }\n\n  template <typename T>\n  class\
    \ ford_fulkerson {\n  public:\n    using edge = ford_fulkerson_impl::edge<T>;\n\
    \    using capacity_type = T;\n\n  private:\n    int size_;\n    std::vector<std::vector<edge>>\
    \ g_;\n    std::vector<bool> visit_;\n\n    T dfs(int from, int to, T flow){\n\
    \      if(from == to) return flow;\n      visit_[from] = true;\n\n      for(auto\
    \ &e : g_[from]){\n        if(not visit_[e.to] and e.cap > 0){\n          T d\
    \ = dfs(e.to, to, std::min(flow, e.cap));\n          if(d > 0){\n            e.cap\
    \ -= d;\n            g_[e.to][e.rev].cap += d;\n            return d;\n      \
    \    }\n        }\n      }\n      return 0;\n    }\n\n  public:\n    ford_fulkerson(){}\n\
    \    ford_fulkerson(int size): size_(size), g_(size), visit_(size){}\n\n    void\
    \ add_edge(int from, int to, T c){\n      assert(0 <= from and from < size_);\n\
    \      assert(0 <= to and to < size_);\n      g_[from].emplace_back(from, to,\
    \ (int)g_[to].size(), c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size()\
    \ - 1, 0, true);\n    }\n\n    void reset_flow(){\n      for(auto &v : g_){\n\
    \        for(auto &e : v){\n          if(e.is_rev){\n            g_[e.to][e.rev].cap\
    \ += e.cap;\n            e.cap = 0;\n          }\n        }\n      }\n    }\n\n\
    \    T max_flow(int s, int t){\n      assert(0 <= s and s < size_);\n      assert(0\
    \ <= t and t < size_);\n\n      T ret = 0;\n\n      while(1){\n        visit_.assign(size_,\
    \ false);\n        T flow = dfs(s, t, std::numeric_limits<T>::max());\n      \
    \  if(flow == 0) return ret;\n        ret += flow;\n      }\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for(auto &v : g_) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp\"\n\
    \nnamespace hl = haar_lib;\n\nint main(){\n  int V, E; std::cin >> V >> E;\n\n\
    \  hl::ford_fulkerson<int> f(V);\n\n  for(auto [s, t, c] : hl::input_tuples<int,\
    \ int, int>(E)){\n    f.add_edge(s, t, c);\n  }\n\n  auto ans = f.max_flow(0,\
    \ V - 1);\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n#include <climits>\n#include \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int V, E; std::cin >> V >> E;\n\n  hl::ford_fulkerson<int> f(V);\n\n  for(auto\
    \ [s, t, c] : hl::input_tuples<int, int, int>(E)){\n    f.add_edge(s, t, c);\n\
    \  }\n\n  auto ans = f.max_flow(0, V - 1);\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Flow/ford_fulkerson.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
- /verify/test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp.html
title: test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
---
