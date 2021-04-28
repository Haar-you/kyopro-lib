---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Algorithm/sqrt_decomposition.cpp
    title: Sqrt decomposition
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118
  bundledCode: "#line 1 \"test/aoj/3118/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118\"\
    \n\n#include <algorithm>\n#include <climits>\n#include <iostream>\n#include <numeric>\n\
    #include <vector>\n#line 3 \"Mylib/Algorithm/sqrt_decomposition.cpp\"\n#include\
    \ <cmath>\n\nnamespace haar_lib {\n  class sqrt_decomposition {\n    int N_, BLOCK_SIZE_,\
    \ BLOCK_NUM_;\n\n  public:\n    sqrt_decomposition(int N) : N_(N), BLOCK_SIZE_((int)\
    \ std::sqrt(N)), BLOCK_NUM_((N + BLOCK_SIZE_ - 1) / BLOCK_SIZE_) {}\n\n    int\
    \ block_size() const { return BLOCK_SIZE_; }\n    int block_num() const { return\
    \ BLOCK_NUM_; }\n\n    template <typename Func>\n    void init(const Func &f)\
    \ {\n      for (int i = 0; i < BLOCK_NUM_; ++i) {\n        const int L = i * BLOCK_SIZE_;\n\
    \        const int R = std::min<int>(N_, (i + 1) * BLOCK_SIZE_);\n        f(i,\
    \ L, R);\n      }\n    }\n\n    template <typename FuncBlock, typename FuncRange>\n\
    \    void query(int l, int r, const FuncBlock &func_block, const FuncRange &func_range)\
    \ {\n      for (int i = 0; i < BLOCK_NUM_; ++i) {\n        const int L = i * BLOCK_SIZE_;\n\
    \        const int R = std::min<int>(N_, (i + 1) * BLOCK_SIZE_);\n\n        if\
    \ (l <= L and R <= r) {\n          func_block(i, L, R);\n        } else if ((L\
    \ <= l and l < R) or (L < r and r <= R)) {\n          func_range(i, L, R, std::max(l,\
    \ L), std::min(r, R));\n        }\n      }\n    }\n  };\n}  // namespace haar_lib\n\
    #line 2 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <initializer_list>\n#line\
    \ 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <tuple>\n#include <utility>\n\
    #line 7 \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T, size_t... I>\n  void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>)\
    \ {\n    (void) std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0)...};\n  }\n\n  template <typename T, size_t... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0)...};\n  }\n\n  template <typename... Args>\n  auto\
    \ input_tuple_vector(int N) {\n    std::tuple<std::vector<Args>...> ret;\n\n \
    \   input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());\n\
    \    for (int i = 0; i < N; ++i) {\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \  }\n}  // namespace haar_lib\n#line 11 \"test/aoj/3118/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  hl::sqrt_decomposition sd(N);\n\n  auto\
    \ [A, B] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  const int NUM = sd.block_num();\n\
    \n  std::vector<std::vector<int64_t>> s(NUM);\n  std::vector<std::vector<int64_t>>\
    \ left(NUM), right(NUM);\n  std::vector<int64_t> sum(NUM);\n\n  auto f =\n   \
    \   [&](int i, int l, int r) {\n        const int size = r - l;\n\n        std::vector<int64_t>\
    \ d(size);\n        for (int j = 0; j < size; ++j) d[j] = A[l + j] - B[l + j];\n\
    \n        std::vector<int> ord(size);\n        std::iota(ord.begin(), ord.end(),\
    \ 0);\n        std::sort(ord.begin(), ord.end(), [&](int i_, int j_) { return\
    \ d[i_] < d[j_]; });\n\n        s[i].assign(size, 0);\n\n        left[i].assign(size,\
    \ 0);\n        right[i].assign(size, 0);\n\n        for (int j = 0; j < size;\
    \ ++j) {\n          s[i][j]     = d[ord[j]];\n          left[i][j]  = B[l + ord[j]];\n\
    \          right[i][j] = A[l + ord[j]];\n        }\n\n        for (int j = 1;\
    \ j < size; ++j) {\n          left[i][j] = std::min(left[i][j], left[i][j - 1]);\n\
    \        }\n\n        for (int j = size - 1; --j >= 0;) {\n          right[i][j]\
    \ = std::min(right[i][j], right[i][j + 1]);\n        }\n      };\n\n  sd.init(f);\n\
    \n  for (auto [c] : hl::input_tuples<int>(Q)) {\n    if (c == 1) {\n      int\
    \ l, r, x;\n      std::cin >> l >> r >> x;\n      --l;\n\n      sd.query(\n  \
    \        l, r,\n          [&](int i, int, int) {\n            sum[i] += x;\n \
    \         },\n          [&](int i, int L, int R, int l, int r) {\n           \
    \ for (int j = L; j < R; ++j) A[j] += sum[i];\n            for (int j = l; j <\
    \ r; ++j) A[j] += x;\n            sum[i] = 0;\n            f(i, L, R);\n     \
    \     });\n    } else {\n      int l, r;\n      std::cin >> l >> r;\n      --l;\n\
    \n      int64_t ans = LLONG_MAX;\n\n      sd.query(\n          l, r,\n       \
    \   [&](int i, int L, int R) {\n            int k = std::upper_bound(s[i].begin(),\
    \ s[i].end(), -sum[i]) - s[i].begin();\n            if (k - 1 >= 0) ans = std::min(ans,\
    \ left[i][k - 1]);\n            if (k < R - L) ans = std::min(ans, right[i][k]\
    \ + sum[i]);\n          },\n          [&](int i, int, int, int l, int r) {\n \
    \           for (int j = l; j < r; ++j) ans = std::min(ans, std::max(A[j] + sum[i],\
    \ B[j]));\n          });\n\n      std::cout << ans << \"\\n\";\n    }\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118\"\
    \n\n#include <algorithm>\n#include <climits>\n#include <iostream>\n#include <numeric>\n\
    #include <vector>\n#include \"Mylib/Algorithm/sqrt_decomposition.cpp\"\n#include\
    \ \"Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\
    \nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  hl::sqrt_decomposition sd(N);\n\n  auto\
    \ [A, B] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  const int NUM = sd.block_num();\n\
    \n  std::vector<std::vector<int64_t>> s(NUM);\n  std::vector<std::vector<int64_t>>\
    \ left(NUM), right(NUM);\n  std::vector<int64_t> sum(NUM);\n\n  auto f =\n   \
    \   [&](int i, int l, int r) {\n        const int size = r - l;\n\n        std::vector<int64_t>\
    \ d(size);\n        for (int j = 0; j < size; ++j) d[j] = A[l + j] - B[l + j];\n\
    \n        std::vector<int> ord(size);\n        std::iota(ord.begin(), ord.end(),\
    \ 0);\n        std::sort(ord.begin(), ord.end(), [&](int i_, int j_) { return\
    \ d[i_] < d[j_]; });\n\n        s[i].assign(size, 0);\n\n        left[i].assign(size,\
    \ 0);\n        right[i].assign(size, 0);\n\n        for (int j = 0; j < size;\
    \ ++j) {\n          s[i][j]     = d[ord[j]];\n          left[i][j]  = B[l + ord[j]];\n\
    \          right[i][j] = A[l + ord[j]];\n        }\n\n        for (int j = 1;\
    \ j < size; ++j) {\n          left[i][j] = std::min(left[i][j], left[i][j - 1]);\n\
    \        }\n\n        for (int j = size - 1; --j >= 0;) {\n          right[i][j]\
    \ = std::min(right[i][j], right[i][j + 1]);\n        }\n      };\n\n  sd.init(f);\n\
    \n  for (auto [c] : hl::input_tuples<int>(Q)) {\n    if (c == 1) {\n      int\
    \ l, r, x;\n      std::cin >> l >> r >> x;\n      --l;\n\n      sd.query(\n  \
    \        l, r,\n          [&](int i, int, int) {\n            sum[i] += x;\n \
    \         },\n          [&](int i, int L, int R, int l, int r) {\n           \
    \ for (int j = L; j < R; ++j) A[j] += sum[i];\n            for (int j = l; j <\
    \ r; ++j) A[j] += x;\n            sum[i] = 0;\n            f(i, L, R);\n     \
    \     });\n    } else {\n      int l, r;\n      std::cin >> l >> r;\n      --l;\n\
    \n      int64_t ans = LLONG_MAX;\n\n      sd.query(\n          l, r,\n       \
    \   [&](int i, int L, int R) {\n            int k = std::upper_bound(s[i].begin(),\
    \ s[i].end(), -sum[i]) - s[i].begin();\n            if (k - 1 >= 0) ans = std::min(ans,\
    \ left[i][k - 1]);\n            if (k < R - L) ans = std::min(ans, right[i][k]\
    \ + sum[i]);\n          },\n          [&](int i, int, int, int l, int r) {\n \
    \           for (int j = l; j < r; ++j) ans = std::min(ans, std::max(A[j] + sum[i],\
    \ B[j]));\n          });\n\n      std::cout << ans << \"\\n\";\n    }\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/sqrt_decomposition.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/3118/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/3118/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3118/main.test.cpp
- /verify/test/aoj/3118/main.test.cpp.html
title: test/aoj/3118/main.test.cpp
---
