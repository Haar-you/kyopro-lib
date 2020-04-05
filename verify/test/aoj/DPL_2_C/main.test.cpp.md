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


# :heavy_check_mark: test/aoj/DPL_2_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ca30339b964798e13b3846ad3753f829">test/aoj/DPL_2_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_2_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 15:40:57+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DynamicProgramming/bitonic_tour.cpp.html">Bitonic tour</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C"
#define ERROR 0.0001

#include <iostream>
#include <vector>
#include <iomanip>
#include "Mylib/DynamicProgramming/bitonic_tour.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n; std::cin >> n;

  std::vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i){
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::fixed << std::setprecision(12) << bitonic_tour(n, x, y) << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_2_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C"
#define ERROR 0.0001

#include <iostream>
#include <vector>
#include <iomanip>
#line 3 "Mylib/DynamicProgramming/bitonic_tour.cpp"
#include <limits>
#include <algorithm>
#include <cmath>

/**
 * @title Bitonic tour
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C
 */
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
      if(i+1 < n){
        dp[i+1][j] = std::min(dp[i+1][j], dp[i][j] + dist[i][i+1]);
        dp[i][i+1] = std::min(dp[i][i+1], dp[i][j] + dist[j][i+1]);
      }
      if(j+1 < n){
        dp[i][j+1] = std::min(dp[i][j+1], dp[i][j] + dist[j][j+1]);
        dp[j+1][j] = std::min(dp[j+1][j], dp[i][j] + dist[i][j+1]);
      }
    }
  }

  return dp[n-1][n-1];
}
#line 8 "test/aoj/DPL_2_C/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n; std::cin >> n;

  std::vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i){
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::fixed << std::setprecision(12) << bitonic_tour(n, x, y) << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

