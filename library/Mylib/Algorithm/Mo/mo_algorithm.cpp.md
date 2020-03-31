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


# :warning: Mylib/Algorithm/Mo/mo_algorithm.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1534504632931a6652ca965283803a2e">Mylib/Algorithm/Mo</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Mo/mo_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 11:59:58+09:00


* see: <a href="https://codeforces.com/contest/86/submission/62912624 (出現数)">https://codeforces.com/contest/86/submission/62912624 (出現数)</a>
* see: <a href="https://www.spoj.com/problems/DQUERY/ (種類数)">https://www.spoj.com/problems/DQUERY/ (種類数)</a>
* see: <a href="https://atcoder.jp/contests/dwacon2017-honsen/submissions/8017651 (積の約数の個数)">https://atcoder.jp/contests/dwacon2017-honsen/submissions/8017651 (積の約数の個数)</a>
* see: <a href="https://codeforces.com/contest/375/submission/73875627 (部分木 / 出現数k以上の種類数)">https://codeforces.com/contest/375/submission/73875627 (部分木 / 出現数k以上の種類数)</a>
* see: <a href="https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem (出現数1の種類数)">https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem (出現数1の種類数)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * @see https://codeforces.com/contest/86/submission/62912624 (出現数)
 * @see https://www.spoj.com/problems/DQUERY/ (種類数)
 * @see https://atcoder.jp/contests/dwacon2017-honsen/submissions/8017651 (積の約数の個数)
 * @see https://codeforces.com/contest/375/submission/73875627 (部分木 / 出現数k以上の種類数)
 * @see https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem (出現数1の種類数)
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
    N(N), Q(Q), index(0), width(sqrt(N)), left(Q), right(Q), ord(Q), append(append), remove(remove), query(query){
  }

  // [l, r)
  inline void add(int l, int r){
    left[index] = l;
    right[index] = r;
    ord[index] = index;
    ++index;
  }

  inline void build(){
    std::sort(ord.begin(), ord.end(),
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
              });

    is_built = true;
  }

  /**
   * @attention time complexity O(N√Q)
   */
  inline void process(){
    assert(is_built);
    
    int q = 0;
    int l = left[ord[0]], r = left[ord[0]];
    
    for(int i = 0; i < Q; ++i){
      int id = ord[q++];

      while(l != left[id] or r != right[id]){
        if(l > left[id]) append(--l);
        if(l < left[id]) remove(l++);
        if(r < right[id]) append(r++);
        if(r > right[id]) remove(--r);
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

/**
 * @see https://codeforces.com/contest/86/submission/62912624 (出現数)
 * @see https://www.spoj.com/problems/DQUERY/ (種類数)
 * @see https://atcoder.jp/contests/dwacon2017-honsen/submissions/8017651 (積の約数の個数)
 * @see https://codeforces.com/contest/375/submission/73875627 (部分木 / 出現数k以上の種類数)
 * @see https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem (出現数1の種類数)
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
    N(N), Q(Q), index(0), width(sqrt(N)), left(Q), right(Q), ord(Q), append(append), remove(remove), query(query){
  }

  // [l, r)
  inline void add(int l, int r){
    left[index] = l;
    right[index] = r;
    ord[index] = index;
    ++index;
  }

  inline void build(){
    std::sort(ord.begin(), ord.end(),
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
              });

    is_built = true;
  }

  /**
   * @attention time complexity O(N√Q)
   */
  inline void process(){
    assert(is_built);
    
    int q = 0;
    int l = left[ord[0]], r = left[ord[0]];
    
    for(int i = 0; i < Q; ++i){
      int id = ord[q++];

      while(l != left[id] or r != right[id]){
        if(l > left[id]) append(--l);
        if(l < left[id]) remove(l++);
        if(r < right[id]) append(r++);
        if(r > right[id]) remove(--r);
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

