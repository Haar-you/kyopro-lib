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


# :warning: 有向グラフの最小閉路

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ac2a729ce4878019d16697115af3ef73">Mylib/Graph/ShortestCycle</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestCycle/directed_shortest_cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

## Requirements

## Notes

## Problems

- [ABC 142 F - Pure](https://atcoder.jp/contests/abc142/tasks/abc142_f)

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
#include <queue>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 有向グラフの最小閉路
 * @docs directed_shortest_cycle.md
 */
template <typename T>
struct DirectShortestCycle{
  const int N;
  std::optional<std::vector<int>> cycle;

  void bfs(int i, const Graph<T> &g, int &min_len){
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
  
  DirectShortestCycle(const Graph<T> &g): N(g.size()){
    int min_len = INT_MAX;
    
    for(int i = 0; i < N; ++i){
      bfs(i, g, min_len);
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestCycle/directed_shortest_cycle.cpp"
#include <vector>
#include <optional>
#include <queue>
#include <algorithm>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title グラフ用テンプレート
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
#line 7 "Mylib/Graph/ShortestCycle/directed_shortest_cycle.cpp"

/**
 * @title 有向グラフの最小閉路
 * @docs directed_shortest_cycle.md
 */
template <typename T>
struct DirectShortestCycle{
  const int N;
  std::optional<std::vector<int>> cycle;

  void bfs(int i, const Graph<T> &g, int &min_len){
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
  
  DirectShortestCycle(const Graph<T> &g): N(g.size()){
    int min_len = INT_MAX;
    
    for(int i = 0; i < N; ++i){
      bfs(i, g, min_len);
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

