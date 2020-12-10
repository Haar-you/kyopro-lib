---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Math/permutation.cpp
    title: Permutation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1311
    links:
    - https://yukicoder.me/problems/no/1311
  bundledCode: "#line 1 \"test/yukicoder/1311/main.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1311\"\n\n#include <iostream>\n#line 2 \"Mylib/Math/permutation.cpp\"\
    \n#include <vector>\n#include <functional>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n\nnamespace haar_lib {\n  std::vector<int>\
    \ index_to_permutation(int64_t N, int S){\n    std::vector<int> ret;\n\n    __gnu_pbds::tree<\n\
    \      int, __gnu_pbds::null_type, std::less<int>,\n      __gnu_pbds::rb_tree_tag,\n\
    \      __gnu_pbds::tree_order_statistics_node_update\n      > set;\n\n    std::vector<int64_t>\
    \ p(S + 1, 1);\n    for(int i = 0; i < S; ++i){\n      p[i + 1] = p[i] * (i +\
    \ 1);\n      set.insert(i);\n    }\n\n    for(int i = S; --i >= 0;){\n      int64_t\
    \ index = N / p[i];\n\n      int j = *set.find_by_order(index);\n      ret.push_back(j);\n\
    \      set.erase(j);\n\n      N %= p[i];\n    }\n\n    return ret;\n  }\n\n  template\
    \ <typename T = int64_t>\n  T permutation_to_index(const std::vector<int> &a){\n\
    \    const int N = a.size();\n    T ret = 0;\n\n    __gnu_pbds::tree<\n      int,\
    \ __gnu_pbds::null_type, std::less<int>,\n      __gnu_pbds::rb_tree_tag,\n   \
    \   __gnu_pbds::tree_order_statistics_node_update\n      > set;\n\n    std::vector<T>\
    \ p(N + 1, 1);\n    for(int i = 0; i < N; ++i){\n      p[i + 1] = p[i] * (i +\
    \ 1);\n      set.insert(i);\n    }\n\n    for(int i = 0; i < N; ++i){\n      int\
    \ k = set.order_of_key(a[i]);\n      ret += p[N - 1 - i] * k;\n      set.erase(a[i]);\n\
    \    }\n\n    return ret;\n  }\n\n  std::vector<int> inverse_permutation(const\
    \ std::vector<int> &a){\n    const int N = a.size();\n    std::vector<int> ret(N);\n\
    \    for(int i = 0; i < N; ++i){\n      ret[a[i]] = i;\n    }\n\n    return ret;\n\
    \  }\n}\n#line 5 \"test/yukicoder/1311/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int64_t N, S; std::cin >> N >> S;\n  int64_t ans =  hl::permutation_to_index(hl::inverse_permutation(hl::index_to_permutation(N,\
    \ S)));\n\n  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1311\"\n\n#include <iostream>\n\
    #include \"Mylib/Math/permutation.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int64_t N, S; std::cin >> N >> S;\n  int64_t ans =  hl::permutation_to_index(hl::inverse_permutation(hl::index_to_permutation(N,\
    \ S)));\n\n  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Math/permutation.cpp
  isVerificationFile: true
  path: test/yukicoder/1311/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-10 17:51:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1311/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1311/main.test.cpp
- /verify/test/yukicoder/1311/main.test.cpp.html
title: test/yukicoder/1311/main.test.cpp
---
