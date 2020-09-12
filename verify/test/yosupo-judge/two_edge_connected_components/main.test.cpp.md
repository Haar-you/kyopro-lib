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


# :x: test/yosupo-judge/two_edge_connected_components/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#caa543e8ce2b504963292c36b66ba2d6">test/yosupo-judge/two_edge_connected_components</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/two_edge_connected_components/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_edge_connected_components">https://judge.yosupo.jp/problem/two_edge_connected_components</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/GraphUtils/two_edge_connected_components.cpp.html">Two edge connected components</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  hl::graph<int> g(N);
  g.read<0, false, false>(M);

  auto res = hl::two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size() << " " << hl::join(v.begin(), v.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/two_edge_connected_components/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

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
#line 3 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include <stack>
#line 5 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"

/**
 * @title Two edge connected components
 * @docs two_edge_connected_components.md
 */
namespace haar_lib {
  namespace two_edge_connected_components_impl {
    template <typename T>
    int dfs(
      const graph<T> &g,
      int cur,
      int par,
      std::vector<int> &low,
      std::vector<int> &order,
      std::vector<std::vector<int>> &ret,
      std::stack<int> &st,
      int &v
    ){
      if(order[cur] != -1) return order[cur];
      order[cur] = v;
      int temp = v++;
      st.push(cur);

      int count = 0;

      for(const auto &e : g[cur]){
        if(e.to == par){
          ++count;
          if(count == 1) continue;
        }

        const int t = dfs(g, e.to, cur, low, order, ret, st, v);
        temp = std::min(temp, t);

        if(low[e.to] > order[cur]){ // e is a bridge
          std::vector<int> cc;
          while(true){
            int c = st.top();
            cc.emplace_back(c);
            st.pop();
            if(c == e.to) break;
          }
          ret.emplace_back(cc);
        }
      }

      return low[cur] = temp;
    }
  }

  template <typename T>
  auto two_edge_connected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<int> low(n, -1), order(n, -1);
    std::vector<std::vector<int>> ret;
    std::stack<int> st;
    int v = 0;

    for(int i = 0; i < n; ++i){
      if(order[i] == -1){
        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st, v);
        if(not st.empty()){
          std::vector<int> cc;
          while(not st.empty()) cc.emplace_back(st.top()), st.pop();
          ret.emplace_back(cc);
        }
      }
    }

    return ret;
  }
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}
#line 7 "test/yosupo-judge/two_edge_connected_components/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  hl::graph<int> g(N);
  g.read<0, false, false>(M);

  auto res = hl::two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size() << " " << hl::join(v.begin(), v.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

