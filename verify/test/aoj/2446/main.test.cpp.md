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


# :x: test/aoj/2446/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5326787223290b45db8eae567be7c0f8">test/aoj/2446</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2446/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Convolution/fast_mobius_transform_subset.cpp.html">Fast Möbius transform (Subsets)</a>
* :x: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446"
#define ERROR 1e-7

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include "Mylib/Convolution/fast_mobius_transform_subset.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n, m; std::cin >> n >> m;

  auto a = input_vector<int64_t>(n);
  auto p = input_vector<double>(n);

  for(auto &x : p) x /= 100.0;

  std::vector<int64_t> dp(1 << n);
  for(int i = 1; i < 1 << n; ++i){
    int64_t l = 1;
    for(int j = 0; j < n; ++j){
      if((i >> j) & 1){
        int64_t g = std::gcd(l, a[j]);

        long long int k;
        if(__builtin_smulll_overflow(l / g, a[j], &k)){
          l = m + 1;
          break;
        }
        l = (l / g) * a[j];
      }
    }
    dp[i] = m / l;
  }

  dp = fast_mobius_transform_subset(dp);

  double ans = 0.0;

  for(int i = 0; i < (1 << n); ++i){
    double q = 1.0;
    for(int j = 0; j < n; ++j){
      if(i >> j & 1) q *= p[j];
      else q *= 1.0 - p[j];
    }
    ans += q * std::abs(dp[i]);
  }

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2446/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446"
#define ERROR 1e-7

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#line 3 "Mylib/Convolution/fast_mobius_transform_subset.cpp"
#include <functional>

/**
 * @title Fast Möbius transform (Subsets)
 * @docs fast_mobius_transform_subset.md
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1 << i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(j & (1 << i)) f[j] = op(f[j], f[j ^ (1 << i)]);
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
#line 10 "test/aoj/2446/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int64_t n, m; std::cin >> n >> m;

  auto a = input_vector<int64_t>(n);
  auto p = input_vector<double>(n);

  for(auto &x : p) x /= 100.0;

  std::vector<int64_t> dp(1 << n);
  for(int i = 1; i < 1 << n; ++i){
    int64_t l = 1;
    for(int j = 0; j < n; ++j){
      if((i >> j) & 1){
        int64_t g = std::gcd(l, a[j]);

        long long int k;
        if(__builtin_smulll_overflow(l / g, a[j], &k)){
          l = m + 1;
          break;
        }
        l = (l / g) * a[j];
      }
    }
    dp[i] = m / l;
  }

  dp = fast_mobius_transform_subset(dp);

  double ans = 0.0;

  for(int i = 0; i < (1 << n); ++i){
    double q = 1.0;
    for(int j = 0; j < n; ++j){
      if(i >> j & 1) q *= p[j];
      else q *= 1.0 - p[j];
    }
    ans += q * std::abs(dp[i]);
  }

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

