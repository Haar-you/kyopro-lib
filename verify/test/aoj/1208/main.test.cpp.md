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


# :x: test/aoj/1208/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#60cfb2a207c530b35f28147fe13d3d80">test/aoj/1208</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1208/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Number/Rational/stern_brocot_tree.cpp.html">Stern-Brocot tree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208"

#include <iostream>
#include <utility>
#include "Mylib/Number/Rational/stern_brocot_tree.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int p, n;
  while(std::cin >> p >> n, p){
    std::pair<int, int> lower, upper;
    stern_brocot_tree(
      [p](int64_t pm, int64_t qm){
        auto a = pm * pm;
        auto b = p * qm * qm;
        if(a < b) return -1;
        if(a > b) return 1;
        return 0;
      },
      n, lower, upper
    );
    std::cout << upper.first << "/" << upper.second << " "
              << lower.first << "/" << lower.second << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1208/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208"

#include <iostream>
#include <utility>
#line 3 "Mylib/Number/Rational/stern_brocot_tree.cpp"
#include <cstdint>

/**
 * @title Stern-Brocot tree
 * @docs stern_brocot_tree.md
 */
template <typename Checker>
void stern_brocot_tree(const Checker &check, int n, std::pair<int, int> &lower, std::pair<int, int> &upper, int64_t pl = 0, int64_t ql = 1, int64_t pr = 1, int64_t qr = 0){
  int64_t pm = pl + pr;
  int64_t qm = ql + qr;

  if(pm > n or qm > n) return;

  auto t = check(pm, qm);

  if(t < 0){
    lower = {pm, qm};
    stern_brocot_tree(check, n, lower, upper, pm, qm, pr, qr);
  }else if(t > 0){
    upper = {pm, qm};
    stern_brocot_tree(check, n, lower, upper, pl, ql, pm, qm);
  }else{
    lower = {pm, qm};
    upper = {pm, qm};
  }
}
#line 6 "test/aoj/1208/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int p, n;
  while(std::cin >> p >> n, p){
    std::pair<int, int> lower, upper;
    stern_brocot_tree(
      [p](int64_t pm, int64_t qm){
        auto a = pm * pm;
        auto b = p * qm * qm;
        if(a < b) return -1;
        if(a > b) return 1;
        return 0;
      },
      n, lower, upper
    );
    std::cout << upper.first << "/" << upper.second << " "
              << lower.first << "/" << lower.second << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

