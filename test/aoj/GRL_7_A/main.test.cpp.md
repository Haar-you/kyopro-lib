---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/Matching/bipartite_matching.cpp
    title: Maximum bipartite matching
  - icon: ':question:'
    path: Mylib/Graph/Flow/ford_fulkerson.cpp
    title: Ford-Fulkerson algorithm
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/aoj/GRL_7_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/Matching/bipartite_matching.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <climits>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename MaxFlow>\n  class bipartite_matching\
    \ {\n    int L, R, s, t;\n    MaxFlow f;\n\n  public:\n    bipartite_matching(int\
    \ L, int R): L(L), R(R), s(L + R), t(s + 1), f(L + R + 2){\n      for(int i =\
    \ 0; i < L; ++i) f.add_edge(s, i, 1);\n      for(int i = 0; i < R; ++i) f.add_edge(L\
    \ + i, t, 1);\n    }\n\n    void add_edge(int i, int j){\n      assert(0 <= i\
    \ and i < L and 0 <= j and j < R);\n      f.add_edge(i, L + j, 1);\n    }\n\n\
    \    int solve(){\n      return f.solve(s, t);\n    }\n\n    auto get_matching(){\n\
    \      const auto g = f.edges();\n      std::vector<std::pair<int, int>> ret;\n\
    \n      for(auto &e : g){\n        if(not e.is_rev and e.cap == 0 and e.from !=\
    \ s and e.to != t){\n          ret.emplace_back(e.from, e.to - L);\n        }\n\
    \      }\n\n      return ret;\n    }\n  };\n}\n#line 3 \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\
    \n#include <algorithm>\n\nnamespace haar_lib {\n  namespace ford_fulkerson_impl\
    \ {\n    template <typename T>\n    struct edge {\n      int from, to, rev;\n\
    \      T cap;\n      bool is_rev;\n      edge(int from, int to, int rev, T cap,\
    \ bool is_rev):\n        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n\
    \    };\n  }\n\n  template <typename T>\n  class ford_fulkerson {\n    using edge\
    \ = ford_fulkerson_impl::edge<T>;\n\n    int size;\n    std::vector<std::vector<edge>>\
    \ g;\n    std::vector<bool> visit;\n\n    T dfs(int from, int to, T flow){\n \
    \     if(from == to) return flow;\n      visit[from] = true;\n\n      for(auto\
    \ &e : g[from]){\n        if(!visit[e.to] and e.cap > 0){\n          T d = dfs(e.to,\
    \ to, std::min(flow, e.cap));\n          if(d > 0){\n            e.cap -= d;\n\
    \            g[e.to][e.rev].cap += d;\n            return d;\n          }\n  \
    \      }\n      }\n      return 0;\n    }\n\n  public:\n    ford_fulkerson(){}\n\
    \    ford_fulkerson(int size): size(size), g(size), visit(size){}\n\n    void\
    \ add_edge(int from, int to, T c){\n      g[from].emplace_back(from, to, (int)g[to].size(),\
    \ c, false);\n      g[to].emplace_back(to, from, (int)g[from].size() - 1, 0, true);\n\
    \    }\n\n    void reset_flow(){\n      for(auto &v : g){\n        for(auto &e\
    \ : v){\n          if(e.is_rev){\n            g[e.to][e.rev].cap += e.cap;\n \
    \           e.cap = 0;\n          }\n        }\n      }\n    }\n\n    T solve(int\
    \ s, int t){\n      T ret = 0;\n\n      while(1){\n        visit.assign(size,\
    \ false);\n        T flow = dfs(s, t, std::numeric_limits<T>::max());\n      \
    \  if(flow == 0) return ret;\n        ret += flow;\n      }\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for(auto &v : g) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ ... Args>\n  class InputTuples {\n    struct iter {\n      using value_type\
    \ = std::tuple<Args ...>;\n      value_type value;\n      bool fetched = false;\n\
    \      int N, c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n\
    \          std::cin >> value;\n        }\n        return value;\n      }\n\n \
    \     void operator++(){\n        ++c;\n        fetched = false;\n      }\n\n\
    \      bool operator!=(iter &) const {\n        return c < N;\n      }\n\n   \
    \   iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n    InputTuples(int\
    \ N): N(N){}\n\n    iter begin() const {return iter(N);}\n    iter end() const\
    \ {return iter(N);}\n  };\n\n  template <typename ... Args>\n  auto input_tuples(int\
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 7 \"test/aoj/GRL_7_A/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int X, Y, E; std::cin >> X >> Y\
    \ >> E;\n\n  hl::bipartite_matching<hl::ford_fulkerson<int>> b(X, Y);\n\n  for(auto\
    \ [x, y] : hl::input_tuples<int, int>(E)){\n    b.add_edge(x, y);\n  }\n\n  int\
    \ ans = b.solve();\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Matching/bipartite_matching.cpp\"\
    \n#include \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int X, Y, E; std::cin >> X >> Y\
    \ >> E;\n\n  hl::bipartite_matching<hl::ford_fulkerson<int>> b(X, Y);\n\n  for(auto\
    \ [x, y] : hl::input_tuples<int, int>(E)){\n    b.add_edge(x, y);\n  }\n\n  int\
    \ ans = b.solve();\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Matching/bipartite_matching.cpp
  - Mylib/Graph/Flow/ford_fulkerson.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 19:52:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A/main.test.cpp
- /verify/test/aoj/GRL_7_A/main.test.cpp.html
title: test/aoj/GRL_7_A/main.test.cpp
---
