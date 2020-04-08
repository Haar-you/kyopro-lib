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


# :heavy_check_mark: test/aoj/NTL_1_D/main.totient.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f883b12bcaccb309536ea11ea7e4a50">test/aoj/NTL_1_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_D/main.totient.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-08 17:37:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/euler_phi_function.cpp.html">Eulerのトーシェント関数</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include "Mylib/Number/euler_phi_function.cpp"

int main(){
  int n; std::cin >> n;

  std::cout << totient(n) << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_D/main.totient.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#line 2 "Mylib/Number/euler_phi_function.cpp"

/**
 * @title Eulerのトーシェント関数
 */
int64_t totient(int64_t n){
  int64_t ret = n;

  for(int64_t i = 2; i * i <= n; ++i){
    if(n % i == 0){
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }

  if(n != 1) ret -= ret / n;

  return ret;
}
#line 5 "test/aoj/NTL_1_D/main.totient.test.cpp"

int main(){
  int n; std::cin >> n;

  std::cout << totient(n) << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

