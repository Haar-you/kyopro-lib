---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/658/main.test.cpp
    title: test/yukicoder/658/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp\"\
    \n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct kitamasa_algorithm {\n    int size;\n    std::vector<T> initial_values,\
    \ coeff;\n\n    kitamasa_algorithm(int size, const std::vector<T> &initial_values,\
    \ const std::vector<T> &coeff):\n      size(size), initial_values(initial_values),\
    \ coeff(coeff){}\n\n    std::vector<T> inc(const std::vector<T> &a) const {\n\
    \      std::vector<T> ret(size);\n\n      for(int i = 0; i < size; ++i) ret[i]\
    \ += a[size - 1] * coeff[i];\n      for(int i = 1; i < size; ++i) ret[i] += a[i\
    \ - 1];\n\n      return ret;\n    }\n\n    std::vector<T> dbl(const std::vector<T>\
    \ &a) const {\n      std::vector<T> ret(size), b(a);\n\n      for(int j = 0; j\
    \ < size; ++j){\n        for(int i = 0; i < size; ++i){\n          ret[i] += a[j]\
    \ * b[i];\n        }\n\n        b = inc(b);\n      }\n\n      return ret;\n  \
    \  }\n\n    T calc(const std::vector<T> &v) const {\n      T ret = 0;\n      for(int\
    \ i = 0; i < size; ++i) ret += v[i] * initial_values[i];\n      return ret;\n\
    \    }\n\n    std::vector<T> get(int64_t index) const {\n      std::vector<T>\
    \ ret(size);\n      ret[0] = 1;\n\n      bool check = false;\n      for(int i\
    \ = 63; i >= 0; --i){\n        if(check) ret = dbl(ret);\n\n        if(index &\
    \ (1LL << i)){\n          ret = inc(ret);\n          check = true;\n        }\n\
    \      }\n\n      return ret;\n    }\n\n    T operator[](int64_t index) const\
    \ {\n      if(index < size) return initial_values[index];\n      return calc(get(index));\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct kitamasa_algorithm {\n    int size;\n \
    \   std::vector<T> initial_values, coeff;\n\n    kitamasa_algorithm(int size,\
    \ const std::vector<T> &initial_values, const std::vector<T> &coeff):\n      size(size),\
    \ initial_values(initial_values), coeff(coeff){}\n\n    std::vector<T> inc(const\
    \ std::vector<T> &a) const {\n      std::vector<T> ret(size);\n\n      for(int\
    \ i = 0; i < size; ++i) ret[i] += a[size - 1] * coeff[i];\n      for(int i = 1;\
    \ i < size; ++i) ret[i] += a[i - 1];\n\n      return ret;\n    }\n\n    std::vector<T>\
    \ dbl(const std::vector<T> &a) const {\n      std::vector<T> ret(size), b(a);\n\
    \n      for(int j = 0; j < size; ++j){\n        for(int i = 0; i < size; ++i){\n\
    \          ret[i] += a[j] * b[i];\n        }\n\n        b = inc(b);\n      }\n\
    \n      return ret;\n    }\n\n    T calc(const std::vector<T> &v) const {\n  \
    \    T ret = 0;\n      for(int i = 0; i < size; ++i) ret += v[i] * initial_values[i];\n\
    \      return ret;\n    }\n\n    std::vector<T> get(int64_t index) const {\n \
    \     std::vector<T> ret(size);\n      ret[0] = 1;\n\n      bool check = false;\n\
    \      for(int i = 63; i >= 0; --i){\n        if(check) ret = dbl(ret);\n\n  \
    \      if(index & (1LL << i)){\n          ret = inc(ret);\n          check = true;\n\
    \        }\n      }\n\n      return ret;\n    }\n\n    T operator[](int64_t index)\
    \ const {\n      if(index < size) return initial_values[index];\n      return\
    \ calc(get(index));\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/658/main.test.cpp
documentation_of: Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp
layout: document
title: Kitamasa algorithm
---

## Operations

## Requirements

## Notes

## Problems

- [yukicoder No.214 素数サイコロと合成数サイコロ (3-Medium)](https://yukicoder.me/problems/no/214)
- [yukicoder No.658 テトラナッチ数列 Hard](https://yukicoder.me/problems/no/658)
- [TDPC T - フィボナッチ](https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci)

## References

- [https://misawa.github.io/others/fast_kitamasa_method.html](https://misawa.github.io/others/fast_kitamasa_method.html)
- [https://smijake3.hatenablog.com/entry/2017/01/02/024712](https://smijake3.hatenablog.com/entry/2017/01/02/024712)
- [http://sugarknri.hatenablog.com/entry/2017/11/18/233936](http://sugarknri.hatenablog.com/entry/2017/11/18/233936)
- [https://yosupo.hatenablog.com/entry/2015/03/27/025132](https://yosupo.hatenablog.com/entry/2015/03/27/025132)
