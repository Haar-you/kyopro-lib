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


# :heavy_check_mark: FenwickTree (2D)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f58e2c328298747e7665b6f6b5791ad">Mylib/DataStructure/FenwickTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2842/main.fenwick_tree.test.cpp.html">test/aoj/2842/main.fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title FenwickTree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
      
  int w, h;
  std::vector<std::vector<value_type>> data;
      
public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w+1, std::vector<value_type>(h+1));
  }

private:
  inline value_type get_w(int i, int y) const {
    value_type ret = AbelianGroup::id();
    i += 1;
    while(i > 0){
      ret = AbelianGroup::op(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }
  
  inline value_type get_w(int l, int r, int y) const {
    return AbelianGroup::inv(get_w(r-1, y), get_w(l-1, y));
  }

  inline value_type get(int x1, int x2, int y) const {
    value_type ret = AbelianGroup::id();
    y += 1;
    while(y > 0){
      ret = AbelianGroup::op(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }
  
public:
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    return AbelianGroup::inv(get(x1, x2, y2-1), get(x1, x2, y1-1));
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = AbelianGroup::op(data[i][j], val);
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
 * @title FenwickTree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
      
  int w, h;
  std::vector<std::vector<value_type>> data;
      
public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w+1, std::vector<value_type>(h+1));
  }

private:
  inline value_type get_w(int i, int y) const {
    value_type ret = AbelianGroup::id();
    i += 1;
    while(i > 0){
      ret = AbelianGroup::op(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }
  
  inline value_type get_w(int l, int r, int y) const {
    return AbelianGroup::inv(get_w(r-1, y), get_w(l-1, y));
  }

  inline value_type get(int x1, int x2, int y) const {
    value_type ret = AbelianGroup::id();
    y += 1;
    while(y > 0){
      ret = AbelianGroup::op(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }
  
public:
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    return AbelianGroup::inv(get(x1, x2, y2-1), get(x1, x2, y1-1));
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = AbelianGroup::op(data[i][j], val);
      }
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

