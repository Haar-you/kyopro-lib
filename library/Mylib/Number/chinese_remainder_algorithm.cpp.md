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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: Chinese remainder theorem

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/chinese_remainder_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :x: <a href="extended_gcd.cpp.html">Extended euclidean algorithm</a>


## Verified with

* :x: <a href="../../../verify/test/yukicoder/186/main.test.cpp.html">test/yukicoder/186/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <tuple>
#include "Mylib/Number/extended_gcd.cpp"

/**
 * @title Chinese remainder theorem
 * @docs chinese_remainder_algorithm.md
 */
bool CRA(int64_t b1, int64_t m1, int64_t b2, int64_t m2, int64_t &r, int64_t &m){
  int64_t p,q,d;
  std::tie(d,p,q) = ext_gcd(m1,m2);
  if((b2-b1) % d != 0) return false;
  m = m1 * m2 / d;
  int64_t t = ((b2-b1) * p / d) % (m2 / d);
  r = (b1 + m1 * t + m) % m;
  return true;
}

bool CRA(const std::vector<int64_t> &bs, const std::vector<int64_t> &ms, int64_t &r, int64_t &m){
  int64_t R = 0, M = 1;
  for(int i = 0; i < (int)bs.size(); ++i){
    if(not CRA(R,M,bs[i],ms[i],r,m)) return false;
    R = r;
    M = m;
  }
  return true;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/chinese_remainder_algorithm.cpp"
#include <vector>
#include <tuple>
#line 3 "Mylib/Number/extended_gcd.cpp"

/**
 * @title Extended euclidean algorithm
 * @docs extended_gcd.md
 */
std::tuple<int64_t,int64_t,int64_t> ext_gcd(int64_t a, int64_t b){
  if(b == 0) return std::make_tuple(a,1,0);
  int64_t d,p,q;
  std::tie(d,q,p) = ext_gcd(b,(a+b)%b);
  return std::make_tuple(d,p,q-a/b*p);
}
#line 5 "Mylib/Number/chinese_remainder_algorithm.cpp"

/**
 * @title Chinese remainder theorem
 * @docs chinese_remainder_algorithm.md
 */
bool CRA(int64_t b1, int64_t m1, int64_t b2, int64_t m2, int64_t &r, int64_t &m){
  int64_t p,q,d;
  std::tie(d,p,q) = ext_gcd(m1,m2);
  if((b2-b1) % d != 0) return false;
  m = m1 * m2 / d;
  int64_t t = ((b2-b1) * p / d) % (m2 / d);
  r = (b1 + m1 * t + m) % m;
  return true;
}

bool CRA(const std::vector<int64_t> &bs, const std::vector<int64_t> &ms, int64_t &r, int64_t &m){
  int64_t R = 0, M = 1;
  for(int i = 0; i < (int)bs.size(); ++i){
    if(not CRA(R,M,bs[i],ms[i],r,m)) return false;
    R = r;
    M = m;
  }
  return true;
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

