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


# :warning: Unionfindによる二部グラフ判定

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3b87eee7aef75da88610c966a8da844f">Mylib/Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 00:04:32+09:00




## Operations

## Requirements

## Notes

## Problems

- [CODE FESTIVAL 2017 qual B C - 3 Steps](https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c)
- [ARC 036 D - 偶数メートル](https://atcoder.jp/contests/arc036/tasks/arc036_d)

## References



## Depends on

* :heavy_check_mark: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">UnionFind</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Unionfindによる二部グラフ判定
 * @docs construct_bipartite_graph.md
 */
class BipartiteGraph{
  int n;
  UnionFind check;

public:
  BipartiteGraph(int n): n(n), check(2*n){}

  void add_diff(int i, int j){ // iとjを異なる色で塗る。
    check.merge(i,j+n);
    check.merge(i+n,j);
  }

  void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
    check.merge(i,j);
    check.merge(i+n,j+n);
  }

  bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
    return !check.is_same(i,i+n);
  }

  bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
    return check.is_same(i,j);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <vector>
#include <numeric>

/**
 * @title UnionFind
 * @docs unionfind.md
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  inline int get_root(int i){
    if(parent[i] == i) return i;
    else return parent[i] = get_root(parent[i]);
  }
  
  inline bool is_same(int i, int j){return get_root(i) == get_root(j);}

  inline int merge(int i, int j){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  inline int get_size(int i){return size[get_root(i)];}

  inline int count_group(){return count;}
};
#line 3 "Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp"

/**
 * @title Unionfindによる二部グラフ判定
 * @docs construct_bipartite_graph.md
 */
class BipartiteGraph{
  int n;
  UnionFind check;

public:
  BipartiteGraph(int n): n(n), check(2*n){}

  void add_diff(int i, int j){ // iとjを異なる色で塗る。
    check.merge(i,j+n);
    check.merge(i+n,j);
  }

  void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
    check.merge(i,j);
    check.merge(i+n,j+n);
  }

  bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
    return !check.is_same(i,i+n);
  }

  bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
    return check.is_same(i,j);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

