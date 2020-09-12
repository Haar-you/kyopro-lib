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


# :heavy_check_mark: BFS on a grid

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#437b04c37f52e5b35f1d2c24c546c491">Mylib/Grid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Grid/grid_bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 07:16:52+09:00




## Operations

## Requirements

## Notes

## Problems

- [AGC 033 A - Darker and Darker](https://atcoder.jp/contests/agc033/tasks/agc033_a)
- [QUPC 2018 C - Ito Campus](https://atcoder.jp/contests/qupc2018/tasks/qupc2018_c)

## References


## Depends on

* :heavy_check_mark: <a href="grid.cpp.html">Grid template</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.test.cpp.html">test/aoj/0558/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include <optional>
#include "Mylib/Grid/grid.cpp"

/**
 * @title BFS on a grid
 * @docs grid_bfs.md
 */
namespace haar_lib {
  template <typename Directions, typename Checker>
  auto grid_bfs(
    const int H, const int W,
    const std::vector<cell> &starting_points,
    const Directions &dir,
    const Checker &check_passable
  ){
    std::vector<std::vector<std::optional<int>>> dist(H, std::vector<std::optional<int>>(W));
    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));

    std::queue<cell> q;
    for(auto &p : starting_points){
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

        if(not dist[nxt.x][nxt.y]){
          dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;
          q.push(nxt);
        }else{
          if(*dist[nxt.x][nxt.y] > *dist[cur.x][cur.y] + 1){
            dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;
            q.push(nxt);
          }
        }
      }
    }

    return dist;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Grid/grid_bfs.cpp"
#include <vector>
#include <queue>
#include <optional>
#line 2 "Mylib/Grid/grid.cpp"
#include <array>
#include <iostream>
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
#line 6 "Mylib/Grid/grid_bfs.cpp"

/**
 * @title BFS on a grid
 * @docs grid_bfs.md
 */
namespace haar_lib {
  template <typename Directions, typename Checker>
  auto grid_bfs(
    const int H, const int W,
    const std::vector<cell> &starting_points,
    const Directions &dir,
    const Checker &check_passable
  ){
    std::vector<std::vector<std::optional<int>>> dist(H, std::vector<std::optional<int>>(W));
    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));

    std::queue<cell> q;
    for(auto &p : starting_points){
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

        if(not dist[nxt.x][nxt.y]){
          dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;
          q.push(nxt);
        }else{
          if(*dist[nxt.x][nxt.y] > *dist[cur.x][cur.y] + 1){
            dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;
            q.push(nxt);
          }
        }
      }
    }

    return dist;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

