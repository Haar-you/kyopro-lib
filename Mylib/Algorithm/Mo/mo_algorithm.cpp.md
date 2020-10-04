---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Typical/InversionNumber/range_inversions_query.cpp
    title: Range inversions query
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425/main.test.cpp
    title: test/aoj/0425/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/static_range_inversions_query/main.test.cpp
    title: test/yosupo-judge/static_range_inversions_query/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Mo/mo_algorithm.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  template <typename AppendLeft, typename AppendRight, typename RemoveLeft,\
    \ typename RemoveRight, typename Query>\n  class mo_algorithm {\n    int N_, Q_,\
    \ index_, width_;\n    std::vector<int> left_, right_, ord_;\n\n    AppendLeft\
    \ append_left_;\n    AppendRight append_right_;\n    RemoveLeft remove_left_;\n\
    \    RemoveRight remove_right_;\n    Query query_;\n\n    bool is_built_ = false;\n\
    \n  public:\n    mo_algorithm(){}\n    mo_algorithm(\n      int N, int Q,\n  \
    \    const AppendLeft &append_left, const AppendRight &append_right,\n      const\
    \ RemoveLeft &remove_left, const RemoveRight &remove_right,\n      const Query\
    \ &query\n    ):\n      N_(N), Q_(Q), index_(0), width_(std::sqrt(N)),\n     \
    \ left_(Q), right_(Q), ord_(Q),\n      append_left_(append_left), append_right_(append_right),\n\
    \      remove_left_(remove_left), remove_right_(remove_right),\n      query_(query)\n\
    \    {}\n\n    // [l, r)\n    void add(int l, int r){\n      left_[index_] = l;\n\
    \      right_[index_] = r;\n      ord_[index_] = index_;\n      ++index_;\n  \
    \  }\n\n    void run(){\n      std::sort(\n        ord_.begin(), ord_.end(),\n\
    \        [&](int i, int j){\n          const int a = left_[i] / width_, b = left_[j]\
    \ / width_;\n          if(a == b){\n            if(a & 1) return right_[i] < right_[j];\n\
    \            else return right_[i] > right_[j];\n          }else{\n          \
    \  return a < b;\n          }\n        }\n      );\n\n      int q = 0;\n     \
    \ int l = left_[ord_[0]], r = left_[ord_[0]];\n\n      for(int i = 0; i < Q_;\
    \ ++i){\n        int id = ord_[q++];\n\n        while(l != left_[id] or r != right_[id]){\n\
    \          if(l > left_[id]) append_left_(--l);\n          if(l < left_[id]) remove_left_(l++);\n\
    \          if(r < right_[id]) append_right_(r++);\n          if(r > right_[id])\
    \ remove_right_(--r);\n        }\n\n        query_(id);\n      }\n    }\n  };\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  template <typename AppendLeft, typename\
    \ AppendRight, typename RemoveLeft, typename RemoveRight, typename Query>\n  class\
    \ mo_algorithm {\n    int N_, Q_, index_, width_;\n    std::vector<int> left_,\
    \ right_, ord_;\n\n    AppendLeft append_left_;\n    AppendRight append_right_;\n\
    \    RemoveLeft remove_left_;\n    RemoveRight remove_right_;\n    Query query_;\n\
    \n    bool is_built_ = false;\n\n  public:\n    mo_algorithm(){}\n    mo_algorithm(\n\
    \      int N, int Q,\n      const AppendLeft &append_left, const AppendRight &append_right,\n\
    \      const RemoveLeft &remove_left, const RemoveRight &remove_right,\n     \
    \ const Query &query\n    ):\n      N_(N), Q_(Q), index_(0), width_(std::sqrt(N)),\n\
    \      left_(Q), right_(Q), ord_(Q),\n      append_left_(append_left), append_right_(append_right),\n\
    \      remove_left_(remove_left), remove_right_(remove_right),\n      query_(query)\n\
    \    {}\n\n    // [l, r)\n    void add(int l, int r){\n      left_[index_] = l;\n\
    \      right_[index_] = r;\n      ord_[index_] = index_;\n      ++index_;\n  \
    \  }\n\n    void run(){\n      std::sort(\n        ord_.begin(), ord_.end(),\n\
    \        [&](int i, int j){\n          const int a = left_[i] / width_, b = left_[j]\
    \ / width_;\n          if(a == b){\n            if(a & 1) return right_[i] < right_[j];\n\
    \            else return right_[i] > right_[j];\n          }else{\n          \
    \  return a < b;\n          }\n        }\n      );\n\n      int q = 0;\n     \
    \ int l = left_[ord_[0]], r = left_[ord_[0]];\n\n      for(int i = 0; i < Q_;\
    \ ++i){\n        int id = ord_[q++];\n\n        while(l != left_[id] or r != right_[id]){\n\
    \          if(l > left_[id]) append_left_(--l);\n          if(l < left_[id]) remove_left_(l++);\n\
    \          if(r < right_[id]) append_right_(r++);\n          if(r > right_[id])\
    \ remove_right_(--r);\n        }\n\n        query_(id);\n      }\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Mo/mo_algorithm.cpp
  requiredBy:
  - Mylib/Typical/InversionNumber/range_inversions_query.cpp
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0425/main.test.cpp
  - test/yosupo-judge/static_range_inversions_query/main.test.cpp
documentation_of: Mylib/Algorithm/Mo/mo_algorithm.cpp
layout: document
title: Mo's algorithm
---

## Operations

- `MoAlgorithm`
- `add(int l, int r)`
	- クエリ`[l, r)`を追加する。
- `build()`
- `run()`
- `make_mo`

## Requirements

- `append(int i, int d)`
	- `i`番目の要素を追加する操作。
    - `d = -1`で左端に追加、`d = 1`で右端に追加。
- `remove(int i, int d)`
	- `i`番目の要素を削除する操作。
    - `d = -1`で左端を削除、`d = 1`で右端を削除。
- `query(int i)`
	- `i`番目のクエリを処理する操作。
- 必ず`add`, `build`, `run`の順で実行する。

## Notes

## Problems

- [Yandex.Algorithm 2011: Round 2 D. Powerful array](https://codeforces.com/contest/86/problem/D) (出現数)
- [SPOJ DQUERY](https://www.spoj.com/problems/DQUERY/) (種類数)
- [第3回 ドワンゴからの挑戦状 本選 B - ニワンゴくんの約数](https://atcoder.jp/contests/dwacon2017-honsen/tasks/dwango2017final_b) (積の約数の個数)
- [Codeforces Round #221 (Div. 1) D. Tree and Queries](https://codeforces.com/contest/375/problem/D) (部分木 / 出現数k以上の種類数)
- [Unique Art](https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem) (出現数1の種類数)

## References

- [https://ei1333.hateblo.jp/entry/2017/09/11/211011](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
- [https://snuke.hatenablog.com/entry/2016/07/01/000000](https://snuke.hatenablog.com/entry/2016/07/01/000000)
- [https://www.hamayanhamayan.com/entry/2017/04/18/012937](https://www.hamayanhamayan.com/entry/2017/04/18/012937)
