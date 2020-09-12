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


# :x: 1D Imos algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6dc6d5a2cac82b39a08fd9ff32ab6e48">Mylib/Algorithm/Imos</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Imos/imos_1d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_5_A/main.test.cpp.html">test/aoj/DSL_5_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 1D Imos algorithm
 * @docs imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct imos_1d {
    using value_type = T;

    std::vector<T> data;
    imos_1d(int n): data(n + 1){}

    void add(int a, int b, const T& val){ // [a, b)
      data[a] += 1;
      data[b] -= 1;
    }

    void build(){
      for(int i = 0; i < (int)data.size() - 1; ++i){
        data[i + 1] += data[i];
      }
    }

    T operator[](size_t i) const {return data[i];}
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Imos/imos_1d.cpp"
#include <vector>

/**
 * @title 1D Imos algorithm
 * @docs imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct imos_1d {
    using value_type = T;

    std::vector<T> data;
    imos_1d(int n): data(n + 1){}

    void add(int a, int b, const T& val){ // [a, b)
      data[a] += 1;
      data[b] -= 1;
    }

    void build(){
      for(int i = 0; i < (int)data.size() - 1; ++i){
        data[i + 1] += data[i];
      }
    }

    T operator[](size_t i) const {return data[i];}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
