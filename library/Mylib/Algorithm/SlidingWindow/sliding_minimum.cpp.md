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


# :x: スライド最小値

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1d0203f9a0b34121f2fb0bb17b094d0f">Mylib/Algorithm/SlidingWindow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #574 (Div. 2) E. OpenStreetMap](https://codeforces.com/contest/1195/problem/E)

## References


## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_3_D/main.test.cpp.html">test/aoj/DSL_3_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <deque>

/**
 * @title スライド最小値
 * @docs sliding_minimum.md
 */
template <typename T>
std::vector<T> sliding_minimum(const std::vector<T> &a, int k){
  const int n = a.size();
  std::deque<int> dq;
  std::vector<T> ret;

  for(int i = 0; i < k; ++i){
    while(not dq.empty() and a[dq.back()] >= a[i]){
      dq.pop_back();
    }

    dq.push_back(i);
  }
  
  for(int i = 0; i < n-k+1; ++i){
    while(dq.front() < i){
      dq.pop_front();
    }

    ret.push_back(a[dq.front()]);

    while(not dq.empty() and i+k < n and a[dq.back()] >= a[i+k]){
      dq.pop_back();
    }
    
    dq.push_back(i+k);
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp"
#include <vector>
#include <deque>

/**
 * @title スライド最小値
 * @docs sliding_minimum.md
 */
template <typename T>
std::vector<T> sliding_minimum(const std::vector<T> &a, int k){
  const int n = a.size();
  std::deque<int> dq;
  std::vector<T> ret;

  for(int i = 0; i < k; ++i){
    while(not dq.empty() and a[dq.back()] >= a[i]){
      dq.pop_back();
    }

    dq.push_back(i);
  }
  
  for(int i = 0; i < n-k+1; ++i){
    while(dq.front() < i){
      dq.pop_front();
    }

    ret.push_back(a[dq.front()]);

    while(not dq.empty() and i+k < n and a[dq.back()] >= a[i+k]){
      dq.pop_back();
    }
    
    dq.push_back(i+k);
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

