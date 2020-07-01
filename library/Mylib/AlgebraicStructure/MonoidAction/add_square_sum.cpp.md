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


# :heavy_check_mark: Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-28 03:01:30+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yukicoder/1099/main.test.cpp.html">test/yukicoder/1099/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @docs add_square_sum.cpp
 */
template <typename T>
struct AddSquareSum{
  using value_type_get = std::pair<T, T>;
  using value_type_update = T;

  static value_type_get id_get(){
    return std::make_pair(0, 0);
  }

  static value_type_update id_update(){
    return 0;
  }

  static value_type_get op_get(const value_type_get &a, const value_type_get &b){
    return std::make_pair(a.first + b.first, a.second + b.second);
  }

  static value_type_update op_update(const value_type_update &a, const value_type_update &b){
    return a + b;
  }
  
  static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return std::make_pair(a.first + b * len, a.second + b * (2 * a.first + b * len));
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp"
#include <utility>

/**
 * @docs add_square_sum.cpp
 */
template <typename T>
struct AddSquareSum{
  using value_type_get = std::pair<T, T>;
  using value_type_update = T;

  static value_type_get id_get(){
    return std::make_pair(0, 0);
  }

  static value_type_update id_update(){
    return 0;
  }

  static value_type_get op_get(const value_type_get &a, const value_type_get &b){
    return std::make_pair(a.first + b.first, a.second + b.second);
  }

  static value_type_update op_update(const value_type_update &a, const value_type_update &b){
    return a + b;
  }
  
  static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return std::make_pair(a.first + b * len, a.second + b * (2 * a.first + b * len));
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

