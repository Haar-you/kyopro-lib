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


# :x: Yen's algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/yen_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22#%E7%AC%AC1%E6%9C%80%E7%9F%AD%E8%B7%AF](https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22)


## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/1069/main.test.cpp.html">test/yukicoder/1069/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <optional>
#include <queue>
#include <functional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Yen's algorithm
 * @docs yen_algorithm.md
 */
namespace haar_lib {
  namespace yen_algorithm_impl {
    template <typename T>
    auto shortest_path(
      const graph<T> &g,
      int from,
      int t,
      const std::vector<bool> &usable,
      const std::vector<std::vector<bool>> &valid
    ){
      using Path = std::pair<T, std::vector<int>>;
      using P = std::pair<T, int>;

      const int N = g.size();
      std::vector<bool> visited(N, false);
      std::vector<std::optional<T>> dist(N);
      std::vector<std::pair<int, int>> restore(N);

      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      dist[from] = 0;
      pq.emplace(0, from);

      while(not pq.empty()){
        auto [d, i] = pq.top(); pq.pop();

        if(visited[i]) continue;
        visited[i] = true;

        for(int k = 0; k < (int)g[i].size(); ++k){
          if(not valid[i][k] or not usable[g[i][k].to]) continue;
          auto &e = g[i][k];

          if(not dist[e.to] or *dist[e.to] > d + e.cost){
            dist[e.to] = d + e.cost;
            restore[e.to] = std::make_pair(i, k);
            if(not visited[e.to]) pq.emplace(*dist[e.to], e.to);
          }
        }
      }

      std::optional<Path> ret;

      if(dist[t]){
        std::vector<int> p;

        int cur = t;
        while(cur != from){
          auto [i, j] = restore[cur];
          p.push_back(j);
          cur = i;
        }

        std::reverse(p.begin(), p.end());

        ret = std::make_pair(*dist[t], p);
      }

      return ret;
    }
  }

  template <typename T>
  auto yen_algorithm(const graph<T> &g, int s, int t, int K){
    using Path = std::pair<T, std::vector<int>>;

    const int N = g.size();

    std::vector<std::vector<bool>> valid(N);
    std::vector<std::optional<Path>> result(K);
    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> stock;

    for(int i = 0; i < N; ++i){
      valid[i].assign(g[i].size(), true);
    }

    for(int i = 0; i < K; ++i){
      if(i == 0){
        std::vector<bool> usable(N, true);
        if(auto res = yen_algorithm_impl::shortest_path(g, s, t, usable, valid); res) stock.push(*res);
      }else{
        std::vector<int> prev_path;

        {
          int cur = s;
          for(auto u : result[i - 1]->second){
            prev_path.push_back(cur);
            cur = g[cur][u].to;
          }
          prev_path.push_back(t);
        }

        std::vector<bool> check(i, true);
        std::vector<bool> usable(N, true);

        for(int k = 0; k < (int)prev_path.size() - 1; ++k){
          const int u = prev_path[k];

          for(int j = 0; j < i; ++j){
            if(check[j]){
              valid[prev_path[k]][result[j]->second[k]] = false;
            }
          }

          if(auto res = yen_algorithm_impl::shortest_path(g, u, t, usable, valid); res){
            auto [c, p] = *res;

            std::vector<int> temp;
            for(int j = 0; j < k; ++j){
              int v = result[i - 1]->second[j];

              c += g[prev_path[j]][v].cost;
              temp.push_back(v);
            }

            temp.insert(temp.end(), p.begin(), p.end());
            stock.emplace(c, temp);
          }

          usable[u] = false;

          for(int j = 0; j < i; ++j){
            if(check[j]){
              valid[prev_path[k]][result[j]->second[k]] = true;
            }
          }

          for(int j = 0; j < i; ++j){
            if(check[j]){
              if(prev_path[k + 1] != g[prev_path[k]][result[j]->second[k]].to){
                check[j] = false;
              }
            }
          }
        }
      }

      if(stock.empty()) break;

      result[i] = stock.top(); stock.pop();

      while(not stock.empty() and stock.top() == result[i]){
        stock.pop();
      }
    }

    return result;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/yen_algorithm.cpp"
#include <vector>
#include <utility>
#include <optional>
#include <queue>
#include <functional>
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
#line 8 "Mylib/Graph/ShortestPath/yen_algorithm.cpp"

/**
 * @title Yen's algorithm
 * @docs yen_algorithm.md
 */
namespace haar_lib {
  namespace yen_algorithm_impl {
    template <typename T>
    auto shortest_path(
      const graph<T> &g,
      int from,
      int t,
      const std::vector<bool> &usable,
      const std::vector<std::vector<bool>> &valid
    ){
      using Path = std::pair<T, std::vector<int>>;
      using P = std::pair<T, int>;

      const int N = g.size();
      std::vector<bool> visited(N, false);
      std::vector<std::optional<T>> dist(N);
      std::vector<std::pair<int, int>> restore(N);

      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      dist[from] = 0;
      pq.emplace(0, from);

      while(not pq.empty()){
        auto [d, i] = pq.top(); pq.pop();

        if(visited[i]) continue;
        visited[i] = true;

        for(int k = 0; k < (int)g[i].size(); ++k){
          if(not valid[i][k] or not usable[g[i][k].to]) continue;
          auto &e = g[i][k];

          if(not dist[e.to] or *dist[e.to] > d + e.cost){
            dist[e.to] = d + e.cost;
            restore[e.to] = std::make_pair(i, k);
            if(not visited[e.to]) pq.emplace(*dist[e.to], e.to);
          }
        }
      }

      std::optional<Path> ret;

      if(dist[t]){
        std::vector<int> p;

        int cur = t;
        while(cur != from){
          auto [i, j] = restore[cur];
          p.push_back(j);
          cur = i;
        }

        std::reverse(p.begin(), p.end());

        ret = std::make_pair(*dist[t], p);
      }

      return ret;
    }
  }

  template <typename T>
  auto yen_algorithm(const graph<T> &g, int s, int t, int K){
    using Path = std::pair<T, std::vector<int>>;

    const int N = g.size();

    std::vector<std::vector<bool>> valid(N);
    std::vector<std::optional<Path>> result(K);
    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> stock;

    for(int i = 0; i < N; ++i){
      valid[i].assign(g[i].size(), true);
    }

    for(int i = 0; i < K; ++i){
      if(i == 0){
        std::vector<bool> usable(N, true);
        if(auto res = yen_algorithm_impl::shortest_path(g, s, t, usable, valid); res) stock.push(*res);
      }else{
        std::vector<int> prev_path;

        {
          int cur = s;
          for(auto u : result[i - 1]->second){
            prev_path.push_back(cur);
            cur = g[cur][u].to;
          }
          prev_path.push_back(t);
        }

        std::vector<bool> check(i, true);
        std::vector<bool> usable(N, true);

        for(int k = 0; k < (int)prev_path.size() - 1; ++k){
          const int u = prev_path[k];

          for(int j = 0; j < i; ++j){
            if(check[j]){
              valid[prev_path[k]][result[j]->second[k]] = false;
            }
          }

          if(auto res = yen_algorithm_impl::shortest_path(g, u, t, usable, valid); res){
            auto [c, p] = *res;

            std::vector<int> temp;
            for(int j = 0; j < k; ++j){
              int v = result[i - 1]->second[j];

              c += g[prev_path[j]][v].cost;
              temp.push_back(v);
            }

            temp.insert(temp.end(), p.begin(), p.end());
            stock.emplace(c, temp);
          }

          usable[u] = false;

          for(int j = 0; j < i; ++j){
            if(check[j]){
              valid[prev_path[k]][result[j]->second[k]] = true;
            }
          }

          for(int j = 0; j < i; ++j){
            if(check[j]){
              if(prev_path[k + 1] != g[prev_path[k]][result[j]->second[k]].to){
                check[j] = false;
              }
            }
          }
        }
      }

      if(stock.empty()) break;

      result[i] = stock.top(); stock.pop();

      while(not stock.empty() and stock.top() == result[i]){
        stock.pop();
      }
    }

    return result;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

