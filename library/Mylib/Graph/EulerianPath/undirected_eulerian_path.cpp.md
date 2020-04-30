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


# :warning: 無向Euler路

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b40e1d8162bf14ce6637a69e4e4fb68d">Mylib/Graph/EulerianPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 00:04:32+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #554 (Div. 2) E. Neko and Flashback](https://codeforces.com/contest/1152/problem/E)

## References



## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <map>
#include <optional>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 無向Euler路
 * @docs undirected_eulerian_path.md
 */
class UndirectedEulerianPath{
  const int n; // node count
  int edges = 0; // edge count
  std::vector<std::map<int,int>> graph;
  std::vector<int> degree;

  void del(int i, int j){
    if(graph[i][j] == 1) graph[i].erase(j);
    else --graph[i][j];

    if(graph[j][i] == 1) graph[j].erase(i);
    else --graph[j][i];
  }

  void dfs(int cur, std::vector<int> &path){
    if(not graph[cur].empty()){
      int next = graph[cur].begin()->fst;
      del(cur, next);
      dfs(next, path);
    }

    while(not graph[cur].empty()){
      int next = graph[cur].begin()->fst;
      del(cur, next);
      std::vector<int> temp;
      dfs(next, temp);
      path.insert(path.end(), ALL(temp));
    }

    path.push_back(cur);
  }

public:
  UndirectedEulerianPath(int n): n(n), graph(n), degree(n){}

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp"
#include <vector>
#include <map>
#include <optional>
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
#line 6 "Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp"

/**
 * @title 無向Euler路
 * @docs undirected_eulerian_path.md
 */
class UndirectedEulerianPath{
  const int n; // node count
  int edges = 0; // edge count
  std::vector<std::map<int,int>> graph;
  std::vector<int> degree;

  void del(int i, int j){
    if(graph[i][j] == 1) graph[i].erase(j);
    else --graph[i][j];

    if(graph[j][i] == 1) graph[j].erase(i);
    else --graph[j][i];
  }

  void dfs(int cur, std::vector<int> &path){
    if(not graph[cur].empty()){
      int next = graph[cur].begin()->fst;
      del(cur, next);
      dfs(next, path);
    }

    while(not graph[cur].empty()){
      int next = graph[cur].begin()->fst;
      del(cur, next);
      std::vector<int> temp;
      dfs(next, temp);
      path.insert(path.end(), ALL(temp));
    }

    path.push_back(cur);
  }

public:
  UndirectedEulerianPath(int n): n(n), graph(n), degree(n){}

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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
