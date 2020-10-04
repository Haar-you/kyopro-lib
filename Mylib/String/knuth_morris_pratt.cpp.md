---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_B/main.kmp.test.cpp
    title: test/aoj/ALDS1_14_B/main.kmp.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/knuth_morris_pratt.cpp\"\n#include <vector>\n\
    #include <string>\n#include <string_view>\n\nnamespace haar_lib {\n  class knuth_morris_pratt\
    \ {\n    int M_;\n    std::string pattern_;\n    std::vector<int> table_;\n\n\
    \  public:\n    knuth_morris_pratt(){}\n    knuth_morris_pratt(std::string p):\
    \ M_(p.size()), pattern_(p), table_(M_ + 1){\n      table_[0] = -1;\n      table_[1]\
    \ = 0;\n\n      pattern_.push_back('\\0');\n\n      for(int i = 2, j = 0; i <=\
    \ M_;){\n        if(pattern_[i - 1] == pattern_[j]){\n          table_[i] = j\
    \ + 1;\n          ++i;\n          ++j;\n        }else if(j > 0){\n          j\
    \ = table_[j];\n        }else{\n          table_[i] = 0;\n          ++i;\n   \
    \     }\n      }\n    }\n\n    std::vector<int> match(const std::string_view &s)\
    \ const {\n      std::vector<int> ret;\n      const int N = s.size();\n\n    \
    \  for(int m = 0, i = 0; m + i < N;){\n        if(pattern_[i] == s[m + i]){\n\
    \          ++i;\n          if(i == M_){\n            ret.push_back(m);\n     \
    \       m += i - table_[i];\n            if(i > 0) i = table_[i];\n          }\n\
    \        }else{\n          m += i - table_[i];\n          if(i > 0) i = table_[i];\n\
    \        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <string_view>\n\
    \nnamespace haar_lib {\n  class knuth_morris_pratt {\n    int M_;\n    std::string\
    \ pattern_;\n    std::vector<int> table_;\n\n  public:\n    knuth_morris_pratt(){}\n\
    \    knuth_morris_pratt(std::string p): M_(p.size()), pattern_(p), table_(M_ +\
    \ 1){\n      table_[0] = -1;\n      table_[1] = 0;\n\n      pattern_.push_back('\\\
    0');\n\n      for(int i = 2, j = 0; i <= M_;){\n        if(pattern_[i - 1] ==\
    \ pattern_[j]){\n          table_[i] = j + 1;\n          ++i;\n          ++j;\n\
    \        }else if(j > 0){\n          j = table_[j];\n        }else{\n        \
    \  table_[i] = 0;\n          ++i;\n        }\n      }\n    }\n\n    std::vector<int>\
    \ match(const std::string_view &s) const {\n      std::vector<int> ret;\n    \
    \  const int N = s.size();\n\n      for(int m = 0, i = 0; m + i < N;){\n     \
    \   if(pattern_[i] == s[m + i]){\n          ++i;\n          if(i == M_){\n   \
    \         ret.push_back(m);\n            m += i - table_[i];\n            if(i\
    \ > 0) i = table_[i];\n          }\n        }else{\n          m += i - table_[i];\n\
    \          if(i > 0) i = table_[i];\n        }\n      }\n\n      return ret;\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/knuth_morris_pratt.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
