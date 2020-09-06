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


# :x: Range inversions query

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f3e3957dafbf526c46359105e1a71d64">Mylib/Algorithm/Query</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Query/range_inversions_query.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Depends on

* :x: <a href="../Mo/mo_algorithm.cpp.html">Mo's algorithm</a>
* :x: <a href="../../DataStructure/FenwickTree/fenwick_tree_add.cpp.html">Fenwick tree (Add)</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/static_range_inversions_query/main.test.cpp.html">test/yosupo-judge/static_range_inversions_query/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"
#include "Mylib/Algorithm/Mo/mo_algorithm.cpp"

/**
 * @title Range inversions query
 * @docs range_inversions_query.md
 */
template <typename T>
class RangeInversionsQuery {
  std::vector<int> a;
  int N;
  std::vector<std::pair<int, int>> qs;

public:
  RangeInversionsQuery(std::vector<T> a_): N(a_.size()){
    auto b = a_;
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    for(auto x : a_){
      const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();
      a.push_back(i);
    }
  }

  void add(int l, int r){ // [l, r)
    qs.emplace_back(l, r);
  }

  auto solve(){
    const int Q = qs.size();
    FenwickTreeAdd<int64_t> b(N);

    int64_t t = 0;
    std::vector<int64_t> ans(Q);

    auto append =
      [&](int i, int d){
        if(d == -1) t += b.get(0, a[i]);
        else t += b.get(a[i] + 1, N);
        b.update(a[i], 1);
      };

    auto remove =
      [&](int i, int d){
        if(d == -1) t -= b.get(0, a[i]);
        else t -= b.get(a[i] + 1, N);
        b.update(a[i], -1);
      };

    auto query = [&](int i){ans[i] = t;};

    auto mo = make_mo(N, Q, append, remove, query);

    for(auto [l, r] : qs){
      mo.add(l, r);
    }

    mo.build();
    mo.run();

    return ans;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Query/range_inversions_query.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#line 3 "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"

/**
 * @title Fenwick tree (Add)
 * @docs fenwick_tree_add.md
 */
template <typename T>
class FenwickTreeAdd {
  using value_type = T;

  int size;
  std::vector<value_type> data;

public:
  FenwickTreeAdd(){}
  FenwickTreeAdd(int size): size(size), data(size + 1, 0){}

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
#line 4 "Mylib/Algorithm/Mo/mo_algorithm.cpp"
#include <cassert>
#include <cmath>

/**
 * @title Mo's algorithm
 * @docs mo_algorithm.md
 */
template <typename F, typename G, typename H>
class MoAlgorithm {
  int N, Q, index, width;
  std::vector<int> left, right, ord;

  const F append;
  const G remove;
  const H query;

  bool is_built = false;

public:
  MoAlgorithm(int N, int Q, const F &append, const G &remove, const H &query):
    N(N), Q(Q), index(0), width(sqrt(N)),
    left(Q), right(Q), ord(Q),
    append(append), remove(remove), query(query)
  {}

  // [l, r)
  void add(int l, int r){
    left[index] = l;
    right[index] = r;
    ord[index] = index;
    ++index;
  }

  void build(){
    std::sort(
      ord.begin(),
      ord.end(),
      [&](int i, int j){
        const int a = left[i] / width, b = left[j] / width;
        if(a == b){
          if(a & 1){
            return right[i] < right[j];
          }else{
            return right[i] > right[j];
          }
        }else{
          return a < b;
        }
      }
    );

    is_built = true;
  }

  void run(){
    assert(is_built);

    int q = 0;
    int l = left[ord[0]], r = left[ord[0]];

    for(int i = 0; i < Q; ++i){
      int id = ord[q++];

      while(l != left[id] or r != right[id]){
        if(l > left[id]) append(--l, -1);
        if(l < left[id]) remove(l++, -1);
        if(r < right[id]) append(r++, 1);
        if(r > right[id]) remove(--r, 1);
      }

      query(id);
    }
  }
};

template <typename F, typename G, typename H>
auto make_mo(int N, int Q, F append, G remove, H query){
  return MoAlgorithm<F, G, H>(N, Q, append, remove, query);
}
#line 7 "Mylib/Algorithm/Query/range_inversions_query.cpp"

/**
 * @title Range inversions query
 * @docs range_inversions_query.md
 */
template <typename T>
class RangeInversionsQuery {
  std::vector<int> a;
  int N;
  std::vector<std::pair<int, int>> qs;

public:
  RangeInversionsQuery(std::vector<T> a_): N(a_.size()){
    auto b = a_;
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    for(auto x : a_){
      const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();
      a.push_back(i);
    }
  }

  void add(int l, int r){ // [l, r)
    qs.emplace_back(l, r);
  }

  auto solve(){
    const int Q = qs.size();
    FenwickTreeAdd<int64_t> b(N);

    int64_t t = 0;
    std::vector<int64_t> ans(Q);

    auto append =
      [&](int i, int d){
        if(d == -1) t += b.get(0, a[i]);
        else t += b.get(a[i] + 1, N);
        b.update(a[i], 1);
      };

    auto remove =
      [&](int i, int d){
        if(d == -1) t -= b.get(0, a[i]);
        else t -= b.get(a[i] + 1, N);
        b.update(a[i], -1);
      };

    auto query = [&](int i){ans[i] = t;};

    auto mo = make_mo(N, Q, append, remove, query);

    for(auto [l, r] : qs){
      mo.add(l, r);
    }

    mo.build();
    mo.run();

    return ans;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

