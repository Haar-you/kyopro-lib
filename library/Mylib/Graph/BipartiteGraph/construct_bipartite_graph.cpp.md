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


# :warning: Check bipartite graph (Using union-find)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3b87eee7aef75da88610c966a8da844f">Mylib/Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [CODE FESTIVAL 2017 qual B C - 3 Steps](https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c)
- [ARC 036 D - 偶数メートル](https://atcoder.jp/contests/arc036/tasks/arc036_d)

## References



## Depends on

* :question: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Check bipartite graph (Using union-find)
 * @docs construct_bipartite_graph.md
 */
namespace haar_lib {
  class bipartite_graph {
    int n;
    unionfind check;

  public:
    bipartite_graph(int n): n(n), check(2 * n){}

    void add_diff(int i, int j){ // iとjを異なる色で塗る。
      check.merge(i, j + n);
      check.merge(i + n, j);
    }

    void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
      check.merge(i, j);
      check.merge(i + n, j + n);
    }

    bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
      return not check.is_same(i, i + n);
    }

    bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
      return check.is_same(i, j);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * @title Union-find
 * @docs unionfind.md
 */
namespace haar_lib {
  class unionfind {
    int n;
    mutable std::vector<int> parent;
    std::vector<int> depth, size;
    int count;

  public:
    unionfind(){}
    unionfind(int n): n(n), parent(n), depth(n, 1), size(n, 1), count(n){
      std::iota(parent.begin(), parent.end(), 0);
    }

    int root_of(int i) const {
      if(parent[i] == i) return i;
      else return parent[i] = root_of(parent[i]);
    }

    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}

    int merge(int i, int j){
      const int ri = root_of(i), rj = root_of(j);
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

    int size_of(int i) const {return size[root_of(i)];}

    int count_groups() const {return count;}

    auto get_groups() const {
      std::vector<std::vector<int>> ret(n);

      for(int i = 0; i < n; ++i){
        ret[root_of(i)].push_back(i);
      }

      ret.erase(
        std::remove_if(
          ret.begin(), ret.end(),
          [](const auto &a){return a.empty();}
        ),
        ret.end()
      );

      return ret;
    }
  };
}
#line 3 "Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp"

/**
 * @title Check bipartite graph (Using union-find)
 * @docs construct_bipartite_graph.md
 */
namespace haar_lib {
  class bipartite_graph {
    int n;
    unionfind check;

  public:
    bipartite_graph(int n): n(n), check(2 * n){}

    void add_diff(int i, int j){ // iとjを異なる色で塗る。
      check.merge(i, j + n);
      check.merge(i + n, j);
    }

    void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
      check.merge(i, j);
      check.merge(i + n, j + n);
    }

    bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
      return not check.is_same(i, i + n);
    }

    bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
      return check.is_same(i, j);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
