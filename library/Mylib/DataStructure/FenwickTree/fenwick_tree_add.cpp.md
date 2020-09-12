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


# :x: Fenwick tree (Add)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2f58e2c328298747e7665b6f6b5791ad">Mylib/DataStructure/FenwickTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Required by

* :warning: <a href="../../Algorithm/Query/range_count_query.cpp.html">Range count query</a>
* :x: <a href="../../Algorithm/Query/range_inversions_query.cpp.html">Range inversions query</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/static_range_inversions_query/main.test.cpp.html">test/yosupo-judge/static_range_inversions_query/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Fenwick tree (Add)
 * @docs fenwick_tree_add.md
 */
namespace haar_lib {
  template <typename T>
  class fenwick_tree_add {
    using value_type = T;

    int size;
    std::vector<value_type> data;

  public:
    fenwick_tree_add(){}
    fenwick_tree_add(int size): size(size), data(size + 1, 0){}

    void update(int i, value_type val){
      i += 1; // 1-index

      while(i <= size){
        data[i] = data[i] + val;
        i += i & (-i);
      }
    }

    value_type get(int i) const { // [0, i)
      value_type ret = 0;
      i += 1; // 1-index

      while(i > 0){
        ret = ret + data[i];
        i -= i & (-i);
      }

      return ret;
    }

    value_type get(int l, int r) const { // [l, r)
      return get(r - 1) - get(l - 1);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"
#include <vector>

/**
 * @title Fenwick tree (Add)
 * @docs fenwick_tree_add.md
 */
namespace haar_lib {
  template <typename T>
  class fenwick_tree_add {
    using value_type = T;

    int size;
    std::vector<value_type> data;

  public:
    fenwick_tree_add(){}
    fenwick_tree_add(int size): size(size), data(size + 1, 0){}

    void update(int i, value_type val){
      i += 1; // 1-index

      while(i <= size){
        data[i] = data[i] + val;
        i += i & (-i);
      }
    }

    value_type get(int i) const { // [0, i)
      value_type ret = 0;
      i += 1; // 1-index

      while(i > 0){
        ret = ret + data[i];
        i -= i & (-i);
      }

      return ret;
    }

    value_type get(int l, int r) const { // [l, r)
      return get(r - 1) - get(l - 1);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

