---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1311/main.test.cpp
    title: test/yukicoder/1311/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/permutation.cpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <functional>\n#include <vector>\n\
    \nnamespace haar_lib {\n  std::vector<int> index_to_permutation(int64_t N, int\
    \ S) {\n    std::vector<int> ret;\n\n    __gnu_pbds::tree<\n        int, __gnu_pbds::null_type,\
    \ std::less<int>,\n        __gnu_pbds::rb_tree_tag,\n        __gnu_pbds::tree_order_statistics_node_update>\n\
    \        set;\n\n    std::vector<int64_t> p(S + 1, 1);\n    for (int i = 0; i\
    \ < S; ++i) {\n      p[i + 1] = p[i] * (i + 1);\n      set.insert(i);\n    }\n\
    \n    for (int i = S; --i >= 0;) {\n      int64_t index = N / p[i];\n\n      int\
    \ j = *set.find_by_order(index);\n      ret.push_back(j);\n      set.erase(j);\n\
    \n      N %= p[i];\n    }\n\n    return ret;\n  }\n\n  template <typename T =\
    \ int64_t>\n  T permutation_to_index(const std::vector<int> &a) {\n    const int\
    \ N = a.size();\n    T ret       = 0;\n\n    __gnu_pbds::tree<\n        int, __gnu_pbds::null_type,\
    \ std::less<int>,\n        __gnu_pbds::rb_tree_tag,\n        __gnu_pbds::tree_order_statistics_node_update>\n\
    \        set;\n\n    std::vector<T> p(N + 1, 1);\n    for (int i = 0; i < N; ++i)\
    \ {\n      p[i + 1] = p[i] * (i + 1);\n      set.insert(i);\n    }\n\n    for\
    \ (int i = 0; i < N; ++i) {\n      int k = set.order_of_key(a[i]);\n      ret\
    \ += p[N - 1 - i] * k;\n      set.erase(a[i]);\n    }\n\n    return ret;\n  }\n\
    \n  std::vector<int> inverse_permutation(const std::vector<int> &a) {\n    const\
    \ int N = a.size();\n    std::vector<int> ret(N);\n    for (int i = 0; i < N;\
    \ ++i) {\n      ret[a[i]] = i;\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <functional>\n#include <vector>\n\nnamespace haar_lib {\n  std::vector<int>\
    \ index_to_permutation(int64_t N, int S) {\n    std::vector<int> ret;\n\n    __gnu_pbds::tree<\n\
    \        int, __gnu_pbds::null_type, std::less<int>,\n        __gnu_pbds::rb_tree_tag,\n\
    \        __gnu_pbds::tree_order_statistics_node_update>\n        set;\n\n    std::vector<int64_t>\
    \ p(S + 1, 1);\n    for (int i = 0; i < S; ++i) {\n      p[i + 1] = p[i] * (i\
    \ + 1);\n      set.insert(i);\n    }\n\n    for (int i = S; --i >= 0;) {\n   \
    \   int64_t index = N / p[i];\n\n      int j = *set.find_by_order(index);\n  \
    \    ret.push_back(j);\n      set.erase(j);\n\n      N %= p[i];\n    }\n\n   \
    \ return ret;\n  }\n\n  template <typename T = int64_t>\n  T permutation_to_index(const\
    \ std::vector<int> &a) {\n    const int N = a.size();\n    T ret       = 0;\n\n\
    \    __gnu_pbds::tree<\n        int, __gnu_pbds::null_type, std::less<int>,\n\
    \        __gnu_pbds::rb_tree_tag,\n        __gnu_pbds::tree_order_statistics_node_update>\n\
    \        set;\n\n    std::vector<T> p(N + 1, 1);\n    for (int i = 0; i < N; ++i)\
    \ {\n      p[i + 1] = p[i] * (i + 1);\n      set.insert(i);\n    }\n\n    for\
    \ (int i = 0; i < N; ++i) {\n      int k = set.order_of_key(a[i]);\n      ret\
    \ += p[N - 1 - i] * k;\n      set.erase(a[i]);\n    }\n\n    return ret;\n  }\n\
    \n  std::vector<int> inverse_permutation(const std::vector<int> &a) {\n    const\
    \ int N = a.size();\n    std::vector<int> ret(N);\n    for (int i = 0; i < N;\
    \ ++i) {\n      ret[a[i]] = i;\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/permutation.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1311/main.test.cpp
documentation_of: Mylib/Math/permutation.cpp
layout: document
title: Permutation
---

## Operations

- `index_to_permutation(N, S)`
  - 長さ`S`の順列で辞書順で`N`番目(0-indexed)のものを求める。
- `permutation_to_index(a[N])`
  - 順列`a`が長さ`N`の順列の中で辞書順で何番目(0-indexed)であるかを求める。
- `inverse_permutation(a)`
  - `a`の逆置換を求める。

## Requirements

## Notes

## Problems

## References
