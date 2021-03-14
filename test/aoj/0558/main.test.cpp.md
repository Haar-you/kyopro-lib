---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid.cpp
    title: Grid template
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_bfs.cpp
    title: BFS on a grid
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_find.cpp
    title: Enumerate points satisfying conditions
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
  bundledCode: "#line 1 \"test/aoj/0558/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/Grid/grid.cpp\"\n\
    #include <array>\n#line 4 \"Mylib/Grid/grid.cpp\"\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  struct cell {\n    int x, y;\n    cell(): x(0), y(0){}\n    cell(int\
    \ x, int y): x(x), y(y){}\n    cell& operator+=(const cell &a){this->x += a.x;\
    \ this->y += a.y; return *this;}\n    cell& operator-=(const cell &a){this->x\
    \ -= a.x; this->y -= a.y; return *this;}\n  };\n\n  cell operator+(const cell\
    \ &a, const cell &b){return cell(a.x + b.x, a.y + b.y);}\n  cell operator-(const\
    \ cell &a, const cell &b){return cell(a.x - b.x, a.y - b.y);}\n  bool operator==(const\
    \ cell &a, const cell &b){return a.x == b.x and a.y == b.y;}\n  bool operator!=(const\
    \ cell &a, const cell &b){return !(a == b);}\n\n  bool operator<(const cell &a,\
    \ const cell &b){\n    return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);\n\
    \  }\n\n  std::ostream& operator<<(std::ostream &os, const cell &a){\n    os <<\
    \ \"(\" << a.x << \",\" << a.y << \")\";\n    return os;\n  }\n\n  const auto\
    \ LEFT = cell(0, -1);\n  const auto RIGHT = cell(0, 1);\n  const auto UP = cell(-1,\
    \ 0);\n  const auto DOWN = cell(1, 0);\n\n  const std::array<cell, 4> dir4 = {LEFT,\
    \ RIGHT, UP, DOWN};\n  const std::array<cell, 8> dir8 = {LEFT, RIGHT, UP, DOWN,\
    \ LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};\n}\n#line 3 \"Mylib/Grid/grid_bfs.cpp\"\
    \n#include <queue>\n#include <optional>\n#line 6 \"Mylib/Grid/grid_bfs.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename Directions, typename Checker>\n \
    \ auto grid_bfs(\n    const int H, const int W,\n    const std::vector<cell> &starting_points,\n\
    \    const Directions &dir,\n    const Checker &check_passable\n  ) -> std::vector<std::vector<std::optional<int>>>\n\
    \  {\n    std::vector<std::vector<std::optional<int>>> dist(H, std::vector<std::optional<int>>(W));\n\
    \    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));\n\n    std::queue<cell>\
    \ q;\n    for(auto &p : starting_points){\n      dist[p.x][p.y] = 0;\n      q.push(p);\n\
    \    }\n\n    while(not q.empty()){\n      auto cur = q.front(); q.pop();\n\n\
    \      if(visited[cur.x][cur.y]) continue;\n      visited[cur.x][cur.y] = true;\n\
    \n      for(auto &d : dir){\n        auto nxt = cur + d;\n\n        if(nxt.x <\
    \ 0 or nxt.x >= H or nxt.y < 0 or nxt.y >= W or not check_passable(cur, nxt))\
    \ continue;\n\n        if(not dist[nxt.x][nxt.y]){\n          dist[nxt.x][nxt.y]\
    \ = *dist[cur.x][cur.y] + 1;\n          q.push(nxt);\n        }else{\n       \
    \   if(*dist[nxt.x][nxt.y] > *dist[cur.x][cur.y] + 1){\n            dist[nxt.x][nxt.y]\
    \ = *dist[cur.x][cur.y] + 1;\n            q.push(nxt);\n          }\n        }\n\
    \      }\n    }\n\n    return dist;\n  }\n}\n#line 4 \"Mylib/Grid/grid_find.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename C, typename T = typename C::value_type>\n\
    \  std::vector<cell> grid_find(const std::vector<C> &A, T value){\n    const int\
    \ H = A.size(), W = A[0].size();\n\n    std::vector<cell> ret;\n    for(int i\
    \ = 0; i < H; ++i){\n      for(int j = 0; j < W; ++j){\n        if(A[i][j] ==\
    \ value){\n          ret.emplace_back(i, j);\n        }\n      }\n    }\n\n  \
    \  return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 9 \"test/aoj/0558/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, N; std::cin >> H >> W >> N;\n\n  auto s = hl::input_vector<std::string>(H);\n\
    \n  std::vector<hl::cell> ps(N + 1);\n\n  ps[0] = hl::grid_find(s, 'S')[0];\n\n\
    \  for(int i = 1; i <= N; ++i) ps[i] = hl::grid_find(s, (char)('0' + i))[0];\n\
    \n  int ans = 0;\n  for(int i = 0; i < N; ++i){\n    auto dist =\n      hl::grid_bfs(\n\
    \        H,\n        W,\n        {ps[i]},\n        hl::dir4,\n        [&](const\
    \ auto &, const auto &p){\n          return s[p.x][p.y] != 'X';\n        }\n \
    \     );\n\n    ans += *dist[ps[i + 1].x][ps[i + 1].y];\n  }\n\n  std::cout <<\
    \ ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Grid/grid.cpp\"\n\
    #include \"Mylib/Grid/grid_bfs.cpp\"\n#include \"Mylib/Grid/grid_find.cpp\"\n\
    #include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int H, W, N; std::cin\
    \ >> H >> W >> N;\n\n  auto s = hl::input_vector<std::string>(H);\n\n  std::vector<hl::cell>\
    \ ps(N + 1);\n\n  ps[0] = hl::grid_find(s, 'S')[0];\n\n  for(int i = 1; i <= N;\
    \ ++i) ps[i] = hl::grid_find(s, (char)('0' + i))[0];\n\n  int ans = 0;\n  for(int\
    \ i = 0; i < N; ++i){\n    auto dist =\n      hl::grid_bfs(\n        H,\n    \
    \    W,\n        {ps[i]},\n        hl::dir4,\n        [&](const auto &, const\
    \ auto &p){\n          return s[p.x][p.y] != 'X';\n        }\n      );\n\n   \
    \ ans += *dist[ps[i + 1].x][ps[i + 1].y];\n  }\n\n  std::cout << ans << \"\\n\"\
    ;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Grid/grid.cpp
  - Mylib/Grid/grid_bfs.cpp
  - Mylib/Grid/grid_find.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/0558/main.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0558/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0558/main.test.cpp
- /verify/test/aoj/0558/main.test.cpp.html
title: test/aoj/0558/main.test.cpp
---
