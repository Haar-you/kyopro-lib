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


# :warning: トポロジカルソートの数え上げ

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5cfab8f1bec9f4a2c22b88bddb7720db">Mylib/Graph/TopologicalSort</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TopologicalSort/count_topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="https://atcoder.jp/contests/abc041/submissions/6549684">https://atcoder.jp/contests/abc041/submissions/6549684</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title トポロジカルソートの数え上げ
 * @see https://atcoder.jp/contests/abc041/submissions/6549684
 * @attention 時間計算量 O(n2^n)
 */
int64_t count_topological_sort(const std::vector<int> &g){
  const int n = g.size();
  std::vector<int64_t> dp(1<<n);
  
  dp[0] = 1;
  
  for(int s = 0; s < 1<<n; ++s){
    for(int i = 0; i < n; ++i){
      if(s & (1<<i)){
        if((s ^ (1<<i)) & g[i]) continue;
        dp[s] += dp[s^(1<<i)];
      }
    }
  }
  
  return dp[(1<<n)-1];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TopologicalSort/count_topological_sort.cpp"
#include <vector>

/**
 * @title トポロジカルソートの数え上げ
 * @see https://atcoder.jp/contests/abc041/submissions/6549684
 * @attention 時間計算量 O(n2^n)
 */
int64_t count_topological_sort(const std::vector<int> &g){
  const int n = g.size();
  std::vector<int64_t> dp(1<<n);
  
  dp[0] = 1;
  
  for(int s = 0; s < 1<<n; ++s){
    for(int i = 0; i < n; ++i){
      if(s & (1<<i)){
        if((s ^ (1<<i)) & g[i]) continue;
        dp[s] += dp[s^(1<<i)];
      }
    }
  }
  
  return dp[(1<<n)-1];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

