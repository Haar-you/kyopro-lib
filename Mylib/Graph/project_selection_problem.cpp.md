---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903/main.test.cpp
    title: test/aoj/2903/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3058/main.test.cpp
    title: test/aoj/3058/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/project_selection_problem.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <cassert>\n#include <limits>\n#include <tuple>\n\n\
    namespace haar_lib {\n  template <typename T, typename Flow>\n  class project_selection_problem\
    \ {\n    int N_, s_, t_;\n    std::vector<std::tuple<int, int, T>> g_;\n    T\
    \ default_gain_;\n    int nodes_;\n\n    constexpr static T INF = std::numeric_limits<T>::max();\n\
    \n  public:\n    project_selection_problem(){}\n    project_selection_problem(int\
    \ N): N_(N), s_(N), t_(N + 1), default_gain_(0), nodes_(N + 2){}\n\n    void penalty_if_red(int\
    \ i, T c){\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n      g_.emplace_back(i,\
    \ t_, c);\n    }\n\n    void gain_if_red(int i, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      default_gain_ += c;\n      penalty_if_blue(i,\
    \ c);\n    }\n\n    void penalty_if_blue(int i, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      g_.emplace_back(s_, i, c);\n    }\n\n\
    \    void gain_if_blue(int i, T c){\n      assert(c >= 0);\n      assert(0 <=\
    \ i and i < N_);\n      default_gain_ += c;\n      penalty_if_red(i, c);\n   \
    \ }\n\n    void penalty_if_red_blue(int i, int j, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n      g_.emplace_back(i,\
    \ j, c);\n    }\n\n    void penalty_if_different(int i, int j, T c){\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      g_.emplace_back(i, j, c);\n      g_.emplace_back(j, i, c);\n    }\n\n \
    \   void must_be_red(int i){\n      assert(0 <= i and i < N_);\n      penalty_if_blue(i,\
    \ INF);\n    }\n\n    void must_be_blue(int i){\n      assert(0 <= i and i < N_);\n\
    \      penalty_if_red(i, INF);\n    }\n\n    void if_red_then_must_be_red(int\
    \ i, int j){\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      penalty_if_red_blue(i, j, INF);\n    }\n\n    void gain_if_red_red(int\
    \ i, int j, T c){\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n \
    \     assert(0 <= j and j < N_);\n      default_gain_ += c;\n      int w = nodes_++;\n\
    \n      g_.emplace_back(s_, w, c);\n      g_.emplace_back(w, i, INF);\n      g_.emplace_back(w,\
    \ j, INF);\n    }\n\n    void gain_if_blue_blue(int i, int j, T c){\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      default_gain_ += c;\n      int w = nodes_++;\n\n      g_.emplace_back(w,\
    \ t_, c);\n      g_.emplace_back(i, w, INF);\n      g_.emplace_back(j, w, INF);\n\
    \    }\n\n    T solve(){\n      Flow flow(nodes_);\n      for(auto [i, j, w] :\
    \ g_) flow.add_edge(i, j, w);\n      return default_gain_ - flow.max_flow(s_,\
    \ t_);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    #include <limits>\n#include <tuple>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Flow>\n  class project_selection_problem {\n    int N_, s_, t_;\n\
    \    std::vector<std::tuple<int, int, T>> g_;\n    T default_gain_;\n    int nodes_;\n\
    \n    constexpr static T INF = std::numeric_limits<T>::max();\n\n  public:\n \
    \   project_selection_problem(){}\n    project_selection_problem(int N): N_(N),\
    \ s_(N), t_(N + 1), default_gain_(0), nodes_(N + 2){}\n\n    void penalty_if_red(int\
    \ i, T c){\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n      g_.emplace_back(i,\
    \ t_, c);\n    }\n\n    void gain_if_red(int i, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      default_gain_ += c;\n      penalty_if_blue(i,\
    \ c);\n    }\n\n    void penalty_if_blue(int i, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      g_.emplace_back(s_, i, c);\n    }\n\n\
    \    void gain_if_blue(int i, T c){\n      assert(c >= 0);\n      assert(0 <=\
    \ i and i < N_);\n      default_gain_ += c;\n      penalty_if_red(i, c);\n   \
    \ }\n\n    void penalty_if_red_blue(int i, int j, T c){\n      assert(c >= 0);\n\
    \      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n      g_.emplace_back(i,\
    \ j, c);\n    }\n\n    void penalty_if_different(int i, int j, T c){\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      g_.emplace_back(i, j, c);\n      g_.emplace_back(j, i, c);\n    }\n\n \
    \   void must_be_red(int i){\n      assert(0 <= i and i < N_);\n      penalty_if_blue(i,\
    \ INF);\n    }\n\n    void must_be_blue(int i){\n      assert(0 <= i and i < N_);\n\
    \      penalty_if_red(i, INF);\n    }\n\n    void if_red_then_must_be_red(int\
    \ i, int j){\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      penalty_if_red_blue(i, j, INF);\n    }\n\n    void gain_if_red_red(int\
    \ i, int j, T c){\n      assert(c >= 0);\n      assert(0 <= i and i < N_);\n \
    \     assert(0 <= j and j < N_);\n      default_gain_ += c;\n      int w = nodes_++;\n\
    \n      g_.emplace_back(s_, w, c);\n      g_.emplace_back(w, i, INF);\n      g_.emplace_back(w,\
    \ j, INF);\n    }\n\n    void gain_if_blue_blue(int i, int j, T c){\n      assert(c\
    \ >= 0);\n      assert(0 <= i and i < N_);\n      assert(0 <= j and j < N_);\n\
    \      default_gain_ += c;\n      int w = nodes_++;\n\n      g_.emplace_back(w,\
    \ t_, c);\n      g_.emplace_back(i, w, INF);\n      g_.emplace_back(j, w, INF);\n\
    \    }\n\n    T solve(){\n      Flow flow(nodes_);\n      for(auto [i, j, w] :\
    \ g_) flow.add_edge(i, j, w);\n      return default_gain_ - flow.max_flow(s_,\
    \ t_);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/project_selection_problem.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3058/main.test.cpp
  - test/aoj/2903/main.test.cpp
documentation_of: Mylib/Graph/project_selection_problem.cpp
layout: document
title: Project selection problem
---

## Operations

- `project_selection_problem(N)`
- `penalty_if_red(int i, T c)`
	- `i`を<font color="red">赤</font>に塗ると`c`の損失になる。
- `gain_if_red(int i, T c)`
	- `i`を<font color="red">赤</font>に塗ると`c`の利益を得る。
- `penalty_if_blue(int i, T c)`
	- `i`を<font color="blue">青</font>に塗ると`c`の損失になる。
- `gain_if_blue(int i, T c)`
	- `i`を<font color="blue">青</font>にぬると`c`の利益を得る。
- `penalty_if_red_blue(int i, int j, T c)`
	- `i`を<font color="red">赤</font>、且つ`j`を<font color="blue">青</font>に塗ると`c`の損失になる。
- `penalty_if_different(int i, int j, T c)`
	- `i`と`j`の色が異なると`c`の損失になる。
- `must_be_red(int i)`
	- `i`は<font color="red">赤</font>でなければならない。
- `must_be_blue(int i)`
	- `i`は<font color="blue">青</font>でなければならない。
- `if_red_then_must_be_red(int i, int j)`
	- `i`が<font color="red">赤</font>ならば、`j`は<font color="red">赤</font>でなければならない。
- `gain_if_red_red(int i, int j, T c)`
	- `i`と`j`をともに<font color="red">赤</font>に塗ると`c`の利益を得る。
- `gain_if_blue_blue(int i, int j, T c)`
	- `i`と`j`をともに<font color="blue">青</font>に塗ると`c`の利益を得る。
- `solve()`
    - 得られる利益の最大値を返す。

## Requirements

- 頂点`s`は<font color="red">赤</font>に、頂点`t`は<font color="blue">青</font>に塗られる。

## Notes

## Problems

- [ARC 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AOJ 3058 Ghost](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058)
- [AOJ 2903 Board](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903)
- [ABC 193 F - Zebraness](https://atcoder.jp/contests/abc193/tasks/abc193_f)

## References

- [https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/](https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/)
- [https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html](https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html)
- [https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C](https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C)
