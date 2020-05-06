---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: 区間スケジューリング問題

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a1062884f064c2b3be412505b6627108">Mylib/TypicalProblem/IntervalSchedulingProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-06 01:45:04+09:00




## Operations

- `interval_scheduling(l[N], r[N])`
	- `N`個の半開区間`[l[i], r[i])`を互いに交差しないように選べる個数を最大にする方法。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

- [KUPC 2015 A - 東京都](https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a)
- [Codeforces Round #296 (Div. 1) B. Clique Problem](https://codeforces.com/contest/528/problem/B)

## References


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/ALDS1_15_C/main.test.cpp.html">test/aoj/ALDS1_15_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <utility>

/**
 * @title 区間スケジューリング問題
 * @docs interval_scheduling.md
 */
template <typename T>
std::vector<std::pair<T,T>> interval_scheduling(const std::vector<T> &l, const std::vector<T> &r){
  const int N = l.size();
  std::vector<std::pair<T,T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(l[i] >= b){
      ret.emplace_back(l[i], r[i]);
      b = r[i];
    }
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp"
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <utility>

/**
 * @title 区間スケジューリング問題
 * @docs interval_scheduling.md
 */
template <typename T>
std::vector<std::pair<T,T>> interval_scheduling(const std::vector<T> &l, const std::vector<T> &r){
  const int N = l.size();
  std::vector<std::pair<T,T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(l[i] >= b){
      ret.emplace_back(l[i], r[i]);
      b = r[i];
    }
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

