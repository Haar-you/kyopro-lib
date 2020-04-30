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


# :heavy_check_mark: 2Dセグメント木

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#dd4a4f8515bcc75e971952e726133342">Mylib/DataStructure/SegmentTree/Static/Normal</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="https://codeforces.com/contest/1301/submission/71853921">https://codeforces.com/contest/1301/submission/71853921</a>


## Verified with

* :heavy_check_mark: <a href="../../../../../../verify/test/aoj/2842/main.segment_tree.test.cpp.html">test/aoj/2842/main.segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 2Dセグメント木
 * @see https://codeforces.com/contest/1301/submission/71853921
 */
template <typename Monoid> class SegmentTree2D{
  using value_type = typename Monoid::value_type;
      
  int w, h;
  std::vector<std::vector<value_type>> data;

  inline value_type get_w(int l, int r, int y) const {
    l += w / 2;
    r += w / 2;

    value_type ret = Monoid::id();

    while(l < r){
      if(r & 1) ret = Monoid::op(ret, data[--r][y]);
      if(l & 1) ret = Monoid::op(ret, data[l++][y]);
      l >>= 1, r >>= 1;
    }
    
    return ret;
  }
      
public:
  SegmentTree2D(int width, int height){
    w = 1;
    while(w < width) w *= 2;
    w = w*2;
    
    h = 1;
    while(h < height) h *= 2;
    h = h*2;
        
    data = std::vector<std::vector<value_type>>(w, std::vector<value_type>(h));
  }
     
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    int l = y1 + h / 2;
    int r = y2 + h / 2;

    value_type ret = Monoid::id();

    while(l < r){
      if(r & 1) ret = Monoid::op(ret, get_w(x1, x2, --r));
      if(l & 1) ret = Monoid::op(ret, get_w(x1, x2, l++));
      l >>= 1, r >>= 1;
    }

    return ret;
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    const int i = x + w / 2;
    const int j = y + h / 2;
    
    data[i][j] = val;
     
    for(int X = i >> 1, Y = j; X > 0; X >>= 1){
      data[X][Y] = Monoid::op(data[X << 1 | 0][Y], data[X << 1 | 1][Y]);
    }
        
    for(int Y = j >> 1; Y > 0; Y >>= 1){
      for(int X = i; X > 0; X >>= 1){
        data[X][Y] = Monoid::op(data[X][Y << 1 | 0], data[X][Y << 1 | 1]);
      }
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_2d.cpp"
#include <vector>

/**
 * @title 2Dセグメント木
 * @see https://codeforces.com/contest/1301/submission/71853921
 */
template <typename Monoid> class SegmentTree2D{
  using value_type = typename Monoid::value_type;
      
  int w, h;
  std::vector<std::vector<value_type>> data;

  inline value_type get_w(int l, int r, int y) const {
    l += w / 2;
    r += w / 2;

    value_type ret = Monoid::id();

    while(l < r){
      if(r & 1) ret = Monoid::op(ret, data[--r][y]);
      if(l & 1) ret = Monoid::op(ret, data[l++][y]);
      l >>= 1, r >>= 1;
    }
    
    return ret;
  }
      
public:
  SegmentTree2D(int width, int height){
    w = 1;
    while(w < width) w *= 2;
    w = w*2;
    
    h = 1;
    while(h < height) h *= 2;
    h = h*2;
        
    data = std::vector<std::vector<value_type>>(w, std::vector<value_type>(h));
  }
     
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    int l = y1 + h / 2;
    int r = y2 + h / 2;

    value_type ret = Monoid::id();

    while(l < r){
      if(r & 1) ret = Monoid::op(ret, get_w(x1, x2, --r));
      if(l & 1) ret = Monoid::op(ret, get_w(x1, x2, l++));
      l >>= 1, r >>= 1;
    }

    return ret;
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    const int i = x + w / 2;
    const int j = y + h / 2;
    
    data[i][j] = val;
     
    for(int X = i >> 1, Y = j; X > 0; X >>= 1){
      data[X][Y] = Monoid::op(data[X << 1 | 0][Y], data[X << 1 | 1][Y]);
    }
        
    for(int Y = j >> 1; Y > 0; Y >>= 1){
      for(int X = i; X > 0; X >>= 1){
        data[X][Y] = Monoid::op(data[X][Y << 1 | 0], data[X][Y << 1 | 1]);
      }
    }
  }
};

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>
