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


# :heavy_check_mark: test/aoj/DPL_1_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#43599916c6d409d5a130510225db3493">test/aoj/DPL_1_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/KnapsackProblem/knapsack_unlimited.cpp.html">個数制限無しナップサック問題</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_unlimited.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  std::vector<int> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_unlimited(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/KnapsackProblem/knapsack_unlimited.cpp"
#include <algorithm>

/**
 * @title 個数制限無しナップサック問題
 * @attention 時間計算量 O(NW)
 */
template <typename Weight, typename Value>
Value knapsack_unlimited(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v){
  std::vector<std::vector<Value>> dp(N+1, std::vector<Value>(W+1));
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= W; ++j){
      if(j < w[i]) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = std::max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
    }
  }

  return dp[N][W];
};
#line 6 "test/aoj/DPL_1_C/main.test.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  std::vector<int> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_unlimited(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

