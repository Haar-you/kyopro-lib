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


# :x: Enumerate supersets (Descending order)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/enumerate_supersets_desc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Operations

- `for(int i : SupersetDesc(a, n)){...}`
	- 大きさ`n`の集合で`a`の上位集合であるものを降順に列挙する。

## Requirements

## Notes

## Problems

## References

- [https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/](https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/)
- [https://jetbead.hatenablog.com/entry/20121202/1354406422](https://jetbead.hatenablog.com/entry/20121202/1354406422)
- [https://ark4rk.hatenablog.com/entry/2018/03/07/230257](https://ark4rk.hatenablog.com/entry/2018/03/07/230257)
- [https://primenumber.hatenadiary.jp/entry/2016/12/01/000000](https://primenumber.hatenadiary.jp/entry/2016/12/01/000000)


## Verified with

* :x: <a href="../../../verify/test/aoj/ITP2_11_B/main.desc.test.cpp.html">test/aoj/ITP2_11_B/main.desc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Enumerate supersets (Descending order)
 * @docs enumerate_supersets_desc.md
 */
namespace haar_lib {
  template <typename Func>
  void enumerate_supersets_desc(int a, int n, const Func &f){
    const int x = (1 << n) - 1, y = x ^ (a & x);
    for(int t = y; ; t = (t - 1) & y){
      if(not f(t | a)) break;
      if(t == 0) break;
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/enumerate_supersets_desc.cpp"

/**
 * @title Enumerate supersets (Descending order)
 * @docs enumerate_supersets_desc.md
 */
namespace haar_lib {
  template <typename Func>
  void enumerate_supersets_desc(int a, int n, const Func &f){
    const int x = (1 << n) - 1, y = x ^ (a & x);
    for(int t = y; ; t = (t - 1) & y){
      if(not f(t | a)) break;
      if(t == 0) break;
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

