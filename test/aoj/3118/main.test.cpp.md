---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Mylib/IO/input_tuple_vector.cpp
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp
    title: Sqrt decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118
  bundledCode: "#line 1 \"test/aoj/3118/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <climits>\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val,\
    \ int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp\"\
    \n#include <cmath>\n\nnamespace haar_lib {\n  struct sqrt_decomposition {\n  \
    \  const int N;\n    const int BLOCK_SIZE;\n    const int BLOCK_NUM;\n\n    sqrt_decomposition(int\
    \ N):\n      N(N), BLOCK_SIZE((int)std::sqrt(N)), BLOCK_NUM((N + BLOCK_SIZE -\
    \ 1) / BLOCK_SIZE)\n    {\n    }\n\n    template <typename Func>\n    void init(const\
    \ Func &f){\n      for(int i = 0; i < BLOCK_NUM; ++i){\n        const int L =\
    \ i * BLOCK_SIZE;\n        const int R = std::min<int>(N, (i + 1) * BLOCK_SIZE);\n\
    \        f(i, L, R);\n      }\n    }\n\n    template <typename FuncBlock, typename\
    \ FuncRange>\n    void query(int l, int r, const FuncBlock &func_block, const\
    \ FuncRange &func_range){ // [l, r)\n      for(int i = 0; i < BLOCK_NUM; ++i){\n\
    \        const int L = i * BLOCK_SIZE;\n        const int R = std::min<int>(N,\
    \ (i + 1) * BLOCK_SIZE);\n\n        if(l <= L and R <= r){\n          func_block(i,\
    \ L, R);\n        }else if((L <= l and l < R) or (L < r and r <= R)){\n      \
    \    func_range(i, L, R, std::max(l, L), std::min(r, R));\n        }\n      }\n\
    \    }\n  };\n}\n#line 11 \"test/aoj/3118/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  hl::sqrt_decomposition sd(N);\n\n  auto [A, B]\
    \ = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  const int NUM = sd.BLOCK_NUM;\n\
    \n  std::vector<std::vector<int64_t>> s(NUM);\n  std::vector<std::vector<int64_t>>\
    \ left(NUM), right(NUM);\n  std::vector<int64_t> sum(NUM);\n\n  auto f =\n   \
    \ [&](int i, int l, int r){\n      const int size = r - l;\n\n      std::vector<int64_t>\
    \ d(size);\n      for(int j = 0; j < size; ++j) d[j] = A[l+j] - B[l+j];\n\n  \
    \    std::vector<int> ord(size);\n      std::iota(ord.begin(), ord.end(), 0);\n\
    \      std::sort(ord.begin(), ord.end(), [&](int i_, int j_){return d[i_] < d[j_];});\n\
    \n      s[i].assign(size, 0);\n\n      left[i].assign(size, 0);\n      right[i].assign(size,\
    \ 0);\n\n      for(int j = 0; j < size; ++j){\n        s[i][j] = d[ord[j]];\n\
    \        left[i][j] = B[l + ord[j]];\n        right[i][j] = A[l + ord[j]];\n \
    \     }\n\n      for(int j = 1; j < size; ++j){\n        left[i][j] = std::min(left[i][j],\
    \ left[i][j - 1]);\n      }\n\n      for(int j = size - 1; --j >= 0;){\n     \
    \   right[i][j] = std::min(right[i][j], right[i][j + 1]);\n      }\n    };\n\n\
    \  sd.init(f);\n\n  for(auto [c] : hl::input_tuples<int>(Q)){\n    if(c == 1){\n\
    \      int l, r, x; std::cin >> l >> r >> x;\n      --l;\n\n      sd.query(\n\
    \        l, r,\n        [&](int i, int, int){\n          sum[i] += x;\n      \
    \  },\n        [&](int i, int L, int R, int l, int r){\n          for(int j =\
    \ L; j < R; ++j) A[j] += sum[i];\n          for(int j = l; j < r; ++j) A[j] +=\
    \ x;\n          sum[i] = 0;\n          f(i, L, R);\n        }\n      );\n    }else{\n\
    \      int l, r; std::cin >> l >> r;\n      --l;\n\n      int64_t ans = LLONG_MAX;\n\
    \n      sd.query(\n        l, r,\n        [&](int i, int L, int R){\n        \
    \  int k = std::upper_bound(s[i].begin(), s[i].end(), -sum[i]) - s[i].begin();\n\
    \          if(k - 1 >= 0) ans = std::min(ans, left[i][k - 1]);\n          if(k\
    \ < R - L) ans = std::min(ans, right[i][k] + sum[i]);\n        },\n        [&](int\
    \ i, int, int, int l, int r){\n          for(int j = l; j < r; ++j) ans = std::min(ans,\
    \ std::max(A[j] + sum[i], B[j]));\n        }\n      );\n\n      std::cout << ans\
    \ << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <climits>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include \"Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  hl::sqrt_decomposition sd(N);\n\n  auto\
    \ [A, B] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  const int NUM = sd.BLOCK_NUM;\n\
    \n  std::vector<std::vector<int64_t>> s(NUM);\n  std::vector<std::vector<int64_t>>\
    \ left(NUM), right(NUM);\n  std::vector<int64_t> sum(NUM);\n\n  auto f =\n   \
    \ [&](int i, int l, int r){\n      const int size = r - l;\n\n      std::vector<int64_t>\
    \ d(size);\n      for(int j = 0; j < size; ++j) d[j] = A[l+j] - B[l+j];\n\n  \
    \    std::vector<int> ord(size);\n      std::iota(ord.begin(), ord.end(), 0);\n\
    \      std::sort(ord.begin(), ord.end(), [&](int i_, int j_){return d[i_] < d[j_];});\n\
    \n      s[i].assign(size, 0);\n\n      left[i].assign(size, 0);\n      right[i].assign(size,\
    \ 0);\n\n      for(int j = 0; j < size; ++j){\n        s[i][j] = d[ord[j]];\n\
    \        left[i][j] = B[l + ord[j]];\n        right[i][j] = A[l + ord[j]];\n \
    \     }\n\n      for(int j = 1; j < size; ++j){\n        left[i][j] = std::min(left[i][j],\
    \ left[i][j - 1]);\n      }\n\n      for(int j = size - 1; --j >= 0;){\n     \
    \   right[i][j] = std::min(right[i][j], right[i][j + 1]);\n      }\n    };\n\n\
    \  sd.init(f);\n\n  for(auto [c] : hl::input_tuples<int>(Q)){\n    if(c == 1){\n\
    \      int l, r, x; std::cin >> l >> r >> x;\n      --l;\n\n      sd.query(\n\
    \        l, r,\n        [&](int i, int, int){\n          sum[i] += x;\n      \
    \  },\n        [&](int i, int L, int R, int l, int r){\n          for(int j =\
    \ L; j < R; ++j) A[j] += sum[i];\n          for(int j = l; j < r; ++j) A[j] +=\
    \ x;\n          sum[i] = 0;\n          f(i, L, R);\n        }\n      );\n    }else{\n\
    \      int l, r; std::cin >> l >> r;\n      --l;\n\n      int64_t ans = LLONG_MAX;\n\
    \n      sd.query(\n        l, r,\n        [&](int i, int L, int R){\n        \
    \  int k = std::upper_bound(s[i].begin(), s[i].end(), -sum[i]) - s[i].begin();\n\
    \          if(k - 1 >= 0) ans = std::min(ans, left[i][k - 1]);\n          if(k\
    \ < R - L) ans = std::min(ans, right[i][k] + sum[i]);\n        },\n        [&](int\
    \ i, int, int, int l, int r){\n          for(int j = l; j < r; ++j) ans = std::min(ans,\
    \ std::max(A[j] + sum[i], B[j]));\n        }\n      );\n\n      std::cout << ans\
    \ << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp
  isVerificationFile: true
  path: test/aoj/3118/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 11:39:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3118/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3118/main.test.cpp
- /verify/test/aoj/3118/main.test.cpp.html
title: test/aoj/3118/main.test.cpp
---
