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


# :heavy_check_mark: 最大二部マッチング

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#65eb1c5db2b1bd726d58cf661f149e7c">Mylib/Graph/Matching</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Matching/bipartite_matching.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 04:30:02+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_7_A/main.test.cpp.html">test/aoj/GRL_7_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <climits>
#include <cassert>

/**
 * @title 最大二部マッチング
 * @docs bipartite_matching.md
 */
template <typename MaxFlow>
class BipartiteMatching{
  int L, R;
  int s, t;
  MaxFlow f;
  
public:
  BipartiteMatching(int L, int R): L(L), R(R), s(L+R), t(s+1), f(L+R+2){
    for(int i = 0; i < L; ++i) f.add_edge(s, i, 1);
    for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1);
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L and 0 <= j and j < R);
    f.add_edge(i, L + j, 1);
  }

  int solve(){
    return f.solve(s, t);
  }

  auto get_matching(){
    auto g = f.get_graph();
    std::vector<std::pair<int,int>> ret;

    for(int i = 0; i < (int)g.size()-2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to - L);
      }
    }

    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Matching/bipartite_matching.cpp"
#include <vector>
#include <utility>
#include <climits>
#include <cassert>

/**
 * @title 最大二部マッチング
 * @docs bipartite_matching.md
 */
template <typename MaxFlow>
class BipartiteMatching{
  int L, R;
  int s, t;
  MaxFlow f;
  
public:
  BipartiteMatching(int L, int R): L(L), R(R), s(L+R), t(s+1), f(L+R+2){
    for(int i = 0; i < L; ++i) f.add_edge(s, i, 1);
    for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1);
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L and 0 <= j and j < R);
    f.add_edge(i, L + j, 1);
  }

  int solve(){
    return f.solve(s, t);
  }

  auto get_matching(){
    auto g = f.get_graph();
    std::vector<std::pair<int,int>> ret;

    for(int i = 0; i < (int)g.size()-2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to - L);
      }
    }

    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

