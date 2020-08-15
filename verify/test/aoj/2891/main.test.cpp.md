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
    - Last commit date: 2020-06-24 17:31:45+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/decompose_pseudotree.cpp.html">Decompose pseudotree</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"

#include <iostream>

#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"

int main(){
  int N; std::cin >> N;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 1, false>(N));

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
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

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
#line 8 "test/aoj/2891/main.test.cpp"

int main(){
  int N; std::cin >> N;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 1, false>(N));

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

