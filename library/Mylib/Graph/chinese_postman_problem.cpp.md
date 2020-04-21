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


# :heavy_check_mark: 中国人郵便配達問題

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/chinese_postman_problem.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 09:17:56+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_B/main.test.cpp.html">test/aoj/DPL_2_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 中国人郵便配達問題
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B
 * @attention 時間計算量 O(n^2 2^n)
 */
template <typename T> T chinese_postman_problem(const Graph<T> &g){
  int n = g.size();
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

  int m = odd.size();

  // 奇数次数の頂点間の最小マッチングを求める。
  std::vector<T> dp(1<<m, -1);
  dp[0] = 0;

  for(int i = 0; i < (1<<m); ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < j; ++k){
        if((i & (1<<j)) and (i & (1<<k))){
          if(dp[i] == -1) dp[i] = dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]];
          else dp[i] = std::min(dp[i], dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]]);
        }
      }
    }
  }

  // 返り値を計算
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;
  }

  ret += dp[(1<<m)-1];

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/chinese_postman_problem.cpp"
#include <vector>
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
#line 5 "Mylib/Graph/chinese_postman_problem.cpp"

/**
 * @title 中国人郵便配達問題
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B
 * @attention 時間計算量 O(n^2 2^n)
 */
template <typename T> T chinese_postman_problem(const Graph<T> &g){
  int n = g.size();
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

  int m = odd.size();

  // 奇数次数の頂点間の最小マッチングを求める。
  std::vector<T> dp(1<<m, -1);
  dp[0] = 0;

  for(int i = 0; i < (1<<m); ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < j; ++k){
        if((i & (1<<j)) and (i & (1<<k))){
          if(dp[i] == -1) dp[i] = dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]];
          else dp[i] = std::min(dp[i], dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]]);
        }
      }
    }
  }

  // 返り値を計算
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;
  }

  ret += dp[(1<<m)-1];

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

