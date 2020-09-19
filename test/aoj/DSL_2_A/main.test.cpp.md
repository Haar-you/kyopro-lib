---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <iostream>\n#include <climits>\n#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <functional>\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid>\n  class segment_tree {\n    using\
    \ value_type = typename Monoid::value_type;\n    const static Monoid M;\n\n  \
    \  int depth, size, hsize;\n    std::vector<value_type> data;\n\n  public:\n \
    \   segment_tree(){}\n    segment_tree(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n      size(1 << depth), hsize(size / 2),\n      data(size, M())\n\
    \    {}\n\n    auto operator[](int i) const {return data[hsize + i];}\n\n    auto\
    \ get(int x, int y) const {\n      value_type ret_left = M();\n      value_type\
    \ ret_right = M();\n\n      int l = x + hsize, r = y + hsize;\n      while(l <\
    \ r){\n        if(r & 1) ret_right = M(data[--r], ret_right);\n        if(l &\
    \ 1) ret_left = M(ret_left, data[l++]);\n        l >>= 1, r >>= 1;\n      }\n\n\
    \      return M(ret_left, ret_right);\n    }\n\n    void update(int i, const value_type\
    \ &x){\n      i += hsize;\n      data[i] = x;\n      while(i > 1) i >>= 1, data[i]\
    \ = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n    template <typename T>\n\
    \    void init_with_vector(const std::vector<T> &val){\n      data.assign(size,\
    \ M());\n      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];\n\
    \      for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i\
    \ << 1 | 1]);\n    }\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<value_type>(hsize, val));\n    }\n\n  private:\n\
    \    template <bool Lower, typename F>\n    int bound(const int l, const int r,\
    \ value_type x, F f) const {\n      std::vector<int> pl, pr;\n      int L = l\
    \ + hsize;\n      int R = r + hsize;\n      while(L < R){\n        if(R & 1) pr.push_back(--R);\n\
    \        if(L & 1) pl.push_back(L++);\n        L >>= 1, R >>= 1;\n      }\n\n\
    \      std::reverse(pr.begin(), pr.end());\n      pl.insert(pl.end(), pr.begin(),\
    \ pr.end());\n\n      value_type a = M();\n\n      for(int i : pl){\n        auto\
    \ b = M(a, data[i]);\n\n        if((Lower and not f(b, x)) or (not Lower and f(x,\
    \ b))){\n          while(i < hsize){\n            if(auto c = M(a, data[i << 1\
    \ | 0]); (Lower and not f(c, x)) or (not Lower and f(x, c))){\n              i\
    \ = i << 1 | 0;\n            }else{\n              a = c;\n              i = i\
    \ << 1 | 1;\n            }\n          }\n\n          return i - hsize;\n     \
    \   }\n\n        a = b;\n      }\n\n      return r;\n    }\n\n  public:\n    template\
    \ <typename F = std::less<value_type>>\n    int lower_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<true>(l, r, x, f);\n    }\n\n    template\
    \ <typename F = std::less<value_type>>\n    int upper_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<false>(l, r, x, f);\n    }\n  };\n\
    }\n#line 3 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include <optional>\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct min_monoid {\n    using\
    \ value_type = std::optional<T>;\n\n    value_type operator()() const {return\
    \ {};}\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      if(not a) return b;\n      if(not b) return a;\n      return {std::min(*a,\
    \ *b)};\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n\
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
    \ ...>(N);\n  }\n}\n#line 8 \"test/aoj/DSL_2_A/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n  hl::segment_tree<hl::min_monoid<int>>\
    \ seg(n);\n\n  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){\n\
    \    if(type == 0){\n      seg.update(x, y);\n    }else{\n      std::cout << seg.get(x,\
    \ y + 1).value_or(INT_MAX) << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <iostream>\n#include <climits>\n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  hl::segment_tree<hl::min_monoid<int>> seg(n);\n\n  for(auto [type, x, y] :\
    \ hl::input_tuples<int, int, int>(q)){\n    if(type == 0){\n      seg.update(x,\
    \ y);\n    }else{\n      std::cout << seg.get(x, y + 1).value_or(INT_MAX) << std::endl;\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A/main.test.cpp
- /verify/test/aoj/DSL_2_A/main.test.cpp.html
title: test/aoj/DSL_2_A/main.test.cpp
---
