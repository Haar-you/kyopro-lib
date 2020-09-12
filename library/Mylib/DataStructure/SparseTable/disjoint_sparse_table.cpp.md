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


# :warning: Disjoint sparse table

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9f519a6857abe7364ea5fbe97ba369aa">Mylib/DataStructure/SparseTable</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 19:51:00+09:00




## Operations

## Requirements

## Notes

## Problems

- [CodeChef SEGPROD](https://www.codechef.com/problems/SEGPROD)

## References

- [https://noshi91.hatenablog.com/entry/2018/05/08/183946](https://noshi91.hatenablog.com/entry/2018/05/08/183946)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <optional>

/**
 * @title Disjoint sparse table
 * @docs disjoint_sparse_table.md
 */
namespace haar_lib {
  template <typename Semigroup>
  class disjoint_sparse_table {
    using value_type = typename Semigroup::value_type;
    const static Semigroup S;

    int N;
    int logN;
    std::vector<value_type> A;

    std::vector<std::vector<value_type>> data;

    void build(int l, int r, int d){
      if(d <= 0) return;

      const int m = (l + r) / 2;

      data[d][m] = A[m];
      for(int i = m + 1; i < r; ++i){
        data[d][i] = S(data[d][i - 1], A[i]);
      }

      data[d][m - 1] = A[m - 1];
      for(int i = m - 2; i >= l; --i){
        data[d][i] = S(data[d][i + 1], A[i]);
      }

      build(l, m, d - 1);
      build(m, r, d - 1);
    }

  public:
    disjoint_sparse_table(std::vector<value_type> a):
      N(a.size()),
      logN(N > 1 ? 32 - __builtin_clz(N - 1) : 0),
      A(a),
      data(logN, std::vector<value_type>(1 << logN))
    {
      A.resize(1 << logN);
      if(logN > 0) std::copy(A.begin(), A.end(), data[0].begin());
      build(0, 1 << logN, logN - 1);
    }

    std::optional<value_type> get(int l, int r) const {
      if(l == r) return std::nullopt;
      --r;

      if(l == r) return A[l];

      const int k = 31 - __builtin_clz(l ^ r);
      return S(data[k][l], data[k][r]);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp"
#include <vector>
#include <algorithm>
#include <cassert>
#include <optional>

/**
 * @title Disjoint sparse table
 * @docs disjoint_sparse_table.md
 */
namespace haar_lib {
  template <typename Semigroup>
  class disjoint_sparse_table {
    using value_type = typename Semigroup::value_type;
    const static Semigroup S;

    int N;
    int logN;
    std::vector<value_type> A;

    std::vector<std::vector<value_type>> data;

    void build(int l, int r, int d){
      if(d <= 0) return;

      const int m = (l + r) / 2;

      data[d][m] = A[m];
      for(int i = m + 1; i < r; ++i){
        data[d][i] = S(data[d][i - 1], A[i]);
      }

      data[d][m - 1] = A[m - 1];
      for(int i = m - 2; i >= l; --i){
        data[d][i] = S(data[d][i + 1], A[i]);
      }

      build(l, m, d - 1);
      build(m, r, d - 1);
    }

  public:
    disjoint_sparse_table(std::vector<value_type> a):
      N(a.size()),
      logN(N > 1 ? 32 - __builtin_clz(N - 1) : 0),
      A(a),
      data(logN, std::vector<value_type>(1 << logN))
    {
      A.resize(1 << logN);
      if(logN > 0) std::copy(A.begin(), A.end(), data[0].begin());
      build(0, 1 << logN, logN - 1);
    }

    std::optional<value_type> get(int l, int r) const {
      if(l == r) return std::nullopt;
      --r;

      if(l == r) return A[l];

      const int k = 31 - __builtin_clz(l ^ r);
      return S(data[k][l], data[k][r]);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

