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


# :heavy_check_mark: test/aoj/3134/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4f0d05e27521ea76d6aad8fca840629e">test/aoj/3134</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/3134/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-30 03:53:09+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Convolution/fast_zeta_transform_subset.cpp.html">Fast Zeta transform (Subsets)</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134"

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Mylib/Convolution/fast_zeta_transform_subset.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N,K; std::cin >> N >> K;

  auto A = input_vector<int>(N);

  std::vector<int> sum(1 << N);

  for(int i = 0; i < 1<<N; ++i){
    for(int j = 0; j < N; ++j){
      if(not (i & (1 << j))){
        sum[i | (1 << j)] = sum[i] + A[j];
      }
    }
  }

  std::vector<int> f(1 << N);
  for(int i = 0; i < 1<<N; ++i){
    if(sum[i] == K) f[i] = true;
  }
  
  f = fast_zeta_transform_subset(f, std::logical_or<bool>());

  int ans = N;

  for(int i = 0; i < 1<<N; ++i){
    if(not f[i]){
      ans = std::min(ans, N - __builtin_popcount(i));
    }
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/3134/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134"

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#line 4 "Mylib/Convolution/fast_zeta_transform_subset.cpp"

/**
 * @title Fast Zeta transform (Subsets)
 * @docs fast_zeta_transform_subset.md
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_subset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(j & (1<<i)) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
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
#line 9 "test/aoj/3134/main.test.cpp"

int main(){
  int N,K; std::cin >> N >> K;

  auto A = input_vector<int>(N);

  std::vector<int> sum(1 << N);

  for(int i = 0; i < 1<<N; ++i){
    for(int j = 0; j < N; ++j){
      if(not (i & (1 << j))){
        sum[i | (1 << j)] = sum[i] + A[j];
      }
    }
  }

  std::vector<int> f(1 << N);
  for(int i = 0; i < 1<<N; ++i){
    if(sum[i] == K) f[i] = true;
  }
  
  f = fast_zeta_transform_subset(f, std::logical_or<bool>());

  int ans = N;

  for(int i = 0; i < 1<<N; ++i){
    if(not f[i]){
      ans = std::min(ans, N - __builtin_popcount(i));
    }
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

