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


# :x: test/yosupo-judge/cycle_detection/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#d8762cb07fdbe3ea6b92987121bbcbe6">test/yosupo-judge/cycle_detection</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/cycle_detection/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-18 02:27:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/cycle_detection">https://judge.yosupo.jp/problem/cycle_detection</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Cycle/detect_cycle.cpp.html">Detect cycle</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/Graph/Cycle/detect_cycle.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  auto edges = input_edges<int, 0, false>(M);

  auto res = detect_cycle(N, M, edges);

  if(res){
    std::cout << (*res).size() << "\n";
    for(auto x : *res){
      std::cout << x << "\n";
    }
  }else{
    std::cout << -1 << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/cycle_detection/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

/**
 * @title Graph template
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
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}
#line 2 "Mylib/Graph/Cycle/detect_cycle.cpp"
#include <optional>
#line 4 "Mylib/Graph/Cycle/detect_cycle.cpp"
#include <algorithm>
#line 6 "Mylib/Graph/Cycle/detect_cycle.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
template <typename T>
std::optional<std::vector<int>> detect_cycle(int V, int E, std::vector<Edge<T>> edges){
  std::vector<std::vector<std::pair<Edge<T>, int>>> g(V);
  std::vector<int> check(V);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  for(int i = 0; i < E; ++i){
    g[edges[i].from].emplace_back(edges[i], i);
  }

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp, std::vector<int> &ret) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto [e, i] : g[cur]){
        temp.push_back(i);

        if(auto res = rec(rec, e.to, temp, ret); res){
          if(*res != -1){
            ret.push_back(i);
            if(*res == cur){
              return {-1};
            }
          }
          
          return res;
        }

        temp.pop_back();
      }

      check[cur] = SEARCHED;
      
      return std::nullopt;
    };

  for(int i = 0; i < V; ++i){
    if(check[i] == 0){
      std::vector<int> temp, ret;
      rec(rec, i, temp, ret);
      if(not ret.empty()){
        std::reverse(ret.begin(), ret.end());
        return {ret};
      }
    }
  }

  return std::nullopt;
}
#line 6 "test/yosupo-judge/cycle_detection/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  auto edges = input_edges<int, 0, false>(M);

  auto res = detect_cycle(N, M, edges);

  if(res){
    std::cout << (*res).size() << "\n";
    for(auto x : *res){
      std::cout << x << "\n";
    }
  }else{
    std::cout << -1 << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

