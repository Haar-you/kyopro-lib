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


# :warning: Range count query

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f3e3957dafbf526c46359105e1a71d64">Mylib/Algorithm/Query</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Query/range_count_query.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

区間に含まれる要素の種類数を求めるクエリを処理する。

## Requirements

## Notes

## Problems

- [SPOJ DQUERY](https://www.spoj.com/problems/DQUERY/)
- [ABC174 F - Range Set Query](https://atcoder.jp/contests/abc174/tasks/abc174_f)

## References

- [https://hama-du-competitive.hatenablog.com/entry/2016/10/01/001418](https://hama-du-competitive.hatenablog.com/entry/2016/10/01/001418)


## Depends on

* :x: <a href="../../DataStructure/FenwickTree/fenwick_tree_add.cpp.html">Fenwick tree (Add)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <tuple>
#include <algorithm>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"

/**
 * @title Range count query
 * @docs range_count_query.md
 */
template <typename T>
struct RangeCountQuery {
  std::vector<int> a;
  std::vector<std::tuple<int, int, int>> qs;
  int N;

  RangeCountQuery(std::vector<T> a_): N(a_.size()){
    auto temp = a_;
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for(auto x : a_){
      int i = std::lower_bound(temp.begin(), temp.end(), x) - temp.begin();
      a.push_back(i);
    }
  }

  void add(int l, int r){ // [l, r)
    const int i = qs.size();
    qs.emplace_back(r, l, i);
  }

  auto solve(){
    std::sort(qs.begin(), qs.end());

    FenwickTreeAdd<int> b(N);

    const int Q = qs.size();
    std::vector<int> last_index(N, -1);
    std::vector<int> ret(Q);

    int cur = 0;
    for(auto [r, l, i] : qs){
      while(cur < r){
        if(last_index[a[cur]] != -1){
          b.update(last_index[a[cur]], -1);
        }

        last_index[a[cur]] = cur;
        b.update(last_index[a[cur]], 1);

        ++cur;
      }

      ret[i] = b.get(l, r);
    }

    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Query/range_count_query.cpp"
#include <vector>
#include <tuple>
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
#line 6 "Mylib/Algorithm/Query/range_count_query.cpp"

/**
 * @title Range count query
 * @docs range_count_query.md
 */
template <typename T>
struct RangeCountQuery {
  std::vector<int> a;
  std::vector<std::tuple<int, int, int>> qs;
  int N;

  RangeCountQuery(std::vector<T> a_): N(a_.size()){
    auto temp = a_;
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for(auto x : a_){
      int i = std::lower_bound(temp.begin(), temp.end(), x) - temp.begin();
      a.push_back(i);
    }
  }

  void add(int l, int r){ // [l, r)
    const int i = qs.size();
    qs.emplace_back(r, l, i);
  }

  auto solve(){
    std::sort(qs.begin(), qs.end());

    FenwickTreeAdd<int> b(N);

    const int Q = qs.size();
    std::vector<int> last_index(N, -1);
    std::vector<int> ret(Q);

    int cur = 0;
    for(auto [r, l, i] : qs){
      while(cur < r){
        if(last_index[a[cur]] != -1){
          b.update(last_index[a[cur]], -1);
        }

        last_index[a[cur]] = cur;
        b.update(last_index[a[cur]], 1);

        ++cur;
      }

      ret[i] = b.get(l, r);
    }

    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

