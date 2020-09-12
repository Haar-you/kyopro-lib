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


# :x: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f20910bc88ed07cbe415ab1d4fdcbec4">test/yosupo-judge/point_add_rectangle_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/point_add_rectangle_sum/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_rectangle_sum">https://judge.yosupo.jp/problem/point_add_rectangle_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Sum monoid</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp.html">Segment tree (On segment tree)</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <variant>
#include <tuple>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

using Query = std::variant<std::tuple<int, int, int>, std::tuple<int, int, int, int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::segment_tree_on_segment_tree<hl::sum_monoid<int64_t>> seg;

  auto [x, y, w] = hl::input_tuple_vector<int, int, int>(N);
  for(int i = 0; i < N; ++i){
    seg.add(x[i], y[i]);
  }

  std::vector<Query> queries(Q);
  for(int i = 0; i < Q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x, y, w; std::cin >> x >> y >> w;
      queries[i] = std::make_tuple(x, y, w);
      seg.add(x, y);
    }else{
      int l, d, r, u; std::cin >> l >> d >> r >> u;
      queries[i] = std::make_tuple(l, d, r, u);
    }
  }

  seg.build();

  for(int i = 0; i < N; ++i){
    seg.update({x[i], y[i]}, w[i]);
  }

  for(auto q : queries){
    if(q.index() == 0){
      auto [x, y, w] = std::get<0>(q);
      seg.update({x, y}, w);
    }else{
      auto [l, d, r, u] = std::get<1>(q);
      std::cout << seg.get({l, d}, {r, u}) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/point_add_rectangle_sum/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <variant>
#include <tuple>
#include <vector>
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"
#include <algorithm>
#line 4 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <functional>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    int depth, size, hsize;
    std::vector<value_type> data;

  public:
    segment_tree(){}
    segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, M())
    {}

    auto operator[](int i) const {return data[hsize + i];}

    auto get(int x, int y) const {
      value_type ret_left = M();
      value_type ret_right = M();

      int l = x + hsize, r = y + hsize;
      while(l < r){
        if(r & 1) ret_right = M(data[--r], ret_right);
        if(l & 1) ret_left = M(ret_left, data[l++]);
        l >>= 1, r >>= 1;
      }

      return M(ret_left, ret_right);
    }

    void update(int i, const value_type &x){
      i += hsize;
      data[i] = x;
      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize, val));
    }

  private:
    template <bool Lower, typename F>
    int bound(const int l, const int r, value_type x, F f) const {
      std::vector<int> pl, pr;
      int L = l + hsize;
      int R = r + hsize;
      while(L < R){
        if(R & 1) pr.push_back(--R);
        if(L & 1) pl.push_back(L++);
        L >>= 1, R >>= 1;
      }

      std::reverse(pr.begin(), pr.end());
      pl.insert(pl.end(), pr.begin(), pr.end());

      value_type a = M();

      for(int i : pl){
        auto b = M(a, data[i]);

        if((Lower and not f(b, x)) or (not Lower and f(x, b))){
          while(i < hsize){
            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not Lower and f(x, c))){
              i = i << 1 | 0;
            }else{
              a = c;
              i = i << 1 | 1;
            }
          }

          return i - hsize;
        }

        a = b;
      }

      return r;
    }

  public:
    template <typename F = std::less<value_type>>
    int lower_bound(int l, int r, value_type x, F f = F()) const {
      return bound<true>(l, r, x, f);
    }

    template <typename F = std::less<value_type>>
    int upper_bound(int l, int r, value_type x, F f = F()) const {
      return bound<false>(l, r, x, f);
    }
  };
}
#line 5 "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"

/**
 * @title Segment tree (On segment tree)
 * @docs segment_tree_on_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class segment_tree_on_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    int N = 0;
    std::vector<int64_t> xs, ys;
    std::vector<int> c_xs;

    std::vector<std::vector<int>> c_ys;

    int x_size;

    std::vector<segment_tree<Monoid>> segs;

  public:
    segment_tree_on_segment_tree(){}

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
        segs[i] = segment_tree<Monoid>(c_ys[i].size());
      }
    }

    void update(std::pair<int64_t, int64_t> p, const value_type &val){
      const auto [x, y] = p;
      int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin() + x_size / 2;

      while(i >= 1){
        int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
        segs[i].update(j, M(segs[i][j], val));

        i >>= 1;
      }
    }

  private:
    value_type get_sub(int i, int64_t y1, int64_t y2) const {
      int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
      int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();

      return segs[i].get(l, r);
    }

  public:
    // [x1, x2), [y1, y2)
    value_type get(std::pair<int64_t, int64_t> p1, std::pair<int64_t, int64_t> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin() + x_size / 2;
      int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin() + x_size / 2;

      value_type ret = M();

      while(l < r){
        if(r & 1) ret = M(ret, get_sub(--r, y1, y2));
        if(l & 1) ret = M(ret, get_sub(l++, y1, y2));
        l >>= 1;
        r >>= 1;
      }

      return ret;
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @title Sum monoid
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_monoid {
    using value_type = T;
    value_type operator()() const {return 0;}
    value_type operator()(value_type a, value_type b) const {return a + b;}
  };
}
#line 5 "Mylib/IO/input_tuple_vector.cpp"
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  void input_tuple_vector_init(T &val, int N, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0) ...};
  }

  template <typename T, size_t ... I>
  void input_tuple_vector_helper(T &val, int i, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0) ...};
  }

  template <typename ... Args>
  auto input_tuple_vector(int N){
    std::tuple<std::vector<Args> ...> ret;

    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());
    for(int i = 0; i < N; ++i){
      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}
#line 10 "test/yosupo-judge/point_add_rectangle_sum/main.test.cpp"

namespace hl = haar_lib;

using Query = std::variant<std::tuple<int, int, int>, std::tuple<int, int, int, int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::segment_tree_on_segment_tree<hl::sum_monoid<int64_t>> seg;

  auto [x, y, w] = hl::input_tuple_vector<int, int, int>(N);
  for(int i = 0; i < N; ++i){
    seg.add(x[i], y[i]);
  }

  std::vector<Query> queries(Q);
  for(int i = 0; i < Q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x, y, w; std::cin >> x >> y >> w;
      queries[i] = std::make_tuple(x, y, w);
      seg.add(x, y);
    }else{
      int l, d, r, u; std::cin >> l >> d >> r >> u;
      queries[i] = std::make_tuple(l, d, r, u);
    }
  }

  seg.build();

  for(int i = 0; i < N; ++i){
    seg.update({x[i], y[i]}, w[i]);
  }

  for(auto q : queries){
    if(q.index() == 0){
      auto [x, y, w] = std::get<0>(q);
      seg.update({x, y}, w);
    }else{
      auto [l, d, r, u] = std::get<1>(q);
      std::cout << seg.get({l, d}, {r, u}) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

