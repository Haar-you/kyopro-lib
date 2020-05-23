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
    - Last commit date: 2020-05-22 12:01:21+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/ShortestPath/bfs_shortest_path.cpp.html">BFS最短路</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid.cpp.html">グリッド用テンプレート</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid_to_graph.cpp.html">グリッドをグラフに変換する</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <iostream>
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Grid/grid_to_graph.cpp"
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];
  
  std::vector<Point> ps(N+1);
  
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(s[i][j] == 'S') ps[0] = Point(i, j);
      else if(s[i][j] >= '1' and s[i][j] <= '9') ps[s[i][j]-'0'] = Point(i, j);
    }
  }

  auto index = [&](int i, int j){return i * W + j;};

  auto g = grid_to_graph<int>(
    H,
    W,
    grid::dir4,
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
    auto dist = bfs_shortest_path(g, {index(ps[i].x, ps[i].y)});
    ans += *dist[index(ps[i+1].x, ps[i+1].y)];
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
 * @title グリッド用テンプレート
 * @docs grid.md
 */
struct Point{
  int x, y;
  Point(): x(0), y(0){}
  Point(int x, int y): x(x), y(y){}
  Point& operator+=(const Point &a){this->x += a.x; this->y += a.y; return *this;}
  Point& operator-=(const Point &a){this->x -= a.x; this->y -= a.y; return *this;}
};

Point operator+(const Point &a, const Point &b){return Point(a.x+b.x, a.y+b.y);}
Point operator-(const Point &a, const Point &b){return Point(a.x-b.x, a.y-b.y);}
bool operator==(const Point &a, const Point &b){return a.x == b.x and a.y == b.y;}
bool operator!=(const Point &a, const Point &b){return !(a == b);}

bool operator<(const Point &a, const Point &b){
  return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);
}

std::ostream& operator<<(std::ostream &os, const Point &a){
  os << "(" << a.x << "," << a.y << ")";
  return os;
}

namespace grid{
  const auto LEFT = Point(0, -1);
  const auto RIGHT = Point(0, 1);
  const auto UP = Point(-1, 0);
  const auto DOWN = Point(1, 0);
  
  const std::array<Point, 4> dir4 = {LEFT, RIGHT, UP, DOWN};
  const std::array<Point, 8> dir8 = {LEFT, RIGHT, UP, DOWN, LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};
}
#line 4 "Mylib/Graph/graph_template.cpp"

/**
 * @title グラフ用テンプレート
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
#line 5 "Mylib/Grid/grid_to_graph.cpp"

/**
 * @title グリッドをグラフに変換する
 * @docs grid_to_graph.md
 */
template <typename T, typename Directions, typename Index, typename Checker, typename Generator>
Graph<T> grid_to_graph(
  int H, int W,
  const Directions &dir,
  const Index &index,
  const Checker &check_passable,
  const Generator &generate_edge_cost
){
  Graph<T> ret(H * W);

  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      auto p = Point(i, j);

      for(auto &d : dir){
        auto q = Point(i, j) + d;

        if(q.x < 0 or q.x >= H or q.y < 0 or q.y >= W or not check_passable(p, q)) continue;

        ret[index(p.x, p.y)].emplace_back(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p, q));
      }
    }
  }
  
  return ret;
}
#line 3 "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/ShortestPath/bfs_shortest_path.cpp"

/**
 * @title BFS最短路
 * @docs bfs_shortest_path.md
 */
template <typename T>
std::vector<std::optional<int>> bfs_shortest_path(const Graph<T> &g, const std::vector<int> &src){
  const int n = g.size();
  std::vector<std::optional<int>> ret(n, std::nullopt);
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
#line 9 "test/aoj/0558/main.graph.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];
  
  std::vector<Point> ps(N+1);
  
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(s[i][j] == 'S') ps[0] = Point(i, j);
      else if(s[i][j] >= '1' and s[i][j] <= '9') ps[s[i][j]-'0'] = Point(i, j);
    }
  }

  auto index = [&](int i, int j){return i * W + j;};

  auto g = grid_to_graph<int>(
    H,
    W,
    grid::dir4,
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
    auto dist = bfs_shortest_path(g, {index(ps[i].x, ps[i].y)});
    ans += *dist[index(ps[i+1].x, ps[i+1].y)];
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

