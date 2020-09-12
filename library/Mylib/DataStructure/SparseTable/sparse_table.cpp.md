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


# :x: Sparse table

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9f519a6857abe7364ea5fbe97ba369aa">Mylib/DataStructure/SparseTable</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SparseTable/sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 19:51:00+09:00




## Operations

- `SparseTable(v[n])`
    - Time complexity $O(n \log n)$
- `get(int s, int t)`
	- `[s, t)`を`Semilattice::op`でfoldする。
	- Time complexity $O(1)$

## Requirements

- `Semilattice`は冪等性・可換性・結合性を満たす`op`を持つ。
	- `max`, `min`, `gcd`, `lcm`, `and`, `or`など


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp.html">test/yosupo-judge/staticrmq/main.sparse_table.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <optional>

/**
 * @title Sparse table
 * @docs sparse_table.md
 */
namespace haar_lib {
  template <typename Semilattice>
  class sparse_table {
    using value_type = typename Semilattice::value_type;
    const static Semilattice S;

    std::vector<std::vector<value_type>> a;
    std::vector<int> log_table;

  public:
    template <typename T>
    sparse_table(const std::vector<T> &v){
      int n = v.size();
      int logn = 0;
      while((1 << logn) <= n) ++logn;

      a.assign(n, std::vector<value_type>(logn));
      for(int i = 0; i < n; ++i) a[i][0] = v[i];
      for(int j = 1; j < logn; ++j){
        for(int i = 0; i < n; ++i){
          a[i][j] = S(a[i][j - 1], a[std::min<int>(n - 1, i + (1 << (j - 1)))][j - 1]);
        }
      }

      log_table.assign(n + 1, 0);
      for(int i = 2; i < n + 1; ++i) log_table[i] = log_table[i >> 1] + 1;
    }

    std::optional<value_type> get(int s, int t) const { // [s, t)
      if(s == t) return std::nullopt;
      int k = log_table[t - s];
      return S(a[s][k], a[t - (1 << k)][k]);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <optional>

/**
 * @title Sparse table
 * @docs sparse_table.md
 */
namespace haar_lib {
  template <typename Semilattice>
  class sparse_table {
    using value_type = typename Semilattice::value_type;
    const static Semilattice S;

    std::vector<std::vector<value_type>> a;
    std::vector<int> log_table;

  public:
    template <typename T>
    sparse_table(const std::vector<T> &v){
      int n = v.size();
      int logn = 0;
      while((1 << logn) <= n) ++logn;

      a.assign(n, std::vector<value_type>(logn));
      for(int i = 0; i < n; ++i) a[i][0] = v[i];
      for(int j = 1; j < logn; ++j){
        for(int i = 0; i < n; ++i){
          a[i][j] = S(a[i][j - 1], a[std::min<int>(n - 1, i + (1 << (j - 1)))][j - 1]);
        }
      }

      log_table.assign(n + 1, 0);
      for(int i = 2; i < n + 1; ++i) log_table[i] = log_table[i >> 1] + 1;
    }

    std::optional<value_type> get(int s, int t) const { // [s, t)
      if(s == t) return std::nullopt;
      int k = log_table[t - s];
      return S(a[s][k], a[t - (1 << k)][k]);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
