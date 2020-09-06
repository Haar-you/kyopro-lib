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


# :x: test/yukicoder/1069/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ccfa4ccd38c1e74c4be79e9bb8104f4d">test/yukicoder/1069</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/1069/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="https://yukicoder.me/problems/no/1069">https://yukicoder.me/problems/no/1069</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/ShortestPath/yen_algorithm.cpp.html">Yen's algorithm</a>
* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1069"
#define ERROR 1e-4

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Graph/ShortestPath/yen_algorithm.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M, K, X, Y; std::cin >> N >> M >> K >> X >> Y;
  --X, --Y;

  auto [p, q] = input_tuple_vector<long double, long double>(N);

  Graph<long double> g(N);
  for(auto [P, Q] : input_tuples<int, int>(M)){
    --P, --Q;

    long double dx = p[P] - p[Q];
    long double dy = q[P] - q[Q];

    long double L = std::sqrt(dx * dx + dy * dy);

    g.add_undirected(P, Q, L);
  }

  auto res = yen_algorithm(g, X, Y, K);

  for(auto x : res){
    if(not x){
      std::cout << -1 << "\n";
    }else{
      std::cout << std::fixed << std::setprecision(12) << x->first << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/1069/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1069"
#define ERROR 1e-4

#include <iostream>
#include <iomanip>
#include <cmath>
#line 3 "Mylib/IO/input_tuple_vector.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
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
#line 4 "Mylib/Graph/ShortestPath/yen_algorithm.cpp"
#include <optional>
#include <queue>
#include <functional>
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
#line 8 "Mylib/Graph/ShortestPath/yen_algorithm.cpp"

/**
 * @title Yen's algorithm
 * @docs yen_algorithm.md
 */
namespace yen_algorithm_impl {
  template <typename T>
  auto shortest_path(
    const Graph<T> &g,
    int from,
    int t,
    const std::vector<bool> &usable,
    const std::vector<std::vector<bool>> &valid
  ){
    using Path = std::pair<T, std::vector<int>>;
    using P = std::pair<T, int>;

    const int N = g.size();
    std::vector<bool> visited(N, false);
    std::vector<std::optional<T>> dist(N);
    std::vector<std::pair<int, int>> restore(N);

    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    dist[from] = 0;
    pq.emplace(0, from);

    while(not pq.empty()){
      auto [d, i] = pq.top(); pq.pop();

      if(visited[i]) continue;
      visited[i] = true;

      for(int k = 0; k < (int)g[i].size(); ++k){
        if(not valid[i][k] or not usable[g[i][k].to]) continue;
        auto &e = g[i][k];

        if(not dist[e.to] or *dist[e.to] > d + e.cost){
          dist[e.to] = d + e.cost;
          restore[e.to] = std::make_pair(i, k);
          if(not visited[e.to]) pq.emplace(*dist[e.to], e.to);
         }
      }
    }

    std::optional<Path> ret;

    if(dist[t]){
      std::vector<int> p;

      int cur = t;
      while(cur != from){
        auto [i, j] = restore[cur];
        p.push_back(j);
        cur = i;
      }

      std::reverse(p.begin(), p.end());

      ret = std::make_pair(*dist[t], p);
    }

    return ret;
  }
}

template <typename T>
auto yen_algorithm(const Graph<T> &g, int s, int t, int K){
  using Path = std::pair<T, std::vector<int>>;

  const int N = g.size();

  std::vector<std::vector<bool>> valid(N);
  std::vector<std::optional<Path>> result(K);
  std::priority_queue<Path, std::vector<Path>, std::greater<Path>> stock;

  for(int i = 0; i < N; ++i){
    valid[i].assign(g[i].size(), true);
  }

  for(int i = 0; i < K; ++i){
    if(i == 0){
      std::vector<bool> usable(N, true);
      if(auto res = yen_algorithm_impl::shortest_path(g, s, t, usable, valid); res) stock.push(*res);
    }else{
      std::vector<int> prev_path;

      {
        int cur = s;
        for(auto u : result[i - 1]->second){
          prev_path.push_back(cur);
          cur = g[cur][u].to;
        }
        prev_path.push_back(t);
      }

      std::vector<bool> check(i, true);
      std::vector<bool> usable(N, true);

      for(int k = 0; k < (int)prev_path.size() - 1; ++k){
        const int u = prev_path[k];

        for(int j = 0; j < i; ++j){
          if(check[j]){
            valid[prev_path[k]][result[j]->second[k]] = false;
          }
        }

        if(auto res = yen_algorithm_impl::shortest_path(g, u, t, usable, valid); res){
          auto [c, p] = *res;

          std::vector<int> temp;
          for(int j = 0; j < k; ++j){
            int v = result[i - 1]->second[j];

            c += g[prev_path[j]][v].cost;
            temp.push_back(v);
          }

          temp.insert(temp.end(), p.begin(), p.end());
          stock.emplace(c, temp);
        }

        usable[u] = false;

        for(int j = 0; j < i; ++j){
          if(check[j]){
            valid[prev_path[k]][result[j]->second[k]] = true;
          }
        }

        for(int j = 0; j < i; ++j){
          if(check[j]){
            if(prev_path[k + 1] != g[prev_path[k]][result[j]->second[k]].to){
              check[j] = false;
            }
          }
        }
      }
    }

    if(stock.empty()) break;

    result[i] = stock.top(); stock.pop();

    while(not stock.empty() and stock.top() == result[i]){
      stock.pop();
    }
  }

  return result;
}
#line 10 "test/yukicoder/1069/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M, K, X, Y; std::cin >> N >> M >> K >> X >> Y;
  --X, --Y;

  auto [p, q] = input_tuple_vector<long double, long double>(N);

  Graph<long double> g(N);
  for(auto [P, Q] : input_tuples<int, int>(M)){
    --P, --Q;

    long double dx = p[P] - p[Q];
    long double dy = q[P] - q[Q];

    long double L = std::sqrt(dx * dx + dy * dy);

    g.add_undirected(P, Q, L);
  }

  auto res = yen_algorithm(g, X, Y, K);

  for(auto x : res){
    if(not x){
      std::cout << -1 << "\n";
    }else{
      std::cout << std::fixed << std::setprecision(12) << x->first << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

