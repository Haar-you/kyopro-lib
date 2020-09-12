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


# :heavy_check_mark: test/aoj/0558/main.graph.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cfdc241edb33a016c1ab681da8d9e179">test/aoj/0558</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0558/main.graph.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 07:16:52+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/ShortestPath/bfs_shortest_path.cpp.html">BFS shortest path</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid.cpp.html">Grid template</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid_find.cpp.html">Enumerate points satisfying conditions</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid_to_graph.cpp.html">Convert grid to graph</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <iostream>
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Grid/grid_to_graph.cpp"
#include "Mylib/Grid/grid_find.cpp"
#include "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  auto s = hl::input_vector<std::string>(H);

  std::vector<hl::cell> ps(N + 1);

  ps[0] = hl::grid_find(s, 'S')[0];

  for(int i = 1; i <= N; ++i) ps[i] = hl::grid_find(s, (char)('0' + i))[0];

  auto index = [&](int i, int j){return i * W + j;};

  auto g = hl::grid_to_graph<int>(
    H, W,
    hl::dir4,
    index,
    [&](const auto &, const auto &p){
      return s[p.x][p.y] != 'X';
    },
    [&](const auto &, const auto &){
      return 1;
    }
  );

  int ans = 0;
  for(int i = 0; i < N; ++i){
    auto dist = hl::bfs_shortest_path(g, {index(ps[i].x, ps[i].y)});
    ans += *dist[index(ps[i + 1].x, ps[i + 1].y)];
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0558/main.graph.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <iostream>
#include <vector>
#line 2 "Mylib/Grid/grid.cpp"
#include <array>
#line 4 "Mylib/Grid/grid.cpp"
#include <utility>

/**
 * @title Grid template
 * @docs grid.md
 */
namespace haar_lib {
  struct cell {
    int x, y;
    cell(): x(0), y(0){}
    cell(int x, int y): x(x), y(y){}
    cell& operator+=(const cell &a){this->x += a.x; this->y += a.y; return *this;}
    cell& operator-=(const cell &a){this->x -= a.x; this->y -= a.y; return *this;}
  };

  cell operator+(const cell &a, const cell &b){return cell(a.x + b.x, a.y + b.y);}
  cell operator-(const cell &a, const cell &b){return cell(a.x - b.x, a.y - b.y);}
  bool operator==(const cell &a, const cell &b){return a.x == b.x and a.y == b.y;}
  bool operator!=(const cell &a, const cell &b){return !(a == b);}

  bool operator<(const cell &a, const cell &b){
    return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);
  }

  std::ostream& operator<<(std::ostream &os, const cell &a){
    os << "(" << a.x << "," << a.y << ")";
    return os;
  }

  const auto LEFT = cell(0, -1);
  const auto RIGHT = cell(0, 1);
  const auto UP = cell(-1, 0);
  const auto DOWN = cell(1, 0);

  const std::array<cell, 4> dir4 = {LEFT, RIGHT, UP, DOWN};
  const std::array<cell, 8> dir8 = {LEFT, RIGHT, UP, DOWN, LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};
}
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
#line 5 "Mylib/Grid/grid_to_graph.cpp"

/**
 * @title Convert grid to graph
 * @docs grid_to_graph.md
 */
namespace haar_lib {
  template <typename T, typename Directions, typename Index, typename Checker, typename Generator>
  graph<T> grid_to_graph(
    int H, int W,
    const Directions &dir,
    const Index &index,
    const Checker &check_passable,
    const Generator &generate_edge_cost
  ){
    graph<T> ret(H * W);

    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        auto p = cell(i, j);

        for(auto &d : dir){
          auto q = cell(i, j) + d;

          if(q.x < 0 or q.x >= H or q.y < 0 or q.y >= W or not check_passable(p, q)) continue;

          ret.add_edge(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p, q));
        }
      }
    }

    return ret;
  }
}
#line 4 "Mylib/Grid/grid_find.cpp"

/**
 * @title Enumerate points satisfying conditions
 * @docs grid_find.md
 */
namespace haar_lib {
  template <typename C, typename T = typename C::value_type>
  auto grid_find(const std::vector<C> &A, T value){
    const int H = A.size(), W = A[0].size();

    std::vector<cell> ret;
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(A[i][j] == value){
          ret.emplace_back(i, j);
        }
      }
    }

    return ret;
  }
}
#line 3 "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"

/**
 * @title BFS shortest path
 * @docs bfs_shortest_path.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<std::optional<int64_t>> bfs_shortest_path(const graph<T> &g, const std::vector<int> &src){
    const int n = g.size();
    std::vector<std::optional<int64_t>> ret(n, std::nullopt);
    std::vector<bool> visited(n);
    std::queue<int> q;

    for(auto s : src){
      ret[s] = 0;
      q.push(s);
    }

    while(not q.empty()){
      const int cur = q.front(); q.pop();

      if(visited[cur]) continue;
      visited[cur] = true;

      for(auto &e : g[cur]){
        if(not ret[e.to] or *ret[e.to] > *ret[e.from] + 1){
          ret[e.to] = *ret[e.from] + 1;
          q.push(e.to);
        }
      }
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
#line 10 "test/aoj/0558/main.graph.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  auto s = hl::input_vector<std::string>(H);

  std::vector<hl::cell> ps(N + 1);

  ps[0] = hl::grid_find(s, 'S')[0];

  for(int i = 1; i <= N; ++i) ps[i] = hl::grid_find(s, (char)('0' + i))[0];

  auto index = [&](int i, int j){return i * W + j;};

  auto g = hl::grid_to_graph<int>(
    H, W,
    hl::dir4,
    index,
    [&](const auto &, const auto &p){
      return s[p.x][p.y] != 'X';
    },
    [&](const auto &, const auto &){
      return 1;
    }
  );

  int ans = 0;
  for(int i = 0; i < N; ++i){
    auto dist = hl::bfs_shortest_path(g, {index(ps[i].x, ps[i].y)});
    ans += *dist[index(ps[i + 1].x, ps[i + 1].y)];
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

