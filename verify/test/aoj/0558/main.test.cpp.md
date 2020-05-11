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


# :heavy_check_mark: test/aoj/0558/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cfdc241edb33a016c1ab681da8d9e179">test/aoj/0558</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0558/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 10:14:38+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid.cpp.html">グリッド用テンプレート</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid_bfs.cpp.html">グリッド上BFS</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <iostream>
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Grid/grid_bfs.cpp"

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

  int ans = 0;
  for(int i = 0; i < N; ++i){
    auto dist =
      grid_bfs(
        H,
        W,
        {ps[i]},
        grid::dir4,
        [&](const auto &, const auto &p){
          return s[p.x][p.y] != 'X';
        }
      );

    ans += dist[ps[i+1].x][ps[i+1].y];
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0558/main.test.cpp"
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
#line 3 "Mylib/Grid/grid_bfs.cpp"
#include <queue>
#line 5 "Mylib/Grid/grid_bfs.cpp"

/**
 * @title グリッド上BFS
 * @docs grid_bfs.md
 */
template <typename Directions, typename Checker>
std::vector<std::vector<int>> grid_bfs(
  const int H, const int W,
  const std::vector<Point> &start_points,
  const Directions &dir,
  const Checker &check_passable
){
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
#line 7 "test/aoj/0558/main.test.cpp"

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

  int ans = 0;
  for(int i = 0; i < N; ++i){
    auto dist =
      grid_bfs(
        H,
        W,
        {ps[i]},
        grid::dir4,
        [&](const auto &, const auto &p){
          return s[p.x][p.y] != 'X';
        }
      );

    ans += dist[ps[i+1].x][ps[i+1].y];
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

