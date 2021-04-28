---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Debug/matrix_viewer.cpp\"\n#include <iomanip>\n#include\
    \ <iostream>\n#include <string>\n\ntemplate <typename M>\nvoid matrix_viewer([[maybe_unused]]\
    \ const M &m, [[maybe_unused]] int w = 10) {\n#ifdef DEBUG\n  const int N = m.size();\n\
    \  std::cerr << \"\u239B\" << std::string((w + 1) * N, ' ') << \"\u239E\" << std::endl;\n\
    \  for (int i = 0; i < N; ++i) {\n    std::cerr << \"\u239C\";\n    for (int j\
    \ = 0; j < N; ++j) std::cerr << std::setw(w) << m[i][j] << \" \";\n    std::cerr\
    \ << \"\u239F\";\n    std::cerr << std::endl;\n  }\n  std::cerr << \"\u239D\"\
    \ << std::string((w + 1) * N, ' ') << \"\u23A0\" << std::endl;\n#endif\n}\n"
  code: "#pragma once\n#include <iomanip>\n#include <iostream>\n#include <string>\n\
    \ntemplate <typename M>\nvoid matrix_viewer([[maybe_unused]] const M &m, [[maybe_unused]]\
    \ int w = 10) {\n#ifdef DEBUG\n  const int N = m.size();\n  std::cerr << \"\u239B\
    \" << std::string((w + 1) * N, ' ') << \"\u239E\" << std::endl;\n  for (int i\
    \ = 0; i < N; ++i) {\n    std::cerr << \"\u239C\";\n    for (int j = 0; j < N;\
    \ ++j) std::cerr << std::setw(w) << m[i][j] << \" \";\n    std::cerr << \"\u239F\
    \";\n    std::cerr << std::endl;\n  }\n  std::cerr << \"\u239D\" << std::string((w\
    \ + 1) * N, ' ') << \"\u23A0\" << std::endl;\n#endif\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Debug/matrix_viewer.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Debug/matrix_viewer.cpp
layout: document
title: Matrix viewer
---

## Operations

## Requirements

## Notes

## Problems

## References
