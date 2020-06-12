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


# :x: Segment tree (On segment tree)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `SegmentTree2D()`
- `add(x, y)`
	- 点`(x, y)`を追加する。
- `build()`
- `update(x, y, value)`
- `get(x1, y1, x2, y2)`

## Requirements

- `Monoid`は**可換性**・結合律を満たす演算`op`と単位元`id`をもつ。
- `add`, `build`, `update / get`の順で呼び出す。

## Notes

## Problems

## References
 


## Depends on

* :question: <a href="segment_tree.cpp.html">Segment tree</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

/**
 * @title Segment tree (On segment tree)
 * @docs segment_tree_on_segment_tree.md
 */
template <typename Monoid>
class SegmentTree2D{
  using value_type = typename Monoid::value_type;

  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int> c_xs;

  std::vector<std::vector<int>> c_ys;

  int x_size;

  std::vector<SegmentTree<Monoid>> segs;

public:
  SegmentTree2D(){}

  void add(int64_t x, int64_t y){
    xs.push_back(x);
    ys.push_back(y);
    ++N;
  }

  void build(){
    c_xs.insert(c_xs.end(), xs.begin(), xs.end());

    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    x_size = 1;
    while(x_size < (int)c_xs.size()) x_size *= 2;
    x_size *= 2;

    c_ys.resize(x_size);
    segs.resize(x_size);

    for(int i = 0; i < N; ++i){
      int j = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();
      c_ys[j + x_size / 2].push_back(ys[i]);
    }

    for(int i = 0; i < x_size / 2; ++i){
      auto &v = c_ys[i + x_size / 2];
      std::sort(v.begin(), v.end());
      v.erase(std::unique(v.begin(), v.end()), v.end());
    }

    for(int i = x_size / 2 - 1; i >= 1; --i){
      const auto &a = c_ys[i << 1 | 0];
      const auto &b = c_ys[i << 1 | 1];
      auto &c = c_ys[i];
      c.resize(a.size() + b.size());

      std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
      c.erase(std::unique(c.begin(), c.end()), c.end());
    }

    for(int i = 1; i < x_size; ++i){
      segs[i] = SegmentTree<Monoid>(c_ys[i].size());
    }
  }

  inline void update(int64_t x, int64_t y, const value_type &val){
    int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin() + x_size / 2;

    while(i >= 1){
      int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
      segs[i].update(j, Monoid::op(segs[i][j], val));

      i >>= 1;
    }
  }

private:
  inline value_type get_sub(int i, int64_t y1, int64_t y2) const {
    int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
    int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();

    return segs[i].get(l, r);
  }

public:
  // [x1, x2), [y1, y2)
  inline value_type get(int64_t x1, int64_t y1, int64_t x2, int64_t y2) const {
    int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin() + x_size / 2;
    int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin() + x_size / 2;

    value_type ret = Monoid::id();

    while(l < r){
      if(r & 1) ret = Monoid::op(ret, get_sub(--r, y1, y2));
      if(l & 1) ret = Monoid::op(ret, get_sub(l++, y1, y2));
      l >>= 1;
      r >>= 1;
    }

    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"
#include <vector>
#include <algorithm>

#line 3 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, Monoid::id())
  {}

  inline auto operator[](int i) const {return at(i);}
  inline auto at(int i) const {return data[hsize + i];}
  
  inline auto get(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(data[--r], ret_right);
      if(l & 1) ret_left = Monoid::op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_left, ret_right);
  }

  inline void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = Monoid::op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = Monoid::op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 6 "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"

/**
 * @title Segment tree (On segment tree)
 * @docs segment_tree_on_segment_tree.md
 */
template <typename Monoid>
class SegmentTree2D{
  using value_type = typename Monoid::value_type;

  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int> c_xs;

  std::vector<std::vector<int>> c_ys;

  int x_size;

  std::vector<SegmentTree<Monoid>> segs;

public:
  SegmentTree2D(){}

  void add(int64_t x, int64_t y){
    xs.push_back(x);
    ys.push_back(y);
    ++N;
  }

  void build(){
    c_xs.insert(c_xs.end(), xs.begin(), xs.end());

    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    x_size = 1;
    while(x_size < (int)c_xs.size()) x_size *= 2;
    x_size *= 2;

    c_ys.resize(x_size);
    segs.resize(x_size);

    for(int i = 0; i < N; ++i){
      int j = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();
      c_ys[j + x_size / 2].push_back(ys[i]);
    }

    for(int i = 0; i < x_size / 2; ++i){
      auto &v = c_ys[i + x_size / 2];
      std::sort(v.begin(), v.end());
      v.erase(std::unique(v.begin(), v.end()), v.end());
    }

    for(int i = x_size / 2 - 1; i >= 1; --i){
      const auto &a = c_ys[i << 1 | 0];
      const auto &b = c_ys[i << 1 | 1];
      auto &c = c_ys[i];
      c.resize(a.size() + b.size());

      std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
      c.erase(std::unique(c.begin(), c.end()), c.end());
    }

    for(int i = 1; i < x_size; ++i){
      segs[i] = SegmentTree<Monoid>(c_ys[i].size());
    }
  }

  inline void update(int64_t x, int64_t y, const value_type &val){
    int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin() + x_size / 2;

    while(i >= 1){
      int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
      segs[i].update(j, Monoid::op(segs[i][j], val));

      i >>= 1;
    }
  }

private:
  inline value_type get_sub(int i, int64_t y1, int64_t y2) const {
    int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
    int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();

    return segs[i].get(l, r);
  }

public:
  // [x1, x2), [y1, y2)
  inline value_type get(int64_t x1, int64_t y1, int64_t x2, int64_t y2) const {
    int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin() + x_size / 2;
    int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin() + x_size / 2;

    value_type ret = Monoid::id();

    while(l < r){
      if(r & 1) ret = Monoid::op(ret, get_sub(--r, y1, y2));
      if(l & 1) ret = Monoid::op(ret, get_sub(l++, y1, y2));
      l >>= 1;
      r >>= 1;
    }

    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
