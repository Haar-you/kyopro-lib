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


# :x: test/aoj/GRL_3_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6ed2a74016dcd1e3ddb47125c558f5b0">test/aoj/GRL_3_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_3_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/GraphUtils/bridges.cpp.html">Bridges</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/bridges.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, false>(V, input_edges<int, 0, false>(E));

  auto ans = bridges(g);
  for(auto &e : ans) if(e.from > e.to) std::swap(e.from, e.to);
  
  std::sort(
    ans.begin(), ans.end(),
    [](const auto &a, const auto &b){
      if(a.from != b.from) return a.from < b.from;
      return a.to < b.to;
    }
  );

  for(auto &e :ans) std::cout << e.from << " " << e.to << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_3_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>
#include <algorithm>
#include <utility>
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
#line 5 "Mylib/Graph/GraphUtils/bridges.cpp"

/**
 * @title Bridges
 * @docs bridges.md
 */
template <typename T>
auto bridges(const Graph<T> &graph){
  const int n = graph.size();
  std::vector<int> visit(n,-1), low(n,-1);
  std::vector<Edge<T>> ret;
  int v = 0;
  auto dfs =
    [&](auto &dfs, int cur, int par) -> int{
      if(visit[cur] != -1) return visit[cur];
      visit[cur] = v;
      int temp = v;
      ++v;
      for(auto &e : graph[cur]){
        if(e.to == par) continue;
        int t = dfs(dfs, e.to, cur);
        temp = std::min(temp, t);
        if(low[e.to] > visit[cur]) ret.push_back(e);
      }  
      return low[cur] = temp;
    };

  for(int i = 0; i < n; ++i) if(visit[i] == -1) dfs(dfs, i, -1);
  return ret;
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
#line 9 "test/aoj/GRL_3_B/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, false>(V, input_edges<int, 0, false>(E));

  auto ans = bridges(g);
  for(auto &e : ans) if(e.from > e.to) std::swap(e.from, e.to);
  
  std::sort(
    ans.begin(), ans.end(),
    [](const auto &a, const auto &b){
      if(a.from != b.from) return a.from < b.from;
      return a.to < b.to;
    }
  );

  for(auto &e :ans) std::cout << e.from << " " << e.to << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

