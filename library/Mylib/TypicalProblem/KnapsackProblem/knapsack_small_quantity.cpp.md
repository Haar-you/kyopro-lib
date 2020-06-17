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


# :heavy_check_mark: 0-1 Knapsack problem (Small quantity)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4bc951e5ca9130b2259fc85dc53eb972">Mylib/TypicalProblem/KnapsackProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `knapsack_small_quantity(int N, Weight cap, Weight w[N], Value v[N])`
	- 0-1ナップサック問題を解く。
	- Time complexity $O(2^{N/2} N)$

## Requirements

## Problems

- [AOJ DPL_1_H Huge Knapsack Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H)

## References



## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DPL_1_H/main.test.cpp.html">test/aoj/DPL_1_H/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

/**
 * @title 0-1 Knapsack problem (Small quantity)
 * @docs knapsack_small_quantity.md
 */
template <typename Weight, typename Value>
Value knapsack_small_quantity(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
  Value ret = 0;

  int p = N/2;
  int q = N-p;

  std::map<Weight, Value> a;
  for(int i = 0; i < 1<<p; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < p; ++j){
      if(i & (1<<j)){
        weight += w[j];
        value += v[j];
      }
    }

    a[weight] = std::max(a[weight], value);
  }

  Value m = 0;
  for(auto &kv : a){
    kv.second = std::max(kv.second, m);
    m = kv.second;
  }
  
  
  for(int i = 0; i < 1<<q; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < q; ++j){
      if(i&(1<<j)){
        weight += w[j+p];
        value += v[j+p];
      }
    }

    auto itr = a.upper_bound(std::max((Weight)0, cap-weight));
    
    itr = std::prev(itr);
    if(weight + itr->first <= cap) ret = std::max(ret, value + itr->second);
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

/**
 * @title 0-1 Knapsack problem (Small quantity)
 * @docs knapsack_small_quantity.md
 */
template <typename Weight, typename Value>
Value knapsack_small_quantity(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
  Value ret = 0;

  int p = N/2;
  int q = N-p;

  std::map<Weight, Value> a;
  for(int i = 0; i < 1<<p; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < p; ++j){
      if(i & (1<<j)){
        weight += w[j];
        value += v[j];
      }
    }

    a[weight] = std::max(a[weight], value);
  }

  Value m = 0;
  for(auto &kv : a){
    kv.second = std::max(kv.second, m);
    m = kv.second;
  }
  
  
  for(int i = 0; i < 1<<q; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < q; ++j){
      if(i&(1<<j)){
        weight += w[j+p];
        value += v[j+p];
      }
    }

    auto itr = a.upper_bound(std::max((Weight)0, cap-weight));
    
    itr = std::prev(itr);
    if(weight + itr->first <= cap) ret = std::max(ret, value + itr->second);
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

