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


# :heavy_check_mark: Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-28 03:01:30+09:00




## Operations

## Requirements

## Notes

## Problems

- [yukicoder No.776 A Simple RMQ Problem](https://yukicoder.me/problems/no/776)

## References



## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yukicoder/776/main.test.cpp.html">test/yukicoder/776/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>
#include <algorithm>

/**
 * @docs max_partial_sum.md
 */
template <typename T>
struct MaxPartialSumMonoid{
  struct MaxPartialSum{
    T sum, left_max, right_max, partial_max;
    static auto make(T x){return MaxPartialSum({x, x, x, x});}
  };
  
  using value_type = std::optional<MaxPartialSum>;
  
  static value_type id(){
    return std::nullopt;
  }
  
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;

    return {
            {
             a->sum + b->sum,
             std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
             std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
             std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
            }
    };
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include <optional>
#include <algorithm>

/**
 * @docs max_partial_sum.md
 */
template <typename T>
struct MaxPartialSumMonoid{
  struct MaxPartialSum{
    T sum, left_max, right_max, partial_max;
    static auto make(T x){return MaxPartialSum({x, x, x, x});}
  };
  
  using value_type = std::optional<MaxPartialSum>;
  
  static value_type id(){
    return std::nullopt;
  }
  
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;

    return {
            {
             a->sum + b->sum,
             std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
             std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
             std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
            }
    };
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

