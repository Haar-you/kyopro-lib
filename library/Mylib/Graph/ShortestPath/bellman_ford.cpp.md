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


# :x: Bellman-Ford algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_1_B/main.test.cpp.html">test/aoj/GRL_1_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Bellman-Ford algorithm
 * @docs bellman_ford.md
 */
template <typename T>
struct BellmanFord{
  struct Result{
    enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
    T val;

  public:
    static auto unreachable() {return Result(Tag::UNREACHABLE);}
    static auto negloop() {return Result(Tag::NEGLOOP);}
    Result(Tag tag): tag(tag){}
    Result(T val): tag(Tag::OK), val(val){}

    bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
    bool is_negloop() const {return tag == Tag::NEGLOOP;}
    bool is_ok() const {return tag == Tag::OK;}

    T value() const {
      assert(tag == Tag::OK);
      return val;
    }
  };
  
  int n;
  std::vector<Result> dist;
  
  BellmanFord(const Graph<T> &graph, int src):
    n(graph.size()),
    dist(n, Result::unreachable())
  {
    dist[src] = 0;
    
    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : graph[s]){
          int t = e.to;
          T d = e.cost;
          
          if(dist[s].is_ok() and
             dist[t].is_ok() and
             dist[s].value() + d < dist[t].value() and i == n-1){
            dist[t] = Result::negloop();
          }else{
            if(dist[s].is_ok()){
              if(dist[t].is_unreachable()){
                dist[t] = dist[s].value() + d;
              }else if(dist[t].is_ok()){
                dist[t] = std::min(dist[t].value(), dist[s].value() + d);
              }
            }
          }
        }
      }
    }
    
    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : graph[s]){
          if(dist[s].is_negloop()){
            dist[e.to] = Result::negloop();
          }
        }
      }
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/bellman_ford.cpp"
#include <vector>
#include <algorithm>
#include <cassert>
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
#line 6 "Mylib/Graph/ShortestPath/bellman_ford.cpp"

/**
 * @title Bellman-Ford algorithm
 * @docs bellman_ford.md
 */
template <typename T>
struct BellmanFord{
  struct Result{
    enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
    T val;

  public:
    static auto unreachable() {return Result(Tag::UNREACHABLE);}
    static auto negloop() {return Result(Tag::NEGLOOP);}
    Result(Tag tag): tag(tag){}
    Result(T val): tag(Tag::OK), val(val){}

    bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
    bool is_negloop() const {return tag == Tag::NEGLOOP;}
    bool is_ok() const {return tag == Tag::OK;}

    T value() const {
      assert(tag == Tag::OK);
      return val;
    }
  };
  
  int n;
  std::vector<Result> dist;
  
  BellmanFord(const Graph<T> &graph, int src):
    n(graph.size()),
    dist(n, Result::unreachable())
  {
    dist[src] = 0;
    
    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : graph[s]){
          int t = e.to;
          T d = e.cost;
          
          if(dist[s].is_ok() and
             dist[t].is_ok() and
             dist[s].value() + d < dist[t].value() and i == n-1){
            dist[t] = Result::negloop();
          }else{
            if(dist[s].is_ok()){
              if(dist[t].is_unreachable()){
                dist[t] = dist[s].value() + d;
              }else if(dist[t].is_ok()){
                dist[t] = std::min(dist[t].value(), dist[s].value() + d);
              }
            }
          }
        }
      }
    }
    
    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : graph[s]){
          if(dist[s].is_negloop()){
            dist[e.to] = Result::negloop();
          }
        }
      }
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

