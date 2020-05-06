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


# :heavy_check_mark: test/aoj/NTL_1_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3008ead005d9a504d0a3e077716b71c1">test/aoj/NTL_1_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Prime/prime_factorize.cpp.html">素因数分解</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>
#include "Mylib/Number/Prime/prime_factorize.cpp"

int main(){
  int n; std::cin >> n;

  auto res = prime_factorize(n);

  std::cout << n << ":";

  for(auto &[x, c] : res){
    for(int i = 0; i < c; ++i){
      std::cout << " " << x;
    }
  }

  std::cout << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>
#line 2 "Mylib/Number/Prime/prime_factorize.cpp"
#include <vector>
#include <utility>

/**
 * @title 素因数分解
 * @docs prime_factorize.md
 */
auto prime_factorize(int64_t n){
  std::vector<std::pair<int64_t,int64_t>> ret;
  for(int64_t i = 2LL; i * i <= n; ++i){
    if(n % i == 0){
      int64_t c = 0;
      while(n % i == 0){
        n /= i;
        ++c;
      }
      ret.emplace_back(i, c);
    }
  }
  if(n != 1) ret.emplace_back(n, 1);
  return ret;
}
#line 5 "test/aoj/NTL_1_A/main.test.cpp"

int main(){
  int n; std::cin >> n;

  auto res = prime_factorize(n);

  std::cout << n << ":";

  for(auto &[x, c] : res){
    for(int i = 0; i < c; ++i){
      std::cout << " " << x;
    }
  }

  std::cout << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

