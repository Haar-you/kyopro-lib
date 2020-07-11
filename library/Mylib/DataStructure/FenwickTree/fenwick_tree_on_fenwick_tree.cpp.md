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


# :x: Fenwick tree (On Fenwick tree)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f58e2c328298747e7665b6f6b5791ad">Mylib/DataStructure/FenwickTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00




## Depends on

* :question: <a href="fenwick_tree.cpp.html">Fenwick tree</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <numeric>
#include <algorithm>

#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"

/**
 * @title Fenwick tree (On Fenwick tree)
 * @docs fenwick_tree_on_fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
  AbelianGroup G;

  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int> c_xs;

  std::vector<std::vector<int>> c_ys;

  int x_size;

  std::vector<FenwickTree<AbelianGroup>> segs;

public:
  FenwickTree2D(){}

  void add(int64_t x, int64_t y){
    xs.push_back(x);
    ys.push_back(y);
    ++N;
  }

  void build(){
    c_xs.insert(c_xs.end(), xs.begin(), xs.end());

    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    x_size = c_xs.size();

    c_ys.resize(x_size + 1);
    segs.resize(x_size + 1);


    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j){return ys[i] < ys[j];});
    for(auto i : ord){
      int x = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();

      for(x += 1; x <= x_size; x += x & (-x)){
        c_ys[x].emplace_back(ys[i]);
      }
    }
    
    for(int i = 1; i <= x_size; ++i){
      auto &a = c_ys[i];
      a.erase(std::unique(a.begin(), a.end()), a.end());
      
      segs[i] = FenwickTree<AbelianGroup>(c_ys[i].size());
    }
  }

  void update(int64_t x, int64_t y, const value_type &val){
    int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin();

    for(i += 1; i <= x_size; i += i & (-i)){
      int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
      segs[i].update(j, val);
    }
  }

private:
  value_type get(int i, int64_t y1, int64_t y2) const {
    value_type ret = G.id();
    for(; i > 0; i -= i & (-i)){
      int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
      int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();
      ret = G.op(ret, segs[i].get(l, r));
    }
    return ret;
  }

public:
  // [x1, x2), [y1, y2)
  value_type get(int64_t x1, int64_t y1, int64_t x2, int64_t y2) const {
    int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin();
    int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin();
    return G.op(get(r, y1, y2), G.inv(get(l, y1, y2)));
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp"
#include <vector>
#include <numeric>
#include <algorithm>

#line 3 "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"

/**
 * @title Fenwick tree
 * @docs fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree{
  using value_type = typename AbelianGroup::value_type;
  AbelianGroup G;
  
  int size;
  std::vector<value_type> data;
  
public:
  FenwickTree(){}
  FenwickTree(int size):
    size(size), data(size + 1, G.id())
  {}
  
  void update(int i, const value_type &val){
    i += 1; // 1-index
    
    while(i <= size){
      data[i] = G.op(data[i], val);
      i += i & (-i);
    }
  }
  
  value_type get(int i) const { // [0, i)
    value_type ret = G.id();
    i += 1; // 1-index

    while(i > 0){
      ret = G.op(ret, data[i]);
      i -= i & (-i);
    }

    return ret;
  }

  value_type get(int l, int r) const { // [l, r)
    return G.op(get(r-1), G.inv(get(l-1)));
  }
  
  value_type at(int x) const {
    return get(x, x+1);
  }
};
#line 7 "Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp"

/**
 * @title Fenwick tree (On Fenwick tree)
 * @docs fenwick_tree_on_fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
  AbelianGroup G;

  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int> c_xs;

  std::vector<std::vector<int>> c_ys;

  int x_size;

  std::vector<FenwickTree<AbelianGroup>> segs;

public:
  FenwickTree2D(){}

  void add(int64_t x, int64_t y){
    xs.push_back(x);
    ys.push_back(y);
    ++N;
  }

  void build(){
    c_xs.insert(c_xs.end(), xs.begin(), xs.end());

    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    x_size = c_xs.size();

    c_ys.resize(x_size + 1);
    segs.resize(x_size + 1);


    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j){return ys[i] < ys[j];});
    for(auto i : ord){
      int x = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();

      for(x += 1; x <= x_size; x += x & (-x)){
        c_ys[x].emplace_back(ys[i]);
      }
    }
    
    for(int i = 1; i <= x_size; ++i){
      auto &a = c_ys[i];
      a.erase(std::unique(a.begin(), a.end()), a.end());
      
      segs[i] = FenwickTree<AbelianGroup>(c_ys[i].size());
    }
  }

  void update(int64_t x, int64_t y, const value_type &val){
    int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin();

    for(i += 1; i <= x_size; i += i & (-i)){
      int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
      segs[i].update(j, val);
    }
  }

private:
  value_type get(int i, int64_t y1, int64_t y2) const {
    value_type ret = G.id();
    for(; i > 0; i -= i & (-i)){
      int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
      int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();
      ret = G.op(ret, segs[i].get(l, r));
    }
    return ret;
  }

public:
  // [x1, x2), [y1, y2)
  value_type get(int64_t x1, int64_t y1, int64_t x2, int64_t y2) const {
    int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin();
    int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin();
    return G.op(get(r, y1, y2), G.inv(get(l, y1, y2)));
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

