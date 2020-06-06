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
    - Last commit date: 2020-06-05 21:15:44+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22#%E7%AC%AC1%E6%9C%80%E7%9F%AD%E8%B7%AF](https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22#%E7%AC%AC1%E6%9C%80%E7%9F%AD%E8%B7%AF)


## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


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

#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Yen's algorithm
 * @docs yen_algorithm.md
 */
template <typename T>
auto yen_algorithm(Graph<T> g, int s, int t, int K){
  using Path = std::pair<T, std::vector<int>>;
  using P = std::pair<T, int>;

  const int N = g.size();

  std::vector<std::vector<bool>> valid(N);
  std::vector<std::optional<Path>> result(K);
  std::priority_queue<Path, std::vector<Path>, std::greater<Path>> stock;

  for(int i = 0; i < N; ++i){
    valid[i].assign(g[i].size(), true);
  }
  
  auto shortest_path =
    [&](int from, const std::vector<bool> &usable){
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
    };

  for(int i = 0; i < K; ++i){
    if(i == 0){
      std::vector<bool> usable(N, true);
      if(auto res = shortest_path(s, usable); res) stock.push(*res);
    }else{
      std::vector<int> prev_path;

      {
        int cur = s;
        for(auto u : result[i-1]->second){
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

        if(auto res = shortest_path(u, usable); res){

          auto [c, p] = *res;

          std::vector<int> temp;
          for(int j = 0; j < k; ++j){
            int v = result[i-1]->second[j];

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
            if(prev_path[k+1] != g[prev_path[k]][result[j]->second[k]].to){
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
#line 10 "Mylib/Graph/ShortestPath/yen_algorithm.cpp"

/**
 * @title Yen's algorithm
 * @docs yen_algorithm.md
 */
template <typename T>
auto yen_algorithm(Graph<T> g, int s, int t, int K){
  using Path = std::pair<T, std::vector<int>>;
  using P = std::pair<T, int>;

  const int N = g.size();

  std::vector<std::vector<bool>> valid(N);
  std::vector<std::optional<Path>> result(K);
  std::priority_queue<Path, std::vector<Path>, std::greater<Path>> stock;

  for(int i = 0; i < N; ++i){
    valid[i].assign(g[i].size(), true);
  }
  
  auto shortest_path =
    [&](int from, const std::vector<bool> &usable){
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
    };

  for(int i = 0; i < K; ++i){
    if(i == 0){
      std::vector<bool> usable(N, true);
      if(auto res = shortest_path(s, usable); res) stock.push(*res);
    }else{
      std::vector<int> prev_path;

      {
        int cur = s;
        for(auto u : result[i-1]->second){
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

        if(auto res = shortest_path(u, usable); res){

          auto [c, p] = *res;

          std::vector<int> temp;
          for(int j = 0; j < k; ++j){
            int v = result[i-1]->second[j];

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
            if(prev_path[k+1] != g[prev_path[k]][result[j]->second[k]].to){
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

