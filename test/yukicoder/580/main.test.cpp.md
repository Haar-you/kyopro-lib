---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Typical/interval_scheduling_k.cpp
    title: Interval scheduling problem (Allow no more than k intervals to overlap)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/580
    links:
    - https://yukicoder.me/problems/no/580
  bundledCode: "#line 1 \"test/yukicoder/580/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/580\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/interval_scheduling_k.cpp\"\
    \n#include <set>\n#include <iterator>\n#include <algorithm>\n#include <utility>\n\
    #include <numeric>\n\nnamespace haar_lib {\n  auto interval_scheduling_k(std::vector<int>\
    \ l, std::vector<int> r, int k){\n    const int N = l.size();\n\n    std::vector<int>\
    \ ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), [&](int i, int j){return r[i] < r[j];});\n\n    std::multiset<int>\
    \ a;\n    std::vector<std::pair<int, int>> ret;\n\n    for(int i : ord){\n   \
    \   auto it = a.upper_bound(l[i]);\n\n      if(it != a.begin()){\n        it =\
    \ std::prev(it);\n        a.erase(it);\n      }\n\n      if((int)a.size() < k){\n\
    \        a.insert(r[i]);\n        ret.emplace_back(l[i], r[i]);\n      }\n   \
    \ }\n\n    return ret;\n  }\n}\n#line 6 \"test/yukicoder/580/main.test.cpp\"\n\
    \nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n, m; std::cin >> n >> m;\n\n  std::vector<int> l(m), r(m);\n\n  for(int\
    \ i = 0; i < m; ++i){\n    int d; std::cin >> d;\n    int h1, m1; std::cin >>\
    \ h1; std::cin.ignore(); std::cin >> m1;\n\n    int o; std::cin >> o;\n    int\
    \ h2, m2; std::cin >> h2; std::cin.ignore(); std::cin >> m2;\n\n    l[i] = d *\
    \ 24 * 60 + h1 * 60 + m1;\n    r[i] = o * 24 * 60 + h2 * 60 + m2 + 1;\n  }\n\n\
    \  auto res = hl::interval_scheduling_k(l, r, n);\n  std::cout << res.size() <<\
    \ \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/580\"\n\n#include <iostream>\n\
    #include <vector>\n#include \"Mylib/Typical/interval_scheduling_k.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n, m; std::cin >> n >> m;\n\n  std::vector<int> l(m), r(m);\n\n  for(int\
    \ i = 0; i < m; ++i){\n    int d; std::cin >> d;\n    int h1, m1; std::cin >>\
    \ h1; std::cin.ignore(); std::cin >> m1;\n\n    int o; std::cin >> o;\n    int\
    \ h2, m2; std::cin >> h2; std::cin.ignore(); std::cin >> m2;\n\n    l[i] = d *\
    \ 24 * 60 + h1 * 60 + m1;\n    r[i] = o * 24 * 60 + h2 * 60 + m2 + 1;\n  }\n\n\
    \  auto res = hl::interval_scheduling_k(l, r, n);\n  std::cout << res.size() <<\
    \ \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/interval_scheduling_k.cpp
  isVerificationFile: true
  path: test/yukicoder/580/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/580/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/580/main.test.cpp
- /verify/test/yukicoder/580/main.test.cpp.html
title: test/yukicoder/580/main.test.cpp
---
