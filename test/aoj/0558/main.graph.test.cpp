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
