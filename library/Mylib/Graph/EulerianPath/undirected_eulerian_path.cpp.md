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


# :warning: Undirected Eulerian path

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b40e1d8162bf14ce6637a69e4e4fb68d">Mylib/Graph/EulerianPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #554 (Div. 2) E. Neko and Flashback](https://codeforces.com/contest/1152/problem/E)

## References



## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <map>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Undirected Eulerian path
 * @docs undirected_eulerian_path.md
 */
namespace haar_lib {
  class undirected_eulerian_path {
    const int n; // node count
    int edges = 0; // edge count
    std::vector<std::map<int, int>> graph;
    std::vector<int> degree;

    void del(int i, int j){
      if(graph[i][j] == 1) graph[i].erase(j);
      else --graph[i][j];

      if(graph[j][i] == 1) graph[j].erase(i);
      else --graph[j][i];
    }

    void dfs(int cur, std::vector<int> &path){
      if(not graph[cur].empty()){
        int next = graph[cur].begin()->first;
        del(cur, next);
        dfs(next, path);
      }

      while(not graph[cur].empty()){
        int next = graph[cur].begin()->first;
        del(cur, next);
        std::vector<int> temp;
        dfs(next, temp);
        path.insert(path.end(), temp.begin(), temp.end());
      }

      path.push_back(cur);
    }

  public:
    undirected_eulerian_path(int n): n(n), graph(n), degree(n){}

    void add(int i, int j){
      ++graph[i][j];
      ++graph[j][i];

      ++degree[i];
      ++degree[j];

      ++edges;
    }

    std::optional<std::vector<int>> build(){
      std::vector<int> ret;

      int odd = 0;
      int start = 0;
      for(int i = 0; i < n; ++i){
        if(degree[i] % 2 == 1){
          ++odd;
          start = i;
        }
      }

      if(odd != 0 and odd != 2) return std::nullopt;

      dfs(start, ret);

      if((int)ret.size() == edges + 1){
        return {ret};
      }else{
        return std::nullopt;
      }
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp"
#include <vector>
#include <map>
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
#line 6 "Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp"

/**
 * @title Undirected Eulerian path
 * @docs undirected_eulerian_path.md
 */
namespace haar_lib {
  class undirected_eulerian_path {
    const int n; // node count
    int edges = 0; // edge count
    std::vector<std::map<int, int>> graph;
    std::vector<int> degree;

    void del(int i, int j){
      if(graph[i][j] == 1) graph[i].erase(j);
      else --graph[i][j];

      if(graph[j][i] == 1) graph[j].erase(i);
      else --graph[j][i];
    }

    void dfs(int cur, std::vector<int> &path){
      if(not graph[cur].empty()){
        int next = graph[cur].begin()->first;
        del(cur, next);
        dfs(next, path);
      }

      while(not graph[cur].empty()){
        int next = graph[cur].begin()->first;
        del(cur, next);
        std::vector<int> temp;
        dfs(next, temp);
        path.insert(path.end(), temp.begin(), temp.end());
      }

      path.push_back(cur);
    }

  public:
    undirected_eulerian_path(int n): n(n), graph(n), degree(n){}

    void add(int i, int j){
      ++graph[i][j];
      ++graph[j][i];

      ++degree[i];
      ++degree[j];

      ++edges;
    }

    std::optional<std::vector<int>> build(){
      std::vector<int> ret;

      int odd = 0;
      int start = 0;
      for(int i = 0; i < n; ++i){
        if(degree[i] % 2 == 1){
          ++odd;
          start = i;
        }
      }

      if(odd != 0 and odd != 2) return std::nullopt;

      dfs(start, ret);

      if((int)ret.size() == edges + 1){
        return {ret};
      }else{
        return std::nullopt;
      }
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

