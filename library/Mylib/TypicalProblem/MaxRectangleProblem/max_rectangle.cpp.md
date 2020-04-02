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


# :heavy_check_mark: 最大面積長方形の面積

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e5c03cf251a1c8b45af0c48200d5638e">Mylib/TypicalProblem/MaxRectangleProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00


* see: <a href="https://atcoder.jp/contests/arc081/submissions/5708645 ((w+1)*(h+1)の最大値を求める変種)">https://atcoder.jp/contests/arc081/submissions/5708645 ((w+1)*(h+1)の最大値を求める変種)</a>


## Depends on

* :question: <a href="max_rectangle_in_histogram.cpp.html">ヒストグラム中の最大面積長方形の面積</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DPL_3_B/main.test.cpp.html">test/aoj/DPL_3_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"

/**
 * @title 最大面積長方形の面積
 * @attention time complexity O(HW)
 * @see https://atcoder.jp/contests/arc081/submissions/5708645 ((w+1)*(h+1)の最大値を求める変種)
 */
int max_rectangle(const std::vector<std::vector<int>> &d){
  int H = d.size();
  int W = d[0].size();
    
  std::vector<std::vector<int>> c(d);
  for(int i = 1; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(c[i][j]){
        c[i][j] += c[i-1][j];
      }
    }
  }
  
  int ret = 0;
  for(int i = 0; i < H; ++i){
    int t = max_rectangle_in_histogram<int>(c[i]);
    ret = std::max(ret, t);
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"
#include <vector>
#include <algorithm>
#line 3 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
#include <stack>
#include <utility>

/**
 * @title ヒストグラム中の最大面積長方形の面積
 * @attention time complexity O(|h|)
 */
template <typename T>
T max_rectangle_in_histogram(const std::vector<T> &h){
  std::stack<std::pair<T,int>> st;
  T ret = 0;

  for(size_t i = 0; i < h.size(); ++i){
    if(st.empty()){
      st.push({h[i],i});
    }else if(st.top().first < h[i]){
      st.push({h[i],i});
    }else if(st.top().first > h[i]){
      int j = i;
      while(not st.empty() and st.top().first > h[i]){
        ret = std::max(ret, st.top().first * ((T)i-st.top().second));
        j = st.top().second;
        st.pop();
      }
      st.push({h[i],j});
    }
  }

  while(not st.empty()){
    ret = std::max(ret, st.top().first * ((T)h.size()-st.top().second));
    st.pop();
  }
  
  return ret;
}
#line 5 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"

/**
 * @title 最大面積長方形の面積
 * @attention time complexity O(HW)
 * @see https://atcoder.jp/contests/arc081/submissions/5708645 ((w+1)*(h+1)の最大値を求める変種)
 */
int max_rectangle(const std::vector<std::vector<int>> &d){
  int H = d.size();
  int W = d[0].size();
    
  std::vector<std::vector<int>> c(d);
  for(int i = 1; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(c[i][j]){
        c[i][j] += c[i-1][j];
      }
    }
  }
  
  int ret = 0;
  for(int i = 0; i < H; ++i){
    int t = max_rectangle_in_histogram<int>(c[i]);
    ret = std::max(ret, t);
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

