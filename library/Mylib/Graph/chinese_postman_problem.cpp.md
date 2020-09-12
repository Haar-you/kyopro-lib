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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: Chinese postman problem

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/chinese_postman_problem.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `chinese_postman_problem(g)`
	- すべての辺を一度以上通る閉路の最小距離を返す。
	- Time complexity $O(n^2 2^n)$

## Requirements

## Notes

## Problems

- [AOJ DPL_2_B Chinese Postman Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B)

## References

- [https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E4%BA%BA%E9%83%B5%E4%BE%BF%E9%85%8D%E9%81%94%E5%95%8F%E9%A1%8C](https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E4%BA%BA%E9%83%B5%E4%BE%BF%E9%85%8D%E9%81%94%E5%95%8F%E9%A1%8C)


## Depends on

* :question: <a href="Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../verify/test/aoj/DPL_2_B/main.test.cpp.html">test/aoj/DPL_2_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Chinese postman problem
 * @docs chinese_postman_problem.md
 */
namespace haar_lib {
  template <typename T>
  T chinese_postman_problem(const graph<T> &g){
    const int n = g.size();
    T ret = 0;

    // 頂点間の最短距離を求める。
    std::vector<std::vector<int>> dist(n, std::vector<T>(n, -1));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        if(dist[e.from][e.to] == -1) dist[e.from][e.to] = e.cost;
        else dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] >= 0 and dist[k][j] >= 0){
            if(dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
            else dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }

    // 奇数次数の頂点を列挙
    std::vector<int> odd;
    for(int i = 0; i < n; ++i){
      if(g[i].size() % 2) odd.push_back(i);
    }

    const int m = odd.size();

    // 奇数次数の頂点間の最小マッチングを求める。
    std::vector<T> dp(1 << m, -1);
    dp[0] = 0;

    for(int i = 0; i < (1 << m); ++i){
      for(int j = 0; j < m; ++j){
        for(int k = 0; k < j; ++k){
          if((i & (1 << j)) and (i & (1 << k))){
            if(dp[i] == -1) dp[i] = dp[i ^ (1 << j) ^ (1 << k)] + dist[odd[j]][odd[k]];
            else dp[i] = std::min(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + dist[odd[j]][odd[k]]);
          }
        }
      }
    }

    // 返り値を計算
    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;
    }

    ret += dp[(1 << m) - 1];

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/chinese_postman_problem.cpp"
#include <vector>
#include <algorithm>
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
#line 5 "Mylib/Graph/chinese_postman_problem.cpp"

/**
 * @title Chinese postman problem
 * @docs chinese_postman_problem.md
 */
namespace haar_lib {
  template <typename T>
  T chinese_postman_problem(const graph<T> &g){
    const int n = g.size();
    T ret = 0;

    // 頂点間の最短距離を求める。
    std::vector<std::vector<int>> dist(n, std::vector<T>(n, -1));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        if(dist[e.from][e.to] == -1) dist[e.from][e.to] = e.cost;
        else dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] >= 0 and dist[k][j] >= 0){
            if(dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
            else dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }

    // 奇数次数の頂点を列挙
    std::vector<int> odd;
    for(int i = 0; i < n; ++i){
      if(g[i].size() % 2) odd.push_back(i);
    }

    const int m = odd.size();

    // 奇数次数の頂点間の最小マッチングを求める。
    std::vector<T> dp(1 << m, -1);
    dp[0] = 0;

    for(int i = 0; i < (1 << m); ++i){
      for(int j = 0; j < m; ++j){
        for(int k = 0; k < j; ++k){
          if((i & (1 << j)) and (i & (1 << k))){
            if(dp[i] == -1) dp[i] = dp[i ^ (1 << j) ^ (1 << k)] + dist[odd[j]][odd[k]];
            else dp[i] = std::min(dp[i], dp[i ^ (1 << j) ^ (1 << k)] + dist[odd[j]][odd[k]]);
          }
        }
      }
    }

    // 返り値を計算
    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;
    }

    ret += dp[(1 << m) - 1];

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
