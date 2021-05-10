---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n    using\
    \ value_type = T;\n    value_type operator()() const { return 0; }\n    value_type\
    \ operator()(value_type a, value_type b) const { return a + b; }\n  };\n}  //\
    \ namespace haar_lib\n#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename Monoid>\n  class segment_tree {\n\
    \  public:\n    using value_type = typename Monoid::value_type;\n\n  private:\n\
    \    Monoid M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type> data_;\n\
    \n  public:\n    segment_tree() {}\n    segment_tree(int n) : depth_(n > 1 ? 32\
    \ - __builtin_clz(n - 1) + 1 : 1),\n                          size_(1 << depth_),\n\
    \                          hsize_(size_ / 2),\n                          data_(size_,\
    \ M_()) {}\n\n    auto operator[](int i) const {\n      assert(0 <= i and i <\
    \ hsize_);\n      return data_[hsize_ + i];\n    }\n\n    auto fold(int l, int\
    \ r) const {\n      assert(0 <= l and l <= r and r <= hsize_);\n      value_type\
    \ ret_left  = M_();\n      value_type ret_right = M_();\n\n      int L = l + hsize_,\
    \ R = r + hsize_;\n      while (L < R) {\n        if (R & 1) ret_right = M_(data_[--R],\
    \ ret_right);\n        if (L & 1) ret_left = M_(ret_left, data_[L++]);\n     \
    \   L >>= 1, R >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n    }\n\
    \n    auto fold_all() const {\n      return data_[1];\n    }\n\n    void set(int\
    \ i, const value_type &x) {\n      assert(0 <= i and i < hsize_);\n      i +=\
    \ hsize_;\n      data_[i] = x;\n      while (i > 1) i >>= 1, data_[i] = M_(data_[i\
    \ << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    void update(int i, const value_type\
    \ &x) {\n      assert(0 <= i and i < hsize_);\n      i += hsize_;\n      data_[i]\
    \ = M_(data_[i], x);\n      while (i > 1) i >>= 1, data_[i] = M_(data_[i << 1\
    \ | 0], data_[i << 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val) {\n      data_.assign(size_, M_());\n      for (int i =\
    \ 0; i < (int) val.size(); ++i) data_[hsize_ + i] = val[i];\n      for (int i\
    \ = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n\
    \    }\n\n    template <typename T>\n    void init(const T &val) {\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize_;\n      int R = r + hsize_;\n      while (L\
    \ < R) {\n        if (R & 1) pr.push_back(--R);\n        if (L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M_();\n\
    \n      for (int i : pl) {\n        auto b = M_(a, data_[i]);\n\n        if ((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))) {\n          while (i < hsize_)\
    \ {\n            const auto c = M_(a, data_[i << 1 | 0]);\n            if ((Lower\
    \ and not f(c, x)) or (not Lower and f(x, c))) {\n              i = i << 1 | 0;\n\
    \            } else {\n              a = c;\n              i = i << 1 | 1;\n \
    \           }\n          }\n\n          return i - hsize_;\n        }\n\n    \
    \    a = b;\n      }\n\n      return r;\n    }\n\n  public:\n    template <typename\
    \ F = std::less<value_type>>\n    int lower_bound(int l, int r, value_type x,\
    \ F f = F()) const {\n      return bound<true>(l, r, x, f);\n    }\n\n    template\
    \ <typename F = std::less<value_type>>\n    int upper_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<false>(l, r, x, f);\n    }\n  };\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>)\
    \ {\n    (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
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
    \  }\n}  // namespace haar_lib\n#line 7 \"test/aoj/DSL_2_B/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\
    \n  auto seg = hl::segment_tree<hl::sum_monoid<int>>(n);\n\n  for (auto [type,\
    \ x, y] : hl::input_tuples<int, int, int>(q)) {\n    if (type == 0) {\n      seg.update(x\
    \ - 1, y);\n    } else {\n      std::cout << seg.fold(x - 1, y) << std::endl;\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\
    #include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int n, q;\n  std::cin >> n >>\
    \ q;\n\n  auto seg = hl::segment_tree<hl::sum_monoid<int>>(n);\n\n  for (auto\
    \ [type, x, y] : hl::input_tuples<int, int, int>(q)) {\n    if (type == 0) {\n\
    \      seg.update(x - 1, y);\n    } else {\n      std::cout << seg.fold(x - 1,\
    \ y) << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B/main.test.cpp
- /verify/test/aoj/DSL_2_B/main.test.cpp.html
title: test/aoj/DSL_2_B/main.test.cpp
---