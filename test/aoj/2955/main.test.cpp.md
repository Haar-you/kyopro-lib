---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/subset_sum_limited.cpp
    title: Subset sum problem (With quantity limitations)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955
  bundledCode: "#line 1 \"test/aoj/2955/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955\"\
    \n\n#include <iostream>\n#include <vector>\n#include <map>\n#line 3 \"Mylib/Typical/subset_sum_limited.cpp\"\
    \n#include <cassert>\n\nnamespace haar_lib {\n  auto subset_sum_limited(int N,\
    \ int K, const std::vector<int> &a, const std::vector<int> &m){\n    assert((int)a.size()\
    \ == N and (int)m.size() == N);\n    std::vector<int> dp(K + 1, -1);\n\n    dp[0]\
    \ = 0;\n    for(int i = 0; i < N; ++i){\n      for(int j = 0; j <= K; ++j){\n\
    \        if(dp[j] >= 0){\n          dp[j] = m[i];\n        }else if(j < a[i] or\
    \ dp[j - a[i]] <= 0){\n          dp[j] = -1;\n        }else{\n          dp[j]\
    \ = dp[j - a[i]] - 1;\n        }\n      }\n    }\n\n    for(int i = 0; i <= K;\
    \ ++i) dp[i] = dp[i] >= 0;\n\n    return dp;\n  }\n}\n#line 3 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include <numeric>\n#include <algorithm>\n\nnamespace haar_lib {\n  class unionfind\
    \ {\n    int n_, count_;\n    mutable std::vector<int> parent_;\n    std::vector<int>\
    \ depth_, size_;\n\n  public:\n    unionfind(){}\n    unionfind(int n): n_(n),\
    \ count_(n), parent_(n), depth_(n, 1), size_(n, 1){\n      std::iota(parent_.begin(),\
    \ parent_.end(), 0);\n    }\n\n    int root_of(int i) const {\n      if(parent_[i]\
    \ == i) return i;\n      else return parent_[i] = root_of(parent_[i]);\n    }\n\
    \n    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}\n\n\
    \    int merge(int i, int j){\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if(ri == rj) return ri;\n      else{\n        --count_;\n        if(depth_[ri]\
    \ < depth_[rj]){\n          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n\
    \          return rj;\n        }else{\n          parent_[rj] = ri;\n         \
    \ size_[ri] += size_[rj];\n          if(depth_[ri] == depth_[rj]) ++depth_[ri];\n\
    \          return ri;\n        }\n      }\n    }\n\n    int size_of(int i) const\
    \ {return size_[root_of(i)];}\n\n    int count_groups() const {return count_;}\n\
    \n    auto get_groups() const {\n      std::vector<std::vector<int>> ret(n_);\n\
    \n      for(int i = 0; i < n_; ++i){\n        ret[root_of(i)].push_back(i);\n\
    \      }\n\n      ret.erase(\n        std::remove_if(\n          ret.begin(),\
    \ ret.end(),\n          [](const auto &a){return a.empty();}\n        ),\n   \
    \     ret.end()\n      );\n\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 9 \"test/aoj/2955/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N, R; std::cin >> N >> R;\n\n  auto p = hl::input_vector<int>(N);\n  for(auto\
    \ &x : p) x -= 1;\n\n  hl::unionfind uf(N);\n\n  for(int i = 0; i < N; ++i){\n\
    \    uf.merge(i, p[i]);\n  }\n\n  std::map<int, int> cycles;\n  for(int i = 0;\
    \ i < N; ++i){\n    if(i == uf.root_of(i)) cycles[uf.size_of(i)] += 1;\n  }\n\n\
    \  std::vector<int> a, m;\n  for(auto &[k, v] : cycles){\n    a.push_back(k);\n\
    \    m.push_back(v);\n  }\n\n  bool ans = hl::subset_sum_limited(a.size(), R,\
    \ a, m)[R];\n\n  std::cout << (ans ? \"Yes\" : \"No\") << std::endl;\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955\"\
    \n\n#include <iostream>\n#include <vector>\n#include <map>\n#include \"Mylib/Typical/subset_sum_limited.cpp\"\
    \n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N, R; std::cin >> N >> R;\n\
    \n  auto p = hl::input_vector<int>(N);\n  for(auto &x : p) x -= 1;\n\n  hl::unionfind\
    \ uf(N);\n\n  for(int i = 0; i < N; ++i){\n    uf.merge(i, p[i]);\n  }\n\n  std::map<int,\
    \ int> cycles;\n  for(int i = 0; i < N; ++i){\n    if(i == uf.root_of(i)) cycles[uf.size_of(i)]\
    \ += 1;\n  }\n\n  std::vector<int> a, m;\n  for(auto &[k, v] : cycles){\n    a.push_back(k);\n\
    \    m.push_back(v);\n  }\n\n  bool ans = hl::subset_sum_limited(a.size(), R,\
    \ a, m)[R];\n\n  std::cout << (ans ? \"Yes\" : \"No\") << std::endl;\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Typical/subset_sum_limited.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/2955/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2955/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2955/main.test.cpp
- /verify/test/aoj/2955/main.test.cpp.html
title: test/aoj/2955/main.test.cpp
---
