---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Graph/maximum_independent_set.cpp
    title: Maximum independent set
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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/yosupo-judge/maximum_independent_set/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\
    \n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Graph/maximum_independent_set.cpp\"\
    \n#include <cassert>\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t maximum_independent_set(const\
    \ std::vector<std::vector<int>> &g){\n    const int n = g.size();\n\n    for(int\
    \ i = 0; i < n; ++i){\n      for(int j = 0; j < n; ++j){\n        assert((int)g[i].size()\
    \ == n);\n        assert(g[i][j] == g[j][i]);\n      }\n    }\n\n    const int\
    \ h1 = n / 2; // V1\n    const int h2 = n - h1; // V2\n\n    std::vector<bool>\
    \ dp1(1 << h1, true); // dp1[S] := S\u304C\u72EC\u7ACB\u96C6\u5408\u304B?\n  \
    \  for(int i = 0; i < h1; ++i){\n      for(int j = 0; j < h1; ++j){\n        if(g[i][j])\
    \ dp1[(1 << i) | (1 << j)] = false;\n      }\n    }\n\n    for(int s = 0; s <\
    \ (1 << h1); ++s){\n      if(not dp1[s]){\n        for(int j = 0; j < h1; ++j){\n\
    \          dp1[s | (1 << j)] = false;\n        }\n      }\n    }\n\n    std::vector<bool>\
    \ dp2(1 << h2, true); // dp2[S] := S\u304C\u72EC\u7ACB\u96C6\u5408\u304B?\n  \
    \  for(int i = h1; i < n; ++i){\n      for(int j = h1; j < n; ++j){\n        if(g[i][j])\
    \ dp2[(1 << (i - h1)) | (1 << (j - h1))] = false;\n      }\n    }\n\n    for(int\
    \ s = 0; s < (1 << h2); ++s){\n      if(not dp2[s]){\n        for(int j = 0; j\
    \ < h2; ++j){\n          dp2[s | (1 << j)] = false;\n        }\n      }\n    }\n\
    \n    std::vector<int> dp3(1 << h1, 0); // S1\u3068\u63A5\u7D9A\u3057\u306A\u3044\
    V2\u306E\u6700\u5927\u306E\u90E8\u5206\u96C6\u5408\n    dp3[0] = (1 << h2) - 1;\n\
    \    for(int i = 0; i < h1; ++i){\n      int t = 0;\n      for(int j = h1; j <\
    \ n; ++j){\n        if(g[i][j]){\n          t |= (1 << (j - h1));\n        }\n\
    \      }\n      dp3[1 << i] = t ^ ((1 << h2) - 1);\n    }\n\n    for(int s = 0;\
    \ s < (1 << h1); ++s){\n      for(int j = 0; j < h1; ++j){\n        if((s & (1\
    \ << j)) == 0){\n          dp3[s | (1 << j)] = dp3[s] & dp3[1 << j];\n       \
    \ }\n      }\n    }\n\n    std::vector<int> dp4(1 << h2, 0); // S2\u306E\u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408\n    for(int i = 0; i < (1 << h2); ++i){\n    \
    \  if(dp2[i]){\n        dp4[i] = i;\n      }\n    }\n\n    for(int s = 0; s <\
    \ (1 << h2); ++s){\n      for(int j = 0; j < h2; ++j){\n        if((s & (1 <<\
    \ j)) == 0){\n          if(__builtin_popcount(dp4[s | (1 << j)]) > __builtin_popcount(dp4[s])){\n\
    \            dp4[s | (1 << j)] = dp4[s | (1 << j)];\n          }else{\n      \
    \      dp4[s | (1 << j)] = dp4[s];\n          }\n        }\n      }\n    }\n\n\
    \    int64_t ans = 0;\n    int size = 0;\n\n    for(int s = 0; s < (1 << h1);\
    \ ++s){\n      if(dp1[s]){\n        int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]])\
    \ << h1);\n\n        if(__builtin_popcountll(t) > size){\n          size = __builtin_popcountll(t);\n\
    \          ans = t;\n        }\n      }\n    }\n\n    return ans;\n  }\n}\n#line\
    \ 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\nnamespace\
    \ haar_lib {\n  template <typename Iter>\n  std::string join(Iter first, Iter\
    \ last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
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
    \ ...>(N);\n  }\n}\n#line 8 \"test/yosupo-judge/maximum_independent_set/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N, M; std::cin >> N >> M;\n\
    \  std::vector<std::vector<int>> g(N, std::vector<int>(N));\n  for(auto [u, v]\
    \ : hl::input_tuples<int, int>(M)){\n    g[u][v] = g[v][u] = 1;\n  }\n\n  auto\
    \ res = hl::maximum_independent_set(g);\n\n  std::vector<int> ans;\n  for(int\
    \ i = 0; i < N; ++i){\n    if(res & (1LL << i)) ans.push_back(i);\n  }\n\n  std::cout\
    \ << ans.size() << \" \" << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Graph/maximum_independent_set.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int N, M; std::cin >> N >> M;\n  std::vector<std::vector<int>>\
    \ g(N, std::vector<int>(N));\n  for(auto [u, v] : hl::input_tuples<int, int>(M)){\n\
    \    g[u][v] = g[v][u] = 1;\n  }\n\n  auto res = hl::maximum_independent_set(g);\n\
    \n  std::vector<int> ans;\n  for(int i = 0; i < N; ++i){\n    if(res & (1LL <<\
    \ i)) ans.push_back(i);\n  }\n\n  std::cout << ans.size() << \" \" << hl::join(ans.begin(),\
    \ ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/maximum_independent_set.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/maximum_independent_set/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-29 00:55:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/maximum_independent_set/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/maximum_independent_set/main.test.cpp
- /verify/test/yosupo-judge/maximum_independent_set/main.test.cpp.html
title: test/yosupo-judge/maximum_independent_set/main.test.cpp
---
