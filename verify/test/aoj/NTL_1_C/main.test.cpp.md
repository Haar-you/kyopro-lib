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


# :heavy_check_mark: test/aoj/NTL_1_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#fcb24e02e278be19ec740adb48092544">test/aoj/NTL_1_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/binary_gcd.cpp.html">Binary GCD</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>
#include <vector>
#include "Mylib/Number/binary_gcd.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);

  int l = 1;
  for(auto x : a){
    l = l / binary_gcd(l, x) * x;
  }

  std::cout << l << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>
#include <vector>
#line 2 "Mylib/Number/binary_gcd.cpp"
#include <utility>
#include <cmath>

/**
 * @title Binary GCD
 * @docs binary_gcd.md
 */
int64_t binary_gcd(int64_t a, int64_t b){
  int64_t g = 1;

  while(1){
    if(a > b) std::swap(a, b);
    
    if(a == 0){
      break;
    }else{
      if((a & 1) == 0 and (b & 1) == 0){
        a >>= 1;
        b >>= 1;
        g <<= 1;
      }else if((a & 1) == 0){
        a >>= 1;
      }else if((b & 1) == 0){
        b >>= 1;
      }else{
        int64_t t = std::abs(a - b) >> 1;
        b = t;
      }
    }
  }

  return g * b;
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
#line 7 "test/aoj/NTL_1_C/main.test.cpp"

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);

  int l = 1;
  for(auto x : a){
    l = l / binary_gcd(l, x) * x;
  }

  std::cout << l << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

