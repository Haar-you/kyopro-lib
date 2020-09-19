---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_5_D/main.test.cpp
    title: test/aoj/ALDS1_5_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/InversionNumber/inversion_number.cpp\"\n\
    #include <vector>\n#include <cstdint>\n\nnamespace haar_lib {\n  namespace inversion_number_impl\
    \ {\n    template <typename T, typename Compare>\n    int64_t rec(std::vector<T>\
    \ &a, const Compare &compare){\n      const int n = a.size();\n      if(n <= 1)\
    \ return 0;\n\n      int64_t ret = 0;\n\n      std::vector<T> b(a.begin(), a.begin()\
    \ + n / 2);\n      std::vector<T> c(a.begin() + n / 2, a.end());\n\n      ret\
    \ += rec(b, compare);\n      ret += rec(c, compare);\n\n      int ai = 0, bi =\
    \ 0, ci = 0;\n\n      while(ai < n){\n        if(bi < (int)b.size() and (ci ==\
    \ (int)c.size() or not compare(b[bi], c[ci]))){\n          a[ai] = b[bi];\n  \
    \        ++bi;\n        }else{\n          ret += n / 2 - bi;\n          a[ai]\
    \ = c[ci];\n          ++ci;\n        }\n        ++ai;\n      }\n\n      return\
    \ ret;\n    }\n  }\n\n  template <typename T, typename Compare>\n  int64_t inversion_number(std::vector<T>\
    \ a, const Compare &compare){\n    return inversion_number_impl::rec(a, compare);\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  namespace inversion_number_impl {\n    template <typename T, typename Compare>\n\
    \    int64_t rec(std::vector<T> &a, const Compare &compare){\n      const int\
    \ n = a.size();\n      if(n <= 1) return 0;\n\n      int64_t ret = 0;\n\n    \
    \  std::vector<T> b(a.begin(), a.begin() + n / 2);\n      std::vector<T> c(a.begin()\
    \ + n / 2, a.end());\n\n      ret += rec(b, compare);\n      ret += rec(c, compare);\n\
    \n      int ai = 0, bi = 0, ci = 0;\n\n      while(ai < n){\n        if(bi < (int)b.size()\
    \ and (ci == (int)c.size() or not compare(b[bi], c[ci]))){\n          a[ai] =\
    \ b[bi];\n          ++bi;\n        }else{\n          ret += n / 2 - bi;\n    \
    \      a[ai] = c[ci];\n          ++ci;\n        }\n        ++ai;\n      }\n\n\
    \      return ret;\n    }\n  }\n\n  template <typename T, typename Compare>\n\
    \  int64_t inversion_number(std::vector<T> a, const Compare &compare){\n    return\
    \ inversion_number_impl::rec(a, compare);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/InversionNumber/inversion_number.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_5_D/main.test.cpp
documentation_of: Mylib/Algorithm/InversionNumber/inversion_number.cpp
layout: document
title: Inversion number
---

## Operations

## Requirements

## Notes

## Problems

## References
