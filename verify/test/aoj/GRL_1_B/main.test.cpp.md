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


# :heavy_check_mark: test/aoj/GRL_1_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f1313a8dcf51d21dc3fedcd116b5c80b">test/aoj/GRL_1_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/ShortestPath/bellman_ford.cpp.html">Bellman-Ford algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/bellman_ford.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  auto g = convert_to_graph<int64_t, true>(V, input_edges<int64_t, 0, true>(E));

  auto res = BellmanFord(g, r);
  
  bool neg_cycle = false;

  for(auto &x : res.dist){
    if(x.is_negloop()) neg_cycle = true;
  }

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res.dist){
      if(x.is_unreachable()){
        std::cout << "INF" << std::endl;
      }else{
        std::cout << x.value() << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/ShortestPath/bellman_ford.cpp"
#include <algorithm>
#include <cassert>
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
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}
#line 7 "test/aoj/GRL_1_B/main.test.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  auto g = convert_to_graph<int64_t, true>(V, input_edges<int64_t, 0, true>(E));

  auto res = BellmanFord(g, r);
  
  bool neg_cycle = false;

  for(auto &x : res.dist){
    if(x.is_negloop()) neg_cycle = true;
  }

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res.dist){
      if(x.is_unreachable()){
        std::cout << "INF" << std::endl;
      }else{
        std::cout << x.value() << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

