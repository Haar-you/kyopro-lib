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
    - Last commit date: 2020-04-02 18:35:49+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <deque>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 0-1 BFS
 */
std::vector<int> bfs_0_1(const Graph<int> &g, const std::vector<int> &src){
  int n = g.size();
  std::vector<int> ret(n, INT_MAX);
  std::vector<bool> visited(n);

  for(auto i : src) ret[i] = 0;
  std::deque<int> dq(src.begin(), src.end());

  while(not dq.empty()){
    int cur = dq.front(); dq.pop_front();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(ret[e.to] > ret[e.from] + e.cost){
        ret[e.to] = ret[e.from] + e.cost;
        
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

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}
#line 5 "Mylib/Graph/ShortestPath/bfs_0_1.cpp"

/**
 * @title 0-1 BFS
 */
std::vector<int> bfs_0_1(const Graph<int> &g, const std::vector<int> &src){
  int n = g.size();
  std::vector<int> ret(n, INT_MAX);
  std::vector<bool> visited(n);

  for(auto i : src) ret[i] = 0;
  std::deque<int> dq(src.begin(), src.end());

  while(not dq.empty()){
    int cur = dq.front(); dq.pop_front();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(ret[e.to] > ret[e.from] + e.cost){
        ret[e.to] = ret[e.from] + e.cost;
        
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

