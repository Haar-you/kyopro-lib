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


# :x: test/yosupo-judge/cycle_detection/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#d8762cb07fdbe3ea6b92987121bbcbe6">test/yosupo-judge/cycle_detection</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/cycle_detection/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 06:29:03+09:00




## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Cycle/detect_cycle.cpp.html">Detect cycle</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#define IGNORE

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/Cycle/detect_cycle.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  hl::graph<int> g(N);
  g.read<0, true, false>(M);

  auto res = hl::detect_cycle(g);

  if(res){
    std::cout << (*res).size() << "\n";
    for(auto &e : *res){
      std::cout << e.index << "\n";
    }
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/cycle_detection/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#define IGNORE

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
#line 2 "Mylib/Graph/Cycle/detect_cycle.cpp"
#include <optional>
#line 4 "Mylib/Graph/Cycle/detect_cycle.cpp"
#include <algorithm>
#line 6 "Mylib/Graph/Cycle/detect_cycle.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
namespace haar_lib {
  namespace detect_cycle_impl {
    constexpr static int SEARCHED = 1;
    constexpr static int SEARCHING = 2;

    template <typename T>
    std::optional<int> rec(
      const graph<T> &g,
      int cur,
      std::vector<edge<T>> &temp,
      std::vector<edge<T>> &ret,
      std::vector<int> &check
    ){
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto &e : g[cur]){
        temp.push_back(e);

        if(auto res = rec(g, e.to, temp, ret, check); res){
          if(*res != -1){
            ret.push_back(e);
            if(*res == cur){
              return {-1};
            }
          }

          return res;
        }

        temp.pop_back();
      }

      check[cur] = SEARCHED;

      return std::nullopt;
    }
  }

  template <typename T>
  std::optional<std::vector<edge<T>>> detect_cycle(const graph<T> &g){
    const int N = g.size();
    std::vector<int> check(N);

    for(int i = 0; i < N; ++i){
      if(check[i] == 0){
        std::vector<edge<T>> temp, ret;
        detect_cycle_impl::rec(g, i, temp, ret, check);
        if(not ret.empty()){
          std::reverse(ret.begin(), ret.end());
          return {ret};
        }
      }
    }

    return std::nullopt;
  }
}
#line 7 "test/yosupo-judge/cycle_detection/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;
  hl::graph<int> g(N);
  g.read<0, true, false>(M);

  auto res = hl::detect_cycle(g);

  if(res){
    std::cout << (*res).size() << "\n";
    for(auto &e : *res){
      std::cout << e.index << "\n";
    }
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
