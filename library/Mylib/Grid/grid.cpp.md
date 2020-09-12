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


# :heavy_check_mark: Grid template

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#437b04c37f52e5b35f1d2c24c546c491">Mylib/Grid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Grid/grid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 07:16:52+09:00




## Required by

* :heavy_check_mark: <a href="grid_bfs.cpp.html">BFS on a grid</a>
* :heavy_check_mark: <a href="grid_find.cpp.html">Enumerate points satisfying conditions</a>
* :heavy_check_mark: <a href="grid_to_graph.cpp.html">Convert grid to graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.graph.test.cpp.html">test/aoj/0558/main.graph.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.test.cpp.html">test/aoj/0558/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

