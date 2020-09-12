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


# :x: test/aoj/GRL_3_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f4ad592153fe633f58e350fdd102799a">test/aoj/GRL_3_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_3_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/GraphUtils/strongly_connected_components.cpp.html">Strongly connected components</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<0, true, false>(E);

  auto scc = hl::strongly_connected_components(g).first;

  int q; std::cin >> q;

  for(auto [u, v] : hl::input_tuples<int, int>(q)){
    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_3_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>
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
#line 3 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title Strongly connected components
 * @docs strongly_connected_components.md
 */
namespace haar_lib {
  template <typename T>
  auto strongly_connected_components(const graph<T> &g){
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

    graph<T> rg(n);

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
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
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
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
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
}
#line 7 "test/aoj/GRL_3_C/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<0, true, false>(E);

  auto scc = hl::strongly_connected_components(g).first;

  int q; std::cin >> q;

  for(auto [u, v] : hl::input_tuples<int, int>(q)){
    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
