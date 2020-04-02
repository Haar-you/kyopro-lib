#pragma once
#include <vector>
#include <algorithm>

/**
 * @title DAGの最長パス
 */
int dag_longest_path(const std::vector<std::vector<int>> &g){
  int n = g.size();
  std::vector<int> ret(n);
  std::vector<bool> visited(n);

  auto dfs =
    [&](auto &f, int cur) -> int{
      if(visited[cur]) return ret[cur];
      visited[cur] = true;

      for(auto &nxt : g[cur]){
        chmax(ret[cur], f(f,nxt) + 1);
      }

      return ret[cur];
    };

  for(int i = 0; i < n; ++i) if(not visited[i]) dfs(dfs,i);

  return *std::max_element(ret.begin(), ret.end());
}
