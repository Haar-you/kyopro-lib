---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':x:'
    path: Mylib/Typical/max_rectangle_in_histogram.cpp
    title: Largest rectangle in histogram
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/aoj/DPL_3_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include <iostream>\n#include <vector>\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N) {\n    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/Typical/max_rectangle_in_histogram.cpp\"\
    \n#include <stack>\n#include <utility>\n#line 5 \"Mylib/Typical/max_rectangle_in_histogram.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T max_rectangle_in_histogram(const\
    \ std::vector<T> &h) {\n    std::stack<std::pair<T, int>> st;\n    T ret = 0;\n\
    \n    for (size_t i = 0; i < h.size(); ++i) {\n      if (st.empty()) {\n     \
    \   st.emplace(h[i], i);\n      } else if (st.top().first < h[i]) {\n        st.emplace(h[i],\
    \ i);\n      } else if (st.top().first > h[i]) {\n        int j = i;\n       \
    \ while (not st.empty() and st.top().first > h[i]) {\n          ret = std::max(ret,\
    \ st.top().first * ((T) i - st.top().second));\n          j   = st.top().second;\n\
    \          st.pop();\n        }\n        st.emplace(h[i], j);\n      }\n    }\n\
    \n    while (not st.empty()) {\n      ret = std::max(ret, st.top().first * ((T)\
    \ h.size() - st.top().second));\n      st.pop();\n    }\n\n    return ret;\n \
    \ }\n}  // namespace haar_lib\n#line 7 \"test/aoj/DPL_3_C/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main() {\n  int N;\n  std::cin >> N;\n\n  auto\
    \ h = hl::input_vector<int64_t>(N);\n\n  auto ans = hl::max_rectangle_in_histogram(h);\n\
    \n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/Typical/max_rectangle_in_histogram.cpp\"\n\nnamespace hl =\
    \ haar_lib;\n\nint main() {\n  int N;\n  std::cin >> N;\n\n  auto h = hl::input_vector<int64_t>(N);\n\
    \n  auto ans = hl::max_rectangle_in_histogram(h);\n\n  std::cout << ans << std::endl;\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/Typical/max_rectangle_in_histogram.cpp
  isVerificationFile: true
  path: test/aoj/DPL_3_C/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_3_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_C/main.test.cpp
- /verify/test/aoj/DPL_3_C/main.test.cpp.html
title: test/aoj/DPL_3_C/main.test.cpp
---