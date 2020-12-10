---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/kth_root_integer.cpp
    title: Kth root integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test/yosupo-judge/kth_root_integer/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#include <iostream>\n\
    #line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n#include\
    \ <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 2 \"Mylib/Number/kth_root_integer.cpp\"\n#include <cassert>\n\
    #include <cstdint>\n\nnamespace haar_lib {\n  uint64_t kth_root(uint64_t a, int\
    \ k){\n    assert(k >= 1);\n    if(k == 1) return a;\n    if(a == 1) return 1;\n\
    \n    uint64_t lb = 0, ub = a;\n\n    auto check =\n      [](uint64_t a, int k,\
    \ uint64_t n){\n        uint64_t r = 1;\n\n        while(k > 0){\n          if(k\
    \ & 1){\n            if(__builtin_umulll_overflow(r, a, (unsigned long long int*)&r))\
    \ return false;\n          }\n          if(__builtin_umulll_overflow(a, a, (unsigned\
    \ long long int*)&a) and k > 1) return false;\n          k >>= 1;\n        }\n\
    \n        return r <= n;\n      };\n\n    while(ub - lb > 1){\n      uint64_t\
    \ mid = lb + (ub - lb) / 2;\n\n      if(check(mid, k, a)){\n        lb = mid;\n\
    \      }else{\n        ub = mid;\n      }\n    }\n\n    return lb;\n  }\n}\n#line\
    \ 6 \"test/yosupo-judge/kth_root_integer/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ T; std::cin >> T;\n\n  for(auto [A, K] : hl::input_tuples<uint64_t, uint64_t>(T)){\n\
    \    std::cout << hl::kth_root(A, K) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include <iostream>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/Number/kth_root_integer.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int T; std::cin >> T;\n\n  for(auto [A, K] : hl::input_tuples<uint64_t, uint64_t>(T)){\n\
    \    std::cout << hl::kth_root(A, K) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Number/kth_root_integer.cpp
  isVerificationFile: true
  path: test/yosupo-judge/kth_root_integer/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/kth_root_integer/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/kth_root_integer/main.test.cpp
- /verify/test/yosupo-judge/kth_root_integer/main.test.cpp.html
title: test/yosupo-judge/kth_root_integer/main.test.cpp
---
