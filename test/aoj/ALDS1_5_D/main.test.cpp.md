---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/inversion_number.cpp
    title: Inversion number
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_5_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n#line 3 \"\
    Mylib/Typical/inversion_number.cpp\"\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  namespace inversion_number_impl {\n    template <typename T, typename Compare>\n\
    \    int64_t rec(std::vector<T> &a, const Compare &compare){\n      const int\
    \ n = a.size();\n      if(n <= 1) return 0;\n\n      int64_t ret = 0;\n\n    \
    \  std::vector<T> b(a.begin(), a.begin() + n / 2);\n      std::vector<T> c(a.begin()\
    \ + n / 2, a.end());\n\n      ret += rec(b, compare);\n      ret += rec(c, compare);\n\
    \n      int ai = 0, bi = 0, ci = 0;\n\n      while(ai < n){\n        if(bi < (int)b.size()\
    \ and (ci == (int)c.size() or not compare(b[bi], c[ci]))){\n          a[ai] =\
    \ b[bi];\n          ++bi;\n        }else{\n          ret += n / 2 - bi;\n    \
    \      a[ai] = c[ci];\n          ++ci;\n        }\n        ++ai;\n      }\n\n\
    \      return ret;\n    }\n  }\n\n  template <typename T, typename Compare>\n\
    \  int64_t inversion_number(std::vector<T> a, const Compare &compare){\n    return\
    \ inversion_number_impl::rec(a, compare);\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 8 \"test/aoj/ALDS1_5_D/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int n; std::cin >> n;\n\n  auto a = hl::input_vector<int>(n);\n\n  auto ans\
    \ = hl::inversion_number(a, std::greater<int>());\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n#include \"\
    Mylib/Typical/inversion_number.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\n\
    \nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  auto a\
    \ = hl::input_vector<int>(n);\n\n  auto ans = hl::inversion_number(a, std::greater<int>());\n\
    \  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/inversion_number.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_5_D/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_5_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_5_D/main.test.cpp
- /verify/test/aoj/ALDS1_5_D/main.test.cpp.html
title: test/aoj/ALDS1_5_D/main.test.cpp
---
