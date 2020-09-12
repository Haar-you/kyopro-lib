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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: Bitonic tour

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3a96c66483797c15eff4c0c3d8733619">Mylib/DynamicProgramming</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/bitonic_tour.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/DPL_2_C/main.test.cpp.html">test/aoj/DPL_2_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

/**
 * @title Bitonic tour
 * @docs bitonic_tour.md
 */
namespace haar_lib {
  template <typename T>
  double bitonic_tour(int n, const std::vector<T> &x, const std::vector<T> &y){
    std::vector<std::vector<double>> dist(n, std::vector<double>(n));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        dist[i][j] = std::sqrt(dx * dx + dy * dy);
      }
    }

    std::vector<std::vector<double>> dp(n, std::vector<double>(n, std::numeric_limits<double>::max()));

    dp[0][0] = 0;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        dp[i][i] = std::min(dp[i][i], dp[i][j] + dist[i][j]);
        if(i + 1 < n){
          dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + dist[i][i + 1]);
          dp[i][i + 1] = std::min(dp[i][i + 1], dp[i][j] + dist[j][i + 1]);
        }
        if(j + 1 < n){
          dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + dist[j][j + 1]);
          dp[j + 1][j] = std::min(dp[j + 1][j], dp[i][j] + dist[i][j + 1]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/bitonic_tour.cpp"
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

/**
 * @title Bitonic tour
 * @docs bitonic_tour.md
 */
namespace haar_lib {
  template <typename T>
  double bitonic_tour(int n, const std::vector<T> &x, const std::vector<T> &y){
    std::vector<std::vector<double>> dist(n, std::vector<double>(n));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        dist[i][j] = std::sqrt(dx * dx + dy * dy);
      }
    }

    std::vector<std::vector<double>> dp(n, std::vector<double>(n, std::numeric_limits<double>::max()));

    dp[0][0] = 0;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        dp[i][i] = std::min(dp[i][i], dp[i][j] + dist[i][j]);
        if(i + 1 < n){
          dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + dist[i][i + 1]);
          dp[i][i + 1] = std::min(dp[i][i + 1], dp[i][j] + dist[j][i + 1]);
        }
        if(j + 1 < n){
          dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + dist[j][j + 1]);
          dp[j + 1][j] = std::min(dp[j + 1][j], dp[i][j] + dist[i][j + 1]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

