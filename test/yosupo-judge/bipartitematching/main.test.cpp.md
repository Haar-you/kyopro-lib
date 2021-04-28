---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/Matching/hopcroft_karp.cpp
    title: Hopcroft-Karp algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo-judge/bipartitematching/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#include <iostream>\n\
    #line 2 \"Mylib/Graph/Matching/hopcroft_karp.cpp\"\n#include <cassert>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  class\
    \ hopcroft_karp {\n    struct edge {\n      int from, to;\n      int rev;\n  \
    \    bool used;\n    };\n\n    int L_, R_, N_;\n    std::vector<std::vector<edge>>\
    \ g_;\n    std::vector<int> dist_;\n\n    bool bfs() {\n      dist_.assign(N_,\
    \ -1);\n      std::queue<int> q;\n\n      q.push(0);\n      dist_[0] = 0;\n\n\
    \      while (not q.empty()) {\n        int i = q.front();\n        q.pop();\n\
    \n        for (auto &e : g_[i]) {\n          if (not e.used and dist_[e.to] ==\
    \ -1) {\n            dist_[e.to] = dist_[i] + 1;\n            q.push(e.to);\n\
    \          }\n        }\n      }\n\n      return dist_[N_ - 1] != -1;\n    }\n\
    \n    bool dfs(int cur) {\n      if (cur == N_ - 1) return true;\n\n      for\
    \ (auto &e : g_[cur]) {\n        if (not e.used and dist_[cur] + 1 == dist_[e.to])\
    \ {\n          if (dfs(e.to)) {\n            e.used = true;\n            if (e.rev\
    \ >= 0) g_[e.to][e.rev].used = false;\n            return true;\n          }\n\
    \        }\n      }\n\n      return false;\n    }\n\n  public:\n    hopcroft_karp()\
    \ {}\n    hopcroft_karp(int L, int R) : L_(L), R_(R), N_(L + R + 2), g_(N_), dist_(N_)\
    \ {\n      for (int i = 0; i < L_; ++i) {\n        g_[0].push_back((edge){0, i\
    \ + 1, -1, false});\n      }\n\n      for (int i = 0; i < R_; ++i) {\n       \
    \ g_[i + L_ + 1].push_back((edge){i + L_ + 1, N_ - 1, -1, false});\n      }\n\
    \    }\n\n    void add_edge(int i, int j) {\n      assert(0 <= i and i < L_);\n\
    \      assert(0 <= j and j < R_);\n\n      const int x = i + 1;\n      const int\
    \ y = j + L_ + 1;\n\n      g_[x].push_back((edge){x, y, (int) g_[y].size(), false});\n\
    \      g_[y].push_back((edge){y, x, (int) g_[x].size() - 1, true});\n    }\n\n\
    \    int match() {\n      int ret = 0;\n\n      while (bfs()) {\n        int flow\
    \ = 0;\n        for (int i = 0; i < L_; ++i) {\n          auto &e = g_[0][i];\n\
    \          if (not e.used and dfs(e.to)) {\n            e.used = true;\n     \
    \       ++flow;\n          }\n        }\n        if (flow == 0) break;\n     \
    \   ret += flow;\n      }\n\n      return ret;\n    }\n\n    auto get_matching()\
    \ {\n      std::vector<std::pair<int, int>> ret;\n      for (int i = 0; i < L_;\
    \ ++i) {\n        for (auto &e : g_[i + 1]) {\n          if (e.used) ret.emplace_back(i,\
    \ e.to - L_ - 1);\n        }\n      }\n      return ret;\n    }\n  };\n}  // namespace\
    \ haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>) {\n \
    \   (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
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
    \  }\n}  // namespace haar_lib\n#line 6 \"test/yosupo-judge/bipartitematching/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int L, R, M;\n  std::cin >> L\
    \ >> R >> M;\n  hl::hopcroft_karp hk(L, R);\n\n  for (auto [a, b] : hl::input_tuples<int,\
    \ int>(M)) {\n    hk.add_edge(a, b);\n  }\n\n  hk.match();\n\n  auto ans = hk.get_matching();\n\
    \n  std::cout << ans.size() << \"\\n\";\n  for (auto& [i, j] : ans) {\n    std::cout\
    \ << i << \" \" << j << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include <iostream>\n#include \"Mylib/Graph/Matching/hopcroft_karp.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main() {\n\
    \  int L, R, M;\n  std::cin >> L >> R >> M;\n  hl::hopcroft_karp hk(L, R);\n\n\
    \  for (auto [a, b] : hl::input_tuples<int, int>(M)) {\n    hk.add_edge(a, b);\n\
    \  }\n\n  hk.match();\n\n  auto ans = hk.get_matching();\n\n  std::cout << ans.size()\
    \ << \"\\n\";\n  for (auto& [i, j] : ans) {\n    std::cout << i << \" \" << j\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Matching/hopcroft_karp.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/bipartitematching/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/bipartitematching/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/bipartitematching/main.test.cpp
- /verify/test/yosupo-judge/bipartitematching/main.test.cpp.html
title: test/yosupo-judge/bipartitematching/main.test.cpp
---
