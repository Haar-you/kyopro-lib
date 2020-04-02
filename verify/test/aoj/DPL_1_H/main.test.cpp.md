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


# :heavy_check_mark: test/aoj/DPL_1_H/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#209a8b7f1b4449e911e26d3b013a1582">test/aoj/DPL_1_H</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_H/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 13:17:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp.html">個数の制約が小さい0-1ナップサック問題 (半分全列挙)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;
  
  std::vector<int64_t> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_small_quantity(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_H/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"
#include <map>
#include <algorithm>
#include <iterator>

/**
 * @title 個数の制約が小さい0-1ナップサック問題 (半分全列挙)
 * @attention 時間計算量 O(2^(N/2) log(2^(N/2)))
 */
template <typename Weight, typename Value>
Value knapsack_small_quantity(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v){
  Value ret = 0;

  int p = N/2;
  int q = N-p;

  std::map<Weight, Value> a;
  for(int i = 0; i < 1<<p; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < p; ++j){
      if(i & (1<<j)){
        weight += w[j];
        value += v[j];
      }
    }

    a[weight] = std::max(a[weight], value);
  }

  Value m = 0;
  for(auto &kv : a){
    kv.second = std::max(kv.second, m);
    m = kv.second;
  }
  
  
  for(int i = 0; i < 1<<q; ++i){
    Weight weight = 0;
    Value value = 0;
    for(int j = 0; j < q; ++j){
      if(i&(1<<j)){
        weight += w[j+p];
        value += v[j+p];
      }
    }

    auto itr = a.upper_bound(std::max((Weight)0, W-weight));
    
    itr = std::prev(itr);
    if(weight + itr->first <= W) ret = std::max(ret, value + itr->second);
  }

  return ret;
}
#line 6 "test/aoj/DPL_1_H/main.test.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;
  
  std::vector<int64_t> v(N), w(N);
  
  for(int i = 0; i < N; ++i){
    std::cin >> v[i] >> w[i];
  }
  
  auto ans = knapsack_small_quantity(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

