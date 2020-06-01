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


# :heavy_check_mark: BFS shortest path

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/bfs_shortest_path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/0558/main.graph.test.cpp.html">test/aoj/0558/main.graph.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title BFS shortest path
 * @docs bfs_shortest_path.md
 */
template <typename T>
std::vector<std::optional<int>> bfs_shortest_path(const Graph<T> &g, const std::vector<int> &src){
  const int n = g.size();
  std::vector<std::optional<int>> ret(n, std::nullopt);
  std::vector<bool> visited(n);
  std::queue<int> q;

  for(auto s : src){
    ret[s] = 0;
    q.push(s);
  }

  while(not q.empty()){
    const int cur = q.front(); q.pop();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(not ret[e.to] or *ret[e.to] > *ret[e.from] + 1){
        ret[e.to] = *ret[e.from] + 1;
        q.push(e.to);
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
#line 2 "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"
#include <vector>
#include <optional>
#include <queue>
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
#line 6 "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"

/**
 * @title BFS shortest path
 * @docs bfs_shortest_path.md
 */
template <typename T>
std::vector<std::optional<int>> bfs_shortest_path(const Graph<T> &g, const std::vector<int> &src){
  const int n = g.size();
  std::vector<std::optional<int>> ret(n, std::nullopt);
  std::vector<bool> visited(n);
  std::queue<int> q;

  for(auto s : src){
    ret[s] = 0;
    q.push(s);
  }

  while(not q.empty()){
    const int cur = q.front(); q.pop();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(not ret[e.to] or *ret[e.to] > *ret[e.from] + 1){
        ret[e.to] = *ret[e.from] + 1;
        q.push(e.to);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

