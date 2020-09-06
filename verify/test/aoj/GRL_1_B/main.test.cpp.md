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


# :x: test/aoj/GRL_1_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f1313a8dcf51d21dc3fedcd116b5c80b">test/aoj/GRL_1_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/ShortestPath/bellman_ford.cpp.html">Bellman-Ford algorithm</a>
* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/ShortestPath/bellman_ford.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  g.read<0>(E);

  auto res = bellman_ford(g, r);

  bool neg_cycle = false;

  for(auto &x : res){
    if(x.is_negloop()) neg_cycle = true;
  }

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res){
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
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>
#line 4 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
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
#line 3 "Mylib/Graph/ShortestPath/bellman_ford.cpp"
#include <algorithm>
#include <cassert>
#line 6 "Mylib/Graph/ShortestPath/bellman_ford.cpp"

/**
 * @title Bellman-Ford algorithm
 * @docs bellman_ford.md
 */
namespace bellman_ford_impl {
  template <typename T>
  struct Result {
    enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
    T val;
    Result(Tag tag): tag(tag){}

  public:
    static auto unreachable() {return Result(Tag::UNREACHABLE);}
    static auto negloop() {return Result(Tag::NEGLOOP);}
    Result(T val): tag(Tag::OK), val(val){}

    bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
    bool is_negloop() const {return tag == Tag::NEGLOOP;}
    bool is_ok() const {return tag == Tag::OK;}

    T value() const {
      assert(tag == Tag::OK);
      return val;
    }

    friend std::ostream& operator<<(std::ostream &s, const Result &a){
      if(a.is_unreachable()) s << "∞";
      else if(a.is_negloop()) s << "-∞";
      else s << a.value();
      return s;
    }
  };
}

template <typename T>
auto bellman_ford(const Graph<T> &g, int src){
  using Result = bellman_ford_impl::Result<T>;
  const int n = g.size();
  std::vector<Result> dist(n, Result::unreachable());

  dist[src] = 0;

  for(int i = 0; i < n; ++i){
    for(int s = 0; s < n; ++s){
      for(auto &e : g[s]){
        int t = e.to;
        T d = e.cost;

        if(dist[s].is_ok() and
           dist[t].is_ok() and
           dist[s].value() + d < dist[t].value() and i == n - 1){
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
      for(auto &e : g[s]){
        if(dist[s].is_negloop()){
          dist[e.to] = Result::negloop();
        }
      }
    }
  }

  return dist;
}
#line 6 "test/aoj/GRL_1_B/main.test.cpp"

int main(){
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  g.read<0>(E);

  auto res = bellman_ford(g, r);

  bool neg_cycle = false;

  for(auto &x : res){
    if(x.is_negloop()) neg_cycle = true;
  }

  if(neg_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(auto &x : res){
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

