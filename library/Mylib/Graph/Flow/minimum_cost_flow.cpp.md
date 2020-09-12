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


# :question: Minimum cost flow

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ecd047c70c23d80351a9f133b49a4638">Mylib/Graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Flow/minimum_cost_flow.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2293/main.test.cpp.html">test/aoj/2293/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/GRL_6_B/main.test.cpp.html">test/aoj/GRL_6_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/assignment/main.test.cpp.html">test/yosupo-judge/assignment/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <tuple>

/**
 * @title Minimum cost flow
 * @docs minimum_cost_flow.md
 */
namespace haar_lib {
  template <typename T, typename U>
  class minimum_cost_flow {
  public:
    struct edge {
      int from, to;
      T cap;
      U cost;
      int rev;
      bool is_rev;
      edge(int from, int to, T cap, U cost, int rev, bool is_rev):
        from(from), to(to), cap(cap), cost(cost), rev(rev), is_rev(is_rev){}
    };

  private:
    int size;
    std::vector<std::vector<edge>> g;

  public:
    minimum_cost_flow(int size): size(size), g(size){}

    void add_edge(int from, int to, T cap, U cost){
      g[from].emplace_back(from, to, cap, cost, g[to].size(), false);
      g[to].emplace_back(to, from, 0, -cost, g[from].size() - 1, true);
    }

    T solve(int src, int dst, const T &f, U &ret){
      using P = std::pair<U, int>;
      ret = 0;
      T flow = f;
      std::vector<U> h(size, 0), cost(size);
      std::vector<bool> is_inf(size, true);
      std::vector<int> prev_node(size), prev_edge(size);
      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      while(flow > 0){
        std::fill(is_inf.begin(), is_inf.end(), true);

        // src -> dst の最小コスト経路を探索する。 (dijkstra algorithm)
        cost[src] = 0;
        pq.emplace(0, src);
        is_inf[src] = false;

        while(!pq.empty()){
          U c;
          int v;
          std::tie(c, v) = pq.top(); pq.pop();

          if(cost[v] < c) continue;
          for(int i = 0; i < (int)g[v].size(); ++i){
            edge &e = g[v][i];
            int w = e.to;
            T cap = e.cap;
            U cst = e.cost;
            if(cap > 0){
              if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){
                is_inf[w] = false;
                cost[w] = cost[v] + cst + h[v] - h[w];
                prev_node[w] = v;
                prev_edge[w] = i;
                pq.emplace(cost[w], w);
              }
            }
          }
        }

        if(is_inf[dst]) return f - flow; // dstへ到達不可能

        for(int i = 0; i < size; ++i) h[i] += cost[i];

        // src -> dst の最小コスト経路へ流せる量(df)を決定する。
        T df = flow;
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);
        }

        flow -= df;
        ret += df * h[dst];

        // capの更新
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          edge &e = g[prev_node[cur]][prev_edge[cur]];
          e.cap -= df;
          g[cur][e.rev].cap += df;
        }
      }

      return f;
    }

    const std::vector<std::vector<edge>>& get_graph(){
      return g;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Flow/minimum_cost_flow.cpp"
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <tuple>

/**
 * @title Minimum cost flow
 * @docs minimum_cost_flow.md
 */
namespace haar_lib {
  template <typename T, typename U>
  class minimum_cost_flow {
  public:
    struct edge {
      int from, to;
      T cap;
      U cost;
      int rev;
      bool is_rev;
      edge(int from, int to, T cap, U cost, int rev, bool is_rev):
        from(from), to(to), cap(cap), cost(cost), rev(rev), is_rev(is_rev){}
    };

  private:
    int size;
    std::vector<std::vector<edge>> g;

  public:
    minimum_cost_flow(int size): size(size), g(size){}

    void add_edge(int from, int to, T cap, U cost){
      g[from].emplace_back(from, to, cap, cost, g[to].size(), false);
      g[to].emplace_back(to, from, 0, -cost, g[from].size() - 1, true);
    }

    T solve(int src, int dst, const T &f, U &ret){
      using P = std::pair<U, int>;
      ret = 0;
      T flow = f;
      std::vector<U> h(size, 0), cost(size);
      std::vector<bool> is_inf(size, true);
      std::vector<int> prev_node(size), prev_edge(size);
      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      while(flow > 0){
        std::fill(is_inf.begin(), is_inf.end(), true);

        // src -> dst の最小コスト経路を探索する。 (dijkstra algorithm)
        cost[src] = 0;
        pq.emplace(0, src);
        is_inf[src] = false;

        while(!pq.empty()){
          U c;
          int v;
          std::tie(c, v) = pq.top(); pq.pop();

          if(cost[v] < c) continue;
          for(int i = 0; i < (int)g[v].size(); ++i){
            edge &e = g[v][i];
            int w = e.to;
            T cap = e.cap;
            U cst = e.cost;
            if(cap > 0){
              if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){
                is_inf[w] = false;
                cost[w] = cost[v] + cst + h[v] - h[w];
                prev_node[w] = v;
                prev_edge[w] = i;
                pq.emplace(cost[w], w);
              }
            }
          }
        }

        if(is_inf[dst]) return f - flow; // dstへ到達不可能

        for(int i = 0; i < size; ++i) h[i] += cost[i];

        // src -> dst の最小コスト経路へ流せる量(df)を決定する。
        T df = flow;
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);
        }

        flow -= df;
        ret += df * h[dst];

        // capの更新
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          edge &e = g[prev_node[cur]][prev_edge[cur]];
          e.cap -= df;
          g[cur][e.rev].cap += df;
        }
      }

      return f;
    }

    const std::vector<std::vector<edge>>& get_graph(){
      return g;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
