#pragma once
#include <optional>
#include <queue>
#include <vector>
#include "Mylib/Grid/grid.cpp"

namespace haar_lib {
  template <typename Directions, typename Checker>
  auto grid_bfs(
      const int H, const int W,
      const std::vector<cell> &starting_points,
      const Directions &dir,
      const Checker &check_passable) -> std::vector<std::vector<std::optional<int>>> {
    std::vector<std::vector<std::optional<int>>> dist(H, std::vector<std::optional<int>>(W));
    std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));

    std::queue<cell> q;
    for (auto &p : starting_points) {
      dist[p.x][p.y] = 0;
      q.push(p);
    }

    while (not q.empty()) {
      auto cur = q.front();
      q.pop();

      if (visited[cur.x][cur.y]) continue;
      visited[cur.x][cur.y] = true;

      for (auto &d : dir) {
        auto nxt = cur + d;

        if (nxt.x < 0 or nxt.x >= H or nxt.y < 0 or nxt.y >= W or not check_passable(cur, nxt)) continue;

        if (not dist[nxt.x][nxt.y]) {
          dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;
          q.push(nxt);
        } else {
          if (*dist[nxt.x][nxt.y] > *dist[cur.x][cur.y] + 1) {
            dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;
            q.push(nxt);
          }
        }
      }
    }

    return dist;
  }
}  // namespace haar_lib
