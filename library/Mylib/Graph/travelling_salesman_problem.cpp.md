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


# :heavy_check_mark: 巡回セールスマン問題

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/travelling_salesman_problem.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_A/main.test.cpp.html">test/aoj/DPL_2_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 巡回セールスマン問題
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
 * @attention 時間計算量 O(n^2 2^n)
 */
template <typename Cost>
std::optional<Cost> travelling_salesman_problem(const Graph<Cost> &g, int src){
  const int n = g.size();

  std::vector<std::vector<std::optional<Cost>>> dp(n, std::vector<std::optional<Cost>>(1<<n));

  for(auto &e : g[src]){
    if(not dp[e.to][1 << e.to]){
      dp[e.to][1 << e.to] = e.cost;
    }else{
      dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);
    }
  }

  for(int s = 1; s < (1<<n); ++s){
    for(int i = 0; i < n; ++i){
      if(not (s & (1<<i))) continue;

      for(auto &e : g[i]){
        if(s & (1<<e.to)) continue;

        if(dp[i][s]){
          if(not dp[e.to][s | (1<<e.to)]){
            dp[e.to][s | (1<<e.to)] = *dp[i][s] + e.cost;
          }else{
            dp[e.to][s | (1<<e.to)] = std::min(*dp[e.to][s | (1<<e.to)], *dp[i][s] + e.cost);
          }
        }
      }
    }
  }

  return dp[src][(1<<n)-1];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/travelling_salesman_problem.cpp"
#include <vector>
#include <optional>
#include <algorithm>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title グラフ用テンプレート
 */
template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}
#line 6 "Mylib/Graph/travelling_salesman_problem.cpp"

/**
 * @title 巡回セールスマン問題
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
 * @attention 時間計算量 O(n^2 2^n)
 */
template <typename Cost>
std::optional<Cost> travelling_salesman_problem(const Graph<Cost> &g, int src){
  const int n = g.size();

  std::vector<std::vector<std::optional<Cost>>> dp(n, std::vector<std::optional<Cost>>(1<<n));

  for(auto &e : g[src]){
    if(not dp[e.to][1 << e.to]){
      dp[e.to][1 << e.to] = e.cost;
    }else{
      dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);
    }
  }

  for(int s = 1; s < (1<<n); ++s){
    for(int i = 0; i < n; ++i){
      if(not (s & (1<<i))) continue;

      for(auto &e : g[i]){
        if(s & (1<<e.to)) continue;

        if(dp[i][s]){
          if(not dp[e.to][s | (1<<e.to)]){
            dp[e.to][s | (1<<e.to)] = *dp[i][s] + e.cost;
          }else{
            dp[e.to][s | (1<<e.to)] = std::min(*dp[e.to][s | (1<<e.to)], *dp[i][s] + e.cost);
          }
        }
      }
    }
  }

  return dp[src][(1<<n)-1];
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

