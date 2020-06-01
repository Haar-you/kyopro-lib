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


# :warning: Enumerate centroids

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/centroid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Enumerate centroids
 * @docs centroid.md
 */
template <typename T>
class Centroid{
public:
  int N;
  std::vector<int> subtree;
  std::vector<int> result;
  Centroid(const Tree<T> &tree): N(tree.size()), subtree(N){
    dfs(tree, 0, -1);    
  }

private:
  void dfs(const Tree<T> &tree, int cur, int par){
    subtree[cur] = 1;
    bool check = true;

    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(tree, e.to, cur);

      if(subtree[e.to] > N / 2) check = false;
      subtree[cur] += subtree[e.to];
    }

    if(N - subtree[cur] > N / 2) check = false;

    if(check) result.push_back(cur);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/centroid.cpp"
#include <vector>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title Graph template
 * @docs graph_template.md
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
#line 4 "Mylib/Graph/TreeUtils/centroid.cpp"

/**
 * @title Enumerate centroids
 * @docs centroid.md
 */
template <typename T>
class Centroid{
public:
  int N;
  std::vector<int> subtree;
  std::vector<int> result;
  Centroid(const Tree<T> &tree): N(tree.size()), subtree(N){
    dfs(tree, 0, -1);    
  }

private:
  void dfs(const Tree<T> &tree, int cur, int par){
    subtree[cur] = 1;
    bool check = true;

    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(tree, e.to, cur);

      if(subtree[e.to] > N / 2) check = false;
      subtree[cur] += subtree[e.to];
    }

    if(N - subtree[cur] > N / 2) check = false;

    if(check) result.push_back(cur);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

