---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
    title: test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_xor.cpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ convolution_xor(std::vector<T> f, std::vector<T> g){\n    const int n = f.size();\n\
    \    assert((int)f.size() == n and (int)g.size() == n and (n & (n - 1)) == 0);\n\
    \n    auto fwt =\n      [n](std::vector<T> f){\n        for(int i = 1; i < n;\
    \ i <<= 1){\n          for(int j = 0; j < n; ++j){\n            if((j & i) ==\
    \ 0){\n              auto x = f[j], y = f[j | i];\n              f[j] = x + y;\n\
    \              f[j | i] = x - y;\n            }\n          }\n        }\n    \
    \    return f;\n      };\n\n    auto ifwt =\n      [n](std::vector<T> f){\n  \
    \      for(int i = 1; i < n; i <<= 1){\n          for(int j = 0; j < n; ++j){\n\
    \            if((j & i) == 0){\n              auto x = f[j], y = f[j | i];\n \
    \             f[j] = (x + y) / 2;\n              f[j | i] = (x - y) / 2;\n   \
    \         }\n          }\n        }\n        return f;\n      };\n\n    f = fwt(f);\n\
    \    g = fwt(g);\n\n    for(int i = 0; i < n; ++i) f[i] *= g[i];\n\n    f = ifwt(f);\n\
    \n    return f;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> convolution_xor(std::vector<T>\
    \ f, std::vector<T> g){\n    const int n = f.size();\n    assert((int)f.size()\
    \ == n and (int)g.size() == n and (n & (n - 1)) == 0);\n\n    auto fwt =\n   \
    \   [n](std::vector<T> f){\n        for(int i = 1; i < n; i <<= 1){\n        \
    \  for(int j = 0; j < n; ++j){\n            if((j & i) == 0){\n              auto\
    \ x = f[j], y = f[j | i];\n              f[j] = x + y;\n              f[j | i]\
    \ = x - y;\n            }\n          }\n        }\n        return f;\n      };\n\
    \n    auto ifwt =\n      [n](std::vector<T> f){\n        for(int i = 1; i < n;\
    \ i <<= 1){\n          for(int j = 0; j < n; ++j){\n            if((j & i) ==\
    \ 0){\n              auto x = f[j], y = f[j | i];\n              f[j] = (x + y)\
    \ / 2;\n              f[j | i] = (x - y) / 2;\n            }\n          }\n  \
    \      }\n        return f;\n      };\n\n    f = fwt(f);\n    g = fwt(g);\n\n\
    \    for(int i = 0; i < n; ++i) f[i] *= g[i];\n\n    f = ifwt(f);\n\n    return\
    \ f;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/convolution_xor.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
documentation_of: Mylib/Convolution/convolution_xor.cpp
layout: document
title: Convolution (Index bitwise XOR)
---

## Operations

- `convolution_xor(f[N], g[N])`
	- `N`は2の累乗
	- `k in [0, N)`について$h_k = \sum_{k=i \oplus j} f_i * g_j$を求める。

## Requirements

## Notes

## Problems

## References

- [https://kazuma8128.hatenablog.com/entry/2018/05/31/144519](https://kazuma8128.hatenablog.com/entry/2018/05/31/144519)
