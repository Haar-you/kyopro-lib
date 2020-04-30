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


# :heavy_check_mark: 双方向のセグメント木

<a href="../../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../../index.html#dd4a4f8515bcc75e971952e726133342">Mylib/DataStructure/SegmentTree/Static/Normal</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_both_foldable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 双方向のセグメント木
 */
template <typename Monoid>
class SegmentTreeBothFoldable{
  using value_type = typename Monoid::value_type;
  
protected:
  const int depth, size, hsize;
  std::vector<value_type> data_left, data_right;

public:
  SegmentTreeBothFoldable(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data_left(size, Monoid::id()),
    data_right(size, Monoid::id())
  {}

  inline auto operator[](int i) const {return at(i);}
  inline auto at(int i) const {return data_left[hsize + i];}
  
  inline auto fold_left(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(data_left[--r], ret_right);
      if(l & 1) ret_left = Monoid::op(ret_left, data_left[l++]);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_left, ret_right);
  }

  inline auto fold_right(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(ret_right, data_right[--r]);
      if(l & 1) ret_left = Monoid::op(data_right[l++], ret_left);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_right, ret_left);
  }

  inline void update(int i, const value_type &x){
    i += hsize;
    data_left[i] = data_right[i] = x;
    while(i > 1){
      i >>= 1;
      data_left[i] = Monoid::op(data_left[i << 1 | 0], data_left[i << 1 | 1]);
      data_right[i] = Monoid::op(data_right[i << 1 | 1], data_right[i << 1 | 0]);
    }
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data_left.assign(size, Monoid::id());
    data_right.assign(size, Monoid::id());
    
    for(int i = 0; i < (int)val.size(); ++i){
      data_left[hsize + i] = val[i];
      data_right[hsize + i] = val[i];
    }
    for(int i = hsize-1; i >= 1; --i){
      data_left[i] = Monoid::op(data_left[i << 1 | 0], data_left[i << 1 | 1]);
      data_right[i] = Monoid::op(data_right[i << 1 | 1], data_right[i << 1 | 0]);
    }
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
#line 2 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_both_foldable.cpp"
#include <vector>

/**
 * @title 双方向のセグメント木
 */
template <typename Monoid>
class SegmentTreeBothFoldable{
  using value_type = typename Monoid::value_type;
  
protected:
  const int depth, size, hsize;
  std::vector<value_type> data_left, data_right;

public:
  SegmentTreeBothFoldable(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data_left(size, Monoid::id()),
    data_right(size, Monoid::id())
  {}

  inline auto operator[](int i) const {return at(i);}
  inline auto at(int i) const {return data_left[hsize + i];}
  
  inline auto fold_left(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(data_left[--r], ret_right);
      if(l & 1) ret_left = Monoid::op(ret_left, data_left[l++]);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_left, ret_right);
  }

  inline auto fold_right(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(ret_right, data_right[--r]);
      if(l & 1) ret_left = Monoid::op(data_right[l++], ret_left);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_right, ret_left);
  }

  inline void update(int i, const value_type &x){
    i += hsize;
    data_left[i] = data_right[i] = x;
    while(i > 1){
      i >>= 1;
      data_left[i] = Monoid::op(data_left[i << 1 | 0], data_left[i << 1 | 1]);
      data_right[i] = Monoid::op(data_right[i << 1 | 1], data_right[i << 1 | 0]);
    }
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data_left.assign(size, Monoid::id());
    data_right.assign(size, Monoid::id());
    
    for(int i = 0; i < (int)val.size(); ++i){
      data_left[hsize + i] = val[i];
      data_right[hsize + i] = val[i];
    }
    for(int i = hsize-1; i >= 1; --i){
      data_left[i] = Monoid::op(data_left[i << 1 | 0], data_left[i << 1 | 1]);
      data_right[i] = Monoid::op(data_right[i << 1 | 1], data_right[i << 1 | 0]);
    }
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};

```
{% endraw %}

<a href="../../../../../../index.html">Back to top page</a>
