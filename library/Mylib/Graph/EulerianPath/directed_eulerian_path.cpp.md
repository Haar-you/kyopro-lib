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


# :warning: Directed eulerian path

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b40e1d8162bf14ce6637a69e4e4fb68d">Mylib/Graph/EulerianPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/EulerianPath/directed_eulerian_path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #288 (Div. 2) D. Tanya and Password](https://codeforces.com/contest/508/problem/D)

## References



## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


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
 * @title Directed eulerian path
 * @docs directed_eulerian_path.md
 */
class DirectedEulerianPath{
  const int n; // node count
  int edges = 0; // edge count
  std::vector<std::map<int,int>> graph;
  std::vector<int> indegree, outdegree;

  void del(int i, int j){
    if(graph[i][j] == 1) graph[i].erase(j);
    else --graph[i][j];
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
  DirectedEulerianPath(int n): n(n), graph(n), indegree(n), outdegree(n){}

  void add(int i, int j){
    ++graph[i][j];

    ++outdegree[i];
    ++indegree[j];

    ++edges;
  }

  std::optional<std::vector<int>> build(){
    int in = 0, out = 0;
    int start = 0;
    
    for(int i = 0; i < n; ++i){
      int d = outdegree[i] - indegree[i];
      if(abs(d) > 1) return std::nullopt;
      if(d == 1){
        ++out;
        start = i;
      }else if(d == -1){
        ++in;
      }
    }
    
    if(not ((in == 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;

    std::vector<int> ret;
    
    dfs(start, ret);
    std::reverse(ret.begin(), ret.end());
    if((int)ret.size() == edges+1){
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
#line 2 "Mylib/Graph/EulerianPath/directed_eulerian_path.cpp"
#include <vector>
#include <map>
#include <optional>
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
#line 6 "Mylib/Graph/EulerianPath/directed_eulerian_path.cpp"

/**
 * @title Directed eulerian path
 * @docs directed_eulerian_path.md
 */
class DirectedEulerianPath{
  const int n; // node count
  int edges = 0; // edge count
  std::vector<std::map<int,int>> graph;
  std::vector<int> indegree, outdegree;

  void del(int i, int j){
    if(graph[i][j] == 1) graph[i].erase(j);
    else --graph[i][j];
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
  DirectedEulerianPath(int n): n(n), graph(n), indegree(n), outdegree(n){}

  void add(int i, int j){
    ++graph[i][j];

    ++outdegree[i];
    ++indegree[j];

    ++edges;
  }

  std::optional<std::vector<int>> build(){
    int in = 0, out = 0;
    int start = 0;
    
    for(int i = 0; i < n; ++i){
      int d = outdegree[i] - indegree[i];
      if(abs(d) > 1) return std::nullopt;
      if(d == 1){
        ++out;
        start = i;
      }else if(d == -1){
        ++in;
      }
    }
    
    if(not ((in == 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;

    std::vector<int> ret;
    
    dfs(start, ret);
    std::reverse(ret.begin(), ret.end());
    if((int)ret.size() == edges+1){
      return {ret};
    }else{
      return std::nullopt;
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

