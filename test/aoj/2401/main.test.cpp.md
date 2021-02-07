---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Parser/parser.cpp
    title: Parsing
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401
  bundledCode: "#line 1 \"test/aoj/2401/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401\"\
    \n\n#include <iostream>\n#include <string>\n#line 3 \"Mylib/Parser/parser.cpp\"\
    \n#include <cassert>\n\nnamespace haar_lib {\n  struct parser {\n    using state\
    \ = std::string::const_iterator;\n\n    state cur, first, last;\n\n    parser(){}\n\
    \    parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}\n\
    \n    char peek() const {return *cur;}\n\n    bool check(char c) const {\n   \
    \   return *cur == c;\n    }\n\n    bool check(const std::string &s) const {\n\
    \      state temp = cur;\n      for(auto c : s){\n        if(c != *temp) return\
    \ false;\n        ++temp;\n      }\n      return true;\n    }\n\n    void ignore(char\
    \ c){\n      assert(*cur == c);\n      ++cur;\n    }\n\n    void ignore(){\n \
    \     ++cur;\n    }\n\n    void ignore(const std::string &s){\n      for(auto\
    \ c : s){\n        assert(*cur == c);\n        ++cur;\n      }\n    }\n\n    template\
    \ <class Checker>\n    void ignore_if(const Checker &f){\n      assert(f(*cur));\n\
    \      ++cur;\n    }\n\n    bool check_and_ignore(char c){\n      if(*cur != c)\
    \ return false;\n      ++cur;\n      return true;\n    }\n\n    bool end() const\
    \ {return cur == last;}\n    bool digit() const {return isdigit(*cur);}\n    bool\
    \ alpha() const {return isalpha(*cur);}\n    bool lower() const {return islower(*cur);}\n\
    \    bool upper() const {return isupper(*cur);}\n\n    char get_char(){\n    \
    \  return *(cur++);\n    }\n\n    int get_digit(){\n      return (int)(*(cur++)\
    \ - '0');\n    }\n\n    template <typename Checker>\n    auto get_string(const\
    \ Checker &f){\n      std::string ret;\n      while(f(peek())){\n        ret +=\
    \ peek();\n        ignore();\n      }\n      return ret;\n    }\n\n    auto get_string_alpha(){\n\
    \      std::string ret;\n      while(isalpha(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    auto get_string_alnum(){\n\
    \      std::string ret;\n      while(isalnum(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    template <typename T>\n\
    \    T get_number(){\n      T ret = get_digit();\n      while(digit()){\n    \
    \    (ret *= 10) += (T)(get_digit());\n      }\n      return ret;\n    }\n  };\n\
    }\n#line 6 \"test/aoj/2401/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstruct\
    \ parser : hl::parser {\n  parser(const std::string &s): hl::parser(s){}\n\n \
    \ bool constant(){\n    bool ret = check('T');\n    ignore();\n    return ret;\n\
    \  }\n\n  bool negate(){\n    ignore('-');\n    return !expression();\n  }\n\n\
    \  std::string get_op(){\n    if(check_and_ignore('*')) return \"*\";\n    if(check_and_ignore('+'))\
    \ return \"+\";\n    ignore(\"->\"); return \"->\";\n  }\n\n  bool term(){\n \
    \   ignore('(');\n    bool left = expression();\n    auto op = get_op();\n   \
    \ bool right = expression();\n    ignore(')');\n\n    if(op == \"*\") return left\
    \ && right;\n    else if(op == \"+\") return left || right;\n    else return !left\
    \ || right;\n  }\n\n  bool expression(){\n    if(check('(')) return term();\n\
    \    if(check('-')) return negate();\n    return constant();\n  }\n\n  bool run(){\n\
    \    bool left = expression();\n    ignore('=');\n    bool right = expression();\n\
    \    return left == right;\n  }\n};\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  std::string s;\n  while(std::cin >> s){\n    if(s == \"#\") break;\n\n   \
    \ bool ans = true;\n\n    for(int i = 0; i < 1 << 11; ++i){\n      std::string\
    \ t(s);\n\n      for(auto &ch : t){\n        if(ch >= 'a' and ch <= 'k'){\n  \
    \        ch = i & (1 << (ch-'a')) ? 'T' : 'F';\n        }\n      }\n\n      ans\
    \ = ans and parser(t).run();\n    }\n\n    std::cout << (ans ? \"YES\" : \"NO\"\
    ) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/Parser/parser.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstruct parser : hl::parser {\n  parser(const std::string\
    \ &s): hl::parser(s){}\n\n  bool constant(){\n    bool ret = check('T');\n   \
    \ ignore();\n    return ret;\n  }\n\n  bool negate(){\n    ignore('-');\n    return\
    \ !expression();\n  }\n\n  std::string get_op(){\n    if(check_and_ignore('*'))\
    \ return \"*\";\n    if(check_and_ignore('+')) return \"+\";\n    ignore(\"->\"\
    ); return \"->\";\n  }\n\n  bool term(){\n    ignore('(');\n    bool left = expression();\n\
    \    auto op = get_op();\n    bool right = expression();\n    ignore(')');\n\n\
    \    if(op == \"*\") return left && right;\n    else if(op == \"+\") return left\
    \ || right;\n    else return !left || right;\n  }\n\n  bool expression(){\n  \
    \  if(check('(')) return term();\n    if(check('-')) return negate();\n    return\
    \ constant();\n  }\n\n  bool run(){\n    bool left = expression();\n    ignore('=');\n\
    \    bool right = expression();\n    return left == right;\n  }\n};\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string s;\n\
    \  while(std::cin >> s){\n    if(s == \"#\") break;\n\n    bool ans = true;\n\n\
    \    for(int i = 0; i < 1 << 11; ++i){\n      std::string t(s);\n\n      for(auto\
    \ &ch : t){\n        if(ch >= 'a' and ch <= 'k'){\n          ch = i & (1 << (ch-'a'))\
    \ ? 'T' : 'F';\n        }\n      }\n\n      ans = ans and parser(t).run();\n \
    \   }\n\n    std::cout << (ans ? \"YES\" : \"NO\") << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Parser/parser.cpp
  isVerificationFile: true
  path: test/aoj/2401/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2401/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2401/main.test.cpp
- /verify/test/aoj/2401/main.test.cpp.html
title: test/aoj/2401/main.test.cpp
---
