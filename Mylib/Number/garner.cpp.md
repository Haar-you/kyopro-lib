---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_inv.cpp
    title: Mod inverse
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/garner.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include <cstdint>\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  constexpr int64_t mod_inv(int64_t a, int64_t\
    \ m) {\n    int64_t b = m, u = 1, v = 0;\n\n    while (b) {\n      int64_t t =\
    \ a / b;\n      a -= t * b;\n      a = a ^ b;\n      b = a ^ b;\n      a = a ^\
    \ b;\n\n      u -= t * v;\n      u = u ^ v;\n      v = u ^ v;\n      u = u ^ v;\n\
    \    }\n\n    u %= m;\n    if (u < 0) u += m;\n\n    return u;\n  }\n}  // namespace\
    \ haar_lib\n#line 5 \"Mylib/Number/garner.cpp\"\n\nnamespace haar_lib {\n  int64_t\
    \ garner_algorithm(std::vector<int64_t> r, std::vector<int64_t> m, const int64_t\
    \ mod) {\n    assert(r.size() == m.size());\n    m.push_back(mod);\n\n    int\
    \ n = r.size();\n    std::vector<int64_t> coeffs(n + 1, 1);\n    std::vector<int64_t>\
    \ constants(n + 1, 0);\n\n    for (int k = 0; k < n; ++k) {\n      int64_t t =\
    \ ((r[k] - constants[k] + m[k]) % m[k] * mod_inv(coeffs[k], m[k])) % m[k];\n \
    \     for (int i = k + 1; i < n + 1; ++i) {\n        (constants[i] += t * coeffs[i]\
    \ % m[i]) %= m[i];\n        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n \
    \   return constants.back();\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"Mylib/Number/Mod/mod_inv.cpp\"\
    \n\nnamespace haar_lib {\n  int64_t garner_algorithm(std::vector<int64_t> r, std::vector<int64_t>\
    \ m, const int64_t mod) {\n    assert(r.size() == m.size());\n    m.push_back(mod);\n\
    \n    int n = r.size();\n    std::vector<int64_t> coeffs(n + 1, 1);\n    std::vector<int64_t>\
    \ constants(n + 1, 0);\n\n    for (int k = 0; k < n; ++k) {\n      int64_t t =\
    \ ((r[k] - constants[k] + m[k]) % m[k] * mod_inv(coeffs[k], m[k])) % m[k];\n \
    \     for (int i = k + 1; i < n + 1; ++i) {\n        (constants[i] += t * coeffs[i]\
    \ % m[i]) %= m[i];\n        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n \
    \   return constants.back();\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Number/Mod/mod_inv.cpp
  isVerificationFile: false
  path: Mylib/Number/garner.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/garner.cpp
layout: document
title: Garner algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
