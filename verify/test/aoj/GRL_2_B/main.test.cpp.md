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


# :heavy_check_mark: test/aoj/GRL_2_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8a44cfd2c1cd011629cace42f57a6853">test/aoj/GRL_2_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/strongly_connected_components.cpp.html">Strongly connected components</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp.html">Chu-Liu/Edmonds algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"

int main() {
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int> g(V);
  g.read<0>(E);

  auto res = ChuLiuEdmonds<int>::solve(g, r);

  int ans = 0;

  for(auto &e : res){
    ans += e.cost;
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_2_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include <iostream>
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
  using weight_type = T;
  using edge_type = Edge<T>;
  
  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}
  
  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
#line 3 "Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title Strongly connected components
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
 * @title Chu-Liu/Edmonds algorithm
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
        G.add_edge(s[e.from], s[e.to], e.cost);
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
        rg.add_edge(e.to, e.from, e.cost);
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
#line 6 "test/aoj/GRL_2_B/main.test.cpp"

int main() {
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int> g(V);
  g.read<0>(E);

  auto res = ChuLiuEdmonds<int>::solve(g, r);

  int ans = 0;

  for(auto &e : res){
    ans += e.cost;
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

