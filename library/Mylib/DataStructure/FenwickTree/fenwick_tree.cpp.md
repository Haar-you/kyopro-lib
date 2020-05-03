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


# :x: FenwickTree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f58e2c328298747e7665b6f6b5791ad">Mylib/DataStructure/FenwickTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/FenwickTree/fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 16:28:32+09:00




## Operations

- `FenwickTree(n)`
- `update(i, v)`
	- $a_i \leftarrow a_i + v$に更新する。
	- Time complexity $O(\log n)$
- `get(i)`
	- $a_0 + a_1 + \ldots + a_{i-1}$を返す。
	- Time complexity $O(\log n)$
- `get(l, r)`
	- $a_l + a_{l+1} + \ldots + a_{r-1}$を返す。
	- Time complexity $O(\log n)$
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(\log n)$

## Requirements

- `AbelianGroup`は可換性・結合性を満たす演算`op`と単位元`id`と逆元を与える関数`inv`をもつ。

## Notes

## Problems

## References
 


## Required by

* :x: <a href="fenwick_tree_on_fenwick_tree.cpp.html">FenwickTree (FenwickTreeを乗せる)</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp.html">test/aoj/DSL_2_B/main.fenwick_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title FenwickTree
 * @docs fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree{
  using value_type = typename AbelianGroup::value_type;
  
  int size;
  std::vector<value_type> data;
  
public:
  FenwickTree(){}
  FenwickTree(int size):
    size(size), data(size + 1, AbelianGroup::id())
  {}
  
  inline void update(int i, const value_type &val){
    i += 1; // 1-index
    
    while(i <= size){
      data[i] = AbelianGroup::op(data[i], val);
      i += i & (-i);
    }
  }
  
  inline value_type get(int i) const { // [0, i)
    value_type ret = AbelianGroup::id();
    i += 1; // 1-index

    while(i > 0){
      ret = AbelianGroup::op(ret, data[i]);
      i -= i & (-i);
    }

    return ret;
  }

  inline value_type get(int l, int r) const { // [l, r)
    return AbelianGroup::op(get(r-1), AbelianGroup::inv(get(l-1)));
  }
  
  inline value_type at(int x) const {
    return get(x, x+1);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include <vector>

/**
 * @title FenwickTree
 * @docs fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree{
  using value_type = typename AbelianGroup::value_type;
  
  int size;
  std::vector<value_type> data;
  
public:
  FenwickTree(){}
  FenwickTree(int size):
    size(size), data(size + 1, AbelianGroup::id())
  {}
  
  inline void update(int i, const value_type &val){
    i += 1; // 1-index
    
    while(i <= size){
      data[i] = AbelianGroup::op(data[i], val);
      i += i & (-i);
    }
  }
  
  inline value_type get(int i) const { // [0, i)
    value_type ret = AbelianGroup::id();
    i += 1; // 1-index

    while(i > 0){
      ret = AbelianGroup::op(ret, data[i]);
      i -= i & (-i);
    }

    return ret;
  }

  inline value_type get(int l, int r) const { // [l, r)
    return AbelianGroup::op(get(r-1), AbelianGroup::inv(get(l-1)));
  }
  
  inline value_type at(int x) const {
    return get(x, x+1);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

