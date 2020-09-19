---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Parser/parser.cpp
    title: Parsing
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Rational/rational.cpp
    title: Rational number
  - icon: ':heavy_check_mark:'
    path: Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp
    title: Gaussian elimination
  - icon: ':heavy_check_mark:'
    path: Mylib/String/split.cpp
    title: split
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: Mylib/IO/join.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300
  bundledCode: "#line 1 \"test/aoj/1300/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300\"\
    \n\n#include <iostream>\n#include <map>\n#include <string>\n#include <vector>\n\
    #line 3 \"Mylib/Parser/parser.cpp\"\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  struct parser {\n    using state = std::string::const_iterator;\n\n   \
    \ state cur, first, last;\n\n    parser(){}\n    parser(const std::string &s):\
    \ cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}\n\n    char peek() const\
    \ {return *cur;}\n\n    bool check(char c) const {\n      return *cur == c;\n\
    \    }\n\n    bool check(const std::string &s) const {\n      state temp = cur;\n\
    \      for(auto c : s){\n        if(c != *temp) return false;\n        ++temp;\n\
    \      }\n      return true;\n    }\n\n    void ignore(char c){\n      assert(*cur\
    \ == c);\n      ++cur;\n    }\n\n    void ignore(){\n      ++cur;\n    }\n\n \
    \   void ignore(const std::string &s){\n      for(auto c : s){\n        assert(*cur\
    \ == c);\n        ++cur;\n      }\n    }\n\n    template <class Checker>\n   \
    \ void ignore_if(const Checker &f){\n      assert(f(*cur));\n      ++cur;\n  \
    \  }\n\n    bool check_and_ignore(char c){\n      if(*cur != c) return false;\n\
    \      ++cur;\n      return true;\n    }\n\n    bool end() const {return cur ==\
    \ last;}\n    bool digit() const {return isdigit(*cur);}\n    bool alpha() const\
    \ {return isalpha(*cur);}\n    bool lower() const {return islower(*cur);}\n  \
    \  bool upper() const {return isupper(*cur);}\n\n    char get_char(){\n      return\
    \ *(cur++);\n    }\n\n    int get_digit(){\n      return (int)(*(cur++) - '0');\n\
    \    }\n\n    template <typename Checker>\n    auto get_string(const Checker &f){\n\
    \      std::string ret;\n      while(f(peek())){\n        ret += peek();\n   \
    \     ignore();\n      }\n      return ret;\n    }\n\n    auto get_string_alpha(){\n\
    \      std::string ret;\n      while(isalpha(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    auto get_string_alnum(){\n\
    \      std::string ret;\n      while(isalnum(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    template <typename T>\n\
    \    T get_number(){\n      T ret = get_digit();\n      while(digit()){\n    \
    \    (ret *= 10) += (T)(get_digit());\n      }\n      return ret;\n    }\n  };\n\
    }\n#line 2 \"Mylib/Number/Rational/rational.cpp\"\n#include <numeric>\n#line 4\
    \ \"Mylib/Number/Rational/rational.cpp\"\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  class rational {\n  public:\n    int64_t nume, deno;\n    rational(): nume(0),\
    \ deno(1){}\n    rational(int64_t num): nume(num), deno(1){}\n    rational(int64_t\
    \ num, int64_t den){\n      int64_t g = std::gcd(num, den);\n      nume = num\
    \ / g;\n      deno = den / g;\n      if(deno < 0){\n        nume = -nume;\n  \
    \      deno = -deno;\n      }\n    }\n\n    auto operator+(const rational &b){\n\
    \      int64_t l = std::lcm((*this).deno, b.deno);\n      return rational(l /\
    \ (*this).deno * (*this).nume + l / b.deno * b.nume, l);\n    }\n\n    auto operator-(const\
    \ rational &b){\n      int64_t l = std::lcm((*this).deno, b.deno);\n      return\
    \ rational(l / (*this).deno * (*this).nume - l / b.deno * b.nume, l);\n    }\n\
    \n    auto operator*(const rational &b){\n      return rational((*this).nume *\
    \ b.nume, (*this).deno * b.deno);\n    }\n\n    auto operator/(const rational\
    \ &b){\n      return rational((*this).nume * b.deno, (*this).deno * b.nume);\n\
    \    }\n\n    auto& operator+=(const rational &a){*this = *this + a; return *this;}\n\
    \    auto& operator-=(const rational &a){*this = *this - a; return *this;}\n \
    \   auto& operator*=(const rational &a){*this = *this * a; return *this;}\n  \
    \  auto& operator/=(const rational &a){*this = *this / a; return *this;}\n\n \
    \   explicit operator double() const {return (double)nume / deno;}\n    explicit\
    \ operator long double() const {return (long double)nume / deno;}\n  };\n\n  std::ostream&\
    \ operator<<(std::ostream &os, const rational &r){\n    if(r.deno == 1) os <<\
    \ r.nume;\n    else os << r.nume << \"/\" << r.deno;\n    return os;\n  }\n\n\
    \  auto operator-(const rational &a){return rational(-a.nume, a.deno);}\n\n  bool\
    \ operator==(const rational &a, const rational &b){return a.nume == b.nume &&\
    \ a.deno == b.deno;}\n  bool operator!=(const rational &a, const rational &b){return\
    \ !(a == b);}\n  bool operator<(const rational &a, const rational &b){return a.nume\
    \ * b.deno < b.nume * a.deno;}\n  bool operator<=(const rational &a, const rational\
    \ &b){return a.nume * b.deno <= b.nume * a.deno;}\n  bool operator>(const rational\
    \ &a, const rational &b){return !(a <= b);}\n  bool operator>=(const rational\
    \ &a, const rational &b){return !(a < b);}\n\n  auto abs(const rational &a){return\
    \ rational(std::abs(a.nume), std::abs(a.deno));}\n}\n#line 3 \"Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <typename T>\n  int gaussian_elimination(std::vector<std::vector<T>>\
    \ &a){\n    const int h = a.size();\n    const int w = a[0].size();\n    int rank\
    \ = 0;\n\n    for(int j = 0; j < w; ++j){\n      int pivot = -1;\n\n      for(int\
    \ i = rank; i < h; ++i){\n        if(a[i][j] != 0){\n          pivot = i;\n  \
    \        break;\n        }\n      }\n\n      if(pivot == -1) continue;\n\n   \
    \   std::swap(a[pivot], a[rank]);\n\n      auto d = a[rank][j];\n      for(int\
    \ k = 0; k < w; ++k) a[rank][k] /= d;\n\n      for(int i = 0; i < h; ++i){\n \
    \       if(i == rank or a[i][j] == 0) continue;\n        auto d = a[i][j];\n \
    \       for(int k = 0; k < w; ++k){\n          a[i][k] -= a[rank][k] * d;\n  \
    \      }\n      }\n\n      ++rank;\n    }\n\n    return rank;\n  }\n}\n#line 4\
    \ \"Mylib/String/split.cpp\"\n\nnamespace haar_lib {\n  auto split(const std::string\
    \ &s, const std::string &delim){\n    std::vector<std::string> ret;\n\n    size_t\
    \ i = 0;\n    while(1){\n      size_t j = s.find(delim, i);\n      if(j == std::string::npos)\
    \ break;\n\n      ret.push_back(s.substr(i, j - i));\n\n      i = j + delim.size();\n\
    \    }\n\n    ret.push_back(s.substr(i, s.size() - i));\n\n    return ret;\n \
    \ }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#line 5 \"Mylib/IO/join.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter\
    \ first, Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n\
    \    for(auto it = first; it != last; ++it){\n      if(it != first) s << delim;\n\
    \      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 12 \"test/aoj/1300/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing result = std::map<std::string, int>;\n\n\
    struct parser : hl::parser {\n  parser(const std::string &s): hl::parser(s){}\n\
    \n  std::string atom(){\n    std::string ret;\n    ret += get_char();\n    if(lower())\
    \ ret += get_char();\n\n    return ret;\n  }\n\n  result factor(){\n    result\
    \ ret;\n    if(check_and_ignore('(')){\n      ret = expression();\n      ignore(')');\n\
    \    }else{\n      ret[atom()] = 1;\n    }\n\n    if(digit()){\n      int n =\
    \ get_number<int>();\n\n      for(auto &kv : ret){\n        kv.second *= n;\n\
    \      }\n    }\n\n    return ret;\n  }\n\n  result expression(){\n    result\
    \ ret = factor();\n\n    while(1){\n      if(digit() or alpha() or check('(')){\n\
    \        result temp = factor();\n\n        for(auto &[k, v] : temp){\n      \
    \    ret[k] += v;\n        }\n      }else{\n        break;\n      }\n    }\n\n\
    \    return ret;\n  }\n\n  result run(){\n    return expression();\n  }\n};\n\n\
    int main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string\
    \ s;\n  while(std::cin >> s){\n    if(s == \".\") break;\n\n    s.pop_back();\
    \ // pop period\n    auto a = hl::split(s, \"->\");\n    auto b = hl::split(a[0],\
    \ \"+\");\n    auto c = hl::split(a[1], \"+\");\n\n    std::map<std::string, int>\
    \ atoms;\n\n    std::vector<result> ress;\n    for(auto &x : b){\n      auto r\
    \ = parser(x).run();\n      for(auto &kv : r){\n        atoms[kv.first] = 0;\n\
    \      }\n      ress.push_back(r);\n    }\n    for(auto &x : c){\n      auto r\
    \ = parser(x).run();\n      for(auto &kv : r){\n        atoms[kv.first] = 0;\n\
    \        kv.second = -kv.second;\n      }\n      ress.push_back(r);\n    }\n\n\
    \    {\n      int i = 0;\n      for(auto &kv : atoms){\n        kv.second = i++;\n\
    \      }\n    }\n\n    std::vector<std::vector<hl::rational>> mat(atoms.size(),\
    \ std::vector<hl::rational>(ress.size()));\n    for(int i = 0; i < (int)ress.size();\
    \ ++i){\n      for(auto &[k, v] : ress[i]){\n        mat[atoms[k]][i] = v;\n \
    \     }\n    }\n\n    hl::gaussian_elimination(mat);\n\n    const int n = ress.size();\n\
    \    std::vector<hl::rational> ans(n);\n\n    ans[n - 1] = 1;\n\n    for(int i\
    \ = (int)atoms.size(); --i >= 0;){\n      if(mat[i].back() == 0) continue;\n\n\
    \      int k = 0;\n      hl::rational coef;\n      hl::rational cons;\n\n    \
    \  for(int j = 0; j < n; ++j){\n        if(ans[j] == 0){\n          k = j;\n \
    \         coef = mat[i][j];\n        }else{\n          cons += mat[i][j] * ans[j];\n\
    \        }\n      }\n\n      ans[k] = -cons / coef;\n    }\n\n    int64_t l =\
    \ 1;\n    for(int i = 0; i < n; ++i) l = std::lcm(l, ans[i].deno);\n\n    for(int\
    \ i = 0; i < n; ++i) ans[i] *= l;\n\n    std::cout << hl::join(ans.begin(), ans.end())\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300\"\
    \n\n#include <iostream>\n#include <map>\n#include <string>\n#include <vector>\n\
    #include \"Mylib/Parser/parser.cpp\"\n#include \"Mylib/Number/Rational/rational.cpp\"\
    \n#include \"Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp\"\
    \n#include \"Mylib/String/split.cpp\"\n#include \"Mylib/IO/join.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing result = std::map<std::string, int>;\n\nstruct parser\
    \ : hl::parser {\n  parser(const std::string &s): hl::parser(s){}\n\n  std::string\
    \ atom(){\n    std::string ret;\n    ret += get_char();\n    if(lower()) ret +=\
    \ get_char();\n\n    return ret;\n  }\n\n  result factor(){\n    result ret;\n\
    \    if(check_and_ignore('(')){\n      ret = expression();\n      ignore(')');\n\
    \    }else{\n      ret[atom()] = 1;\n    }\n\n    if(digit()){\n      int n =\
    \ get_number<int>();\n\n      for(auto &kv : ret){\n        kv.second *= n;\n\
    \      }\n    }\n\n    return ret;\n  }\n\n  result expression(){\n    result\
    \ ret = factor();\n\n    while(1){\n      if(digit() or alpha() or check('(')){\n\
    \        result temp = factor();\n\n        for(auto &[k, v] : temp){\n      \
    \    ret[k] += v;\n        }\n      }else{\n        break;\n      }\n    }\n\n\
    \    return ret;\n  }\n\n  result run(){\n    return expression();\n  }\n};\n\n\
    int main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string\
    \ s;\n  while(std::cin >> s){\n    if(s == \".\") break;\n\n    s.pop_back();\
    \ // pop period\n    auto a = hl::split(s, \"->\");\n    auto b = hl::split(a[0],\
    \ \"+\");\n    auto c = hl::split(a[1], \"+\");\n\n    std::map<std::string, int>\
    \ atoms;\n\n    std::vector<result> ress;\n    for(auto &x : b){\n      auto r\
    \ = parser(x).run();\n      for(auto &kv : r){\n        atoms[kv.first] = 0;\n\
    \      }\n      ress.push_back(r);\n    }\n    for(auto &x : c){\n      auto r\
    \ = parser(x).run();\n      for(auto &kv : r){\n        atoms[kv.first] = 0;\n\
    \        kv.second = -kv.second;\n      }\n      ress.push_back(r);\n    }\n\n\
    \    {\n      int i = 0;\n      for(auto &kv : atoms){\n        kv.second = i++;\n\
    \      }\n    }\n\n    std::vector<std::vector<hl::rational>> mat(atoms.size(),\
    \ std::vector<hl::rational>(ress.size()));\n    for(int i = 0; i < (int)ress.size();\
    \ ++i){\n      for(auto &[k, v] : ress[i]){\n        mat[atoms[k]][i] = v;\n \
    \     }\n    }\n\n    hl::gaussian_elimination(mat);\n\n    const int n = ress.size();\n\
    \    std::vector<hl::rational> ans(n);\n\n    ans[n - 1] = 1;\n\n    for(int i\
    \ = (int)atoms.size(); --i >= 0;){\n      if(mat[i].back() == 0) continue;\n\n\
    \      int k = 0;\n      hl::rational coef;\n      hl::rational cons;\n\n    \
    \  for(int j = 0; j < n; ++j){\n        if(ans[j] == 0){\n          k = j;\n \
    \         coef = mat[i][j];\n        }else{\n          cons += mat[i][j] * ans[j];\n\
    \        }\n      }\n\n      ans[k] = -cons / coef;\n    }\n\n    int64_t l =\
    \ 1;\n    for(int i = 0; i < n; ++i) l = std::lcm(l, ans[i].deno);\n\n    for(int\
    \ i = 0; i < n; ++i) ans[i] *= l;\n\n    std::cout << hl::join(ans.begin(), ans.end())\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Parser/parser.cpp
  - Mylib/Number/Rational/rational.cpp
  - Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp
  - Mylib/String/split.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/aoj/1300/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1300/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1300/main.test.cpp
- /verify/test/aoj/1300/main.test.cpp.html
title: test/aoj/1300/main.test.cpp
---
