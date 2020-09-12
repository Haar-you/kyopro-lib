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
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


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
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Bellman-Ford algorithm
 * @docs bellman_ford.md
 */
namespace haar_lib {
  namespace bellman_ford_impl {
    template <typename T>
    struct result {
      enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
      T val;
      result(Tag tag): tag(tag){}

    public:
      static auto unreachable() {return result(Tag::UNREACHABLE);}
      static auto negloop() {return result(Tag::NEGLOOP);}
      result(T val): tag(Tag::OK), val(val){}

      bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
      bool is_negloop() const {return tag == Tag::NEGLOOP;}
      bool is_ok() const {return tag == Tag::OK;}

      T value() const {
        assert(tag == Tag::OK);
        return val;
      }

      friend std::ostream& operator<<(std::ostream &s, const result &a){
        if(a.is_unreachable()) s << "∞";
        else if(a.is_negloop()) s << "-∞";
        else s << a.value();
        return s;
      }
    };
  }

  template <typename T>
  auto bellman_ford(const graph<T> &g, int src){
    using Result = bellman_ford_impl::result<T>;
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
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/bellman_ford.cpp"
#include <vector>
#include <algorithm>
#include <cassert>
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
#line 6 "Mylib/Graph/ShortestPath/bellman_ford.cpp"

/**
 * @title Bellman-Ford algorithm
 * @docs bellman_ford.md
 */
namespace haar_lib {
  namespace bellman_ford_impl {
    template <typename T>
    struct result {
      enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
      T val;
      result(Tag tag): tag(tag){}

    public:
      static auto unreachable() {return result(Tag::UNREACHABLE);}
      static auto negloop() {return result(Tag::NEGLOOP);}
      result(T val): tag(Tag::OK), val(val){}

      bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
      bool is_negloop() const {return tag == Tag::NEGLOOP;}
      bool is_ok() const {return tag == Tag::OK;}

      T value() const {
        assert(tag == Tag::OK);
        return val;
      }

      friend std::ostream& operator<<(std::ostream &s, const result &a){
        if(a.is_unreachable()) s << "∞";
        else if(a.is_negloop()) s << "-∞";
        else s << a.value();
        return s;
      }
    };
  }

  template <typename T>
  auto bellman_ford(const graph<T> &g, int src){
    using Result = bellman_ford_impl::result<T>;
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
