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


# :x: test/aoj/DPL_1_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5ffb9908d171cb12894511e5d6b7ae00">test/aoj/DPL_1_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DynamicProgramming/longest_increasing_subsequence.cpp.html">最長増加部分列</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>
#include "Mylib/DynamicProgramming/longest_increasing_subsequence.cpp"

int main(){
  int N; std::cin >> N;
  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  
  auto ans = lis(a);
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <iostream>
#include <vector>
#line 3 "Mylib/DynamicProgramming/longest_increasing_subsequence.cpp"
#include <algorithm>

/**
 * @title 最長増加部分列
 * @docs longest_increasing_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lis(const Container &xs){
  std::vector<T> dp;
  dp.reserve(xs.size());
  
  for(auto x : xs){
    if(dp.empty() or dp.back() < x){
      dp.push_back(x);
    }else{
      dp[std::lower_bound(dp.begin(),dp.end(),x)-dp.begin()] = x;
    }
  }

  return dp.size();
}
#line 6 "test/aoj/DPL_1_D/main.test.cpp"

int main(){
  int N; std::cin >> N;
  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  
  auto ans = lis(a);
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

