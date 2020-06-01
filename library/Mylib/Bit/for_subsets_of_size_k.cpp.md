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


# :x: Enumerate sets of size k

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/for_subsets_of_size_k.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/ITP2_11_D/main.test.cpp.html">test/aoj/ITP2_11_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Enumerate sets of size k
 * @docs for_subsets_of_size_k.md
 */
class KSubsets{
  struct iter{
    int c, n;
    bool is_end;

    int operator*() const {return c;}
    void operator++(){
      int x = c & (-c);
      int y = c + x;

      c = ((c & ~y) / x >> 1) | y;

      if(c >= 1 << n) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int k, n;

public:
  KSubsets(int k, int n): k(k), n(n){}
  iter begin() const {return iter({(1 << k) - 1, n, false});}
  iter end() const {return iter();}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/for_subsets_of_size_k.cpp"

/**
 * @title Enumerate sets of size k
 * @docs for_subsets_of_size_k.md
 */
class KSubsets{
  struct iter{
    int c, n;
    bool is_end;

    int operator*() const {return c;}
    void operator++(){
      int x = c & (-c);
      int y = c + x;

      c = ((c & ~y) / x >> 1) | y;

      if(c >= 1 << n) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int k, n;

public:
  KSubsets(int k, int n): k(k), n(n){}
  iter begin() const {return iter({(1 << k) - 1, n, false});}
  iter end() const {return iter();}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

