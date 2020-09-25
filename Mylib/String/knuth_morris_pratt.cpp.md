---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B/main.kmp.test.cpp
    title: test/aoj/ALDS1_14_B/main.kmp.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/String/knuth_morris_pratt.cpp\"\n#include <vector>\n\
    #include <string>\n#include <string_view>\n\nnamespace haar_lib {\n  struct knuth_morris_pratt\
    \ {\n    int M;\n    std::string pattern;\n    std::vector<int> table;\n\n   \
    \ knuth_morris_pratt(std::string p): M(p.size()), pattern(p), table(M + 1){\n\
    \      table[0] = -1;\n      table[1] = 0;\n\n      pattern.push_back('\\0');\n\
    \n      for(int i = 2, j = 0; i <= M;){\n        if(pattern[i - 1] == pattern[j]){\n\
    \          table[i] = j + 1;\n          ++i;\n          ++j;\n        }else if(j\
    \ > 0){\n          j = table[j];\n        }else{\n          table[i] = 0;\n  \
    \        ++i;\n        }\n      }\n    }\n\n    std::vector<int> match(const std::string_view\
    \ &s) const {\n      std::vector<int> ret;\n      const int N = s.size();\n\n\
    \      for(int m = 0, i = 0; m + i < N;){\n        if(pattern[i] == s[m + i]){\n\
    \          ++i;\n          if(i == M){\n            ret.push_back(m);\n      \
    \      m += i - table[i];\n            if(i > 0) i = table[i];\n          }\n\
    \        }else{\n          m += i - table[i];\n          if(i > 0) i = table[i];\n\
    \        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <string_view>\n\
    \nnamespace haar_lib {\n  struct knuth_morris_pratt {\n    int M;\n    std::string\
    \ pattern;\n    std::vector<int> table;\n\n    knuth_morris_pratt(std::string\
    \ p): M(p.size()), pattern(p), table(M + 1){\n      table[0] = -1;\n      table[1]\
    \ = 0;\n\n      pattern.push_back('\\0');\n\n      for(int i = 2, j = 0; i <=\
    \ M;){\n        if(pattern[i - 1] == pattern[j]){\n          table[i] = j + 1;\n\
    \          ++i;\n          ++j;\n        }else if(j > 0){\n          j = table[j];\n\
    \        }else{\n          table[i] = 0;\n          ++i;\n        }\n      }\n\
    \    }\n\n    std::vector<int> match(const std::string_view &s) const {\n    \
    \  std::vector<int> ret;\n      const int N = s.size();\n\n      for(int m = 0,\
    \ i = 0; m + i < N;){\n        if(pattern[i] == s[m + i]){\n          ++i;\n \
    \         if(i == M){\n            ret.push_back(m);\n            m += i - table[i];\n\
    \            if(i > 0) i = table[i];\n          }\n        }else{\n          m\
    \ += i - table[i];\n          if(i > 0) i = table[i];\n        }\n      }\n\n\
    \      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/knuth_morris_pratt.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B/main.kmp.test.cpp
documentation_of: Mylib/String/knuth_morris_pratt.cpp
layout: document
title: Knuth-Morris-Pratt algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法](https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%8C%E3%83%BC%E3%82%B9%E2%80%93%E3%83%A2%E3%83%AA%E3%82%B9%E2%80%93%E3%83%97%E3%83%A9%E3%83%83%E3%83%88%E6%B3%95)
