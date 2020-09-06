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


# :x: Fenwick tree (2D)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f58e2c328298747e7665b6f6b5791ad">Mylib/DataStructure/FenwickTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Operations
可換群$(G, +, e)$上の二次元配列を扱う。
- `FenwickTree2D(w, h)`
- `get(x1, y1, x2, y2)`
	- $\sum_{x_1 \le i \lt x_2} \sum_{y_1 \le j \lt y_2} a_{i, j}$を返す。
	- Time complexity $O(\log w \log h)$
- `at(x, y)`
	- $a_{x, y}$を返す。
	- Time complexity $O(\log w \log h)$
- `update(x, y, v)`
	- $a_{x, y} \leftarrow a_{x, y} + v$で更新する。
	- Time complexity $O(\log w \log h)$

## Requirements

- `AbelianGroup`は可換性・結合性を満たす演算`op`と単位元`id`と逆元を与える関数`inv`をもつ。

## Notes

## Problems

## References



## Verified with

* :x: <a href="../../../../verify/test/aoj/2842/main.fenwick_tree.test.cpp.html">test/aoj/2842/main.fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Fenwick tree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D {
  using value_type = typename AbelianGroup::value_type;
  const static AbelianGroup G;

  int w, h;
  std::vector<std::vector<value_type>> data;

private:
  value_type get_w(int i, int y) const {
    value_type ret = G();
    i += 1;
    while(i > 0){
      ret = G(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }

  value_type get_w(int l, int r, int y) const {
    return G(get_w(r - 1, y), G.inv(get_w(l - 1, y)));
  }

  value_type get(int x1, int x2, int y) const {
    value_type ret = G();
    y += 1;
    while(y > 0){
      ret = G(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }

public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w + 1, std::vector<value_type>(h + 1));
  }

  value_type get(std::pair<int, int> p1, std::pair<int, int> p2) const { // [(x1, y1), (x2, y2))
    const auto [x1, y1] = p1;
    const auto [x2, y2] = p2;
    return G(get(x1, x2, y2 - 1), G.inv(get(x1, x2, y1 - 1)));
  }

  value_type operator[](std::pair<int, int> p) const {
    const auto [x, y] = p;
    return get({x, y}, {x + 1, y + 1});
  }

  void update(std::pair<int, int> p, const value_type &val){
    auto [x, y] = p;
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = G(data[i][j], val);
      }
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp"
#include <vector>

/**
 * @title Fenwick tree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D {
  using value_type = typename AbelianGroup::value_type;
  const static AbelianGroup G;

  int w, h;
  std::vector<std::vector<value_type>> data;

private:
  value_type get_w(int i, int y) const {
    value_type ret = G();
    i += 1;
    while(i > 0){
      ret = G(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }

  value_type get_w(int l, int r, int y) const {
    return G(get_w(r - 1, y), G.inv(get_w(l - 1, y)));
  }

  value_type get(int x1, int x2, int y) const {
    value_type ret = G();
    y += 1;
    while(y > 0){
      ret = G(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }

public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w + 1, std::vector<value_type>(h + 1));
  }

  value_type get(std::pair<int, int> p1, std::pair<int, int> p2) const { // [(x1, y1), (x2, y2))
    const auto [x1, y1] = p1;
    const auto [x2, y2] = p2;
    return G(get(x1, x2, y2 - 1), G.inv(get(x1, x2, y1 - 1)));
  }

  value_type operator[](std::pair<int, int> p) const {
    const auto [x, y] = p;
    return get({x, y}, {x + 1, y + 1});
  }

  void update(std::pair<int, int> p, const value_type &val){
    auto [x, y] = p;
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = G(data[i][j], val);
      }
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

