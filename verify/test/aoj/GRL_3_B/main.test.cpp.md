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


# :heavy_check_mark: test/aoj/GRL_3_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6ed2a74016dcd1e3ddb47125c558f5b0">test/aoj/GRL_3_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_3_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/bridges.cpp.html">Bridges</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/bridges.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0, false, false>(E);

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
#line 8 "test/aoj/GRL_3_B/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0, false, false>(E);

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

