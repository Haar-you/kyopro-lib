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


# :heavy_check_mark: Topological sort

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5cfab8f1bec9f4a2c22b88bddb7720db">Mylib/Graph/TopologicalSort</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TopologicalSort/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Required by

* :heavy_check_mark: <a href="../two_sat.cpp.html">2-SAT</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>


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
 * @title Topological sort
 * @docs topological_sort.md
 */
template <typename T>
std::optional<std::vector<int>> topological_sort(const Graph<T> &g){
  const int n = g.size();
  std::vector<int> indeg(n);
  
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      ++indeg[e.to];
    }
  }

  std::queue<int> q;
  for(int i = n-1; i >= 0; --i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    for(auto &e : g[cur]){
      --indeg[e.to];
      if(indeg[e.to] == 0){
        q.push(e.to);
      }
    }
  }

  if((int)ret.size() == n){
    return {ret};
  }else{
    return std::nullopt;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TopologicalSort/topological_sort.cpp"
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
#line 6 "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title Topological sort
 * @docs topological_sort.md
 */
template <typename T>
std::optional<std::vector<int>> topological_sort(const Graph<T> &g){
  const int n = g.size();
  std::vector<int> indeg(n);
  
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      ++indeg[e.to];
    }
  }

  std::queue<int> q;
  for(int i = n-1; i >= 0; --i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    for(auto &e : g[cur]){
      --indeg[e.to];
      if(indeg[e.to] == 0){
        q.push(e.to);
      }
    }
  }

  if((int)ret.size() == n){
    return {ret};
  }else{
    return std::nullopt;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

