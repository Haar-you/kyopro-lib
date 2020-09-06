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


# :warning: 0-1 BFS

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/bfs_0_1.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Depends on

* :x: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <deque>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title 0-1 BFS
 * @docs bfs_0_1.md
 */
std::vector<std::optional<int64_t>> bfs_0_1(const Graph<int> &g, const std::vector<int> &src){
  const int n = g.size();
  std::vector<std::optional<int64_t>> ret(n);
  std::vector<bool> visited(n);

  for(auto i : src) ret[i] = 0;
  std::deque<int> dq(src.begin(), src.end());

  while(not dq.empty()){
    int cur = dq.front(); dq.pop_front();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(not ret[e.to] or *ret[e.to] > *ret[e.from] + e.cost){
        ret[e.to] = *ret[e.from] + e.cost;

        if(e.cost == 0) dq.push_front(e.to);
        else dq.push_back(e.to);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/bfs_0_1.cpp"
#include <vector>
#include <deque>
#include <optional>
#line 3 "Mylib/Graph/Template/graph.cpp"
#include <iostream>

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
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
#line 6 "Mylib/Graph/ShortestPath/bfs_0_1.cpp"

/**
 * @title 0-1 BFS
 * @docs bfs_0_1.md
 */
std::vector<std::optional<int64_t>> bfs_0_1(const Graph<int> &g, const std::vector<int> &src){
  const int n = g.size();
  std::vector<std::optional<int64_t>> ret(n);
  std::vector<bool> visited(n);

  for(auto i : src) ret[i] = 0;
  std::deque<int> dq(src.begin(), src.end());

  while(not dq.empty()){
    int cur = dq.front(); dq.pop_front();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(not ret[e.to] or *ret[e.to] > *ret[e.from] + e.cost){
        ret[e.to] = *ret[e.from] + e.cost;

        if(e.cost == 0) dq.push_front(e.to);
        else dq.push_back(e.to);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

