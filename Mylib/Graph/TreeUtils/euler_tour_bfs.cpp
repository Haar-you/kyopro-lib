#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Euler tour (BFS)
 * @docs euler_tour_bfs.md
 */
namespace haar_lib {
  template <typename T>
  struct EulerTourBFS {
    int N;
    std::vector<int> parent;
    std::vector<int> depth;

    std::vector<std::vector<int>> bfs_order;
    std::vector<std::vector<int>> dfs_order;
    std::vector<int> left, right;

    EulerTourBFS(const Tree<T> &tree, int root):
      N(tree.size()), parent(N), depth(N), left(N), right(N)
    {
      {
        int ord = 0;
        dfs(tree, root, -1, 0, ord);
      }

      {
        std::queue<std::pair<int, int>> q;
        q.emplace(root, 0);
        int ord = 0;

        while(not q.empty()){
          auto [i, d] = q.front(); q.pop();

          if((int)bfs_order.size() <= d) bfs_order.emplace_back();
          bfs_order[d].push_back(ord);
          ++ord;

          for(auto &e : tree[i]){
            if(e.to == parent[i]) continue;
            q.emplace(e.to, d + 1);
          }
        }
      }
    }

    void dfs(const Tree<T> &tree, int cur, int par, int d, int &ord){
      parent[cur] = par;
      depth[cur] = d;

      if((int)dfs_order.size() <= d) dfs_order.emplace_back();
      dfs_order[d].push_back(ord);
      left[cur] = ord;
      ++ord;

      for(auto &e : tree[cur]){
        if(e.to == par) continue;
        dfs(tree, e.to, cur, d + 1, ord);
      }

      right[cur] = ord;
    }

  public:
    template <typename Func>
    void query_children(int i, int d, const Func &f) const {
      if(i != -1){
        d += depth[i];
        if((int)bfs_order.size() > d){
          int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), left[i]) - dfs_order[d].begin();
          int r = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), right[i]) - dfs_order[d].begin();

          if(l >= (int)bfs_order[d].size()) return;
          if(r == l) return;

          f(bfs_order[d][l], bfs_order[d][r - 1] + 1);
        }
      }
    }

    template <typename Func>
    void query_at(int i, const Func &f) const {
      query_children(i, 0, f);
    }

    int get_parent(int i) const {
      if(i == -1) return -1;
      return parent[i];
    }

    int get_ancestor(int i, int k) const {
      int ret = i;
      for(int i = 0; i < k; ++i){
        ret = get_parent(ret);
        if(ret == -1) break;
      }
      return ret;
    }
  };
}
