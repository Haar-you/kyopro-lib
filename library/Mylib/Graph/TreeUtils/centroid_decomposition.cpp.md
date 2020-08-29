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


# :warning: Centroid decomposition

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/centroid_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Centroid decomposition
 * @docs centroid_decomposition.md
 */
template <typename T>
struct CentroidDecomposition{
  Tree<T> tree;
  const int N;

  std::vector<int> size;
  std::vector<bool> checked;
  std::vector<int> depth;
  
  CentroidDecomposition(const Tree<T> &tree):
    tree(tree), N(tree.size()), size(N), checked(N), depth(N)
  {
    decompose(0, 0);
  }

  void decompose(int cur, int d){
    dfs_subsize(cur, -1);
    auto c = get_centroid(cur, -1, size[cur]);

    checked[c] = true;
    depth[c] = d;

    for(auto &e : tree[c]){
      if(checked[e.to]) continue;
      decompose(e.to, d+1);
    }
  }

  int get_centroid(int cur, int par, int total_size){
    for(auto &e : tree[cur]){
      if(e.to == par or checked[e.to]) continue;

      if(2 * size[e.to] > total_size){
        return get_centroid(e.to, cur, total_size);
      }
    }

    return cur;
  }

  void dfs_subsize(int cur, int par){
    size[cur] = 1;
    for(auto &e : tree[cur]){
      if(e.to == par or checked[e.to]) continue;
      dfs_subsize(e.to, cur);
      size[cur] += size[e.to];
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/centroid_decomposition.cpp"
#include <vector>
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
  using weight_type = T;
  using edge_type = Edge<T>;
  
  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}
  
  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
#line 4 "Mylib/Graph/TreeUtils/centroid_decomposition.cpp"

/**
 * @title Centroid decomposition
 * @docs centroid_decomposition.md
 */
template <typename T>
struct CentroidDecomposition{
  Tree<T> tree;
  const int N;

  std::vector<int> size;
  std::vector<bool> checked;
  std::vector<int> depth;
  
  CentroidDecomposition(const Tree<T> &tree):
    tree(tree), N(tree.size()), size(N), checked(N), depth(N)
  {
    decompose(0, 0);
  }

  void decompose(int cur, int d){
    dfs_subsize(cur, -1);
    auto c = get_centroid(cur, -1, size[cur]);

    checked[c] = true;
    depth[c] = d;

    for(auto &e : tree[c]){
      if(checked[e.to]) continue;
      decompose(e.to, d+1);
    }
  }

  int get_centroid(int cur, int par, int total_size){
    for(auto &e : tree[cur]){
      if(e.to == par or checked[e.to]) continue;

      if(2 * size[e.to] > total_size){
        return get_centroid(e.to, cur, total_size);
      }
    }

    return cur;
  }

  void dfs_subsize(int cur, int par){
    size[cur] = 1;
    for(auto &e : tree[cur]){
      if(e.to == par or checked[e.to]) continue;
      dfs_subsize(e.to, cur);
      size[cur] += size[e.to];
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

