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


# :heavy_check_mark: test/aoj/0575/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#bc5135b351a05eb69baff19bb9fa33f2">test/aoj/0575</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0575/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/Search/parallel_binary_search.cpp.html">Parallel binary search</a>
* :question: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :question: <a href="../../../../library/Mylib/Graph/ShortestPath/dijkstra.cpp.html">Dijkstra algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575"

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/Algorithm/Search/parallel_binary_search.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M, K, Q; std::cin >> N >> M >> K >> Q;

  hl::graph<int> g(N);
  g.read<1, false>(M);

  auto F = hl::input_vector<int>(K);
  for(auto &x : F) x -= 1;

  auto [S, T] = hl::input_tuple_vector<int, int>(Q);
  for(auto &x : S) x -= 1;
  for(auto &x : T) x -= 1;

  auto dist = hl::dijkstra(g, {F});

  std::vector<int> dist_list;
  for(auto &x : dist){
    dist_list.push_back(*x);
  }

  std::sort(dist_list.begin(), dist_list.end());
  dist_list.erase(std::unique(dist_list.begin(), dist_list.end()), dist_list.end());

  const int C = dist_list.size();

  std::vector<std::vector<std::pair<int, int>>> edges(C);
  for(int i = 0; i < N; ++i){
    for(auto &e : g[i]){
      if(*dist[e.from] <= *dist[e.to]){
        int x = std::lower_bound(dist_list.begin(), dist_list.end(), *dist[e.from]) - dist_list.begin();
        edges[x].emplace_back(e.from, e.to);
      }
    }
  }

  hl::unionfind uf;

  auto res =
    hl::parallel_binary_search(
      C,
      Q,
      [&](){uf = hl::unionfind(N);},
      [&](int i){
        for(auto [x, y] : edges[C - 1 - i]){
          uf.merge(x, y);
        }
      },
      [&](int i) -> bool {
        return uf.is_same(S[i], T[i]);
      }
    );

  for(auto x : res){
    std::cout << dist_list[C - x - 1] << "\n";
  }

  return 0;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0575/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575"

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#line 3 "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include <functional>
#line 4 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
namespace haar_lib {
  template <typename T>
  struct edge {
    int from, to;
    T cost;
    int index = -1;
    edge(){}
    edge(int from, int to, T cost): from(from), to(to), cost(cost){}
    edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
  };

  template <typename T>
  struct graph {
    using weight_type = T;
    using edge_type = edge<T>;

    std::vector<std::vector<edge<T>>> data;

    auto& operator[](size_t i){return data[i];}
    const auto& operator[](size_t i) const {return data[i];}

    auto begin() const {return data.begin();}
    auto end() const {return data.end();}

    graph(){}
    graph(int N): data(N){}

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
  using tree = graph<T>;
}
#line 8 "Mylib/Graph/ShortestPath/dijkstra.cpp"

/**
 * @title Dijkstra algorithm
 * @docs dijkstra.md
 */
namespace haar_lib {
  template <typename T>
  auto dijkstra(const graph<T> &graph, std::vector<int> src){
    using P = std::pair<T, int>;

    const int n = graph.size();
    std::vector<std::optional<T>> dist(n);

    std::vector<bool> check(n, false);
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    for(auto s : src){
      dist[s] = 0;
      pq.emplace(0, s);
    }

    while(not pq.empty()){
      const auto [d, i] = pq.top(); pq.pop();

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

    return dist;
  }
}
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>
#line 5 "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Union-find
 * @docs unionfind.md
 */
namespace haar_lib {
  class unionfind {
    int n;
    mutable std::vector<int> parent;
    std::vector<int> depth, size;
    int count;

  public:
    unionfind(){}
    unionfind(int n): n(n), parent(n), depth(n, 1), size(n, 1), count(n){
      std::iota(parent.begin(), parent.end(), 0);
    }

    int root_of(int i) const {
      if(parent[i] == i) return i;
      else return parent[i] = root_of(parent[i]);
    }

    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}

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

    int size_of(int i) const {return size[root_of(i)];}

    int count_groups() const {return count;}

    auto get_groups() const {
      std::vector<std::vector<int>> ret(n);

      for(int i = 0; i < n; ++i){
        ret[root_of(i)].push_back(i);
      }

      ret.erase(
        std::remove_if(
          ret.begin(), ret.end(),
          [](const auto &a){return a.empty();}
        ),
        ret.end()
      );

      return ret;
    }
  };
}
#line 3 "Mylib/Algorithm/Search/parallel_binary_search.cpp"
#include <cmath>

/**
 * @title Parallel binary search
 * @docs parallel_binary_search.md
 */
namespace haar_lib {
  template <typename Init, typename Process, typename Checker>
  auto parallel_binary_search(int M, int Q, Init init, Process process, Checker checker){
    std::vector<int> lb(Q, -1), ub(Q, M);

    while(1){
      bool check = true;
      std::vector<std::vector<int>> mids(M);
      for(int i = 0; i < Q; ++i){
        if(std::abs(lb[i] - ub[i]) > 1){
          check = false;
          int mid = (lb[i] + ub[i]) / 2;
          mids[mid].push_back(i);
        }
      }

      if(check) break;

      init();

      for(int i = 0; i < M; ++i){
        process(i);
        for(int j : mids[i]){
          if(checker(j)){
            ub[j] = i;
          }else{
            lb[j] = i;
          }
        }
      }
    }

    return ub;
  }
}
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuple_vector.cpp"
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  void input_tuple_vector_init(T &val, int N, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0) ...};
  }

  template <typename T, size_t ... I>
  void input_tuple_vector_helper(T &val, int i, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0) ...};
  }

  template <typename ... Args>
  auto input_tuple_vector(int N){
    std::tuple<std::vector<Args> ...> ret;

    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());
    for(int i = 0; i < N; ++i){
      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> input_vector(int N){
    std::vector<T> ret(N);
    for(int i = 0; i < N; ++i) std::cin >> ret[i];
    return ret;
  }

  template <typename T>
  std::vector<std::vector<T>> input_vector(int N, int M){
    std::vector<std::vector<T>> ret(N);
    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
    return ret;
  }
}
#line 13 "test/aoj/0575/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M, K, Q; std::cin >> N >> M >> K >> Q;

  hl::graph<int> g(N);
  g.read<1, false>(M);

  auto F = hl::input_vector<int>(K);
  for(auto &x : F) x -= 1;

  auto [S, T] = hl::input_tuple_vector<int, int>(Q);
  for(auto &x : S) x -= 1;
  for(auto &x : T) x -= 1;

  auto dist = hl::dijkstra(g, {F});

  std::vector<int> dist_list;
  for(auto &x : dist){
    dist_list.push_back(*x);
  }

  std::sort(dist_list.begin(), dist_list.end());
  dist_list.erase(std::unique(dist_list.begin(), dist_list.end()), dist_list.end());

  const int C = dist_list.size();

  std::vector<std::vector<std::pair<int, int>>> edges(C);
  for(int i = 0; i < N; ++i){
    for(auto &e : g[i]){
      if(*dist[e.from] <= *dist[e.to]){
        int x = std::lower_bound(dist_list.begin(), dist_list.end(), *dist[e.from]) - dist_list.begin();
        edges[x].emplace_back(e.from, e.to);
      }
    }
  }

  hl::unionfind uf;

  auto res =
    hl::parallel_binary_search(
      C,
      Q,
      [&](){uf = hl::unionfind(N);},
      [&](int i){
        for(auto [x, y] : edges[C - 1 - i]){
          uf.merge(x, y);
        }
      },
      [&](int i) -> bool {
        return uf.is_same(S[i], T[i]);
      }
    );

  for(auto x : res){
    std::cout << dist_list[C - x - 1] << "\n";
  }

  return 0;
}


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

