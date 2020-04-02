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
