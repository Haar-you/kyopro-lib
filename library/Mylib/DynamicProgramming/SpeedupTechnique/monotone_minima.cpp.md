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


# :warning: Monotone minima

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#826136648af25fa7c5e97a1b794f9784">Mylib/DynamicProgramming/SpeedupTechnique</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/SpeedupTechnique/monotone_minima.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 03:09:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c)

## References

- [https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html](https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html)
- [https://ferin-tech.hatenablog.com/entry/2018/02/23/071343](https://ferin-tech.hatenablog.com/entry/2018/02/23/071343)
- [https://wiki.kimiyuki.net/monotone%20minima](https://wiki.kimiyuki.net/monotone%20minima)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>

/**
 * @title Monotone minima
 * @docs monotone_minima.md
 */
namespace monotone_minima_impl {
  template <typename T, typename F>
  auto rec(
    int N, int M, const F &f, int top, int bottom, int left, int right,
    std::vector<std::pair<int, T>> &ret
  ){
    if(top > bottom) return;
    if(top == bottom){
      const int i = top;

      int index = left;
      T m = f(i, index);

      for(int j = left; j <= right; ++j){
        const auto temp = f(i, j);
        if(temp < m){
          m = temp;
          index = j;
        }
      }

      ret[i] = std::make_pair(index, m);
      return;
    }

    const int mid = (top + bottom) / 2;
    rec(N, M, f, mid, mid, left, right, ret);
    rec(N, M, f, top, mid - 1, left, ret[mid].first, ret);
    rec(N, M, f, mid + 1, bottom, ret[mid].first, right, ret);
  }
}

template <typename T, typename F>
auto monotone_minima(int N, int M, const F &f){
  std::vector<std::pair<int, T>> ret(M);
  monotone_minima_impl::rec<T, F>(N, M, f, 0, N - 1, 0, M - 1, ret);

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/SpeedupTechnique/monotone_minima.cpp"
#include <vector>
#include <utility>

/**
 * @title Monotone minima
 * @docs monotone_minima.md
 */
namespace monotone_minima_impl {
  template <typename T, typename F>
  auto rec(
    int N, int M, const F &f, int top, int bottom, int left, int right,
    std::vector<std::pair<int, T>> &ret
  ){
    if(top > bottom) return;
    if(top == bottom){
      const int i = top;

      int index = left;
      T m = f(i, index);

      for(int j = left; j <= right; ++j){
        const auto temp = f(i, j);
        if(temp < m){
          m = temp;
          index = j;
        }
      }

      ret[i] = std::make_pair(index, m);
      return;
    }

    const int mid = (top + bottom) / 2;
    rec(N, M, f, mid, mid, left, right, ret);
    rec(N, M, f, top, mid - 1, left, ret[mid].first, ret);
    rec(N, M, f, mid + 1, bottom, ret[mid].first, right, ret);
  }
}

template <typename T, typename F>
auto monotone_minima(int N, int M, const F &f){
  std::vector<std::pair<int, T>> ret(M);
  monotone_minima_impl::rec<T, F>(N, M, f, 0, N - 1, 0, M - 1, ret);

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

