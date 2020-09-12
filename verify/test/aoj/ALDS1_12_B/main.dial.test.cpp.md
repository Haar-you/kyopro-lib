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


# :x: test/aoj/ALDS1_12_B/main.dial.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a6c8b4021f35786cffddca87bd181284">test/aoj/ALDS1_12_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_12_B/main.dial.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/ShortestPath/dial_algorithm.cpp.html">Dial's algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/ShortestPath/dial_algorithm.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  hl::graph<int> g(n);

  for(int i = 0; i < n; ++i){
    int u, k; std::cin >> u >> k;
    for(int j = 0; j < k; ++j){
      int v, c; std::cin >> v >> c;
      g.add_edge(u, v, c);
    }
  }

  auto ans = hl::dial_algorithm(g, {0}, 100000);

  for(int i = 0; i < n; ++i) std::cout << i << " " << *ans[i] << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_12_B/main.dial.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"

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
#line 3 "Mylib/Graph/ShortestPath/dial_algorithm.cpp"
#include <optional>
#include <stack>
#line 6 "Mylib/Graph/ShortestPath/dial_algorithm.cpp"

/**
 * @title Dial's algorithm
 * @docs dial_algorithm.md
 */
namespace haar_lib {
  auto dial_algorithm(const graph<int> &g, std::vector<int> src, int MAX){
    const int N = g.size();
    std::vector<std::stack<int>> buckets(MAX + 1);
    std::vector<std::optional<int>> ret(N);
    std::vector<bool> check(N);

    for(int i : src){
      ret[i] = 0;
      buckets[0].push(i);
    }

    for(int i = 0; i <= MAX; ++i){
      while(not buckets[i].empty()){
        int cur = buckets[i].top(); buckets[i].pop();

        if(check[cur]) continue;
        check[cur] = true;

        for(auto &e : g[cur]){
          if(not ret[e.to] or *ret[cur] + e.cost < *ret[e.to]){
            ret[e.to] = *ret[cur] + e.cost;
            buckets[*ret[e.to] % (MAX + 1)].push(e.to);
          }
        }
      }
    }

    return ret;
  }
}
#line 6 "test/aoj/ALDS1_12_B/main.dial.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  hl::graph<int> g(n);

  for(int i = 0; i < n; ++i){
    int u, k; std::cin >> u >> k;
    for(int j = 0; j < k; ++j){
      int v, c; std::cin >> v >> c;
      g.add_edge(u, v, c);
    }
  }

  auto ans = hl::dial_algorithm(g, {0}, 100000);

  for(int i = 0; i < n; ++i) std::cout << i << " " << *ans[i] << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

