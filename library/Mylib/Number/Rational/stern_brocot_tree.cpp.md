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


# :heavy_check_mark: Stern-Brocot tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e55110d6133c602b43ca77c4caba1f06">Mylib/Number/Rational</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Rational/stern_brocot_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [http://www.prefield.com/algorithm/math/stern_brocot_tree.html](http://www.prefield.com/algorithm/math/stern_brocot_tree.html)
- [https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree](https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree)
- [http://blue-jam.hatenablog.com/entry/20110306/1299415086](http://blue-jam.hatenablog.com/entry/20110306/1299415086)


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1208/main.test.cpp.html">test/aoj/1208/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include <cstdint>

/**
 * @title Stern-Brocot tree
 * @docs stern_brocot_tree.md
 */
namespace haar_lib {
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
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Rational/stern_brocot_tree.cpp"
#include <utility>
#include <cstdint>

/**
 * @title Stern-Brocot tree
 * @docs stern_brocot_tree.md
 */
namespace haar_lib {
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

