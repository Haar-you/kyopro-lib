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


# :question: Weighted maximum bipartite matching

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#65eb1c5db2b1bd726d58cf661f149e7c">Mylib/Graph/Matching</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Matching/weighted_bipartite_matching.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [AOJ 2581 Derangement](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2581)
- [AOJ 2429 marukaite](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429)

## References


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2293/main.test.cpp.html">test/aoj/2293/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/assignment/main.test.cpp.html">test/yosupo-judge/assignment/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <tuple>

/**
 * @title Weighted maximum bipartite matching
 * @docs weighted_bipartite_matching.md
 */
template <typename T, typename MinCostFlow, bool MIN_MATCHING = false>
class WeightedBipartiteMatching{
public:
  int L, R, s, t;
  MinCostFlow f;
  
  WeightedBipartiteMatching(int L, int R, bool arbitrary_flow = false):
    L(L), R(R), s(L+R), t(s+1), f(L+R+2)
  {
    for(int i = 0; i < L; ++i) f.add_edge(s, i, 1, 0);
    for(int i = 0; i < R; ++i) f.add_edge(L+i, t, 1, 0);
    if(arbitrary_flow) f.add_edge(s, t, std::numeric_limits<int>::max(), 0);
  }
  
  void add_edge(int from, int to, T gain){
    f.add_edge(from, L + to, 1, gain * (MIN_MATCHING ? 1 : -1));
  }
  
  T solve(int flow){
    T ret;
    f.solve(s, t, flow, ret);
    return ret * (MIN_MATCHING ? 1 : -1);
  }
  
  auto get_matching(){
    auto g = f.get_graph();
    std::vector<std::tuple<int,int,T>> ret;
    
    for(int i = 0; i < L; ++i){
      for(auto &e : g[i]){
        if(not e.is_rev and e.to != t and e.cap == 0){
          ret.emplace_back(i, e.to - L, e.cost * (MIN_MATCHING ? 1 : -1));
        }
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
#line 2 "Mylib/Graph/Matching/weighted_bipartite_matching.cpp"
#include <vector>
#include <tuple>

/**
 * @title Weighted maximum bipartite matching
 * @docs weighted_bipartite_matching.md
 */
template <typename T, typename MinCostFlow, bool MIN_MATCHING = false>
class WeightedBipartiteMatching{
public:
  int L, R, s, t;
  MinCostFlow f;
  
  WeightedBipartiteMatching(int L, int R, bool arbitrary_flow = false):
    L(L), R(R), s(L+R), t(s+1), f(L+R+2)
  {
    for(int i = 0; i < L; ++i) f.add_edge(s, i, 1, 0);
    for(int i = 0; i < R; ++i) f.add_edge(L+i, t, 1, 0);
    if(arbitrary_flow) f.add_edge(s, t, std::numeric_limits<int>::max(), 0);
  }
  
  void add_edge(int from, int to, T gain){
    f.add_edge(from, L + to, 1, gain * (MIN_MATCHING ? 1 : -1));
  }
  
  T solve(int flow){
    T ret;
    f.solve(s, t, flow, ret);
    return ret * (MIN_MATCHING ? 1 : -1);
  }
  
  auto get_matching(){
    auto g = f.get_graph();
    std::vector<std::tuple<int,int,T>> ret;
    
    for(int i = 0; i < L; ++i){
      for(auto &e : g[i]){
        if(not e.is_rev and e.to != t and e.cap == 0){
          ret.emplace_back(i, e.to - L, e.cost * (MIN_MATCHING ? 1 : -1));
        }
      }
    }
    
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

