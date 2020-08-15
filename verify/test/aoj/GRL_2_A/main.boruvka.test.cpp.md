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


# :heavy_check_mark: test/aoj/GRL_2_A/main.boruvka.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#81ed75a9aa7f4e6edc886499b1a67fa4">test/aoj/GRL_2_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_A/main.boruvka.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-12 01:35:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/boruvka.cpp.html">Borůvka algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/boruvka.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int64_t, false>(V, input_edges<int64_t, 0, true>(E));

  auto res = boruvka(g);

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
#line 1 "test/aoj/GRL_2_A/main.boruvka.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

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
#line 2 "Mylib/Graph/MinimumSpanningTree/boruvka.cpp"

#line 4 "Mylib/Graph/MinimumSpanningTree/boruvka.cpp"
#include <utility>

#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>

/**
 * @title Union-find
 * @docs unionfind.md
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(){}
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  int root_of(int i){
    if(parent[i] == i) return i;
    else return parent[i] = root_of(parent[i]);
  }
  
  bool is_same(int i, int j){return root_of(i) == root_of(j);}

  int merge(int i, int j){
    int ri = root_of(i), rj = root_of(j);
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
#line 8 "Mylib/Graph/MinimumSpanningTree/boruvka.cpp"

/**
 * @title Borůvka algorithm
 * @docs boruvka.md
 */
template <typename T>
auto boruvka(const Graph<T> &g){
  std::vector<Edge<T>> ret;
  const int N = g.size();

  UnionFind uf(N);
  std::vector<std::vector<int>> c(N);
  for(int i = 0; i < N; ++i) c[i].push_back(i);

  while((int)(ret.size()) < N - 1){
    std::vector<Edge<T>> temp;

    for(auto &a : c){
      Edge<T> m;
      bool ok = false;

      if(a.empty()) continue;

      for(auto i : a){
        for(auto &e : g[i]){
          if(uf.is_same(e.from, e.to)) continue;
          if(not std::exchange(ok, true) or e.cost < m.cost){
            m = e;
          }
        }
      }
      
      temp.push_back(m);
    }

    for(auto &e : temp){
      if(uf.is_same(e.from, e.to)) continue;

      const int i = uf.root_of(e.from);
      const int j = uf.root_of(e.to);
      const int k = uf.merge(i, j);

      if(c[i].size() < c[j].size()) std::swap(c[i], c[j]);

      c[i].insert(c[i].end(), c[j].begin(), c[j].end());
      c[j].clear();

      std::swap(c[k], c[i]);

      ret.push_back(e);
    }
  }

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
#line 7 "test/aoj/GRL_2_A/main.boruvka.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int64_t, false>(V, input_edges<int64_t, 0, true>(E));

  auto res = boruvka(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost; 
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

