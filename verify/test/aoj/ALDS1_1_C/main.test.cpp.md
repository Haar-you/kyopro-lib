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


# :x: test/aoj/ALDS1_1_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a8a6d8e3138deb7c2a3646b5ea12ddc2">test/aoj/ALDS1_1_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_1_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Number/Prime/is_prime.cpp.html">試し割り素数判定</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>
#include "Mylib/Number/Prime/is_prime.cpp"

int main(){
  int N; std::cin >> N;

  int ans = 0;
  
  while(N--){
    int x; std::cin >> x;
    if(is_prime(x)) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_1_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>
#line 2 "Mylib/Number/Prime/is_prime.cpp"

/**
 * @title 試し割り素数判定
 * @docs is_prime.md
 */
bool is_prime(int n){
  if(n <= 1) return false;
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0) return false;
  }
  return true;
}
#line 5 "test/aoj/ALDS1_1_C/main.test.cpp"

int main(){
  int N; std::cin >> N;

  int ans = 0;
  
  while(N--){
    int x; std::cin >> x;
    if(is_prime(x)) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

