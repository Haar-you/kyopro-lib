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


# :heavy_check_mark: Mo's algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1534504632931a6652ca965283803a2e">Mylib/Algorithm/Mo</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Mo/mo_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-03 23:59:26+09:00




## Operations

- `MoAlgorithm`
- `add(int l, int r)`
	- クエリ`[l, r)`を追加する。
- `build()`
- `run()`
- `make_mo`

## Requirements

- `append(int i, int d)`
	- `i`番目の要素を追加する操作。
    - `d = -1`で左端に追加、`d = 1`で右端に追加。
- `remove(int i, int d)`
	- `i`番目の要素を削除する操作。
    - `d = -1`で左端を削除、`d = 1`で右端を削除。
- `query(int i)`
	- `i`番目のクエリを処理する操作。
- 必ず`add`, `build`, `run`の順で実行する。

## Problems

- [Yandex.Algorithm 2011: Round 2 D. Powerful array](https://codeforces.com/contest/86/problem/D) (出現数)
- [SPOJ DQUERY](https://www.spoj.com/problems/DQUERY/) (種類数)
- [第3回 ドワンゴからの挑戦状 本選 B - ニワンゴくんの約数](https://atcoder.jp/contests/dwacon2017-honsen/tasks/dwango2017final_b) (積の約数の個数)
- [Codeforces Round #221 (Div. 1) D. Tree and Queries](https://codeforces.com/contest/375/problem/D) (部分木 / 出現数k以上の種類数)
- [Unique Art](https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem) (出現数1の種類数)

## References

- [https://ei1333.hateblo.jp/entry/2017/09/11/211011](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
- [https://snuke.hatenablog.com/entry/2016/07/01/000000](https://snuke.hatenablog.com/entry/2016/07/01/000000)
- [https://www.hamayanhamayan.com/entry/2017/04/18/012937](https://www.hamayanhamayan.com/entry/2017/04/18/012937)


## Required by

* :heavy_check_mark: <a href="../Query/range_inversions_query.cpp.html">Range inversions query</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/static_range_inversions_query/main.test.cpp.html">test/yosupo-judge/static_range_inversions_query/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

/**
 * @title Mo's algorithm
 * @docs mo_algorithm.md
 */
template <typename F, typename G, typename H>
class MoAlgorithm{
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Mo/mo_algorithm.cpp"
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

/**
 * @title Mo's algorithm
 * @docs mo_algorithm.md
 */
template <typename F, typename G, typename H>
class MoAlgorithm{
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

