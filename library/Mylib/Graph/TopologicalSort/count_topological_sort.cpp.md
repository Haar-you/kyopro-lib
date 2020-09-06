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


# :warning: Count topological sort

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5cfab8f1bec9f4a2c22b88bddb7720db">Mylib/Graph/TopologicalSort</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TopologicalSort/count_topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Operations

- `count_topological_sort(g)`
	- Time complexity $O(n 2^n)$

## Requirements

## Notes

## Problems

- [ABC 041 D - 徒競走](https://atcoder.jp/contests/abc041/tasks/abc041_d)

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cstdint>

/**
 * @title Count topological sort
 * @docs count_topological_sort.md
 */
int64_t count_topological_sort(const std::vector<int> &g){
  const int n = g.size();
  std::vector<int64_t> dp(1 << n);

  dp[0] = 1;

  for(int s = 0; s < (1 << n); ++s){
    for(int i = 0; i < n; ++i){
      if(s & (1 << i)){
        if((s ^ (1 << i)) & g[i]) continue;
        dp[s] += dp[s ^ (1 << i)];
      }
    }
  }

  return dp[(1 << n) - 1];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TopologicalSort/count_topological_sort.cpp"
#include <vector>
#include <cstdint>

/**
 * @title Count topological sort
 * @docs count_topological_sort.md
 */
int64_t count_topological_sort(const std::vector<int> &g){
  const int n = g.size();
  std::vector<int64_t> dp(1 << n);

  dp[0] = 1;

  for(int s = 0; s < (1 << n); ++s){
    for(int i = 0; i < n; ++i){
      if(s & (1 << i)){
        if((s ^ (1 << i)) & g[i]) continue;
        dp[s] += dp[s ^ (1 << i)];
      }
    }
  }

  return dp[(1 << n) - 1];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

