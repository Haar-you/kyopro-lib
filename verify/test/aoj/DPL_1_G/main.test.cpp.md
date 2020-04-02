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


# :heavy_check_mark: test/aoj/DPL_1_G/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#d7859a8f41cb711fe2876b3f2c82daaf">test/aoj/DPL_1_G</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_G/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp.html">個数制限付きナップサック問題</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  
  std::vector<int> v(N), w(N), m(N);
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i] >> m[i];
  }
  
  auto ans = knapsack_limited(N, W, w, v, m);
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_G/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp"
#include <algorithm>

/**
 * @title 個数制限付きナップサック問題
 * @attention 時間計算量 O(NWlog(MaxM))
 */
template <typename Weight, typename Value>
Value knapsack_limited(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v, const std::vector<int> &m){
  std::vector<Value> dp(W+1);

  for(int i = 0; i < N; ++i){
    for(int64_t a = 1, x = m[i], k; k = std::min(x,a), x > 0; x -= k, a *= 2){
      for(int j = W; j >= 0; --j){
        if(j-k*w[i] >= 0){
          dp[j] = std::max(dp[j], dp[j-k*w[i]] + (Weight)k*v[i]);
        }
      }
    }
  }

  return dp[W];
}
#line 6 "test/aoj/DPL_1_G/main.test.cpp"

int main(){
  int N, W; std::cin >> N >> W;
  
  std::vector<int> v(N), w(N), m(N);
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i] >> m[i];
  }
  
  auto ans = knapsack_limited(N, W, w, v, m);
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

