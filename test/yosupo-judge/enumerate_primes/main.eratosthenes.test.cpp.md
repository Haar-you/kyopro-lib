---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/sieve_eratosthenes.cpp
    title: Sieve of Eratosthenes
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n\
    #include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 3 \"Mylib/Number/Prime/sieve_eratosthenes.cpp\"\
    \n\nnamespace haar_lib {\n  class eratosthenes_sieve {\n    std::vector<bool>\
    \ is_prime_;\n\n  public:\n    eratosthenes_sieve(){}\n    eratosthenes_sieve(int\
    \ MAX): is_prime_((MAX + 1) / 2, true){\n      is_prime_[0] = false;\n\n     \
    \ for(int i = 3; i * i <= MAX; i += 2){\n        if(not is_prime_[i / 2]) continue;\n\
    \n        for(int j = i * i; j <= MAX; j += 2 * i){\n          is_prime_[j / 2]\
    \ = false;\n        }\n      }\n    }\n\n    bool operator()(int i) const {\n\
    \      if(i == 2) return true;\n      if(i % 2 == 0) return false;\n      return\
    \ is_prime_[i / 2];\n    }\n  };\n}\n#line 7 \"test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, A, B; std::cin >> N >> A >> B;\n\n  const auto is_prime = hl::eratosthenes_sieve(N);\n\
    \n  int pi = 0;\n  std::vector<int> ans;\n\n  for(int i = 2; i <= N; ++i){\n \
    \   if(is_prime(i)){\n      if((pi - B) % A == 0){\n        ans.push_back(i);\n\
    \      }\n      ++pi;\n    }\n  }\n\n  std::cout << pi << \" \" << ans.size()\
    \ << \"\\n\"\n            << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"Mylib/IO/join.cpp\"\n#include\
    \ \"Mylib/Number/Prime/sieve_eratosthenes.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, A, B; std::cin >> N >> A >> B;\n\n  const auto is_prime = hl::eratosthenes_sieve(N);\n\
    \n  int pi = 0;\n  std::vector<int> ans;\n\n  for(int i = 2; i <= N; ++i){\n \
    \   if(is_prime(i)){\n      if((pi - B) % A == 0){\n        ans.push_back(i);\n\
    \      }\n      ++pi;\n    }\n  }\n\n  std::cout << pi << \" \" << ans.size()\
    \ << \"\\n\"\n            << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/join.cpp
  - Mylib/Number/Prime/sieve_eratosthenes.cpp
  isVerificationFile: true
  path: test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2020-11-05 03:06:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
- /verify/test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp.html
title: test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
---
