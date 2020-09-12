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


# :warning: Directed shortest cycle

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a962efc2861dbe1e0963e7d8bf7dda18">Mylib/Graph/Cycle</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Cycle/directed_shortest_cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [ABC 142 F - Pure](https://atcoder.jp/contests/abc142/tasks/abc142_f)

## References


## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <queue>
#include <algorithm>
#include <climits>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Directed shortest cycle
 * @docs directed_shortest_cycle.md
 */
namespace haar_lib {
  template <typename T>
  struct direct_shortest_cycle {
    const int N;
    std::optional<std::vector<int>> cycle;

    void bfs(int i, const graph<T> &g, int &min_len){
      std::queue<int> q;
      q.push(i);

      std::vector<int> dist(N), pre(N);
      std::vector<bool> visited(N);

      while(not q.empty()){
        int cur = q.front(); q.pop();

        if(visited[cur]) continue;
        visited[cur] = true;

        for(auto &e : g[cur]){
          if(e.to == i){
            if(dist[cur] < min_len){
              min_len = dist[cur];
              cycle = std::vector<int>();

              int j = cur;
              while(1){
                (*cycle).push_back(j);
                if(j == i) break;

                j = pre[j];
              }

              std::reverse((*cycle).begin(), (*cycle).end());
            }

            return;
          }

          if(not visited[e.to]){
            dist[e.to] = dist[cur] + 1;
            pre[e.to] = cur;
            q.push(e.to);
          }
        }
      }
    }

    direct_shortest_cycle(const graph<T> &g): N(g.size()){
      int min_len = INT_MAX;

      for(int i = 0; i < N; ++i){
        bfs(i, g, min_len);
      }
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Cycle/directed_shortest_cycle.cpp"
#include <vector>
#include <optional>
#include <queue>
#include <algorithm>
#include <climits>
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
#line 8 "Mylib/Graph/Cycle/directed_shortest_cycle.cpp"

/**
 * @title Directed shortest cycle
 * @docs directed_shortest_cycle.md
 */
namespace haar_lib {
  template <typename T>
  struct direct_shortest_cycle {
    const int N;
    std::optional<std::vector<int>> cycle;

    void bfs(int i, const graph<T> &g, int &min_len){
      std::queue<int> q;
      q.push(i);

      std::vector<int> dist(N), pre(N);
      std::vector<bool> visited(N);

      while(not q.empty()){
        int cur = q.front(); q.pop();

        if(visited[cur]) continue;
        visited[cur] = true;

        for(auto &e : g[cur]){
          if(e.to == i){
            if(dist[cur] < min_len){
              min_len = dist[cur];
              cycle = std::vector<int>();

              int j = cur;
              while(1){
                (*cycle).push_back(j);
                if(j == i) break;

                j = pre[j];
              }

              std::reverse((*cycle).begin(), (*cycle).end());
            }

            return;
          }

          if(not visited[e.to]){
            dist[e.to] = dist[cur] + 1;
            pre[e.to] = cur;
            q.push(e.to);
          }
        }
      }
    }

    direct_shortest_cycle(const graph<T> &g): N(g.size()){
      int min_len = INT_MAX;

      for(int i = 0; i < N; ++i){
        bfs(i, g, min_len);
      }
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

