---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Prime/atkin_sieve.cpp
    title: Sieve of Atkin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/843
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/yukicoder/843/main.atkin.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/843\"\n\n#include <iostream>\n#line 2 \"\
    Mylib/Number/Prime/atkin_sieve.cpp\"\n#include <vector>\n#include <cstdint>\n\n\
    namespace haar_lib {\n  class atkin_sieve {\n    std::vector<bool> is_prime_;\n\
    \n  public:\n    atkin_sieve(){}\n    atkin_sieve(int MAX): is_prime_(MAX + 1){\n\
    \      for(int64_t i = 1; i * i <= MAX; ++i){\n        for(int64_t j = 1; j *\
    \ j <= MAX; ++j){\n          {\n            auto n = 4LL * i * i + j * j;\n  \
    \          if(n <= MAX and (n % 12 == 1 or n % 12 == 5)){\n              is_prime_[n]\
    \ = not is_prime_[n];\n            }\n          }\n          {\n            auto\
    \ n = 3LL * i * i + j * j;\n            if(n <= MAX and n % 12 == 7){\n      \
    \        is_prime_[n] = not is_prime_[n];\n            }\n          }\n      \
    \    if(i > j){\n            auto n = 3LL * i * i - j * j;\n            if(n <=\
    \ MAX and n % 12 == 11){\n              is_prime_[n] = not is_prime_[n];\n   \
    \         }\n          }\n        }\n      }\n\n      for(int64_t i = 5; i * i\
    \ <= MAX; ++i){\n        if(is_prime_[i]){\n          for(int64_t k = i * i, j\
    \ = k; j <= MAX; j += k){\n            is_prime_[j] = false;\n          }\n  \
    \      }\n      }\n\n      is_prime_[2] = is_prime_[3] = true;\n    }\n\n    bool\
    \ operator()(int i) const {\n      return is_prime_[i];\n    }\n  };\n}\n#line\
    \ 5 \"test/yukicoder/843/main.atkin.test.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  hl::atkin_sieve is_prime(500000);\n\n  int N; std::cin >> N;\n\n\
    \  int64_t ans = 0;\n\n  if(N >= 2){\n    ans += 1;\n\n    int t = 0;\n    for(int64_t\
    \ r = 3; r <= N; ++r){\n      int64_t q = r * r - 2;\n      if(q <= N and is_prime(r)\
    \ and is_prime(q)) ++t;\n    }\n\n    ans += t * 2;\n  }\n\n  std::cout << ans\
    \ << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/843\"\n\n#include <iostream>\n\
    #include \"Mylib/Number/Prime/atkin_sieve.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  hl::atkin_sieve is_prime(500000);\n\n  int N; std::cin >> N;\n\n\
    \  int64_t ans = 0;\n\n  if(N >= 2){\n    ans += 1;\n\n    int t = 0;\n    for(int64_t\
    \ r = 3; r <= N; ++r){\n      int64_t q = r * r - 2;\n      if(q <= N and is_prime(r)\
    \ and is_prime(q)) ++t;\n    }\n\n    ans += t * 2;\n  }\n\n  std::cout << ans\
    \ << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Prime/atkin_sieve.cpp
  isVerificationFile: true
  path: test/yukicoder/843/main.atkin.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/843/main.atkin.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/843/main.atkin.test.cpp
- /verify/test/yukicoder/843/main.atkin.test.cpp.html
title: test/yukicoder/843/main.atkin.test.cpp
---
