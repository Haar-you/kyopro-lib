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
    - Last commit date: 2020-06-19 17:32:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/Search/parallel_binary_search.cpp.html">Parallel binary search</a>
* :question: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/ShortestPath/dijkstra.cpp.html">Dijkstra algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
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

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/Algorithm/Search/parallel_binary_search.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M, K, Q; std::cin >> N >> M >> K >> Q;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 1, true>(M));

  auto F = input_vector<int>(K);
  for(auto &x : F) x -= 1;

  auto [S, T] = input_tuple_vector<int, int>(Q);
  for(auto &x : S) x -= 1;
  for(auto &x : T) x -= 1;

  auto dist = Dijkstra(g, F).dist;

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

  auto res =
    parallel_binary_search(
      C,
      Q,
      [&, S = S, T = T](const auto &f){
        UnionFind uf(N);
        f(
          [&](int i){
            for(auto [x, y] : edges[C-1-i]){
              uf.merge(x, y);
            }
          },
          [&, S = S, T = T](int i) -> bool{
            return uf.is_same(S[i], T[i]);
          }
        );
      }
    );
  
  for(auto x : res){
    std::cout << dist_list[C-x-1] << "\n";
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
#line 3 "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include <functional>
#line 8 "Mylib/Graph/ShortestPath/dijkstra.cpp"

/**
 * @title Dijkstra algorithm
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
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  inline int get_root(int i){
    if(parent[i] == i) return i;
    else return parent[i] = get_root(parent[i]);
  }
  
  inline bool is_same(int i, int j){return get_root(i) == get_root(j);}

  inline int merge(int i, int j){
    int ri = get_root(i), rj = get_root(j);
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

  inline int get_size(int i){return size[get_root(i)];}

  inline int count_group(){return count;}
};
#line 3 "Mylib/Algorithm/Search/parallel_binary_search.cpp"
#include <cmath>

/**
 * @title Parallel binary search
 * @docs parallel_binary_search.md
 */
template <typename F>
auto parallel_binary_search(int M, int Q, F f){
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

    f(
      [&](auto process, auto checker){
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
    );
  }

  return ub;
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
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
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
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuple_vector.cpp"
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
template <typename T, size_t ... I>
void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0)...};
}

template <typename T, size_t ... I>
void input_tuple_vector_helper(T &val, int i, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0)...};
}

template <typename ... Args>
auto input_tuple_vector(int N){
  std::tuple<std::vector<Args>...> ret;

  input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());
  for(int i = 0; i < N; ++i){
    input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());
  }

  return ret;
}
#line 15 "test/aoj/0575/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M, K, Q; std::cin >> N >> M >> K >> Q;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 1, true>(M));

  auto F = input_vector<int>(K);
  for(auto &x : F) x -= 1;

  auto [S, T] = input_tuple_vector<int, int>(Q);
  for(auto &x : S) x -= 1;
  for(auto &x : T) x -= 1;

  auto dist = Dijkstra(g, F).dist;

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

  auto res =
    parallel_binary_search(
      C,
      Q,
      [&, S = S, T = T](const auto &f){
        UnionFind uf(N);
        f(
          [&](int i){
            for(auto [x, y] : edges[C-1-i]){
              uf.merge(x, y);
            }
          },
          [&, S = S, T = T](int i) -> bool{
            return uf.is_same(S[i], T[i]);
          }
        );
      }
    );
  
  for(auto x : res){
    std::cout << dist_list[C-x-1] << "\n";
  }  
  
  return 0;
}


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

