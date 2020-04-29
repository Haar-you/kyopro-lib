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


# :warning: 非連結グラフの二部グラフ判定

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3b87eee7aef75da88610c966a8da844f">Mylib/Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/BipartiteGraph/check_bipartite_graph_disconnected.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 00:04:32+09:00




## Operations

## Requirements

## Notes

## Problems

- [Maximum-Cup 2018 C - 嘘つきな天使たち](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c)
- [ARC 099 E - Independence](https://atcoder.jp/contests/arc099/tasks/arc099_c)

## References



## Depends on

* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <stack>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 非連結グラフの二部グラフ判定
 * @docs check_bipartite_graph_disconnected.md
 */
template <typename T> struct CheckBipartiteGraph{
  std::vector<std::optional<std::pair<int,int>>> results;
  bool all_bipartite;
  
  CheckBipartiteGraph(const Graph<T> &g): all_bipartite(true){
    const int n = g.size();

    std::vector<int> check(n,-1);
    std::vector<bool> visit(n,false);

    for(int i = 0; i < n; ++i){
      if(visit[i]) continue;

      auto t = aux(g, i, check, visit);
      results.push_back(t);

      if(not t){
        all_bipartite = false;
      }
    }
  }
  
  std::optional<std::pair<int,int>> aux(const Graph<T> &graph, int root, std::vector<int> &check, std::vector<bool> &visit){
    std::stack<int> st;

    int a = 1, b = 0;
 
    st.push(root);
    check[root] = 0;
 
    while(!st.empty()){
      auto cur = st.top(); st.pop();
      if(visit[cur]) continue;
      visit[cur] = true;
 
      for(auto &e : graph[cur]){
        if(check[e.to] == check[cur]) return std::nullopt;
 
        if(check[e.to] == -1){
          if(check[cur] == 0){
            check[e.to] = 1;
            ++b;
          }else{
            check[e.to] = 0;
            ++a;
          }
          st.push(e.to);
        }
      }
    }
  
    return {std::make_pair(a, b)};
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/BipartiteGraph/check_bipartite_graph_disconnected.cpp"
#include <vector>
#include <optional>
#include <stack>
#include <utility>
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
#line 7 "Mylib/Graph/BipartiteGraph/check_bipartite_graph_disconnected.cpp"

/**
 * @title 非連結グラフの二部グラフ判定
 * @docs check_bipartite_graph_disconnected.md
 */
template <typename T> struct CheckBipartiteGraph{
  std::vector<std::optional<std::pair<int,int>>> results;
  bool all_bipartite;
  
  CheckBipartiteGraph(const Graph<T> &g): all_bipartite(true){
    const int n = g.size();

    std::vector<int> check(n,-1);
    std::vector<bool> visit(n,false);

    for(int i = 0; i < n; ++i){
      if(visit[i]) continue;

      auto t = aux(g, i, check, visit);
      results.push_back(t);

      if(not t){
        all_bipartite = false;
      }
    }
  }
  
  std::optional<std::pair<int,int>> aux(const Graph<T> &graph, int root, std::vector<int> &check, std::vector<bool> &visit){
    std::stack<int> st;

    int a = 1, b = 0;
 
    st.push(root);
    check[root] = 0;
 
    while(!st.empty()){
      auto cur = st.top(); st.pop();
      if(visit[cur]) continue;
      visit[cur] = true;
 
      for(auto &e : graph[cur]){
        if(check[e.to] == check[cur]) return std::nullopt;
 
        if(check[e.to] == -1){
          if(check[cur] == 0){
            check[e.to] = 1;
            ++b;
          }else{
            check[e.to] = 0;
            ++a;
          }
          st.push(e.to);
        }
      }
    }
  
    return {std::make_pair(a, b)};
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

