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


# :heavy_check_mark: Enumerate supersets (Ascending order)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/for_each_superset_asc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `for(int i : SupersetAsc(a, n)){...}`
	- 大きさ`n`の集合で`a`の上位集合であるものを昇順に列挙する。

## Requirements

## Notes

## Problems

## References

- [https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/](https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/)
- [https://jetbead.hatenablog.com/entry/20121202/1354406422](https://jetbead.hatenablog.com/entry/20121202/1354406422)
- [https://ark4rk.hatenablog.com/entry/2018/03/07/230257](https://ark4rk.hatenablog.com/entry/2018/03/07/230257)
- [https://primenumber.hatenadiary.jp/entry/2016/12/01/000000](https://primenumber.hatenadiary.jp/entry/2016/12/01/000000)


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ITP2_11_B/main.asc.test.cpp.html">test/aoj/ITP2_11_B/main.asc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Enumerate supersets (Ascending order)
 * @docs for_each_superset_asc.md
 */
class SupersetAsc{
  struct iter{
    int t, a, n;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      t = (t + 1) | a;
      if(t >= (1 << n)) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a, n;

public:
  SupersetAsc(int a, int n): a(a), n(n){}
  iter begin() const {return iter({a, a, n, false});}
  iter end() const {return iter();}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/for_each_superset_asc.cpp"

/**
 * @title Enumerate supersets (Ascending order)
 * @docs for_each_superset_asc.md
 */
class SupersetAsc{
  struct iter{
    int t, a, n;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      t = (t + 1) | a;
      if(t >= (1 << n)) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a, n;

public:
  SupersetAsc(int a, int n): a(a), n(n){}
  iter begin() const {return iter({a, a, n, false});}
  iter end() const {return iter();}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

