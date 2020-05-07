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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :heavy_check_mark: LiChaoTree

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#7e10cb4eef4fe46e217959a10aea6a72">Mylib/DynamicProgramming/SpeedupTechnique/ConvexHullTrick</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/SpeedupTechnique/ConvexHullTrick/lichao_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 16:28:32+09:00




## Operations

- `LiChaoSegmentTree(xs)`
- `add_line(T a, T b)`
	- 直線`f(x) = a*x + b`を追加する。
	- Time complexity $O(\log N)$
- `add_segment(T l, T r, T a, T b)`
	- 線分`x in [l, r), f(x) = a*x + b`を追加する。
	- Time complexity $O(\log^2 N)$
- `query(T x)`
	- `Comparator = std::greater<T>`の場合は、`x`での最大値
	- `Comparator = std::less<T>`の場合は、`x`での最小値
	- Time complexity $O(\log N)$

## Problems

- [Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)
- [Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)

## References

- [https://smijake3.hatenablog.com/entry/2018/06/16/144548](https://smijake3.hatenablog.com/entry/2018/06/16/144548)


## Verified with

* :heavy_check_mark: <a href="../../../../../verify/test/yosupo-judge/line_add_get_min/main.test.cpp.html">test/yosupo-judge/line_add_get_min/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../../verify/test/yosupo-judge/segment_add_get_min/main.test.cpp.html">test/yosupo-judge/segment_add_get_min/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include <vector>
#include <algorithm>
#include <optional>

/**
 * @title LiChaoTree
 * @docs lichao_tree.md
 */
template <typename T, typename Comparator>
class LiChaoSegmentTree{
  using line = std::pair<T,T>;

  const Comparator cmp = Comparator();
  std::vector<T> xs;
  int n;

  std::vector<std::optional<line>> data;
  std::vector<std::pair<int,int>> range;

  inline T chm(const T &a, const T &b) const {
    return cmp(a, b) ? a : b;
  }

  void init_range(int i, int left, int right){
    if(i >= 2*n) return;

    range[i] = std::make_pair(left, right);
    int mid = (left + right) / 2;
    init_range(i << 1 | 0, left, mid);
    init_range(i << 1 | 1, mid, right);
  }

public:
  LiChaoSegmentTree(std::vector<T> xs_): xs(xs_){
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    n = 1;
    while(n < (int)xs.size()) n *= 2;

    const auto m = xs.back();
    xs.resize(n, m);

    data.assign(2*n, std::nullopt);

    range.resize(2*n);
    init_range(1, 0, n);
  }

  inline T apply(const line &l, const T &x) const {
    return l.first * x + l.second;
  }

private:
  void update(int i, line new_line, int l, int r){
    if(not data[i]){
      data[i] = new_line;
      return;
    }

    int m = (l + r) / 2;

    auto lx = xs[l], mx = xs[m], rx = xs[r-1];

    bool left = cmp(apply(new_line, lx), apply(*data[i], lx));
    bool mid = cmp(apply(new_line, mx), apply(*data[i], mx));
    bool right = cmp(apply(new_line, rx), apply(*data[i], rx));

    if(left and right){
      data[i] = new_line;
      return;
    }

    if(not left and not right){
      return;
    }

    if(mid){
      std::swap(*data[i], new_line);
    }

    if(left != mid){
      update(i << 1 | 0, new_line, l, m);
    }else{
      update(i << 1 | 1, new_line, m, r);
    }
  }
  
public:
  inline void add_line(T a, T b){
    update(1, std::make_pair(a, b), 0, n);
  }

  // [l, r)
  inline void add_segment(T l, T r, T a, T b){
    int left = std::lower_bound(xs.begin(), xs.end(), l) - xs.begin();
    int right = std::lower_bound(xs.begin(), xs.end(), r) - xs.begin();

    int L = left + n;
    int R = right + n;

    while(L < R){
      if(R & 1){
        --R;
        update(R, std::make_pair(a, b), range[R].first, range[R].second);
      }

      if(L & 1){
        update(L, std::make_pair(a, b), range[L].first, range[L].second);
        ++L;
      }

      L >>= 1;
      R >>= 1;
    }
  }

public:
  inline auto query(const T &x) const {
    const int i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    int k = i + n;
    
    std::optional<T> ret;

    while(k > 0){
      if(data[k]){
        if(not ret) ret = apply(*data[k], xs[i]);
        else ret = chm(*ret, apply(*data[k], xs[i]));
      }
      k >>= 1;
    }

    return ret;
  }
};

template <typename T>
auto make_lichao_min(const std::vector<T> &xs){
  return LiChaoSegmentTree<T, std::less<T>>(xs);
}

template <typename T>
auto make_lichao_max(const std::vector<T> &xs){
  return LiChaoSegmentTree<T, std::greater<T>>(xs);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/SpeedupTechnique/ConvexHullTrick/lichao_tree.cpp"
#include <utility>
#include <vector>
#include <algorithm>
#include <optional>

/**
 * @title LiChaoTree
 * @docs lichao_tree.md
 */
template <typename T, typename Comparator>
class LiChaoSegmentTree{
  using line = std::pair<T,T>;

  const Comparator cmp = Comparator();
  std::vector<T> xs;
  int n;

  std::vector<std::optional<line>> data;
  std::vector<std::pair<int,int>> range;

  inline T chm(const T &a, const T &b) const {
    return cmp(a, b) ? a : b;
  }

  void init_range(int i, int left, int right){
    if(i >= 2*n) return;

    range[i] = std::make_pair(left, right);
    int mid = (left + right) / 2;
    init_range(i << 1 | 0, left, mid);
    init_range(i << 1 | 1, mid, right);
  }

public:
  LiChaoSegmentTree(std::vector<T> xs_): xs(xs_){
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    n = 1;
    while(n < (int)xs.size()) n *= 2;

    const auto m = xs.back();
    xs.resize(n, m);

    data.assign(2*n, std::nullopt);

    range.resize(2*n);
    init_range(1, 0, n);
  }

  inline T apply(const line &l, const T &x) const {
    return l.first * x + l.second;
  }

private:
  void update(int i, line new_line, int l, int r){
    if(not data[i]){
      data[i] = new_line;
      return;
    }

    int m = (l + r) / 2;

    auto lx = xs[l], mx = xs[m], rx = xs[r-1];

    bool left = cmp(apply(new_line, lx), apply(*data[i], lx));
    bool mid = cmp(apply(new_line, mx), apply(*data[i], mx));
    bool right = cmp(apply(new_line, rx), apply(*data[i], rx));

    if(left and right){
      data[i] = new_line;
      return;
    }

    if(not left and not right){
      return;
    }

    if(mid){
      std::swap(*data[i], new_line);
    }

    if(left != mid){
      update(i << 1 | 0, new_line, l, m);
    }else{
      update(i << 1 | 1, new_line, m, r);
    }
  }
  
public:
  inline void add_line(T a, T b){
    update(1, std::make_pair(a, b), 0, n);
  }

  // [l, r)
  inline void add_segment(T l, T r, T a, T b){
    int left = std::lower_bound(xs.begin(), xs.end(), l) - xs.begin();
    int right = std::lower_bound(xs.begin(), xs.end(), r) - xs.begin();

    int L = left + n;
    int R = right + n;

    while(L < R){
      if(R & 1){
        --R;
        update(R, std::make_pair(a, b), range[R].first, range[R].second);
      }

      if(L & 1){
        update(L, std::make_pair(a, b), range[L].first, range[L].second);
        ++L;
      }

      L >>= 1;
      R >>= 1;
    }
  }

public:
  inline auto query(const T &x) const {
    const int i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    int k = i + n;
    
    std::optional<T> ret;

    while(k > 0){
      if(data[k]){
        if(not ret) ret = apply(*data[k], xs[i]);
        else ret = chm(*ret, apply(*data[k], xs[i]));
      }
      k >>= 1;
    }

    return ret;
  }
};

template <typename T>
auto make_lichao_min(const std::vector<T> &xs){
  return LiChaoSegmentTree<T, std::less<T>>(xs);
}

template <typename T>
auto make_lichao_max(const std::vector<T> &xs){
  return LiChaoSegmentTree<T, std::greater<T>>(xs);
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>
