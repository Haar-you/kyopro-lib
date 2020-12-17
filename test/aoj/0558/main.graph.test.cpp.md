---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/ShortestPath/bfs_shortest_path.cpp
    title: BFS shortest path
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid.cpp
    title: Grid template
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_find.cpp
    title: Enumerate points satisfying conditions
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_to_graph.cpp
    title: Convert grid to graph
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558
  bundledCode: "#line 1 \"test/aoj/0558/main.graph.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"Mylib/Grid/grid.cpp\"\n#include <array>\n#line 4\
    \ \"Mylib/Grid/grid.cpp\"\n#include <utility>\n\nnamespace haar_lib {\n  struct\
    \ cell {\n    int x, y;\n    cell(): x(0), y(0){}\n    cell(int x, int y): x(x),\
    \ y(y){}\n    cell& operator+=(const cell &a){this->x += a.x; this->y += a.y;\
    \ return *this;}\n    cell& operator-=(const cell &a){this->x -= a.x; this->y\
    \ -= a.y; return *this;}\n  };\n\n  cell operator+(const cell &a, const cell &b){return\
    \ cell(a.x + b.x, a.y + b.y);}\n  cell operator-(const cell &a, const cell &b){return\
    \ cell(a.x - b.x, a.y - b.y);}\n  bool operator==(const cell &a, const cell &b){return\
    \ a.x == b.x and a.y == b.y;}\n  bool operator!=(const cell &a, const cell &b){return\
    \ !(a == b);}\n\n  bool operator<(const cell &a, const cell &b){\n    return std::make_pair(a.x,\
    \ a.y) < std::make_pair(b.x, b.y);\n  }\n\n  std::ostream& operator<<(std::ostream\
    \ &os, const cell &a){\n    os << \"(\" << a.x << \",\" << a.y << \")\";\n   \
    \ return os;\n  }\n\n  const auto LEFT = cell(0, -1);\n  const auto RIGHT = cell(0,\
    \ 1);\n  const auto UP = cell(-1, 0);\n  const auto DOWN = cell(1, 0);\n\n  const\
    \ std::array<cell, 4> dir4 = {LEFT, RIGHT, UP, DOWN};\n  const std::array<cell,\
    \ 8> dir8 = {LEFT, RIGHT, UP, DOWN, LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT\
    \ + DOWN};\n}\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n\
    \    int index = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from),\
    \ to(to), cost(cost){}\n    edge(int from, int to, T cost, int index): from(from),\
    \ to(to), cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct\
    \ graph {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
    \ i) const {return data[i];}\n\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Grid/grid_to_graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename Directions, typename\
    \ Index, typename Checker, typename Generator>\n  graph<T> grid_to_graph(\n  \
    \  int H, int W,\n    const Directions &dir,\n    const Index &index,\n    const\
    \ Checker &check_passable,\n    const Generator &generate_edge_cost\n  ){\n  \
    \  graph<T> ret(H * W);\n\n    for(int i = 0; i < H; ++i){\n      for(int j =\
    \ 0; j < W; ++j){\n        auto p = cell(i, j);\n\n        for(auto &d : dir){\n\
    \          auto q = cell(i, j) + d;\n\n          if(q.x < 0 or q.x >= H or q.y\
    \ < 0 or q.y >= W or not check_passable(p, q)) continue;\n\n          ret.add_edge(index(p.x,\
    \ p.y), index(q.x, q.y), generate_edge_cost(p, q));\n        }\n      }\n    }\n\
    \n    return ret;\n  }\n}\n#line 4 \"Mylib/Grid/grid_find.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename C, typename T = typename C::value_type>\n  auto grid_find(const\
    \ std::vector<C> &A, T value){\n    const int H = A.size(), W = A[0].size();\n\
    \n    std::vector<cell> ret;\n    for(int i = 0; i < H; ++i){\n      for(int j\
    \ = 0; j < W; ++j){\n        if(A[i][j] == value){\n          ret.emplace_back(i,\
    \ j);\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/Graph/ShortestPath/bfs_shortest_path.cpp\"\
    \n#include <optional>\n#include <queue>\n#line 6 \"Mylib/Graph/ShortestPath/bfs_shortest_path.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<std::optional<int64_t>>\
    \ bfs_shortest_path(const graph<T> &g, const std::vector<int> &src){\n    const\
    \ int n = g.size();\n    std::vector<std::optional<int64_t>> ret(n, std::nullopt);\n\
    \    std::vector<bool> visited(n);\n    std::queue<int> q;\n\n    for(auto s :\
    \ src){\n      ret[s] = 0;\n      q.push(s);\n    }\n\n    while(not q.empty()){\n\
    \      const int cur = q.front(); q.pop();\n\n      if(visited[cur]) continue;\n\
    \      visited[cur] = true;\n\n      for(auto &e : g[cur]){\n        if(not ret[e.to]\
    \ or *ret[e.to] > *ret[e.from] + 1){\n          ret[e.to] = *ret[e.from] + 1;\n\
    \          q.push(e.to);\n        }\n      }\n    }\n\n    return ret;\n  }\n\
    }\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> input_vector(int N){\n    std::vector<T> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template <typename\
    \ T>\n  std::vector<std::vector<T>> input_vector(int N, int M){\n    std::vector<std::vector<T>>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return\
    \ ret;\n  }\n}\n#line 10 \"test/aoj/0558/main.graph.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, N; std::cin >> H >> W >> N;\n\n  auto s = hl::input_vector<std::string>(H);\n\
    \n  std::vector<hl::cell> ps(N + 1);\n\n  ps[0] = hl::grid_find(s, 'S')[0];\n\n\
    \  for(int i = 1; i <= N; ++i) ps[i] = hl::grid_find(s, (char)('0' + i))[0];\n\
    \n  auto index = [&](int i, int j){return i * W + j;};\n\n  auto g = hl::grid_to_graph<int>(\n\
    \    H, W,\n    hl::dir4,\n    index,\n    [&](const auto &, const auto &p){\n\
    \      return s[p.x][p.y] != 'X';\n    },\n    [&](const auto &, const auto &){\n\
    \      return 1;\n    }\n  );\n\n  int ans = 0;\n  for(int i = 0; i < N; ++i){\n\
    \    auto dist = hl::bfs_shortest_path(g, {index(ps[i].x, ps[i].y)});\n    ans\
    \ += *dist[index(ps[i + 1].x, ps[i + 1].y)];\n  }\n\n  std::cout << ans << \"\\\
    n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Grid/grid.cpp\"\n\
    #include \"Mylib/Grid/grid_to_graph.cpp\"\n#include \"Mylib/Grid/grid_find.cpp\"\
    \n#include \"Mylib/Graph/ShortestPath/bfs_shortest_path.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, N; std::cin >> H >> W >> N;\n\n  auto s = hl::input_vector<std::string>(H);\n\
    \n  std::vector<hl::cell> ps(N + 1);\n\n  ps[0] = hl::grid_find(s, 'S')[0];\n\n\
    \  for(int i = 1; i <= N; ++i) ps[i] = hl::grid_find(s, (char)('0' + i))[0];\n\
    \n  auto index = [&](int i, int j){return i * W + j;};\n\n  auto g = hl::grid_to_graph<int>(\n\
    \    H, W,\n    hl::dir4,\n    index,\n    [&](const auto &, const auto &p){\n\
    \      return s[p.x][p.y] != 'X';\n    },\n    [&](const auto &, const auto &){\n\
    \      return 1;\n    }\n  );\n\n  int ans = 0;\n  for(int i = 0; i < N; ++i){\n\
    \    auto dist = hl::bfs_shortest_path(g, {index(ps[i].x, ps[i].y)});\n    ans\
    \ += *dist[index(ps[i + 1].x, ps[i + 1].y)];\n  }\n\n  std::cout << ans << \"\\\
    n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Grid/grid.cpp
  - Mylib/Grid/grid_to_graph.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Grid/grid_find.cpp
  - Mylib/Graph/ShortestPath/bfs_shortest_path.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/0558/main.graph.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0558/main.graph.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0558/main.graph.test.cpp
- /verify/test/aoj/0558/main.graph.test.cpp.html
title: test/aoj/0558/main.graph.test.cpp
---
