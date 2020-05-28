#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558"

#include <iostream>
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Grid/grid_bfs.cpp"
#include "Mylib/Grid/grid_find.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, N; std::cin >> H >> W >> N;

  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];
  
  std::vector<Point> ps(N+1);

  ps[0] = grid_find(s, 'S')[0];

  for(int i = 1; i <= N; ++i){
    ps[i] = grid_find(s, (char)('0' + i))[0];
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

    ans += *dist[ps[i+1].x][ps[i+1].y];
  }

  std::cout << ans << "\n";

  return 0;
}
