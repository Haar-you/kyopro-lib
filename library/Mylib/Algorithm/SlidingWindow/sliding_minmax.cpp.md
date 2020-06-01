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


# :warning: Sliding window minmax

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1d0203f9a0b34121f2fb0bb17b094d0f">Mylib/Algorithm/SlidingWindow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/SlidingWindow/sliding_minmax.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <deque>
#include <utility>

/**
 * @title Sliding window minmax
 * @docs sliding_minmax.md
 */
template <typename T> std::vector<std::pair<T,T>> sliding_minmax(const std::vector<T> &a, int k){
  int n = a.size();
  std::deque<int> dq_min, dq_max;
  std::vector<std::pair<T,T>> ret;

  for(int i = 0; i < k; ++i){
    while(not dq_min.empty() and a[dq_min.back()] >= a[i]){
      dq_min.pop_back();
    }
    
    dq_min.push_back(i);

    while(not dq_max.empty() and a[dq_max.back()] <= a[i]){
      dq_max.pop_back();
    }
    
    dq_max.push_back(i);
  }

  for(int i = 0; i < n-k+1; ++i){
    while(dq_min.front() < i){
      dq_min.pop_front();
    }

    while(dq_max.front() < i){
      dq_max.pop_front();
    }

    ret.push_back(std::make_pair(a[dq_min.front()], a[dq_max.front()]));

    while(not dq_min.empty() and i+k < n and a[dq_min.back()] >= a[i+k]){
      dq_min.pop_back();
    }

    while(not dq_max.empty() and i+k < n and a[dq_max.back()] <= a[i+k]){
      dq_max.pop_back();
    }
    
    dq_min.push_back(i+k);
    dq_max.push_back(i+k);
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/SlidingWindow/sliding_minmax.cpp"
#include <vector>
#include <deque>
#include <utility>

/**
 * @title Sliding window minmax
 * @docs sliding_minmax.md
 */
template <typename T> std::vector<std::pair<T,T>> sliding_minmax(const std::vector<T> &a, int k){
  int n = a.size();
  std::deque<int> dq_min, dq_max;
  std::vector<std::pair<T,T>> ret;

  for(int i = 0; i < k; ++i){
    while(not dq_min.empty() and a[dq_min.back()] >= a[i]){
      dq_min.pop_back();
    }
    
    dq_min.push_back(i);

    while(not dq_max.empty() and a[dq_max.back()] <= a[i]){
      dq_max.pop_back();
    }
    
    dq_max.push_back(i);
  }

  for(int i = 0; i < n-k+1; ++i){
    while(dq_min.front() < i){
      dq_min.pop_front();
    }

    while(dq_max.front() < i){
      dq_max.pop_front();
    }

    ret.push_back(std::make_pair(a[dq_min.front()], a[dq_max.front()]));

    while(not dq_min.empty() and i+k < n and a[dq_min.back()] >= a[i+k]){
      dq_min.pop_back();
    }

    while(not dq_max.empty() and i+k < n and a[dq_max.back()] <= a[i+k]){
      dq_max.pop_back();
    }
    
    dq_min.push_back(i+k);
    dq_max.push_back(i+k);
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

