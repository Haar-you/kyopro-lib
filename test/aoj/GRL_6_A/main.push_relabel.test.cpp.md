---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Flow/push_relabel.cpp
    title: Push-relabel
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
  bundledCode: "#line 1 \"test/aoj/GRL_6_A/main.push_relabel.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n#include\
    \ <iostream>\n#include <climits>\n#line 2 \"Mylib/Graph/Flow/push_relabel.cpp\"\
    \n#include <vector>\n#include <queue>\n#include <utility>\n#include <limits>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  namespace push_relabel_impl {\n\
    \    template <typename T>\n    struct edge {\n      int from, to, rev;\n    \
    \  T cap;\n      bool is_rev;\n      edge(int from, int to, int rev, T cap, bool\
    \ is_rev):\n        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n\
    \    };\n  }\n\n  template <typename T>\n  class push_relabel {\n  public:\n \
    \   using edge = push_relabel_impl::edge<T>;\n    using capacity_type = T;\n\n\
    \  private:\n    int N_;\n    std::vector<std::vector<edge>> g_;\n    std::vector<T>\
    \ excess_;\n    std::vector<int> height_;\n    std::queue<int> next_active_vertex_;\n\
    \    constexpr static T inf = std::numeric_limits<T>::max();\n\n    void init(int\
    \ s, int t){\n      excess_[s] = inf;\n\n      for(auto &e : g_[s]){\n       \
    \ push(e, s, t);\n      }\n\n      {\n        for(int i = 0; i < N_; ++i){\n \
    \         height_[i] = N_;\n        }\n\n        std::queue<int> q;\n        std::vector<bool>\
    \ check(N_);\n        q.push(t);\n        height_[t] = 0;\n\n        while(not\
    \ q.empty()){\n          const int i = q.front(); q.pop();\n\n          if(check[i])\
    \ continue;\n          check[i] = true;\n\n          for(auto &e : g_[i]){\n \
    \           if(not e.is_rev) continue;\n            if(height_[e.from] + 1 < height_[e.to]){\n\
    \              height_[e.to] = height_[e.from] + 1;\n              q.push(e.to);\n\
    \            }\n          }\n        }\n\n        height_[s] = N_;\n      }\n\
    \    }\n\n    bool is_pushable(const edge &e){\n      if(excess_[e.from] == 0)\
    \ return false;\n      if(height_[e.from] != height_[e.to] + 1) return false;\n\
    \      if(e.cap == 0) return false;\n      return true;\n    }\n\n    void push(edge\
    \ &e, int, int){\n      auto &r = g_[e.to][e.rev];\n\n      T flow = std::min(e.cap,\
    \ excess_[e.from]);\n\n      e.cap -= flow;\n      r.cap += flow;\n\n      excess_[e.from]\
    \ -= flow;\n      excess_[e.to] += flow;\n\n      if(excess_[e.to] == flow) next_active_vertex_.push(e.to);\n\
    \    }\n\n    void relabel(int i, int, int){\n      int a = std::numeric_limits<int>::max()\
    \ / 2;\n      for(auto &e : g_[i]){\n        if(e.cap > 0) a = std::min(a, height_[e.to]);\n\
    \      }\n\n      height_[i] = a + 1;\n    }\n\n  public:\n    push_relabel(){}\n\
    \    push_relabel(int N): N_(N), g_(N), excess_(N), height_(N){}\n\n    void add_edge(int\
    \ from, int to, T c){\n      assert(0 <= from and from < N_);\n      assert(0\
    \ <= to and to < N_);\n      g_[from].emplace_back(from, to, (int)g_[to].size(),\
    \ c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size() - 1, 0,\
    \ true);\n    }\n\n    T max_flow(int s, int t){\n      assert(0 <= s and s <\
    \ N_);\n      assert(0 <= t and t < N_);\n      init(s, t);\n\n      while(true){\n\
    \        int index = -1;\n\n        while(not next_active_vertex_.empty()){\n\
    \          int i = next_active_vertex_.front();\n          if(i != s and i !=\
    \ t and excess_[i] > 0){\n            index = i;\n            break;\n       \
    \   }\n          next_active_vertex_.pop();\n        }\n\n        if(index ==\
    \ -1) break;\n\n        bool ok = false;\n        for(auto &e : g_[index]){\n\
    \          if(is_pushable(e)){\n            push(e, s, t);\n            ok = true;\n\
    \            break;\n          }\n        }\n\n        if(not ok){\n         \
    \ relabel(index, s, t);\n        }\n      }\n\n      return excess_[t];\n    }\n\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/GRL_6_A/main.push_relabel.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main(){\n  int V, E; std::cin >> V >> E;\n\n \
    \ hl::push_relabel<int> f(V);\n\n  for(auto [s, t, c] : hl::input_tuples<int,\
    \ int, int>(E)){\n    f.add_edge(s, t, c);\n  }\n\n  auto ans = f.max_flow(0,\
    \ V - 1);\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <iostream>\n#include <climits>\n#include \"Mylib/Graph/Flow/push_relabel.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int V, E; std::cin >> V >> E;\n\n  hl::push_relabel<int> f(V);\n\n  for(auto\
    \ [s, t, c] : hl::input_tuples<int, int, int>(E)){\n    f.add_edge(s, t, c);\n\
    \  }\n\n  auto ans = f.max_flow(0, V - 1);\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Flow/push_relabel.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A/main.push_relabel.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A/main.push_relabel.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A/main.push_relabel.test.cpp
- /verify/test/aoj/GRL_6_A/main.push_relabel.test.cpp.html
title: test/aoj/GRL_6_A/main.push_relabel.test.cpp
---
