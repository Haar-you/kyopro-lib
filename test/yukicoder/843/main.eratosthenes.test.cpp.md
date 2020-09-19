---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Prime/eratosthenes_sieve.cpp
    title: Sieve of Eratosthenes
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/843
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/yukicoder/843/main.eratosthenes.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/843\"\n\n#include <iostream>\n#line\
    \ 2 \"Mylib/Number/Prime/eratosthenes_sieve.cpp\"\n#include <vector>\n\nnamespace\
    \ haar_lib {\n  class eratosthenes_sieve {\n    std::vector<bool> is_prime;\n\n\
    \  public:\n    eratosthenes_sieve(int MAX): is_prime(MAX + 1){\n      is_prime.flip();\n\
    \      is_prime[0] = is_prime[1] = false;\n\n      for(int i = 2; i <= MAX; ++i){\n\
    \        if(is_prime[i]){\n          for(int j = 2 * i; j <= MAX; j += i){\n \
    \           is_prime[j] = false;\n          }\n        }\n      }\n    }\n\n \
    \   bool operator()(int i) const {\n      return is_prime[i];\n    }\n  };\n}\n\
    #line 5 \"test/yukicoder/843/main.eratosthenes.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  hl::eratosthenes_sieve is_prime(500000);\n\n  int N; std::cin\
    \ >> N;\n\n  int64_t ans = 0;\n\n  if(N >= 2){\n    ans += 1;\n\n    int t = 0;\n\
    \    for(int64_t r = 3; r <= N; ++r){\n      int64_t q = r * r - 2;\n      if(q\
    \ <= N and is_prime(r) and is_prime(q)) ++t;\n    }\n\n    ans += t * 2;\n  }\n\
    \n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/843\"\n\n#include <iostream>\n\
    #include \"Mylib/Number/Prime/eratosthenes_sieve.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  hl::eratosthenes_sieve is_prime(500000);\n\n  int N; std::cin\
    \ >> N;\n\n  int64_t ans = 0;\n\n  if(N >= 2){\n    ans += 1;\n\n    int t = 0;\n\
    \    for(int64_t r = 3; r <= N; ++r){\n      int64_t q = r * r - 2;\n      if(q\
    \ <= N and is_prime(r) and is_prime(q)) ++t;\n    }\n\n    ans += t * 2;\n  }\n\
    \n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Prime/eratosthenes_sieve.cpp
  isVerificationFile: true
  path: test/yukicoder/843/main.eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/843/main.eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/843/main.eratosthenes.test.cpp
- /verify/test/yukicoder/843/main.eratosthenes.test.cpp.html
title: test/yukicoder/843/main.eratosthenes.test.cpp
---
