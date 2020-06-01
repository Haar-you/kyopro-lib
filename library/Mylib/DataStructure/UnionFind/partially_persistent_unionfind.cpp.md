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


# :warning: Partially persistent union-find

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ff74e8366c88d06b530f361450b1117">Mylib/DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `PartiallyPersistentUnionFind(N)`
- `get_root(int i, int t)`
	- 時刻`t`での`i`の属する連結成分のrootを返す。
- `is_same(int u, int v, int t)`
	- 時刻`t`での`u`と`v`が同じ連結成分に属するかを判定する。
- `size(int u, int t)`
	- 時刻`t`での`u`が属する連結成分の大きさを返す。
- `merge(int u, int v)`
	- 最新の状態で`u`と`v`を連結する。

## Problems

- [CODE THANKS FESTIVAL 2017 H - Union Sets](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h)
- [AGC 002 D - Stamp Rally](https://atcoder.jp/contests/agc002/tasks/agc002_d)

## References

- [https://camypaper.bitbucket.io/2016/12/18/adc2016/](https://camypaper.bitbucket.io/2016/12/18/adc2016/)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>

/**
 * @title Partially persistent union-find
 * @docs partially_persistent_unionfind.md
 */
class PartiallyPersistentUnionFind{
  int N;
  std::vector<std::vector<std::pair<int,int>>> P;
  std::vector<int> par;
  int T = 0;
  std::vector<int> rank;

public:
  PartiallyPersistentUnionFind(int N): N(N), P(N), par(N), rank(N,1){
    for(int i = 0; i < N; ++i) P[i].push_back({0,1});
    std::iota(par.begin(), par.end(), 0);
  }
  
  int get_root(int i, int t){
    if(par[i] == i) return i;

    if(P[i].back().first == 0 || t < P[i].back().first) return i;
    else if(t == P[i].back().first) return P[i].back().second;
    else return get_root(par[i],t);
  }

  bool is_same(int u, int v, int t){
    return get_root(u,t) == get_root(v,t);
  }

  int size(int u, int t){
    u = get_root(u,t);
    auto it = std::prev(std::lower_bound(P[u].begin(), P[u].end(), std::make_pair(t+1,0)));
    return it->second;
  }

  void merge(int u, int v){
    u = get_root(u,T);
    v = get_root(v,T);
    ++T;

    if(u == v) return;

    int s = size(u,T-1) + size(v,T-1);
    
    if(rank[u] < rank[v]){
      par[u] = par[v] = v;
      P[u].push_back({T,v});
      P[v].push_back({T,s});
    }else{
      par[u] = par[v] = u;
      P[v].push_back({T,u});
      P[u].push_back({T,s});
      if(rank[u] == rank[v]) ++rank[u];
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>

/**
 * @title Partially persistent union-find
 * @docs partially_persistent_unionfind.md
 */
class PartiallyPersistentUnionFind{
  int N;
  std::vector<std::vector<std::pair<int,int>>> P;
  std::vector<int> par;
  int T = 0;
  std::vector<int> rank;

public:
  PartiallyPersistentUnionFind(int N): N(N), P(N), par(N), rank(N,1){
    for(int i = 0; i < N; ++i) P[i].push_back({0,1});
    std::iota(par.begin(), par.end(), 0);
  }
  
  int get_root(int i, int t){
    if(par[i] == i) return i;

    if(P[i].back().first == 0 || t < P[i].back().first) return i;
    else if(t == P[i].back().first) return P[i].back().second;
    else return get_root(par[i],t);
  }

  bool is_same(int u, int v, int t){
    return get_root(u,t) == get_root(v,t);
  }

  int size(int u, int t){
    u = get_root(u,t);
    auto it = std::prev(std::lower_bound(P[u].begin(), P[u].end(), std::make_pair(t+1,0)));
    return it->second;
  }

  void merge(int u, int v){
    u = get_root(u,T);
    v = get_root(v,T);
    ++T;

    if(u == v) return;

    int s = size(u,T-1) + size(v,T-1);
    
    if(rank[u] < rank[v]){
      par[u] = par[v] = v;
      P[u].push_back({T,v});
      P[v].push_back({T,s});
    }else{
      par[u] = par[v] = u;
      P[v].push_back({T,u});
      P[u].push_back({T,s});
      if(rank[u] == rank[v]) ++rank[u];
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

