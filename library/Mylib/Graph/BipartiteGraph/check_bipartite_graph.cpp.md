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


# :heavy_check_mark: Check bipartite graph

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3b87eee7aef75da88610c966a8da844f">Mylib/Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Operations

## Requirements

## Notes

## Problems

- [Maximum-Cup 2018 C - 嘘つきな天使たち](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c)
- [ARC 099 E - Independence](https://atcoder.jp/contests/arc099/tasks/arc099_c)

## References



## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2370/main.test.cpp.html">test/aoj/2370/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <stack>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Check bipartite graph
 * @docs check_bipartite_graph.md
 */
template <typename T>
auto check_bipartite_graph(const Graph<T> &g){
  std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>> ret;

  const int N = g.size();

  std::vector<int> check(N, -1);
  std::vector<bool> visit(N);

  for(int i = 0; i < N; ++i){
    if(visit[i]) continue;

    std::vector<int> a, b;
      
    bool res =
      [&](){
        std::stack<int> st;
 
        st.push(i);
        check[i] = 0;
        a.push_back(i);

        while(not st.empty()){
          auto cur = st.top(); st.pop();
          if(visit[cur]) continue;
          visit[cur] = true;
 
          for(auto &e : g[cur]){
            if(check[e.to] == check[cur]) return false;
 
            if(check[e.to] == -1){
              if(check[cur] == 0){
                check[e.to] = 1;
                b.push_back(e.to);
              }else{
                check[e.to] = 0;
                a.push_back(e.to);
              }
          
              st.push(e.to);
            }
          }
        }

        return true;
      }();

    if(res){
      ret.push_back({{a, b}});
    }else{
      ret.push_back(std::nullopt);
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include <vector>
#include <optional>
#include <stack>
#include <utility>
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
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
#line 7 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"

/**
 * @title Check bipartite graph
 * @docs check_bipartite_graph.md
 */
template <typename T>
auto check_bipartite_graph(const Graph<T> &g){
  std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>> ret;

  const int N = g.size();

  std::vector<int> check(N, -1);
  std::vector<bool> visit(N);

  for(int i = 0; i < N; ++i){
    if(visit[i]) continue;

    std::vector<int> a, b;
      
    bool res =
      [&](){
        std::stack<int> st;
 
        st.push(i);
        check[i] = 0;
        a.push_back(i);

        while(not st.empty()){
          auto cur = st.top(); st.pop();
          if(visit[cur]) continue;
          visit[cur] = true;
 
          for(auto &e : g[cur]){
            if(check[e.to] == check[cur]) return false;
 
            if(check[e.to] == -1){
              if(check[cur] == 0){
                check[e.to] = 1;
                b.push_back(e.to);
              }else{
                check[e.to] = 0;
                a.push_back(e.to);
              }
          
              st.push(e.to);
            }
          }
        }

        return true;
      }();

    if(res){
      ret.push_back({{a, b}});
    }else{
      ret.push_back(std::nullopt);
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

