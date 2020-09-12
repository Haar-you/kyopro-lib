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


# :x: Largest rectangle in histogram

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e5c03cf251a1c8b45af0c48200d5638e">Mylib/TypicalProblem/MaxRectangleProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Operations
- `max_rectangle_in_histogram(T h[N])`
	- Time complexity $O(N)$

## Requirements

## Problems

- [AOJ DPL_3_C Largest Rectangle in a Histogram](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C)

## References



## Required by

* :x: <a href="max_rectangle.cpp.html">Largest rectangle</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/DPL_3_B/main.test.cpp.html">test/aoj/DPL_3_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DPL_3_C/main.test.cpp.html">test/aoj/DPL_3_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <stack>
#include <utility>

/**
 * @title Largest rectangle in histogram
 * @docs max_rectangle_in_histogram.md
 */
namespace haar_lib {
  template <typename T>
  T max_rectangle_in_histogram(const std::vector<T> &h){
    std::stack<std::pair<T, int>> st;
    T ret = 0;

    for(size_t i = 0; i < h.size(); ++i){
      if(st.empty()){
        st.emplace(h[i], i);
      }else if(st.top().first < h[i]){
        st.emplace(h[i], i);
      }else if(st.top().first > h[i]){
        int j = i;
        while(not st.empty() and st.top().first > h[i]){
          ret = std::max(ret, st.top().first * ((T)i - st.top().second));
          j = st.top().second;
          st.pop();
        }
        st.emplace(h[i], j);
      }
    }

    while(not st.empty()){
      ret = std::max(ret, st.top().first * ((T)h.size() - st.top().second));
      st.pop();
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
#include <vector>
#include <stack>
#include <utility>

/**
 * @title Largest rectangle in histogram
 * @docs max_rectangle_in_histogram.md
 */
namespace haar_lib {
  template <typename T>
  T max_rectangle_in_histogram(const std::vector<T> &h){
    std::stack<std::pair<T, int>> st;
    T ret = 0;

    for(size_t i = 0; i < h.size(); ++i){
      if(st.empty()){
        st.emplace(h[i], i);
      }else if(st.top().first < h[i]){
        st.emplace(h[i], i);
      }else if(st.top().first > h[i]){
        int j = i;
        while(not st.empty() and st.top().first > h[i]){
          ret = std::max(ret, st.top().first * ((T)i - st.top().second));
          j = st.top().second;
          st.pop();
        }
        st.emplace(h[i], j);
      }
    }

    while(not st.empty()){
      ret = std::max(ret, st.top().first * ((T)h.size() - st.top().second));
      st.pop();
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
