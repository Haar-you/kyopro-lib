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


# :heavy_check_mark: Montmort数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/montmort_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="https://atcoder.jp/contests/arc009/tasks/arc009_3">https://atcoder.jp/contests/arc009/tasks/arc009_3</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/montmort_number_mod/main.test.cpp.html">test/yosupo-judge/montmort_number_mod/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Montmort数
 * @see https://atcoder.jp/contests/arc009/tasks/arc009_3
 * @note 完全順列,撹乱順列の個数
 * @note 1..nの順列を並び変えた時にどの要素も元の要素と異なるような並び替えの総数。
 */
template <typename T>
auto montmort_number(int n){
  std::vector<T> ret(n+1);

  ret[0] = 1;
  ret[1] = 0;
  ret[2] = 1;

  for(int i = 3; i <= n; ++i){
    ret[i] = (ret[i-1] + ret[i-2]) * (i-1);
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/montmort_number.cpp"
#include <vector>

/**
 * @title Montmort数
 * @see https://atcoder.jp/contests/arc009/tasks/arc009_3
 * @note 完全順列,撹乱順列の個数
 * @note 1..nの順列を並び変えた時にどの要素も元の要素と異なるような並び替えの総数。
 */
template <typename T>
auto montmort_number(int n){
  std::vector<T> ret(n+1);

  ret[0] = 1;
  ret[1] = 0;
  ret[2] = 1;

  for(int i = 3; i <= n; ++i){
    ret[i] = (ret[i-1] + ret[i-2]) * (i-1);
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

