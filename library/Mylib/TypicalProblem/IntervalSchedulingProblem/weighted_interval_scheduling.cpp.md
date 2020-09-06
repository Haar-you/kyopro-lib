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


# :warning: Weighted interval scheduling problem

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a1062884f064c2b3be412505b6627108">Mylib/TypicalProblem/IntervalSchedulingProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/IntervalSchedulingProblem/weighted_interval_scheduling.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

## Requirements

## Notes

## Problems

- [J - 異世界転生2](https://www.hackerrank.com/contests/kodamanwithothers/challenges/2-82/problem)

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <utility>

/**
 * @title Weighted interval scheduling problem
 * @docs weighted_interval_scheduling.md
 */
template <typename T, typename U>
U weighted_interval_scheduling(std::vector<T> from, std::vector<T> to, std::vector<U> value){
  int n = from.size();

  std::vector<T> c(from);
  c.insert(c.end(), to.begin(), to.end());

  std::sort(c.begin(), c.end());
  c.erase(std::unique(c.begin(), c.end()), c.end());

  for(int i = 0; i < n; ++i){
    from[i] = lower_bound(c.begin(), c.end(), from[i]) - c.begin();
    to[i] = lower_bound(c.begin(), c.end(), to[i]) - c.begin();
  }

  int m = c.size();

  std::vector<U> dp(m + 1);

  std::vector<std::vector<std::pair<int, U>>> memo(m);
  for(int i = 0; i < n; ++i){
    memo[to[i]].emplace_back(from[i], value[i]);
  }

  for(int i = 0; i < m; ++i){
    dp[i + 1] = dp[i];

    for(auto &p : memo[i]){
      dp[i + 1] = std::max(dp[i + 1], dp[p.first] + p.second);
    }
  }

  return dp[m];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/IntervalSchedulingProblem/weighted_interval_scheduling.cpp"
#include <vector>
#include <algorithm>
#include <utility>

/**
 * @title Weighted interval scheduling problem
 * @docs weighted_interval_scheduling.md
 */
template <typename T, typename U>
U weighted_interval_scheduling(std::vector<T> from, std::vector<T> to, std::vector<U> value){
  int n = from.size();

  std::vector<T> c(from);
  c.insert(c.end(), to.begin(), to.end());

  std::sort(c.begin(), c.end());
  c.erase(std::unique(c.begin(), c.end()), c.end());

  for(int i = 0; i < n; ++i){
    from[i] = lower_bound(c.begin(), c.end(), from[i]) - c.begin();
    to[i] = lower_bound(c.begin(), c.end(), to[i]) - c.begin();
  }

  int m = c.size();

  std::vector<U> dp(m + 1);

  std::vector<std::vector<std::pair<int, U>>> memo(m);
  for(int i = 0; i < n; ++i){
    memo[to[i]].emplace_back(from[i], value[i]);
  }

  for(int i = 0; i < m; ++i){
    dp[i + 1] = dp[i];

    for(auto &p : memo[i]){
      dp[i + 1] = std::max(dp[i + 1], dp[p.first] + p.second);
    }
  }

  return dp[m];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

