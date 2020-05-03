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
<script type="text/javascript" src="../../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../../assets/css/copy-button.css" />


# :x: 双対SegmentTree

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#ca42c2f4d81b13ae1e33bd4dfd939e89">Mylib/DataStructure/SegmentTree/Static/Dual</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/Static/Dual/dual_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

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

* :x: <a href="../../../../../../verify/test/aoj/DSL_2_D/main.test.cpp.html">test/aoj/DSL_2_D/main.test.cpp</a>
* :x: <a href="../../../../../../verify/test/aoj/DSL_2_E/main.test.cpp.html">test/aoj/DSL_2_E/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 双対SegmentTree
 * @docs dual_segment_tree.md
 */
template <typename Monoid>
class DualSegmentTree{
  using value_type = typename Monoid::value_type;
  
private:
  const int depth, size, hsize;
  std::vector<value_type> data;
  
  inline void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = Monoid::op(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = Monoid::op(data[i], data[i << 1 | 1]);
      data[i] = Monoid::id();
    }
  }

  inline void propagate_top_down(int i){
    std::vector<int> temp;
    while(i > 1){
      i >>= 1;
      temp.push_back(i);
    }

    for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
  }
  
public:
  DualSegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, Monoid::id())
  {}

  inline void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;
    
    while(L < R){
      if(R & 1) --R, data[R] = Monoid::op(x, data[R]);
      if(L & 1) data[L] = Monoid::op(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  inline value_type get(int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &a){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/Static/Dual/dual_segment_tree.cpp"
#include <vector>

/**
 * @title 双対SegmentTree
 * @docs dual_segment_tree.md
 */
template <typename Monoid>
class DualSegmentTree{
  using value_type = typename Monoid::value_type;
  
private:
  const int depth, size, hsize;
  std::vector<value_type> data;
  
  inline void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = Monoid::op(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = Monoid::op(data[i], data[i << 1 | 1]);
      data[i] = Monoid::id();
    }
  }

  inline void propagate_top_down(int i){
    std::vector<int> temp;
    while(i > 1){
      i >>= 1;
      temp.push_back(i);
    }

    for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
  }
  
public:
  DualSegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, Monoid::id())
  {}

  inline void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;
    
    while(L < R){
      if(R & 1) --R, data[R] = Monoid::op(x, data[R]);
      if(L & 1) data[L] = Monoid::op(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  inline value_type get(int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &a){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>

