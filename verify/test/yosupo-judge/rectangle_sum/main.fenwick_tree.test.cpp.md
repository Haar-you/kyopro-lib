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


# :x: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9102555d140c20ca7196c4db584ea7b6">test/yosupo-judge/rectangle_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Group/sum.cpp.html">Sum group</a>
* :x: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree.cpp.html">Fenwick tree</a>
* :x: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp.html">Fenwick tree (On Fenwick tree)</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#include "Mylib/AlgebraicStructure/Group/sum.cpp"
#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = input_tuple_vector<int64_t, int64_t, int64_t>(N);

  FenwickTree2D<SumGroup<int64_t>> seg;

  for(int i = 0; i < N; ++i){
    seg.add(x[i], y[i]);
  }

  seg.build();

  for(int i = 0; i < N; ++i){
    seg.update({x[i], y[i]}, w[i]);
  }

  for(auto [l, d, r, u] : input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
    auto ans = seg.get({l, d}, {r, u});
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#line 2 "Mylib/AlgebraicStructure/Group/sum.cpp"

/**
 * @title Sum group
 * @docs sum.md
 */
template <typename T>
struct SumGroup {
  using value_type = T;

  value_type operator()() const {return 0;}
  value_type operator()(const value_type &a, const value_type &b) const {return a + b;}
  value_type inv(const value_type &a) const {return -a;}
};
#line 3 "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"

/**
 * @title Fenwick tree
 * @docs fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree {
  using value_type = typename AbelianGroup::value_type;
  const static AbelianGroup G;

  int size;
  std::vector<value_type> data;

public:
  FenwickTree(){}
  FenwickTree(int size):
    size(size), data(size + 1, G())
  {}

  void update(int i, const value_type &val){
    i += 1; // 1-index

    while(i <= size){
      data[i] = G(data[i], val);
      i += i & (-i);
    }
  }

  value_type get(int i) const { // [0, i)
    value_type ret = G();
    i += 1; // 1-index

    while(i > 0){
      ret = G(ret, data[i]);
      i -= i & (-i);
    }

    return ret;
  }

  value_type get(int l, int r) const { // [l, r)
    return G(get(r - 1), G.inv(get(l - 1)));
  }

  value_type operator[](int x) const {
    return get(x, x + 1);
  }
};
#line 3 "Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp"
#include <numeric>
#include <algorithm>
#line 6 "Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp"

/**
 * @title Fenwick tree (On Fenwick tree)
 * @docs fenwick_tree_on_fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree2D {
  using value_type = typename AbelianGroup::value_type;
  const static AbelianGroup G;

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

  void update(std::pair<int, int> p, const value_type &val){
    const auto [x, y] = p;
    int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin();

    for(i += 1; i <= x_size; i += i & (-i)){
      int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
      segs[i].update(j, val);
    }
  }

private:
  value_type get(int i, int64_t y1, int64_t y2) const {
    value_type ret = G();
    for(; i > 0; i -= i & (-i)){
      int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
      int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();
      ret = G(ret, segs[i].get(l, r));
    }
    return ret;
  }

public:
  // [x1, x2), [y1, y2)
  value_type get(std::pair<int64_t, int64_t> p1, std::pair<int64_t, int64_t> p2) const {
    const auto [x1, y1] = p1;
    const auto [x2, y2] = p2;
    int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin();
    int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin();
    return G(get(r, y1, y2), G.inv(get(l, y1, y2)));
  }
};
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
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
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 10 "test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = input_tuple_vector<int64_t, int64_t, int64_t>(N);

  FenwickTree2D<SumGroup<int64_t>> seg;

  for(int i = 0; i < N; ++i){
    seg.add(x[i], y[i]);
  }

  seg.build();

  for(int i = 0; i < N; ++i){
    seg.update({x[i], y[i]}, w[i]);
  }

  for(auto [l, d, r, u] : input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
    auto ans = seg.get({l, d}, {r, u});
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

