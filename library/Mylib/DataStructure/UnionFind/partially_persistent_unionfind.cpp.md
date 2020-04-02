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


# :warning: 部分永続Unionfind

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ff74e8366c88d06b530f361450b1117">Mylib/DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/7720761">https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/7720761</a>
* see: <a href="https://atcoder.jp/contests/agc002/submissions/7720745">https://atcoder.jp/contests/agc002/submissions/7720745</a>


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
 * @title 部分永続Unionfind
 * @see https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/7720761
 * @see https://atcoder.jp/contests/agc002/submissions/7720745
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

    if(u==v) return;

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
 * @title 部分永続Unionfind
 * @see https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/7720761
 * @see https://atcoder.jp/contests/agc002/submissions/7720745
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

    if(u==v) return;

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

