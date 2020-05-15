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


# :heavy_check_mark: test/aoj/GRL_1_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#653494e934116182fd158eb8385c6547">test/aoj/GRL_1_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/ShortestPath/dijkstra.cpp.html">Dijkstra法</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    int64_t d; std::cin >> d;
    add_edge(g, s, t, d);
  }

  auto res = Dijkstra<int64_t>(g, r);
  
  for(auto x : res.dist){
    if(not x){
      std::cout << "INF" << std::endl;
    }else{
      std::cout << *x << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

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
#line 3 "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include <optional>
#include <queue>
#include <utility>
#include <functional>
#line 8 "Mylib/Graph/ShortestPath/dijkstra.cpp"

/**
 * @title Dijkstra法
 * @docs dijkstra.md
 */
template <typename T>
class Dijkstra{
public:
  std::vector<std::optional<T>> dist;

private:
  void run(const Graph<T> &graph, std::vector<int> src){
    const int n = graph.size();
    dist.assign(n, std::nullopt);
    
    std::vector<bool> check(n, false);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> pq;

    for(auto s : src){
      dist[s] = 0;
      pq.emplace(0, s);
    }

    while(not pq.empty()){
      const auto [d,i] = pq.top(); pq.pop();

      if(check[i]) continue;
      check[i] = true;

      for(auto &e : graph[i]){
        if(not dist[e.to]){
          dist[e.to] = d + e.cost;
          pq.emplace(*dist[e.to], e.to);
        }else{
          if(*dist[e.to] > d + e.cost){
            dist[e.to] = d + e.cost;
            if(not check[e.to]) pq.emplace(*dist[e.to], e.to);
          }
        }
      }
    }
  }

public:
  Dijkstra(const Graph<T> &graph, int src){run(graph, {src});}
  Dijkstra(const Graph<T> &graph, const std::vector<int> &src){run(graph, src);}
};
#line 6 "test/aoj/GRL_1_A/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int V, E, r; std::cin >> V >> E >> r;

  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    int64_t d; std::cin >> d;
    add_edge(g, s, t, d);
  }

  auto res = Dijkstra<int64_t>(g, r);
  
  for(auto x : res.dist){
    if(not x){
      std::cout << "INF" << std::endl;
    }else{
      std::cout << *x << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

