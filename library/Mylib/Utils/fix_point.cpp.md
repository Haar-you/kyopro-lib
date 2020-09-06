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


# :x: Fixed point combinator

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cf1ec978dae666792e23e53a3672d204">Mylib/Utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Utils/fix_point.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [http://koturn.hatenablog.com/entry/2018/06/10/060000](http://koturn.hatenablog.com/entry/2018/06/10/060000)


## Verified with

* :x: <a href="../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/2559/main.leftist_heap.test.cpp.html">test/aoj/2559/main.leftist_heap.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @title Fixed point combinator
 * @docs fix_point.md
 */
template <typename F>
struct FixPoint : F {
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename ... Args>
  constexpr auto operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args) ...);
  }
};

template <typename F>
inline constexpr auto make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
inline constexpr auto make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Utils/fix_point.cpp"
#include <utility>

/**
 * @title Fixed point combinator
 * @docs fix_point.md
 */
template <typename F>
struct FixPoint : F {
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename ... Args>
  constexpr auto operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args) ...);
  }
};

template <typename F>
inline constexpr auto make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
inline constexpr auto make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

