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


# :x: Warshall-Floyd algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/warshall_floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_1_C/main.test.cpp.html">test/aoj/GRL_1_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Warshall-Floyd algorithm
 * @docs warshall_floyd.md
 */
namespace haar_lib {
  namespace warshall_floyd_impl {
    template <typename T>
    struct result {
      std::vector<std::vector<std::optional<T>>> dist;
      bool has_negative_cycle;
      const auto& operator[](int i) const {return dist[i];}
    };
  }

  template <typename T>
  auto warshall_floyd(const graph<T> &g){
    const int n = g.size();
    auto dist = std::vector(n, std::vector<std::optional<T>>(n));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        dist[e.from][e.to] = e.cost;
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] and dist[k][j]){
            if(not dist[i][j]){
              dist[i][j] = *dist[i][k] + *dist[k][j];
            }else{
              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
            }
          }
        }
      }
    }

    bool has_negative_cycle = false;
    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;

    return warshall_floyd_impl::result<T>{dist, has_negative_cycle};
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/warshall_floyd.cpp"
#include <vector>
#include <optional>
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
#line 5 "Mylib/Graph/ShortestPath/warshall_floyd.cpp"

/**
 * @title Warshall-Floyd algorithm
 * @docs warshall_floyd.md
 */
namespace haar_lib {
  namespace warshall_floyd_impl {
    template <typename T>
    struct result {
      std::vector<std::vector<std::optional<T>>> dist;
      bool has_negative_cycle;
      const auto& operator[](int i) const {return dist[i];}
    };
  }

  template <typename T>
  auto warshall_floyd(const graph<T> &g){
    const int n = g.size();
    auto dist = std::vector(n, std::vector<std::optional<T>>(n));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        dist[e.from][e.to] = e.cost;
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] and dist[k][j]){
            if(not dist[i][j]){
              dist[i][j] = *dist[i][k] + *dist[k][j];
            }else{
              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
            }
          }
        }
      }
    }

    bool has_negative_cycle = false;
    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;

    return warshall_floyd_impl::result<T>{dist, has_negative_cycle};
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

