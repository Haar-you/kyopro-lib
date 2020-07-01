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


# :heavy_check_mark: test/yosupo-judge/scc/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6ffd15f8d9c15c119e35f664edb2d617">test/yosupo-judge/scc</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/scc/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/strongly_connected_components.cpp.html">Strongly connected components</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/TopologicalSort/topological_sort.cpp.html">Topological sort</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto g = convert_to_graph<int, true>(N, input_edges<int, 0, false>(M));

  auto [scc, K] = strongly_connected_components(g);
  std::vector<std::vector<int>> ans(K);
  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);

  Graph<int> g2(K);
  for(auto &v : g){
    for(auto &e : v){
      if(scc[e.from] != scc[e.to]) add_edge(g2, scc[e.from], scc[e.to], 1);
    }
  }

  auto ts = topological_sort(g2).value();

  std::cout << K << "\n";

  for(auto i : ts){
    auto &t = ans[i];
    std::cout << t.size() << " " << join(t.begin(), t.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/scc/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
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
#line 3 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
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
#line 3 "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title Topological sort
 * @docs topological_sort.md
 */
template <typename T>
std::optional<std::vector<int>> topological_sort(const Graph<T> &g){
  const int n = g.size();
  std::vector<int> indeg(n);
  
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      ++indeg[e.to];
    }
  }

  std::queue<int> q;
  for(int i = n-1; i >= 0; --i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    for(auto &e : g[cur]){
      --indeg[e.to];
      if(indeg[e.to] == 0){
        q.push(e.to);
      }
    }
  }

  if((int)ret.size() == n){
    return {ret};
  }else{
    return std::nullopt;
  }
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
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 10 "test/yosupo-judge/scc/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto g = convert_to_graph<int, true>(N, input_edges<int, 0, false>(M));

  auto [scc, K] = strongly_connected_components(g);
  std::vector<std::vector<int>> ans(K);
  for(int i = 0; i < N; ++i) ans[scc[i]].push_back(i);

  Graph<int> g2(K);
  for(auto &v : g){
    for(auto &e : v){
      if(scc[e.from] != scc[e.to]) add_edge(g2, scc[e.from], scc[e.to], 1);
    }
  }

  auto ts = topological_sort(g2).value();

  std::cout << K << "\n";

  for(auto i : ts){
    auto &t = ans[i];
    std::cout << t.size() << " " << join(t.begin(), t.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

