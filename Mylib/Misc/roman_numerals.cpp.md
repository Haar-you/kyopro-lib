---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/roman_numerals.cpp\"\n#include <string>\n\nnamespace\
    \ haar_lib::misn {\n  int roman_to_num(std::string s){\n    int ret = 0;\n\n \
    \   for(int i = 0; i < (int)s.size(); ++i){\n      switch(s[i]){\n      case 'I':\
    \ {\n        if(i + 1 < (int)s.size() and (s[i + 1] == 'V' or s[i + 1] == 'X')){\n\
    \          ret -= 1;\n        }else{\n          ret += 1;\n        }\n       \
    \ break;\n      }\n\n      case 'V': ret += 5; break;\n\n      case 'X': {\n \
    \       if(i + 1 < (int)s.size() and (s[i + 1] == 'L' or s[i + 1] == 'C')){\n\
    \          ret -= 10;\n        }else{\n          ret += 10;\n        }\n     \
    \   break;\n      }\n\n      case 'L': ret += 50; break;\n\n      case 'C': {\n\
    \        if(i + 1 < (int)s.size() and (s[i + 1] == 'D' or s[i + 1] == 'M')){\n\
    \          ret -= 100;\n        }else{\n          ret += 100;\n        }\n   \
    \     break;\n      }\n\n      case 'D': ret += 500; break;\n\n      case 'M':\
    \ ret += 1000; break;\n      }\n    }\n\n    return ret;\n  }\n\n  std::string\
    \ num_to_roman(int n){\n    std::string ret = \"\";\n\n    if(n >= 1000){\n  \
    \    int k = n / 1000;\n      ret += std::string(k, 'M');\n      n %= 1000;\n\
    \    }\n\n    if(n >= 100){\n      int k = n / 100;\n      if(k <= 3) ret += std::string(k,\
    \ 'C');\n      else if(k == 4) ret += \"CD\";\n      else if(k <= 8) ret += \"\
    D\" + std::string(k - 5, 'C');\n      else ret += \"CM\";\n\n      n %= 100;\n\
    \    }\n\n    if(n >= 10){\n      int k = n / 10;\n      if(k <= 3) ret += std::string(k,\
    \ 'X');\n      else if(k == 4) ret += \"XL\";\n      else if(k <= 8) ret += \"\
    L\" + std::string(k - 5, 'X');\n      else ret += \"XC\";\n\n      n %= 10;\n\
    \    }\n\n    int k = n;\n    if(k <= 3) ret += std::string(k, 'I');\n    else\
    \ if(k == 4) ret += \"IV\";\n    else if(k <= 8) ret += \"V\" + std::string(k\
    \ - 5, 'I');\n    else ret += \"IX\";\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <string>\n\nnamespace haar_lib::misn {\n  int roman_to_num(std::string\
    \ s){\n    int ret = 0;\n\n    for(int i = 0; i < (int)s.size(); ++i){\n     \
    \ switch(s[i]){\n      case 'I': {\n        if(i + 1 < (int)s.size() and (s[i\
    \ + 1] == 'V' or s[i + 1] == 'X')){\n          ret -= 1;\n        }else{\n   \
    \       ret += 1;\n        }\n        break;\n      }\n\n      case 'V': ret +=\
    \ 5; break;\n\n      case 'X': {\n        if(i + 1 < (int)s.size() and (s[i +\
    \ 1] == 'L' or s[i + 1] == 'C')){\n          ret -= 10;\n        }else{\n    \
    \      ret += 10;\n        }\n        break;\n      }\n\n      case 'L': ret +=\
    \ 50; break;\n\n      case 'C': {\n        if(i + 1 < (int)s.size() and (s[i +\
    \ 1] == 'D' or s[i + 1] == 'M')){\n          ret -= 100;\n        }else{\n   \
    \       ret += 100;\n        }\n        break;\n      }\n\n      case 'D': ret\
    \ += 500; break;\n\n      case 'M': ret += 1000; break;\n      }\n    }\n\n  \
    \  return ret;\n  }\n\n  std::string num_to_roman(int n){\n    std::string ret\
    \ = \"\";\n\n    if(n >= 1000){\n      int k = n / 1000;\n      ret += std::string(k,\
    \ 'M');\n      n %= 1000;\n    }\n\n    if(n >= 100){\n      int k = n / 100;\n\
    \      if(k <= 3) ret += std::string(k, 'C');\n      else if(k == 4) ret += \"\
    CD\";\n      else if(k <= 8) ret += \"D\" + std::string(k - 5, 'C');\n      else\
    \ ret += \"CM\";\n\n      n %= 100;\n    }\n\n    if(n >= 10){\n      int k =\
    \ n / 10;\n      if(k <= 3) ret += std::string(k, 'X');\n      else if(k == 4)\
    \ ret += \"XL\";\n      else if(k <= 8) ret += \"L\" + std::string(k - 5, 'X');\n\
    \      else ret += \"XC\";\n\n      n %= 10;\n    }\n\n    int k = n;\n    if(k\
    \ <= 3) ret += std::string(k, 'I');\n    else if(k == 4) ret += \"IV\";\n    else\
    \ if(k <= 8) ret += \"V\" + std::string(k - 5, 'I');\n    else ret += \"IX\";\n\
    \n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/roman_numerals.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/roman_numerals.cpp
layout: document
title: Roman numerals
---

## Operations

## Requirements

## Notes

## Problems

## References
