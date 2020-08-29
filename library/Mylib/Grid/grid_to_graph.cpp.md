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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Convert grid to graph

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#437b04c37f52e5b35f1d2c24c546c491">Mylib/Grid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Grid/grid_to_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Depends on

* :question: <a href="../Graph/Template/graph.cpp.html">Basic graph</a>
* :heavy_check_mark: <a href="grid.cpp.html">Grid template</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.graph.test.cpp.html">test/aoj/0558/main.graph.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Convert grid to graph
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

        ret.add_edge(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p, q));
      }
    }
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Grid/grid_to_graph.cpp"
#include <vector>
#line 2 "Mylib/Grid/grid.cpp"
#include <array>
#include <iostream>
#include <utility>

/**
 * @title Grid template
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
#line 5 "Mylib/Grid/grid_to_graph.cpp"

/**
 * @title Convert grid to graph
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

        ret.add_edge(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p, q));
      }
    }
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

