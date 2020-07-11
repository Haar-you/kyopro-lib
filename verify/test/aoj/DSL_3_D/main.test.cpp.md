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


# :heavy_check_mark: test/aoj/DSL_3_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#701acb68cf3d7eb2875e08c5c295c84f">test/aoj/DSL_3_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_3_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp.html">Sliding window minimum</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <iostream>
#include <vector>
#include "Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N,L; std::cin >> N >> L;

  auto a = input_vector<int>(N);

  auto ans = sliding_minimum(a, L);

  std::cout << join(ans.begin(), ans.end()) << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_3_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <iostream>
#include <vector>
#line 3 "Mylib/Algorithm/SlidingWindow/sliding_minimum.cpp"
#include <deque>

/**
 * @title Sliding window minimum
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
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 8 "test/aoj/DSL_3_D/main.test.cpp"

int main(){
  int N,L; std::cin >> N >> L;

  auto a = input_vector<int>(N);

  auto ans = sliding_minimum(a, L);

  std::cout << join(ans.begin(), ans.end()) << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

