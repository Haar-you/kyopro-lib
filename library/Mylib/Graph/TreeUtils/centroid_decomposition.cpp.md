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


# :warning: 重心分解

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/centroid_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 09:17:56+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 重心分解
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
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title グラフ用テンプレート
 */
template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename T, typename C> void add_edge(C &g, int from, int to, T w = 1){
  g[from].emplace_back(from, to, w);
}

template <typename T, typename C> void add_undirected(C &g, int a, int b, T w = 1){
  add_edge<T, C>(g, a, b, w);
  add_edge<T, C>(g, b, a, w);
}
#line 4 "Mylib/Graph/TreeUtils/centroid_decomposition.cpp"

/**
 * @title 重心分解
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

