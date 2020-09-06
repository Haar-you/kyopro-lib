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


# :x: test/aoj/GRL_2_A/main.kruskal.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#81ed75a9aa7f4e6edc886499b1a67fa4">test/aoj/GRL_2_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_A/main.kruskal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :x: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/kruskal.cpp.html">Kruskal algorithm</a>
* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int64_t> g(V);
  g.read<0, false>(E);

  auto res = kruskal(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost;
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_2_A/main.kruskal.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>
#line 4 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
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
#line 2 "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"
#include <algorithm>
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>

/**
 * @title Union-find
 * @docs unionfind.md
 */
class UnionFind {
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(){}
  UnionFind(int n): parent(n), depth(n, 1), size(n, 1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }

  int root_of(int i){
    if(parent[i] == i) return i;
    else return parent[i] = root_of(parent[i]);
  }

  bool is_same(int i, int j){return root_of(i) == root_of(j);}

  int merge(int i, int j){
    const int ri = root_of(i), rj = root_of(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  int size_of(int i){return size[root_of(i)];}

  int count_group(){return count;}
};
#line 6 "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

/**
 * @title Kruskal algorithm
 * @docs kruskal.md
 */
template <typename T>
std::vector<Edge<T>> kruskal(const Graph<T> &graph){
  const int n = graph.size();
  std::vector<Edge<T>> edges;
  for(auto &v : graph){
    for(auto &e : v){
      edges.push_back(e);
    }
  }

  std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){return a.cost < b.cost;});

  UnionFind uf(n);

  std::vector<Edge<T>> ret;

  for(auto &e : edges){
    if(!uf.is_same(e.from, e.to)){
      uf.merge(e.from, e.to);
      ret.push_back(e);
    }
  }

  return ret;
}
#line 6 "test/aoj/GRL_2_A/main.kruskal.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int64_t> g(V);
  g.read<0, false>(E);

  auto res = kruskal(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost;
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

