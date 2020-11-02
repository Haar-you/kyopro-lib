---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/sieve_atkin.cpp
    title: Sieve of Atkin
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo-judge/enumerate_primes/main.atkin.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n\
    #include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 3 \"Mylib/Number/Prime/sieve_atkin.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  class atkin_sieve {\n    std::vector<bool>\
    \ is_prime_;\n\n  public:\n    atkin_sieve(){}\n    atkin_sieve(int MAX): is_prime_(MAX\
    \ + 1){\n      for(int64_t i = 1; i * i <= MAX; ++i){\n        for(int64_t j =\
    \ 1; j * j <= MAX; ++j){\n          {\n            auto n = 4LL * i * i + j *\
    \ j;\n            if(n <= MAX and (n % 12 == 1 or n % 12 == 5)){\n           \
    \   is_prime_[n] = not is_prime_[n];\n            }\n          }\n          {\n\
    \            auto n = 3LL * i * i + j * j;\n            if(n <= MAX and n % 12\
    \ == 7){\n              is_prime_[n] = not is_prime_[n];\n            }\n    \
    \      }\n          if(i > j){\n            auto n = 3LL * i * i - j * j;\n  \
    \          if(n <= MAX and n % 12 == 11){\n              is_prime_[n] = not is_prime_[n];\n\
    \            }\n          }\n        }\n      }\n\n      for(int64_t i = 5; i\
    \ * i <= MAX; ++i){\n        if(is_prime_[i]){\n          for(int64_t k = i *\
    \ i, j = k; j <= MAX; j += k){\n            is_prime_[j] = false;\n          }\n\
    \        }\n      }\n\n      is_prime_[2] = is_prime_[3] = true;\n    }\n\n  \
    \  bool operator()(int i) const {\n      return is_prime_[i];\n    }\n  };\n}\n\
    #line 7 \"test/yosupo-judge/enumerate_primes/main.atkin.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, A, B; std::cin >> N >> A >> B;\n\n  const auto is_prime = hl::atkin_sieve(N);\n\
    \n  int pi = 0;\n  std::vector<int> ans;\n\n  for(int i = 2; i <= N; ++i){\n \
    \   if(is_prime(i)){\n      if((pi - B) % A == 0){\n        ans.push_back(i);\n\
    \      }\n      ++pi;\n    }\n  }\n\n  std::cout << pi << \" \" << ans.size()\
    \ << \"\\n\"\n            << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"Mylib/IO/join.cpp\"\n#include\
    \ \"Mylib/Number/Prime/sieve_atkin.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, A, B; std::cin\
    \ >> N >> A >> B;\n\n  const auto is_prime = hl::atkin_sieve(N);\n\n  int pi =\
    \ 0;\n  std::vector<int> ans;\n\n  for(int i = 2; i <= N; ++i){\n    if(is_prime(i)){\n\
    \      if((pi - B) % A == 0){\n        ans.push_back(i);\n      }\n      ++pi;\n\
    \    }\n  }\n\n  std::cout << pi << \" \" << ans.size() << \"\\n\"\n         \
    \   << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/join.cpp
  - Mylib/Number/Prime/sieve_atkin.cpp
  isVerificationFile: true
  path: test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
  requiredBy: []
  timestamp: '2020-11-02 13:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
- /verify/test/yosupo-judge/enumerate_primes/main.atkin.test.cpp.html
title: test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
---
