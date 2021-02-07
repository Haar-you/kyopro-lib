---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Flow/dinic.cpp
    title: Dinic algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A/main.dinic.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n#include\
    \ <iostream>\n#include <climits>\n#line 2 \"Mylib/Graph/Flow/dinic.cpp\"\n#include\
    \ <vector>\n#include <utility>\n#include <queue>\n#include <algorithm>\n#include\
    \ <cassert>\n\nnamespace haar_lib {\n  namespace dinic_impl {\n    template <typename\
    \ T>\n    struct edge {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n\
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
    \ }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6\
    \ \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/GRL_6_A/main.dinic.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int V, E; std::cin >> V >> E;\n\n  hl::dinic<int>\
    \ f(V);\n\n  for(auto [s, t, c] : hl::input_tuples<int, int, int>(E)){\n    f.add_edge(s,\
    \ t, c);\n  }\n\n  auto ans = f.max_flow(0, V - 1);\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n#include <climits>\n#include \"Mylib/Graph/Flow/dinic.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int V, E; std::cin >> V >> E;\n\n  hl::dinic<int> f(V);\n\n  for(auto [s, t,\
    \ c] : hl::input_tuples<int, int, int>(E)){\n    f.add_edge(s, t, c);\n  }\n\n\
    \  auto ans = f.max_flow(0, V - 1);\n  std::cout << ans << std::endl;\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Flow/dinic.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A/main.dinic.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A/main.dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A/main.dinic.test.cpp
- /verify/test/aoj/GRL_6_A/main.dinic.test.cpp.html
title: test/aoj/GRL_6_A/main.dinic.test.cpp
---
