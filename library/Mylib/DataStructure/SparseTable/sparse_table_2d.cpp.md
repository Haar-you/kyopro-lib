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


# :warning: Sparse table (2D)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9f519a6857abe7364ea5fbe97ba369aa">Mylib/DataStructure/SparseTable</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SparseTable/sparse_table_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `SparseTable2D(v[n][m])`
	- Time complexity $O(nm\log n \log m)$
- `get(int r1, int c1, int r2, int c2)`
	- `[r1, r2), [c1, c2)`を`Semilattice::op`でfoldする。
	- Time complexity $O(1)$

## Requirements

- `Semilattice`は冪等性・可換性・結合性を満たす`op`を持つ。
	- `max`, `min`, `gcd`, `lcm`, `and`, `or`など

## Problems

- [Codeforces Round #619 (Div. 2) E. Nanosoft](https://codeforces.com/contest/1301/problem/E)

## References

- [https://codeforces.com/blog/entry/45485](https://codeforces.com/blog/entry/45485)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>

/**
 * @title Sparse table (2D)
 * @docs sparse_table_2d.md
 */
template <typename Semilattice>
class SparseTable2D{
  using value_type = typename Semilattice::value_type;
  
  std::vector<std::vector<std::vector<std::vector<value_type>>>> a;
  std::vector<int> log_table;
  
public:
  SparseTable2D(const std::vector<std::vector<value_type>> &v){
    const int n = v.size();
    const int m = v[0].size();
    int logn = 0;
    int logm = 0;
    while((1 << logn) <= n) ++logn;
    while((1 << logm) <= m) ++logm;

    a = std::vector(n, std::vector(logn, std::vector(m, std::vector<value_type>(logm))));

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j) a[i][0][j][0] = v[i][j];

      for(int y = 1; y < logm; ++y){
        for(int j = 0; j < m; ++j){
          a[i][0][j][y] =
            Semilattice::op(a[i][0][j][y-1],
                          a[i][0][std::min<int>(m-1, j+(1<<(y-1)))][y-1]);
        }
      }
    }

    for(int x = 1; x < logn; ++x){
      for(int i = 0; i < n; ++i){
        for(int y = 0; y < logm; ++y){
          for(int j = 0; j < m; ++j){
            a[i][x][j][y] =
              Semilattice::op(a[i][x-1][j][y],
                            a[std::min<int>(n-1, i+(1<<(x-1)))][x-1][j][y]);
          }
        }
      }
    }
    
    log_table.assign(std::max(n,m)+1, 0);
    for(int i = 2; i < std::max(n,m)+1; ++i) log_table[i] = log_table[i>>1] + 1;
  }
  
  inline value_type get(int r1, int c1, int r2, int c2) const { // [(r1,c1), (r2,c2))
    int kr = log_table[r2-r1];
    int kc = log_table[c2-c1];
    
    value_type x = Semilattice::op(a[r1][kr][c1][kc], a[r1][kr][c2-(1<<kc)][kc]);
    value_type y = Semilattice::op(a[r2-(1<<kr)][kr][c1][kc], a[r2-(1<<kr)][kr][c2-(1<<kc)][kc]);
    
    return Semilattice::op(x, y);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SparseTable/sparse_table_2d.cpp"
#include <vector>
#include <utility>
#include <algorithm>

/**
 * @title Sparse table (2D)
 * @docs sparse_table_2d.md
 */
template <typename Semilattice>
class SparseTable2D{
  using value_type = typename Semilattice::value_type;
  
  std::vector<std::vector<std::vector<std::vector<value_type>>>> a;
  std::vector<int> log_table;
  
public:
  SparseTable2D(const std::vector<std::vector<value_type>> &v){
    const int n = v.size();
    const int m = v[0].size();
    int logn = 0;
    int logm = 0;
    while((1 << logn) <= n) ++logn;
    while((1 << logm) <= m) ++logm;

    a = std::vector(n, std::vector(logn, std::vector(m, std::vector<value_type>(logm))));

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j) a[i][0][j][0] = v[i][j];

      for(int y = 1; y < logm; ++y){
        for(int j = 0; j < m; ++j){
          a[i][0][j][y] =
            Semilattice::op(a[i][0][j][y-1],
                          a[i][0][std::min<int>(m-1, j+(1<<(y-1)))][y-1]);
        }
      }
    }

    for(int x = 1; x < logn; ++x){
      for(int i = 0; i < n; ++i){
        for(int y = 0; y < logm; ++y){
          for(int j = 0; j < m; ++j){
            a[i][x][j][y] =
              Semilattice::op(a[i][x-1][j][y],
                            a[std::min<int>(n-1, i+(1<<(x-1)))][x-1][j][y]);
          }
        }
      }
    }
    
    log_table.assign(std::max(n,m)+1, 0);
    for(int i = 2; i < std::max(n,m)+1; ++i) log_table[i] = log_table[i>>1] + 1;
  }
  
  inline value_type get(int r1, int c1, int r2, int c2) const { // [(r1,c1), (r2,c2))
    int kr = log_table[r2-r1];
    int kc = log_table[c2-c1];
    
    value_type x = Semilattice::op(a[r1][kr][c1][kc], a[r1][kr][c2-(1<<kc)][kc]);
    value_type y = Semilattice::op(a[r2-(1<<kr)][kr][c1][kc], a[r2-(1<<kr)][kr][c2-(1<<kc)][kc]);
    
    return Semilattice::op(x, y);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

