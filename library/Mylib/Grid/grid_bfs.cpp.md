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


# :warning: グリッド上BFS

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#437b04c37f52e5b35f1d2c24c546c491">Mylib/Grid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Grid/grid_bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00


* see: <a href="https://atcoder.jp/contests/agc033/submissions/7429070">https://atcoder.jp/contests/agc033/submissions/7429070</a>
* see: <a href="https://atcoder.jp/contests/qupc2018/submissions/7429448">https://atcoder.jp/contests/qupc2018/submissions/7429448</a>


## Depends on

* :warning: <a href="grid.cpp.html">グリッド用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include "Mylib/Grid/grid.cpp"

/**
 * @title グリッド上BFS
 * @see https://atcoder.jp/contests/agc033/submissions/7429070
 * @see https://atcoder.jp/contests/qupc2018/submissions/7429448
 */
template <typename Directions, typename Checker>
std::vector<std::vector<int>> bfs_grid(const int H, const int W,
                                       const std::vector<Point> &start_points,
                                       const Directions &dir,
                                       const Checker &check_passable)
{
  std::vector<std::vector<int>> dist(H, std::vector<int>(W, -1));
  std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));

  std::queue<Point> q;
  for(auto &p : start_points){
    dist[p.x][p.y] = 0;
    q.push(p);
  }
  
  while(not q.empty()){
    auto cur = q.front(); q.pop();

    if(visited[cur.x][cur.y]) continue;
    visited[cur.x][cur.y] = true;

    for(auto &d : dir){
      auto nxt = cur + d;

      if(nxt.x < 0 or nxt.x >= H or nxt.y < 0 or nxt.y >= W or not check_passable(cur, nxt)) continue;

      if(dist[nxt.x][nxt.y] == -1){
        dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
        q.push(nxt);
      }else{
        if(dist[nxt.x][nxt.y] > dist[cur.x][cur.y] + 1){
          dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
          q.push(nxt);
        }
      }
    }
  }

  return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Grid/grid_bfs.cpp"
#include <vector>
#include <queue>
#line 2 "Mylib/Grid/grid.cpp"
#include <array>
#include <iostream>
#include <utility>

/**
 * @title グリッド用テンプレート
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
#line 5 "Mylib/Grid/grid_bfs.cpp"

/**
 * @title グリッド上BFS
 * @see https://atcoder.jp/contests/agc033/submissions/7429070
 * @see https://atcoder.jp/contests/qupc2018/submissions/7429448
 */
template <typename Directions, typename Checker>
std::vector<std::vector<int>> bfs_grid(const int H, const int W,
                                       const std::vector<Point> &start_points,
                                       const Directions &dir,
                                       const Checker &check_passable)
{
  std::vector<std::vector<int>> dist(H, std::vector<int>(W, -1));
  std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));

  std::queue<Point> q;
  for(auto &p : start_points){
    dist[p.x][p.y] = 0;
    q.push(p);
  }
  
  while(not q.empty()){
    auto cur = q.front(); q.pop();

    if(visited[cur.x][cur.y]) continue;
    visited[cur.x][cur.y] = true;

    for(auto &d : dir){
      auto nxt = cur + d;

      if(nxt.x < 0 or nxt.x >= H or nxt.y < 0 or nxt.y >= W or not check_passable(cur, nxt)) continue;

      if(dist[nxt.x][nxt.y] == -1){
        dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
        q.push(nxt);
      }else{
        if(dist[nxt.x][nxt.y] > dist[cur.x][cur.y] + 1){
          dist[nxt.x][nxt.y] = dist[cur.x][cur.y] + 1;
          q.push(nxt);
        }
      }
    }
  }

  return dist;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

