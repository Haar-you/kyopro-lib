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


# :x: test/aoj/NTL_1_E/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#eb00a432be8a262fbfe01324f50ff04b">test/aoj/NTL_1_E</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_E/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Number/extended_gcd.cpp.html">Extended Euclidean algorithm</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>
#include "Mylib/Number/extended_gcd.cpp"

namespace hl = haar_lib;

int main(){
  int a, b; std::cin >> a >> b;

  int x, y;
  std::tie(std::ignore, x, y) = hl::ext_gcd(a, b);

  std::cout << x << " " << y << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_E/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>
#line 2 "Mylib/Number/extended_gcd.cpp"
#include <tuple>

/**
 * @title Extended Euclidean algorithm
 * @docs extended_gcd.md
 */
namespace haar_lib {
  std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t b){
    if(b == 0) return std::make_tuple(a, 1, 0);
    int64_t d, p, q;
    std::tie(d, q, p) = ext_gcd(b, (a + b) % b);
    return std::make_tuple(d, p, q - a / b * p);
  }
}
#line 5 "test/aoj/NTL_1_E/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int a, b; std::cin >> a >> b;

  int x, y;
  std::tie(std::ignore, x, y) = hl::ext_gcd(a, b);

  std::cout << x << " " << y << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

