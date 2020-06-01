#pragma once
#include <vector>
#include <queue>
#include <optional>
#include "Mylib/Grid/grid.cpp"

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
