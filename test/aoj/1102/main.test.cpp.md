---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Parser/parser.cpp
    title: Parsing
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102
  bundledCode: "#line 1 \"test/aoj/1102/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102\"\
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
    }\n#line 6 \"test/aoj/1102/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstruct\
    \ complex {\n  int real, imag;\n  bool overflow;\n\n  complex(): real(0), imag(0),\
    \ overflow(false){}\n  complex(int real, int imag = 0): real(real), imag(imag),\
    \ overflow(false){\n    if(abs(real) > 10000 or abs(imag) > 10000) overflow =\
    \ true;\n  }\n  complex(bool overflow): real(0), imag(0), overflow(true){}\n\n\
    \  friend complex operator+(const complex &a, const complex &b){\n    if(a.overflow\
    \ or b.overflow) return complex(true);\n    return complex(a.real + b.real, a.imag\
    \ + b.imag);\n  }\n\n  friend complex operator-(const complex &a, const complex\
    \ &b){\n    if(a.overflow or b.overflow) return complex(true);\n    return complex(a.real\
    \ - b.real, a.imag - b.imag);\n  }\n\n  friend complex operator-(const complex\
    \ &a){\n    if(a.overflow) return complex(true);\n    return complex(-a.real,\
    \ -a.imag);\n  }\n\n  friend complex operator*(const complex &a, const complex\
    \ &b){\n    if(a.overflow or b.overflow) return complex(true);\n    return complex(a.real\
    \ * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);\n  }\n\n  complex&\
    \ operator=(const complex &a){\n    this->real = a.real;\n    this->imag = a.imag;\n\
    \    this->overflow = a.overflow;\n    return *this;\n  }\n\n  complex& operator+=(const\
    \ complex &a){\n    *this = *this + a;\n    return *this;\n  }\n\n  complex& operator-=(const\
    \ complex &a){\n    *this = *this - a;\n    return *this;\n  }\n\n  complex& operator*=(const\
    \ complex &a){\n    *this = *this * a;\n    return *this;\n  }\n};\n\n\nstd::ostream&\
    \ operator<<(std::ostream &os, const complex &a){\n  if(a.overflow) os << \"overflow\"\
    ;\n  else{\n    if(a.real == 0 and a.imag == 0) os << 0;\n    else{\n      if(a.real){\n\
    \        os << a.real;\n      }\n      if(a.imag){\n        if(a.imag > 0 and\
    \ a.real) os << \"+\";\n        os << a.imag;\n        os << \"i\";\n      }\n\
    \    }\n  }\n  return os;\n}\n\n\nstruct parser : hl::parser {\n  parser(const\
    \ std::string &s): hl::parser(s){}\n\n  complex number(){\n    bool neg = false;\n\
    \    if(check_and_ignore('-')) neg = true;\n\n    complex ret;\n\n    if(digit()){\n\
    \      ret = get_number<complex>();\n\n      if(check_and_ignore('i')){\n    \
    \    ret *= complex(0, 1);\n      }\n    }else{\n      if(check_and_ignore('i')){\n\
    \        ret = complex(0, 1);\n      }\n    }\n\n    if(neg) ret = -ret;\n\n \
    \   return ret;\n  }\n\n  complex factor(){\n    complex ret;\n\n    if(check_and_ignore('(')){\n\
    \      ret = expression();\n      ignore(')');\n    }else{\n      ret = number();\n\
    \    }\n\n    return ret;\n  }\n\n  complex term(){\n    complex ret = factor();\n\
    \n    while(1){\n      if(check_and_ignore('*')){\n        ret *= factor();\n\
    \      }else{\n        break;\n      }\n    }\n\n    return ret;\n  }\n\n  complex\
    \ expression(){\n    complex ret = term();\n\n    while(1){\n      if(check_and_ignore('+')){\n\
    \        ret += term();\n      }else if(check_and_ignore('-')){\n        ret -=\
    \ term();\n      }else{\n        break;\n      }\n    }\n\n    return ret;\n \
    \ }\n\n  complex run(){\n    return expression();\n  }\n};\n\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string s;\n\
    \  while(std::cin >> s){\n    std::cout << parser(s).run() << \"\\n\";\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/Parser/parser.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstruct complex {\n  int real, imag;\n  bool overflow;\n\
    \n  complex(): real(0), imag(0), overflow(false){}\n  complex(int real, int imag\
    \ = 0): real(real), imag(imag), overflow(false){\n    if(abs(real) > 10000 or\
    \ abs(imag) > 10000) overflow = true;\n  }\n  complex(bool overflow): real(0),\
    \ imag(0), overflow(true){}\n\n  friend complex operator+(const complex &a, const\
    \ complex &b){\n    if(a.overflow or b.overflow) return complex(true);\n    return\
    \ complex(a.real + b.real, a.imag + b.imag);\n  }\n\n  friend complex operator-(const\
    \ complex &a, const complex &b){\n    if(a.overflow or b.overflow) return complex(true);\n\
    \    return complex(a.real - b.real, a.imag - b.imag);\n  }\n\n  friend complex\
    \ operator-(const complex &a){\n    if(a.overflow) return complex(true);\n   \
    \ return complex(-a.real, -a.imag);\n  }\n\n  friend complex operator*(const complex\
    \ &a, const complex &b){\n    if(a.overflow or b.overflow) return complex(true);\n\
    \    return complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag\
    \ * b.real);\n  }\n\n  complex& operator=(const complex &a){\n    this->real =\
    \ a.real;\n    this->imag = a.imag;\n    this->overflow = a.overflow;\n    return\
    \ *this;\n  }\n\n  complex& operator+=(const complex &a){\n    *this = *this +\
    \ a;\n    return *this;\n  }\n\n  complex& operator-=(const complex &a){\n   \
    \ *this = *this - a;\n    return *this;\n  }\n\n  complex& operator*=(const complex\
    \ &a){\n    *this = *this * a;\n    return *this;\n  }\n};\n\n\nstd::ostream&\
    \ operator<<(std::ostream &os, const complex &a){\n  if(a.overflow) os << \"overflow\"\
    ;\n  else{\n    if(a.real == 0 and a.imag == 0) os << 0;\n    else{\n      if(a.real){\n\
    \        os << a.real;\n      }\n      if(a.imag){\n        if(a.imag > 0 and\
    \ a.real) os << \"+\";\n        os << a.imag;\n        os << \"i\";\n      }\n\
    \    }\n  }\n  return os;\n}\n\n\nstruct parser : hl::parser {\n  parser(const\
    \ std::string &s): hl::parser(s){}\n\n  complex number(){\n    bool neg = false;\n\
    \    if(check_and_ignore('-')) neg = true;\n\n    complex ret;\n\n    if(digit()){\n\
    \      ret = get_number<complex>();\n\n      if(check_and_ignore('i')){\n    \
    \    ret *= complex(0, 1);\n      }\n    }else{\n      if(check_and_ignore('i')){\n\
    \        ret = complex(0, 1);\n      }\n    }\n\n    if(neg) ret = -ret;\n\n \
    \   return ret;\n  }\n\n  complex factor(){\n    complex ret;\n\n    if(check_and_ignore('(')){\n\
    \      ret = expression();\n      ignore(')');\n    }else{\n      ret = number();\n\
    \    }\n\n    return ret;\n  }\n\n  complex term(){\n    complex ret = factor();\n\
    \n    while(1){\n      if(check_and_ignore('*')){\n        ret *= factor();\n\
    \      }else{\n        break;\n      }\n    }\n\n    return ret;\n  }\n\n  complex\
    \ expression(){\n    complex ret = term();\n\n    while(1){\n      if(check_and_ignore('+')){\n\
    \        ret += term();\n      }else if(check_and_ignore('-')){\n        ret -=\
    \ term();\n      }else{\n        break;\n      }\n    }\n\n    return ret;\n \
    \ }\n\n  complex run(){\n    return expression();\n  }\n};\n\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string s;\n\
    \  while(std::cin >> s){\n    std::cout << parser(s).run() << \"\\n\";\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/Parser/parser.cpp
  isVerificationFile: true
  path: test/aoj/1102/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1102/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1102/main.test.cpp
- /verify/test/aoj/1102/main.test.cpp.html
title: test/aoj/1102/main.test.cpp
---
