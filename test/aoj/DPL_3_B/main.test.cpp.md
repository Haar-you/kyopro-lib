---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Typical/MaxRectangleProblem/max_rectangle.cpp
    title: Largest rectangle
  - icon: ':x:'
    path: Mylib/Typical/MaxRectangleProblem/max_rectangle_in_histogram.cpp
    title: Largest rectangle in histogram
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
  bundledCode: "#line 1 \"test/aoj/DPL_3_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/MaxRectangleProblem/max_rectangle.cpp\"\
    \n#include <algorithm>\n#line 3 \"Mylib/Typical/MaxRectangleProblem/max_rectangle_in_histogram.cpp\"\
    \n#include <stack>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  T max_rectangle_in_histogram(const std::vector<T> &h){\n    std::stack<std::pair<T,\
    \ int>> st;\n    T ret = 0;\n\n    for(size_t i = 0; i < h.size(); ++i){\n   \
    \   if(st.empty()){\n        st.emplace(h[i], i);\n      }else if(st.top().first\
    \ < h[i]){\n        st.emplace(h[i], i);\n      }else if(st.top().first > h[i]){\n\
    \        int j = i;\n        while(not st.empty() and st.top().first > h[i]){\n\
    \          ret = std::max(ret, st.top().first * ((T)i - st.top().second));\n \
    \         j = st.top().second;\n          st.pop();\n        }\n        st.emplace(h[i],\
    \ j);\n      }\n    }\n\n    while(not st.empty()){\n      ret = std::max(ret,\
    \ st.top().first * ((T)h.size() - st.top().second));\n      st.pop();\n    }\n\
    \n    return ret;\n  }\n}\n#line 5 \"Mylib/Typical/MaxRectangleProblem/max_rectangle.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  int max_rectangle(const std::vector<std::vector<T>>\
    \ &d, T value){\n    const int H = d.size();\n    const int W = d[0].size();\n\
    \n    std::vector<std::vector<int>> c(H, std::vector<int>(W));\n    for(int i\
    \ = 0; i < H; ++i){\n      for(int j = 0; j < W; ++j){\n        if(d[i][j] ==\
    \ value) c[i][j] = 1;\n      }\n    }\n\n    for(int i = 1; i < H; ++i){\n   \
    \   for(int j = 0; j < W; ++j){\n        if(c[i][j]){\n          c[i][j] += c[i\
    \ - 1][j];\n        }\n      }\n    }\n\n    int ret = 0;\n    for(int i = 0;\
    \ i < H; ++i){\n      int t = max_rectangle_in_histogram<int>(c[i]);\n      ret\
    \ = std::max(ret, t);\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 7 \"test/aoj/DPL_3_B/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int H, W; std::cin >> H >> W;\n\n  auto c = hl::input_vector<int>(H, W);\n\n\
    \  auto ans = hl::max_rectangle(c, 0);\n  std::cout << ans << std::endl;\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/MaxRectangleProblem/max_rectangle.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int H, W; std::cin >> H >> W;\n\n  auto c = hl::input_vector<int>(H, W);\n\n\
    \  auto ans = hl::max_rectangle(c, 0);\n  std::cout << ans << std::endl;\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/MaxRectangleProblem/max_rectangle.cpp
  - Mylib/Typical/MaxRectangleProblem/max_rectangle_in_histogram.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_3_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 02:36:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_3_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_B/main.test.cpp
- /verify/test/aoj/DPL_3_B/main.test.cpp.html
title: test/aoj/DPL_3_B/main.test.cpp
---
