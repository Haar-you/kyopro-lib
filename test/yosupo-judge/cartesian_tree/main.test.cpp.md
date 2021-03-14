---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/cartesian_tree.cpp
    title: Cartesian tree
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/yosupo-judge/cartesian_tree/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include <iostream>\n\
    #include <tuple>\n#include <functional>\n#line 3 \"Mylib/IO/input_vector.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ input_vector(int N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N;\
    \ ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template <typename T>\n\
    \  std::vector<std::vector<T>> input_vector(int N, int M){\n    std::vector<std::vector<T>>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return\
    \ ret;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/Algorithm/cartesian_tree.cpp\"\
    \n#include <optional>\n\nnamespace haar_lib {\n  template <typename T, typename\
    \ Compare>\n  auto cartesian_tree(const std::vector<T> &a, Compare compare) ->\n\
    \    std::tuple<\n      int, // root\n      std::vector<std::optional<int>>, //\
    \ parent nodes\n      std::vector<std::optional<int>>, // left nodes\n      std::vector<std::optional<int>>\
    \ // right nodes\n      >\n  {\n    const int n = a.size();\n    std::vector<std::optional<int>>\
    \ p(n), l(n), r(n);\n    int root = 0;\n\n    for(int i = 0; i < n; ++i){\n  \
    \    if(i == 0){\n        continue;\n      }\n\n      int j = i - 1;\n\n     \
    \ while(1){\n        if(compare(a[i], a[j])){\n          if(not p[j]){\n     \
    \       p[j] = i;\n            l[i] = j;\n            root = i;\n            break;\n\
    \          }\n\n          j = *p[j];\n          continue;\n        }\n\n     \
    \   auto t = r[j];\n        r[j] = i;\n        p[i] = j;\n\n        l[i] = t;\n\
    \        if(t) p[*t] = i;\n\n        break;\n      }\n    }\n\n    return std::make_tuple(root,\
    \ p, l, r);\n  }\n}\n#line 9 \"test/yosupo-judge/cartesian_tree/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n  auto a = hl::input_vector<int>(N);\n\n  auto ans\
    \ = std::get<1>(hl::cartesian_tree(a, std::less<>()));\n\n  for(int i = 0; i <\
    \ N; ++i){\n    std::cout << ans[i].value_or(i) << \"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <iostream>\n#include <tuple>\n#include <functional>\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/Algorithm/cartesian_tree.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n  auto a = hl::input_vector<int>(N);\n\n  auto ans\
    \ = std::get<1>(hl::cartesian_tree(a, std::less<>()));\n\n  for(int i = 0; i <\
    \ N; ++i){\n    std::cout << ans[i].value_or(i) << \"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/join.cpp
  - Mylib/Algorithm/cartesian_tree.cpp
  isVerificationFile: true
  path: test/yosupo-judge/cartesian_tree/main.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/cartesian_tree/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/cartesian_tree/main.test.cpp
- /verify/test/yosupo-judge/cartesian_tree/main.test.cpp.html
title: test/yosupo-judge/cartesian_tree/main.test.cpp
---
