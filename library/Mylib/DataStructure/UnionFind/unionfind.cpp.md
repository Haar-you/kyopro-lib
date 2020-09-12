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


# :question: Union-find

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ff74e8366c88d06b530f361450b1117">Mylib/DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/UnionFind/unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `UnionFind(n)`
- `root_of(int i)`
	- `i`のrootを得る。
- `is_same(int i, int j)`
	- `i`と`j`が同じ連結成分かどうかを判定する。
- `merge(int i, int j)`
	- `i`と`j`を同じ連結成分にし、その連結成分のrootを返す。
- `size_of(int i)`
	- `i`の属する連結成分の大きさ。
- `count_group()`
	- 連結成分の個数を返す。


## Required by

* :warning: <a href="../../Graph/BipartiteGraph/construct_bipartite_graph.cpp.html">Check bipartite graph (Using union-find)</a>
* :x: <a href="../../Graph/MinimumSpanningTree/boruvka.cpp.html">Borůvka algorithm</a>
* :x: <a href="../../Graph/MinimumSpanningTree/kruskal.cpp.html">Kruskal algorithm</a>
* :x: <a href="../../Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp.html">Manhattan distance MST</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/1337/main.test.cpp.html">test/aoj/1337/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/2955/main.test.cpp.html">test/aoj/2955/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/GRL_2_A/main.boruvka.test.cpp.html">test/aoj/GRL_2_A/main.boruvka.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html">test/aoj/GRL_2_A/main.kruskal.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/manhattanmst/main.test.cpp.html">test/yosupo-judge/manhattanmst/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/unionfind/main.test.cpp.html">test/yosupo-judge/unionfind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

