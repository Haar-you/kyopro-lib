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


# :x: Dual segment tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `DualSegmentTree(n)`
- `update(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow v \circ a_i$に更新する。
- `get(i)`
	- $a_i$を返す。
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References



## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_2_D/main.test.cpp.html">test/aoj/DSL_2_D/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DSL_2_E/main.test.cpp.html">test/aoj/DSL_2_E/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Dual segment tree
 * @docs dual_segment_tree.md
 */
template <typename Monoid>
class DualSegmentTree {
  using value_type = typename Monoid::value_type;
  const static Monoid M;

  const int depth, size, hsize;
  std::vector<value_type> data;

  void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = M(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = M(data[i], data[i << 1 | 1]);
      data[i] = M();
    }
  }

  void propagate_top_down(int i){
    std::vector<int> temp;
    while(i > 1){
      i >>= 1;
      temp.push_back(i);
    }

    for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
  }

public:
  DualSegmentTree(int n):
    depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M())
  {}

  void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;

    while(L < R){
      if(R & 1) --R, data[R] = M(x, data[R]);
      if(L & 1) data[L] = M(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  value_type operator[](int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &a){
    data.assign(size, M());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp"
#include <vector>

/**
 * @title Dual segment tree
 * @docs dual_segment_tree.md
 */
template <typename Monoid>
class DualSegmentTree {
  using value_type = typename Monoid::value_type;
  const static Monoid M;

  const int depth, size, hsize;
  std::vector<value_type> data;

  void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = M(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = M(data[i], data[i << 1 | 1]);
      data[i] = M();
    }
  }

  void propagate_top_down(int i){
    std::vector<int> temp;
    while(i > 1){
      i >>= 1;
      temp.push_back(i);
    }

    for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
  }

public:
  DualSegmentTree(int n):
    depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M())
  {}

  void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;

    while(L < R){
      if(R & 1) --R, data[R] = M(x, data[R]);
      if(L & 1) data[L] = M(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  value_type operator[](int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &a){
    data.assign(size, M());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

