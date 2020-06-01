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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: Longest increasing subsequence

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3a96c66483797c15eff4c0c3d8733619">Mylib/DynamicProgramming</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/longest_increasing_subsequence.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `lis(a[N])`
	- `a`の最長増加部分列の長さを返す。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

## References
 


## Verified with

* :x: <a href="../../../verify/test/aoj/DPL_1_D/main.test.cpp.html">test/aoj/DPL_1_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Longest increasing subsequence
 * @docs longest_increasing_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lis(const Container &xs){
  std::vector<T> dp;
  dp.reserve(xs.size());
  
  for(auto x : xs){
    if(dp.empty() or dp.back() < x){
      dp.push_back(x);
    }else{
      dp[std::lower_bound(dp.begin(),dp.end(),x)-dp.begin()] = x;
    }
  }

  return dp.size();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/longest_increasing_subsequence.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Longest increasing subsequence
 * @docs longest_increasing_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lis(const Container &xs){
  std::vector<T> dp;
  dp.reserve(xs.size());
  
  for(auto x : xs){
    if(dp.empty() or dp.back() < x){
      dp.push_back(x);
    }else{
      dp[std::lower_bound(dp.begin(),dp.end(),x)-dp.begin()] = x;
    }
  }

  return dp.size();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

