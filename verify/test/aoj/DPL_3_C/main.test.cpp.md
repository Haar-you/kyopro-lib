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


# :heavy_check_mark: test/aoj/DPL_3_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#acc0c5805d321988fbdcefb0f7160988">test/aoj/DPL_3_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_3_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 20:22:17+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp.html">ヒストグラム中の最大面積長方形の面積</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"
     
#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
     
int main(){
  int N; std::cin >> N;
  
  std::vector<int64_t> h(N);
  for(int i = 0; i < N; ++i) std::cin >> h[i];
  
  auto ans = max_rectangle_in_histogram(h);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_3_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"
     
#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
#include <stack>
#include <utility>

/**
 * @title ヒストグラム中の最大面積長方形の面積
 * @docs max_rectangle_in_histogram.md
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
#line 6 "test/aoj/DPL_3_C/main.test.cpp"
     
int main(){
  int N; std::cin >> N;
  
  std::vector<int64_t> h(N);
  for(int i = 0; i < N; ++i) std::cin >> h[i];
  
  auto ans = max_rectangle_in_histogram(h);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
