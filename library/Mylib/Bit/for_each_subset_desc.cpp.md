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


# :heavy_check_mark: 下位集合を降順に列挙

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/for_each_subset_desc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-20 18:00:03+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ITP2_11_C/main.desc.test.cpp.html">test/aoj/ITP2_11_C/main.desc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title 下位集合を降順に列挙
 * @docs for_each_subset_desc.md
 */
class SubsetDesc{
  struct iter{
    int t, a;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      if(t == 0) is_end = true;
      t = (t - 1) & a;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a;

public:
  SubsetDesc(int a): a(a){}
  iter begin() const {return iter({a, a, false});}
  iter end() const {return iter();}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/for_each_subset_desc.cpp"

/**
 * @title 下位集合を降順に列挙
 * @docs for_each_subset_desc.md
 */
class SubsetDesc{
  struct iter{
    int t, a;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      if(t == 0) is_end = true;
      t = (t - 1) & a;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a;

public:
  SubsetDesc(int a): a(a){}
  iter begin() const {return iter({a, a, false});}
  iter end() const {return iter();}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

