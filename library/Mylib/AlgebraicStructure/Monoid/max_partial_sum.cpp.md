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


# :x: Max partial sum monoid

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [yukicoder No.776 A Simple RMQ Problem](https://yukicoder.me/problems/no/776)

## References



## Verified with

* :x: <a href="../../../../verify/test/yukicoder/776/main.test.cpp.html">test/yukicoder/776/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>
#include <algorithm>
#include <iostream>

/**
 * @title Max partial sum monoid
 * @docs max_partial_sum.md
 */
namespace haar_lib {
  template <typename T>
  struct max_partial_sum_monoid {
    struct max_partial_sum {
      T sum, left_max, right_max, partial_max;
      max_partial_sum(T x): sum(x), left_max(x), right_max(x), partial_max(x){}
      max_partial_sum(T sum, T left_max, T right_max, T partial_max): sum(sum), left_max(left_max), right_max(right_max), partial_max(partial_max){}

      friend std::ostream& operator<<(std::ostream &s, const max_partial_sum &a){
        s << "(" << "sum: " << a.sum << ", "
          << "left_max: " << a.left_max << ", "
          << "right_max: " << a.right_max << ", "
          << "partial_max: " << a.partial_max << ")";
        return s;
      }
    };

    using value_type = std::optional<max_partial_sum>;

    value_type operator()() const {
      return std::nullopt;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(not a) return b;
      if(not b) return a;

      return max_partial_sum(
        a->sum + b->sum,
        std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
        std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
        std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
      );
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include <optional>
#include <algorithm>
#include <iostream>

/**
 * @title Max partial sum monoid
 * @docs max_partial_sum.md
 */
namespace haar_lib {
  template <typename T>
  struct max_partial_sum_monoid {
    struct max_partial_sum {
      T sum, left_max, right_max, partial_max;
      max_partial_sum(T x): sum(x), left_max(x), right_max(x), partial_max(x){}
      max_partial_sum(T sum, T left_max, T right_max, T partial_max): sum(sum), left_max(left_max), right_max(right_max), partial_max(partial_max){}

      friend std::ostream& operator<<(std::ostream &s, const max_partial_sum &a){
        s << "(" << "sum: " << a.sum << ", "
          << "left_max: " << a.left_max << ", "
          << "right_max: " << a.right_max << ", "
          << "partial_max: " << a.partial_max << ")";
        return s;
      }
    };

    using value_type = std::optional<max_partial_sum>;

    value_type operator()() const {
      return std::nullopt;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(not a) return b;
      if(not b) return a;

      return max_partial_sum(
        a->sum + b->sum,
        std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
        std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
        std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
      );
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

