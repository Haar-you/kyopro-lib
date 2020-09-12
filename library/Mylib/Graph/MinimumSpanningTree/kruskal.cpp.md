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


# :x: Kruskal algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Required by

* :x: <a href="manhattan_minimum_spanning_tree.cpp.html">Manhattan distance MST</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html">test/aoj/GRL_2_A/main.kruskal.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/manhattanmst/main.test.cpp.html">test/yosupo-judge/manhattanmst/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Kruskal algorithm
 * @docs kruskal.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> kruskal(const graph<T> &graph){
    const int n = graph.size();
    std::vector<edge<T>> edges;
    for(auto &v : graph){
      for(auto &e : v){
        edges.push_back(e);
      }
    }

    std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){return a.cost < b.cost;});

    unionfind uf(n);

    std::vector<edge<T>> ret;

    for(auto &e : edges){
      if(!uf.is_same(e.from, e.to)){
        uf.merge(e.from, e.to);
        ret.push_back(e);
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"
#include <algorithm>
#include <vector>
#line 3 "Mylib/Graph/Template/graph.cpp"
#include <iostream>

/**
 * @title Basic graph
 * @docs graph.md
 */
namespace haar_lib {
  template <typename T>
  struct edge {
    int from, to;
    T cost;
    int index = -1;
    edge(){}
    edge(int from, int to, T cost): from(from), to(to), cost(cost){}
    edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
  };

  template <typename T>
  struct graph {
    using weight_type = T;
    using edge_type = edge<T>;

    std::vector<std::vector<edge<T>>> data;

    auto& operator[](size_t i){return data[i];}
    const auto& operator[](size_t i) const {return data[i];}

    auto begin() const {return data.begin();}
    auto end() const {return data.end();}

    graph(){}
    graph(int N): data(N){}

    bool empty() const {return data.empty();}
    int size() const {return data.size();}

    void add_edge(int i, int j, T w, int index = -1){
      data[i].emplace_back(i, j, w, index);
    }

    void add_undirected(int i, int j, T w, int index = -1){
      add_edge(i, j, w, index);
      add_edge(j, i, w, index);
    }

    template <size_t I, bool DIRECTED = true, bool WEIGHTED = true>
    void read(int M){
      for(int i = 0; i < M; ++i){
        int u, v; std::cin >> u >> v;
        u -= I;
        v -= I;
        T w = 1;
        if(WEIGHTED) std::cin >> w;
        if(DIRECTED) add_edge(u, v, w, i);
        else add_undirected(u, v, w, i);
      }
    }
  };

  template <typename T>
  using tree = graph<T>;
}
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>
#line 5 "Mylib/DataStructure/UnionFind/unionfind.cpp"

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
#line 6 "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

/**
 * @title Kruskal algorithm
 * @docs kruskal.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> kruskal(const graph<T> &graph){
    const int n = graph.size();
    std::vector<edge<T>> edges;
    for(auto &v : graph){
      for(auto &e : v){
        edges.push_back(e);
      }
    }

    std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){return a.cost < b.cost;});

    unionfind uf(n);

    std::vector<edge<T>> ret;

    for(auto &e : edges){
      if(!uf.is_same(e.from, e.to)){
        uf.merge(e.from, e.to);
        ret.push_back(e);
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

