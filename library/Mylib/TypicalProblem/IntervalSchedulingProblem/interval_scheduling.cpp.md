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
    - Last commit date: 2020-04-02 08:41:26+09:00


* see: <a href="https://atcoder.jp/contests/kupc2015/submissions/6604297">https://atcoder.jp/contests/kupc2015/submissions/6604297</a>
* see: <a href="https://codeforces.com/contest/528/submission/57933292">https://codeforces.com/contest/528/submission/57933292</a>


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
 * @see https://atcoder.jp/contests/kupc2015/submissions/6604297
 * @see https://codeforces.com/contest/528/submission/57933292
 * @attention time complexity O(N log N)
 */
template <typename T>
std::vector<std::pair<T,T>> interval_scheduling(const std::vector<T> &left, const std::vector<T> &right){ // 区間は[a,b]
  const int N = left.size();
  std::vector<std::pair<T,T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return right[i] < right[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(left[i] >= b){
      ret.emplace_back(left[i], right[i]);
      b = right[i];
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
 * @see https://atcoder.jp/contests/kupc2015/submissions/6604297
 * @see https://codeforces.com/contest/528/submission/57933292
 * @attention time complexity O(N log N)
 */
template <typename T>
std::vector<std::pair<T,T>> interval_scheduling(const std::vector<T> &left, const std::vector<T> &right){ // 区間は[a,b]
  const int N = left.size();
  std::vector<std::pair<T,T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return right[i] < right[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(left[i] >= b){
      ret.emplace_back(left[i], right[i]);
      b = right[i];
    }
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

