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


# :heavy_check_mark: test/aoj/GRL_1_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#52520cdd925fa3dd96b0b332cb95e6a5">test/aoj/GRL_1_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/ShortestPath/warshall_floyd.cpp.html">Warshall-Floyd法</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/warshall_floyd.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s,t,d; std::cin >> s >> t >> d;
    add_edge(g, s, t, d);
  }

  auto res = WarshallFloyd<int>(g);
  
  if(res.has_negative_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(int i = 0; i < V; ++i){
      for(int j = 0; j < V; ++j){
        if(j) std::cout << " ";
        auto &ans = res.dist[i][j];
        if(ans){
          std::cout << *ans;
        }else{
          std::cout << "INF";
        }
      }
      std::cout << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/ShortestPath/warshall_floyd.cpp"
#include <optional>
#line 5 "Mylib/Graph/ShortestPath/warshall_floyd.cpp"

/**
 * @title Warshall-Floyd法
 * @docs warshall_floyd.md
 */
template <typename T>
struct WarshallFloyd{
  const int n;
  std::vector<std::vector<std::optional<T>>> dist;
  bool has_negative_cycle;
  
  WarshallFloyd(const Graph<T> &graph):
    n(graph.size()),
    dist(n, std::vector<std::optional<T>>(n, std::nullopt)),
    has_negative_cycle(false)
  {
    for(int i = 0; i < n; ++i) dist[i][i] = 0;
    
    for(int i = 0; i < n; ++i){
      for(auto &e : graph[i]){
        dist[e.from][e.to] = e.cost;
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] and dist[k][j]){
            if(not dist[i][j]){
              dist[i][j] = *dist[i][k] + *dist[k][j];
            }else{
              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
            }
          }
        }
      }
    }
    
    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;
  }
};
#line 6 "test/aoj/GRL_1_C/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s,t,d; std::cin >> s >> t >> d;
    add_edge(g, s, t, d);
  }

  auto res = WarshallFloyd<int>(g);
  
  if(res.has_negative_cycle){
    std::cout << "NEGATIVE CYCLE" << std::endl;
  }else{
    for(int i = 0; i < V; ++i){
      for(int j = 0; j < V; ++j){
        if(j) std::cout << " ";
        auto &ans = res.dist[i][j];
        if(ans){
          std::cout << *ans;
        }else{
          std::cout << "INF";
        }
      }
      std::cout << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

