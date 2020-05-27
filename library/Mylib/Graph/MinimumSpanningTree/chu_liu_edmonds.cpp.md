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


# :heavy_check_mark: Chu-Liu/Edmonds

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-27 18:33:06+09:00




## Operations

- `solve(g, r)`
	- `r`を根とする`g`の最小有向全域木の辺集合を返す。
	- Time complexity $O(VE)$

## Requirements

## Notes

## Problems

## References

- [https://ark4rk.hatenablog.com/entry/2017/09/15/011937](https://ark4rk.hatenablog.com/entry/2017/09/15/011937)
- [http://www.prefield.com/algorithm/graph/chu-liu-edmonds.html](http://www.prefield.com/algorithm/graph/chu-liu-edmonds.html)
- [http://ti2236.hatenablog.com/entry/2012/12/07/175841](http://ti2236.hatenablog.com/entry/2012/12/07/175841)


## Depends on

* :heavy_check_mark: <a href="../GraphUtils/strongly_connected_components.cpp.html">強連結成分分解</a>
* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_2_B/main.test.cpp.html">test/aoj/GRL_2_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title Chu-Liu/Edmonds
 * @docs chu_liu_edmonds.md
 */
template <typename T>
class ChuLiuEdmonds{
  static Graph<T> rec(Graph<T> g, int r){
    const int N = g.size();

    Graph<T> in_edges(N);
    
    for(int i = 0; i < N; ++i){
      if(i != r){
        auto e = *std::min_element(g[i].begin(), g[i].end(),
          [](const auto &a, const auto &b){
            return a.cost < b.cost;
          }
        );

        in_edges[i].push_back(e);
      }
    }

    const auto [s, m] = strongly_connected_components(in_edges);

    std::vector<std::vector<int>> v(m);
    for(int i = 0; i < N; ++i){
      v[s[i]].push_back(i);
    }

    int count_cycle = 0;
    for(int i = 0; i < m; ++i){
      if(v[i].size() > 1){
        for(int j : v[i]){
          auto c =
            *std::min_element(
              g[j].begin(), g[j].end(),
              [](const auto &a, const auto &b){return a.cost < b.cost;}
            );
          
          for(auto &e : g[j]){
            e.cost -= c.cost;
          }
        }
        ++count_cycle;
      }
    }

    if(count_cycle == 0){
      return in_edges;
    }

    Graph<T> G(m);
    const int R = s[r];
    for(int i = 0; i < N; ++i){
      for(auto &e : g[i]){
        if(s[e.from] == s[e.to]) continue;
        add_edge(G, s[e.from], s[e.to], e.cost);
      }
    }

    auto res = rec(G, R);

    for(int i = 0; i < m; ++i){
      if(i == R) continue;

      int j = res[i][0].to;

      std::vector<Edge<T>> c;

      for(int x : v[i]){
        for(auto &e : g[x]){
          if(s[e.to] == j){
            c.push_back(e);
          }
        }
      }

      auto e =
        *std::min_element(
          c.begin(), c.end(),
          [](const auto &a, const auto &b){return a.cost < b.cost;}
        );

      in_edges[e.from][0] = e;
    }

    return in_edges;
  }

public:
  static auto solve(Graph<T> g, int r){
    std::vector<Edge<T>> ret;
    
    const int N = g.size();
    
    Graph<T> rg(N);
    for(int i = 0; i < N; ++i){
      for(auto &e : g[i]){
        add_edge(rg, e.to, e.from, e.cost);
      }
    }

    auto res = rec(rg, r);

    for(int i = 0; i < N; ++i){
      if(i != r){

        std::vector<T> c;

        for(auto &e : rg[i]){
          if(e.to == res[i][0].to){
            c.push_back(e.cost);
          }
        }
        
        ret.emplace_back(res[i][0].to, i, *std::min_element(c.begin(), c.end()));
      }
    }

    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"
#include <vector>
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
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title 強連結成分分解
 * @docs strongly_connected_components.md
 */
template <typename T>
auto strongly_connected_components(const Graph<T> &g){
  const int n = g.size();

  std::vector<bool> visit(n);
  std::vector<int> check(n);
  std::vector<int> result(n, -1);

  auto dfs =
    [&](auto &f, int cur) -> void {
      visit[cur] = true;
      for(const auto &e : g[cur]){
        if(not visit[e.to]) f(f, e.to);
      }
      check.push_back(cur);
    };

  for(int i = 0; i < n; ++i) if(not visit[i]) dfs(dfs, i);

  std::reverse(check.begin(), check.end());

  Graph<T> rg(n);

  auto rdfs =
    [&](auto &f, int cur, int i) -> void {
      result[cur] = i;
      for(const auto &e : rg[cur]){
        if(result[e.to] == -1) f(f, e.to, i);
      }
    };

  for(int i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from, e.cost);

  int i = 0;
  for(auto c : check) if(result[c] == -1) rdfs(rdfs, c, i), ++i;

  
  return std::make_pair(result, i);
}
#line 6 "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"

/**
 * @title Chu-Liu/Edmonds
 * @docs chu_liu_edmonds.md
 */
template <typename T>
class ChuLiuEdmonds{
  static Graph<T> rec(Graph<T> g, int r){
    const int N = g.size();

    Graph<T> in_edges(N);
    
    for(int i = 0; i < N; ++i){
      if(i != r){
        auto e = *std::min_element(g[i].begin(), g[i].end(),
          [](const auto &a, const auto &b){
            return a.cost < b.cost;
          }
        );

        in_edges[i].push_back(e);
      }
    }

    const auto [s, m] = strongly_connected_components(in_edges);

    std::vector<std::vector<int>> v(m);
    for(int i = 0; i < N; ++i){
      v[s[i]].push_back(i);
    }

    int count_cycle = 0;
    for(int i = 0; i < m; ++i){
      if(v[i].size() > 1){
        for(int j : v[i]){
          auto c =
            *std::min_element(
              g[j].begin(), g[j].end(),
              [](const auto &a, const auto &b){return a.cost < b.cost;}
            );
          
          for(auto &e : g[j]){
            e.cost -= c.cost;
          }
        }
        ++count_cycle;
      }
    }

    if(count_cycle == 0){
      return in_edges;
    }

    Graph<T> G(m);
    const int R = s[r];
    for(int i = 0; i < N; ++i){
      for(auto &e : g[i]){
        if(s[e.from] == s[e.to]) continue;
        add_edge(G, s[e.from], s[e.to], e.cost);
      }
    }

    auto res = rec(G, R);

    for(int i = 0; i < m; ++i){
      if(i == R) continue;

      int j = res[i][0].to;

      std::vector<Edge<T>> c;

      for(int x : v[i]){
        for(auto &e : g[x]){
          if(s[e.to] == j){
            c.push_back(e);
          }
        }
      }

      auto e =
        *std::min_element(
          c.begin(), c.end(),
          [](const auto &a, const auto &b){return a.cost < b.cost;}
        );

      in_edges[e.from][0] = e;
    }

    return in_edges;
  }

public:
  static auto solve(Graph<T> g, int r){
    std::vector<Edge<T>> ret;
    
    const int N = g.size();
    
    Graph<T> rg(N);
    for(int i = 0; i < N; ++i){
      for(auto &e : g[i]){
        add_edge(rg, e.to, e.from, e.cost);
      }
    }

    auto res = rec(rg, r);

    for(int i = 0; i < N; ++i){
      if(i != r){

        std::vector<T> c;

        for(auto &e : rg[i]){
          if(e.to == res[i][0].to){
            c.push_back(e.cost);
          }
        }
        
        ret.emplace_back(res[i][0].to, i, *std::min_element(c.begin(), c.end()));
      }
    }

    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

