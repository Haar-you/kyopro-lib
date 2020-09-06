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


# :x: Segment tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `SegmentTree(n)`
- `operator[](i)`
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(1)$
- `get(l, r)`
	- $a_l \circ a_{l+1} \circ \ldots \circ a_{r-1}$を返す。
	- Time complexity $O(\log n)$
- `update(i, value)`
	- $a_i$を`value`に変更する。
	- Time complexity $O(\log n)$
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References



## Required by

* :x: <a href="segment_tree_on_segment_tree.cpp.html">Segment tree (On segment tree)</a>
* :x: <a href="../../Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp.html">Manhattan distance MST</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/0390/main.test.cpp.html">test/aoj/0390/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/2444/main.test.cpp.html">test/aoj/2444/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/3132/main.test.cpp.html">test/aoj/3132/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DSL_2_A/main.test.cpp.html">test/aoj/DSL_2_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DSL_2_B/main.test.cpp.html">test/aoj/DSL_2_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/manhattanmst/main.test.cpp.html">test/yosupo-judge/manhattanmst/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/point_add_rectangle_sum/main.test.cpp.html">test/yosupo-judge/point_add_rectangle_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/point_set_range_composite/main.test.cpp.html">test/yosupo-judge/point_set_range_composite/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/510/main.test.cpp.html">test/yukicoder/510/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/776/main.test.cpp.html">test/yukicoder/776/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/875/main.test.cpp.html">test/yukicoder/875/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree {
  using value_type = typename Monoid::value_type;
  const static Monoid M;

  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M())
  {}

  auto operator[](int i) const {return data[hsize + i];}

  auto get(int x, int y) const {
    value_type ret_left = M();
    value_type ret_right = M();

    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = M(data[--r], ret_right);
      if(l & 1) ret_left = M(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }

    return M(ret_left, ret_right);
  }

  void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
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
#line 2 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <vector>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree {
  using value_type = typename Monoid::value_type;
  const static Monoid M;

  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M())
  {}

  auto operator[](int i) const {return data[hsize + i];}

  auto get(int x, int y) const {
    value_type ret_left = M();
    value_type ret_right = M();

    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = M(data[--r], ret_right);
      if(l & 1) ret_left = M(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }

    return M(ret_left, ret_right);
  }

  void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

