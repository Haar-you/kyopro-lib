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


# :x: test/aoj/GRL_5_C/main.doubling.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#502e31dec0efb369b23aee4c6aa81a7e">test/aoj/GRL_5_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_C/main.doubling.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp.html">Lowest common ancestor (Doubling)</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples_with_index.cpp.html">Mylib/IO/input_tuples_with_index.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  for(auto [i, k] : input_tuples_with_index<int>(n)){
    for(auto [c] : input_tuples<int>(k)){
      tree.add_edge(i, c, 1);
    }
  }

  auto lca = LCA(tree, 0);

  int q; std::cin >> q;

  for(auto [u, v] : input_tuples<int, int>(q)){
    std::cout << lca(u, v) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_C/main.doubling.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

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
#line 3 "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"
#include <cmath>
#line 5 "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"

/**
 * @title Lowest common ancestor (Doubling)
 * @docs lca_based_on_doubling.md
 */
template <typename T>
class LCA {
private:
  std::vector<std::vector<int>> parent;
  int n, log2n;

  void dfs(const Tree<T> &tree, int cur, int par, int d){
    parent[cur][0] = par;
    depth[cur] = d;

    for(auto &e : tree[cur]){
      if(e.to != par){
        dist[e.to] = dist[cur] + e.cost;
        dfs(tree, e.to, cur, d + 1);
      }
    }
  }

public:
  std::vector<int> depth;
  std::vector<T> dist;

  LCA(){}
  LCA(const Tree<T> &tree, int root):
    n(tree.size()), depth(n), dist(n)
  {
    log2n = (int)ceil(log2(n)) + 1;
    parent = std::vector(n, std::vector<int>(log2n, 0));

    dfs(tree, root, -1, 0);
    for(int k = 0; k < log2n - 1; ++k){
      for(int v = 0; v < n; ++v){
        if(parent[v][k] == -1) parent[v][k + 1] = -1;
        else parent[v][k + 1] = parent[parent[v][k]][k];
      }
    }
  }

  int lca(int a, int b) const {
    if(depth[a] >= depth[b]) std::swap(a, b);
    for(int k = 0; k < log2n; ++k) if((depth[b] - depth[a]) >> k & 1) b = parent[b][k];
    if(a == b) return a;
    for(int k = log2n - 1; k >= 0; --k) if(parent[a][k] != parent[b][k]){a = parent[a][k]; b = parent[b][k];}
    return parent[a][0];
  }

  int operator()(int a, int b) const {return lca(a, b);}

  T distance(int a, int b) const {
    return dist[a] + dist[b] - 2 * dist[lca(a, b)];
  }
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 8 "Mylib/IO/input_tuples_with_index.cpp"

/**
 * @docs input_tuples_with_index.md
 */
template <typename ... Args>
class InputTuplesWithIndex {
  struct iter {
    using value_type = std::tuple<int, Args ...>;
    value_type value;
    bool fetched = false;
    int N;
    int c = 0;

    value_type operator*(){
      if(not fetched){
        std::tuple<Args ...> temp; std::cin >> temp;
        value = std::tuple_cat(std::make_tuple(c), temp);
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuplesWithIndex(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples_with_index(int N){
  return InputTuplesWithIndex<Args ...>(N);
}
#line 8 "test/aoj/GRL_5_C/main.doubling.test.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  for(auto [i, k] : input_tuples_with_index<int>(n)){
    for(auto [c] : input_tuples<int>(k)){
      tree.add_edge(i, c, 1);
    }
  }

  auto lca = LCA(tree, 0);

  int q; std::cin >> q;

  for(auto [u, v] : input_tuples<int, int>(q)){
    std::cout << lca(u, v) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

