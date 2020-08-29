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


# :heavy_check_mark: test/aoj/2891/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8c3e2a047e69e0e27426b8794b30b6b7">test/aoj/2891</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2891/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/decompose_pseudotree.cpp.html">Decompose pseudotree</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"

int main(){
  int N; std::cin >> N;

  Graph<int> g(N);
  g.read<1, false, false>(N);

  auto res = PseudoTree<int>(g);

  int Q; std::cin >> Q;
  for(auto [a, b] : input_tuples<int, int>(Q)){
    --a, --b;

    if(res.in_loop[a] and res.in_loop[b]){
      std::cout << 2 << "\n";
    }else{
      std::cout << 1 << "\n"; 
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2891/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"

#include <iostream>
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
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
#line 3 "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"
#include <queue>
#line 5 "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"

/**
 * @title Decompose pseudotree
 * @docs decompose_pseudotree.md
 */
template <typename T>
struct PseudoTree{
  const int n;
  std::vector<bool> in_loop;
  std::vector<int> group;

  void dfs(int cur, int par, const Graph<T> &g){
    group[cur] = group[par];

    for(auto &e : g[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, g);
    }
  }
  
  PseudoTree(const Graph<T> &g): n(g.size()), in_loop(n, true), group(n){
    std::vector<int> indeg(n);
    std::vector<bool> visited(n);
    std::queue<int> q;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        ++indeg[e.to];
      }
    }

    for(int i = 0; i < n; ++i){
      if(indeg[i] == 1){
        q.push(i);
      }
    }

    while(not q.empty()){
      int cur = q.front(); q.pop();

      in_loop[cur] = false;

      if(visited[cur]) continue;
      visited[cur] = true;
      
      for(auto &e : g[cur]){
        if(not visited[e.to]){
          --indeg[e.to];
          if(indeg[e.to] == 1){
            q.push(e.to);
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      if(in_loop[i]){
        for(auto &e : g[i]){
          if(not in_loop[e.to]){
            group[i] = i;
            dfs(e.to, i, g);
            break;
          }
        }
      }
    }
  }
};
#line 7 "test/aoj/2891/main.test.cpp"

int main(){
  int N; std::cin >> N;

  Graph<int> g(N);
  g.read<1, false, false>(N);

  auto res = PseudoTree<int>(g);

  int Q; std::cin >> Q;
  for(auto [a, b] : input_tuples<int, int>(Q)){
    --a, --b;

    if(res.in_loop[a] and res.in_loop[b]){
      std::cout << 2 << "\n";
    }else{
      std::cout << 1 << "\n"; 
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

