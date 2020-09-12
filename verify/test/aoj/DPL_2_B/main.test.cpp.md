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


# :x: test/aoj/DPL_2_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cea1c4a75215bab49202f95330eeee2b">test/aoj/DPL_2_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_2_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/chinese_postman_problem.cpp.html">Chinese postman problem</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/chinese_postman_problem.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<0, false>(E);

  auto ans = hl::chinese_postman_problem(g);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_2_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B"

#include <iostream>
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>
#line 4 "Mylib/Graph/Template/graph.cpp"

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
#line 3 "Mylib/Graph/chinese_postman_problem.cpp"
#include <algorithm>
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
#line 6 "test/aoj/DPL_2_B/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<0, false>(E);

  auto ans = hl::chinese_postman_problem(g);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
