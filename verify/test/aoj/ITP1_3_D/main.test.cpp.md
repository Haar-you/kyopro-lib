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


# :heavy_check_mark: test/aoj/ITP1_3_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8d38fbe7bd169996a63c214260a5e34a">test/aoj/ITP1_3_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP1_3_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 17:27:30+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Divisor/enumerate_divisors.cpp.html">Enumerate divisors</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include <iostream>
#include "Mylib/Number/Divisor/enumerate_divisors.cpp"

int main(){
  int a, b, c; std::cin >> a >> b >> c;

  int ans = 0;

  for(auto d : enumerate_divisors(c)){
    if(a <= d and d <= b) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ITP1_3_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include <iostream>
#line 2 "Mylib/Number/Divisor/enumerate_divisors.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Enumerate divisors
 * @docs enumerate_divisors.md
 */
std::vector<std::int64_t> enumerate_divisors(std::int64_t n){
  std::vector<std::int64_t> temp, ret;

  {
    std::int64_t i;
    for(i = 1LL; i * i < n; ++i){
      if(n%i == 0){
        temp.push_back(n / i);
        ret.push_back(i);
      }
    }
    if(i * i == n) ret.push_back(i);
  }

  std::reverse(temp.begin(), temp.end());
  ret.insert(ret.end(), temp.begin(), temp.end());
  
  return ret;
}
#line 5 "test/aoj/ITP1_3_D/main.test.cpp"

int main(){
  int a, b, c; std::cin >> a >> b >> c;

  int ans = 0;

  for(auto d : enumerate_divisors(c)){
    if(a <= d and d <= b) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

