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


# :heavy_check_mark: test/yukicoder/186/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0bd636f7c7da7cc28e18f9f04b1f4152">test/yukicoder/186</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/186/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://yukicoder.me/problems/447">https://yukicoder.me/problems/447</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/chinese_remainder_algorithm.cpp.html">中国剰余定理</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/extended_gcd.cpp.html">拡張Euclidの互除法</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#include "Mylib/Number/chinese_remainder_algorithm.cpp"

int main(){
  int64_t x1, y1, x2, y2, x3, y3; std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int64_t m, r;
  
  if(CRA({x1, x2, x3}, {y1, y2, y3}, r, m)){
    std::cout << (r == 0 ? m : r) << std::endl;
  }else{
    std::cout << -1 << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/186/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#line 2 "Mylib/Number/chinese_remainder_algorithm.cpp"
#include <vector>
#include <tuple>
#line 3 "Mylib/Number/extended_gcd.cpp"

/**
 * @title 拡張Euclidの互除法
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
 * @title 中国剰余定理
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

#line 5 "test/yukicoder/186/main.test.cpp"

int main(){
  int64_t x1, y1, x2, y2, x3, y3; std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int64_t m, r;
  
  if(CRA({x1, x2, x3}, {y1, y2, y3}, r, m)){
    std::cout << (r == 0 ? m : r) << std::endl;
  }else{
    std::cout << -1 << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

