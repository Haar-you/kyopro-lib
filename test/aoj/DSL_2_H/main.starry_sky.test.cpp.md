---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp
    title: Starry-sky tree
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL_2_H/main.starry_sky.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\n\n#include\
    \ <iostream>\n#include <functional>\n#line 2 \"Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp\"\
    \n#include <vector>\n#include <optional>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare>\n  class starry_sky_tree {\n  \
    \  int depth, size, hsize;\n    std::vector<T> data;\n\n    Compare compare =\
    \ Compare();\n\n    T f(T a, T b) const {\n      return compare(a, b) ? a : b;\n\
    \    }\n\n    void bottom_up(int i){\n      if(i > size) return;\n\n      while(i\
    \ >= 1){\n        if(i < hsize){\n          const auto d = f(data[i << 1 | 0],\
    \ data[i << 1 | 1]);\n\n          data[i << 1 | 0] -= d;\n          data[i <<\
    \ 1 | 1] -= d;\n          data[i] += d;\n        }\n\n        i >>= 1;\n     \
    \ }\n    }\n\n    std::optional<T> get(int i, int l, int r, int s, int t, T val)\
    \ const {\n      if(r <= s or t <= l) return std::nullopt;\n      if(s <= l and\
    \ r <= t) return val + data[i];\n\n      auto a = get(i << 1 | 0, l, (l + r) /\
    \ 2, s, t, val + data[i]);\n      auto b = get(i << 1 | 1, (l + r) / 2, r, s,\
    \ t, val + data[i]);\n\n      if(not a) return b;\n      if(not b) return a;\n\
    \      return f(*a, *b);\n    }\n\n  public:\n    starry_sky_tree(int n):\n  \
    \    depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth),\n\
    \      hsize(size / 2),\n      data(size, 0)\n    {}\n\n    void update(int l,\
    \ int r, T val){\n      int L = l + hsize;\n      int R = r + hsize;\n\n     \
    \ while(L < R){\n        if(R & 1) --R, data[R] += val;\n        if(L & 1) data[L]\
    \ += val, ++L;\n        L >>= 1;\n        R >>= 1;\n      }\n\n      bottom_up(l\
    \ + hsize);\n      bottom_up(r + hsize);\n    }\n\n    T fold(int l, int r) const\
    \ {\n      return *get(1, 0, hsize, l, r, 0);\n    }\n\n    template <typename\
    \ U>\n    void init_with_vector(std::vector<U> &a){\n      for(int i = 0; i <\
    \ (int)a.size(); ++i){\n        data[hsize + i] = a[i];\n      }\n\n      for(int\
    \ i = hsize - 1; i >= 1; --i){\n        data[i] = f(data[i << 1 | 0], data[i <<\
    \ 1 | 1]);\n      }\n\n      for(int i = size - 1; i > 1; --i){\n        data[i]\
    \ -= data[i >> 1];\n      }\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/DSL_2_H/main.starry_sky.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n \
    \ hl::starry_sky_tree<int, std::less<>> seg(n);\n\n  for(auto [type, s, t] : hl::input_tuples<int,\
    \ int, int>(q)){\n    if(type == 0){\n      int x; std::cin >> x;\n      seg.update(s,\
    \ t + 1, x);\n    }else{\n      std::cout << seg.fold(s, t + 1) << std::endl;\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n\n#include <iostream>\n#include <functional>\n#include \"Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int n, q; std::cin >> n >> q;\n\n  hl::starry_sky_tree<int, std::less<>> seg(n);\n\
    \n  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){\n    if(type\
    \ == 0){\n      int x; std::cin >> x;\n      seg.update(s, t + 1, x);\n    }else{\n\
    \      std::cout << seg.fold(s, t + 1) << std::endl;\n    }\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_H/main.starry_sky.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H/main.starry_sky.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H/main.starry_sky.test.cpp
- /verify/test/aoj/DSL_2_H/main.starry_sky.test.cpp.html
title: test/aoj/DSL_2_H/main.starry_sky.test.cpp
---
