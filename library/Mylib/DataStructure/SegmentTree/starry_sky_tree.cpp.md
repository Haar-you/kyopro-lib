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


# :heavy_check_mark: Starry-sky tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-01 07:13:20+09:00




## Operations

- `StarrySkyTree(n)`
- `update(l, r, val)`
	- `i in [l, r)`について$a_i \leftarrow a_i + v$に更新する。
- `get(l, r)`
	- `Compare = less<T>`
		- $\min_{l \le i \lt r} a_i$を返す。
	- `Compare = greater<T>`
		- $\max_{l \le i \lt r} a_i$を返す。
- `init_with_vector(a)`

## Requirements

## Notes

## Problems

- [starry_sky - 星空 (Starry Sky)](https://atcoder.jp/contests/joisc2009/tasks/joisc2009_starry_sky)
- [yukicoder No.631 Noelちゃんと電車旅行](https://yukicoder.me/problems/no/631)

## References

- [https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html](https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html)



## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_2_H/main.starry_sky.test.cpp.html">test/aoj/DSL_2_H/main.starry_sky.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yukicoder/631/main.starry_sky.test.cpp.html">test/yukicoder/631/main.starry_sky.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <algorithm>

/**
 * @title Starry-sky tree
 * @docs starry_sky_tree.md
 */
template <typename T, typename Compare>
class StarrySkyTree{
  int depth, size, hsize;
  std::vector<T> data;

  Compare compare = Compare();

  T f(T a, T b) const {
    return compare(a, b) ? a : b;
  }

  void bottom_up(int i){
    if(i > size) return;

    while(i >= 1){
      if(i < hsize){
        const auto d = f(data[i << 1 | 0], data[i << 1 | 1]);
        
        data[i << 1 | 0] -= d;
        data[i << 1 | 1] -= d;
        data[i] += d;
      }

      i >>= 1;
    }
  }
  
  std::optional<T> get(int i, int l, int r, int s, int t, T val) const {
    if(r <= s or t <= l) return std::nullopt;
    if(s <= l and r <= t) return val + data[i];

    auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data[i]);
    auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data[i]);

    if(not a) return b;
    if(not b) return a;
    return f(*a, *b);
  }

public:
  StarrySkyTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, 0)
  {}

  void update(int l, int r, T val){
    int L = l + hsize;
    int R = r + hsize;

    while(L < R){
      if(R & 1) --R, data[R] += val;
      if(L & 1) data[L] += val, ++L;
      L >>= 1;
      R >>= 1;
    }

    bottom_up(l + hsize);
    bottom_up(r + hsize);
  }

  T get(int l, int r) const {
    return *get(1, 0, hsize, l, r, 0);
  }

  template <typename U>
  void init_with_vector(std::vector<U> &a){
    for(int i = 0; i < (int)a.size(); ++i){
      data[hsize + i] = a[i];
    }

    for(int i = hsize - 1; i >= 1; --i){
      data[i] = f(data[i << 1 | 0], data[i << 1 | 1]);
    }

    for(int i = size - 1; i > 1; --i){
      data[i] -= data[i >> 1];
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include <vector>
#include <optional>
#include <algorithm>

/**
 * @title Starry-sky tree
 * @docs starry_sky_tree.md
 */
template <typename T, typename Compare>
class StarrySkyTree{
  int depth, size, hsize;
  std::vector<T> data;

  Compare compare = Compare();

  T f(T a, T b) const {
    return compare(a, b) ? a : b;
  }

  void bottom_up(int i){
    if(i > size) return;

    while(i >= 1){
      if(i < hsize){
        const auto d = f(data[i << 1 | 0], data[i << 1 | 1]);
        
        data[i << 1 | 0] -= d;
        data[i << 1 | 1] -= d;
        data[i] += d;
      }

      i >>= 1;
    }
  }
  
  std::optional<T> get(int i, int l, int r, int s, int t, T val) const {
    if(r <= s or t <= l) return std::nullopt;
    if(s <= l and r <= t) return val + data[i];

    auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data[i]);
    auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data[i]);

    if(not a) return b;
    if(not b) return a;
    return f(*a, *b);
  }

public:
  StarrySkyTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, 0)
  {}

  void update(int l, int r, T val){
    int L = l + hsize;
    int R = r + hsize;

    while(L < R){
      if(R & 1) --R, data[R] += val;
      if(L & 1) data[L] += val, ++L;
      L >>= 1;
      R >>= 1;
    }

    bottom_up(l + hsize);
    bottom_up(r + hsize);
  }

  T get(int l, int r) const {
    return *get(1, 0, hsize, l, r, 0);
  }

  template <typename U>
  void init_with_vector(std::vector<U> &a){
    for(int i = 0; i < (int)a.size(); ++i){
      data[hsize + i] = a[i];
    }

    for(int i = hsize - 1; i >= 1; --i){
      data[i] = f(data[i << 1 | 0], data[i << 1 | 1]);
    }

    for(int i = size - 1; i > 1; --i){
      data[i] -= data[i >> 1];
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

