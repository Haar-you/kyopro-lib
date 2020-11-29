---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp
    title: Starry-sky tree
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/631
    links:
    - https://yukicoder.me/problems/no/631
  bundledCode: "#line 1 \"test/yukicoder/631/main.starry_sky.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/631\"\n\n#include <iostream>\n#include <vector>\n\
    #include <functional>\n#line 3 \"Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp\"\
    \n#include <optional>\n#include <algorithm>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare>\n  class starry_sky_tree {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    int depth_, size_, hsize_;\n   \
    \ std::vector<T> data_;\n    Compare compare_ = Compare();\n\n    T f(T a, T b)\
    \ const {\n      return compare_(a, b) ? a : b;\n    }\n\n    void bottom_up(int\
    \ i){\n      if(i > size_) return;\n\n      while(i >= 1){\n        if(i < hsize_){\n\
    \          const auto d = f(data_[i << 1 | 0], data_[i << 1 | 1]);\n\n       \
    \   data_[i << 1 | 0] -= d;\n          data_[i << 1 | 1] -= d;\n          data_[i]\
    \ += d;\n        }\n\n        i >>= 1;\n      }\n    }\n\n    std::optional<T>\
    \ get(int i, int l, int r, int s, int t, T val) const {\n      if(r <= s or t\
    \ <= l) return std::nullopt;\n      if(s <= l and r <= t) return val + data_[i];\n\
    \n      auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data_[i]);\n    \
    \  auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data_[i]);\n\n      if(not\
    \ a) return b;\n      if(not b) return a;\n      return f(*a, *b);\n    }\n\n\
    \  public:\n    starry_sky_tree(){}\n    starry_sky_tree(int n):\n      depth_(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n     \
    \ hsize_(size_ / 2),\n      data_(size_, 0)\n    {}\n\n    void update(int l,\
    \ int r, T val){\n      assert(0 <= l and l <= r and r <= hsize_);\n      int\
    \ L = l + hsize_;\n      int R = r + hsize_;\n\n      while(L < R){\n        if(R\
    \ & 1) --R, data_[R] += val;\n        if(L & 1) data_[L] += val, ++L;\n      \
    \  L >>= 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize_);\n     \
    \ bottom_up(r + hsize_);\n    }\n\n    T fold(int l, int r) const {\n      assert(0\
    \ <= l and l <= r and r <= hsize_);\n      return *get(1, 0, hsize_, l, r, 0);\n\
    \    }\n\n    T fold_all() const {\n      return data_[1];\n    }\n\n    template\
    \ <typename U>\n    void init_with_vector(std::vector<U> &a){\n      for(int i\
    \ = 0; i < (int)a.size(); ++i){\n        data_[hsize_ + i] = a[i];\n      }\n\n\
    \      for(int i = hsize_; --i >= 1;){\n        data_[i] = f(data_[i << 1 | 0],\
    \ data_[i << 1 | 1]);\n      }\n\n      for(int i = size_; --i > 1;){\n      \
    \  data_[i] -= data_[i >> 1];\n      }\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n#include\
    \ <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){\n    s >>\
    \ value.first >> value.second;\n    return s;\n  }\n\n  template <typename ...\
    \ Args>\n  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){\n\
    \    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename ... Args>\n  class InputTuples {\n    struct iter {\n\
    \      using value_type = std::tuple<Args ...>;\n      value_type value;\n   \
    \   bool fetched = false;\n      int N, c = 0;\n\n      value_type operator*(){\n\
    \        if(not fetched){\n          std::cin >> value;\n        }\n        return\
    \ value;\n      }\n\n      void operator++(){\n        ++c;\n        fetched =\
    \ false;\n      }\n\n      bool operator!=(iter &) const {\n        return c <\
    \ N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n\
    \    InputTuples(int N): N(N){}\n\n    iter begin() const {return iter(N);}\n\
    \    iter end() const {return iter(N);}\n  };\n\n  template <typename ... Args>\n\
    \  auto input_tuples(int N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line\
    \ 9 \"test/yukicoder/631/main.starry_sky.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n\n  auto seg = hl::starry_sky_tree<int64_t, std::greater<>>(N\
    \ - 1);\n\n  auto T = hl::input_vector<int64_t>(N - 1);\n\n  for(int i = 0; i\
    \ < N - 1; ++i){\n    T[i] += 3 * (N - 1 - i);\n  }\n\n  seg.init_with_vector(T);\n\
    \n  int M; std::cin >> M;\n\n  for(auto [L, R, D] : hl::input_tuples<int, int,\
    \ int>(M)){\n    --L, --R;\n\n    seg.update(L, R + 1, D);\n\n    auto ans = seg.fold_all();\n\
    \    std::cout << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/631\"\n\n#include <iostream>\n\
    #include <vector>\n#include <functional>\n#include \"Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto seg = hl::starry_sky_tree<int64_t, std::greater<>>(N\
    \ - 1);\n\n  auto T = hl::input_vector<int64_t>(N - 1);\n\n  for(int i = 0; i\
    \ < N - 1; ++i){\n    T[i] += 3 * (N - 1 - i);\n  }\n\n  seg.init_with_vector(T);\n\
    \n  int M; std::cin >> M;\n\n  for(auto [L, R, D] : hl::input_tuples<int, int,\
    \ int>(M)){\n    --L, --R;\n\n    seg.update(L, R + 1, D);\n\n    auto ans = seg.fold_all();\n\
    \    std::cout << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/631/main.starry_sky.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/631/main.starry_sky.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/631/main.starry_sky.test.cpp
- /verify/test/yukicoder/631/main.starry_sky.test.cpp.html
title: test/yukicoder/631/main.starry_sky.test.cpp
---
