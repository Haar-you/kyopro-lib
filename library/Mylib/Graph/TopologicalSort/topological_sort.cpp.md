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


# :x: Topological sort

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5cfab8f1bec9f4a2c22b88bddb7720db">Mylib/Graph/TopologicalSort</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TopologicalSort/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Required by

* :x: <a href="../two_sat.cpp.html">2-SAT</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Topological sort
 * @docs topological_sort.md
 */
namespace haar_lib {
  template <typename T>
  std::optional<std::vector<int>> topological_sort(const graph<T> &g){
    const int n = g.size();
    std::vector<int> indeg(n);

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        ++indeg[e.to];
      }
    }

    std::queue<int> q;
    for(int i = 0; i < n; ++i){
      if(indeg[i] == 0) q.push(i);
    }

    std::vector<int> ret;
    while(not q.empty()){
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
#line 6 "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title Topological sort
 * @docs topological_sort.md
 */
namespace haar_lib {
  template <typename T>
  std::optional<std::vector<int>> topological_sort(const graph<T> &g){
    const int n = g.size();
    std::vector<int> indeg(n);

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        ++indeg[e.to];
      }
    }

    std::queue<int> q;
    for(int i = 0; i < n; ++i){
      if(indeg[i] == 0) q.push(i);
    }

    std::vector<int> ret;
    while(not q.empty()){
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
