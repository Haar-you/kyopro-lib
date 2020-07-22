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
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid.cpp.html">Grid template</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid_bfs.cpp.html">BFS on a grid</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Grid/grid_find.cpp.html">Enumerate points satisfying conditions</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <iostream>
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Grid/grid_bfs.cpp"
#include "Mylib/Grid/grid_find.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  auto s = input_vector<std::string>(H);
  
  std::vector<Point> ps(N+1);

  ps[0] = grid_find(s, 'S')[0];

  for(int i = 1; i <= N; ++i) ps[i] = grid_find(s, (char)('0' + i))[0];
  
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

    ans += *dist[ps[i+1].x][ps[i+1].y];
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
#line 3 "Mylib/Grid/grid_bfs.cpp"
#include <queue>
#include <optional>
#line 6 "Mylib/Grid/grid_bfs.cpp"

/**
 * @title BFS on a grid
 * @docs grid_bfs.md
 */
template <typename Directions, typename Checker>
auto grid_bfs(
  const int H, const int W,
  const std::vector<Point> &starting_points,
  const Directions &dir,
  const Checker &check_passable
){
  std::vector<std::vector<std::optional<int>>> dist(H, std::vector<std::optional<int>>(W));
  std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));

  std::queue<Point> q;
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
#line 4 "Mylib/Grid/grid_find.cpp"

/**
 * @title Enumerate points satisfying conditions
 * @docs grid_find.md
 */
template <typename C, typename T = typename C::value_type>
auto grid_find(const std::vector<C> &A, T value){
  const int H = A.size(), W = A[0].size();
  
  std::vector<Point> ret;
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(A[i][j] == value){
        ret.emplace_back(i, j);
      }
    }
  }

  return ret;  
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
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
#line 9 "test/aoj/0558/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  auto s = input_vector<std::string>(H);
  
  std::vector<Point> ps(N+1);

  ps[0] = grid_find(s, 'S')[0];

  for(int i = 1; i <= N; ++i) ps[i] = grid_find(s, (char)('0' + i))[0];
  
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

    ans += *dist[ps[i+1].x][ps[i+1].y];
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

