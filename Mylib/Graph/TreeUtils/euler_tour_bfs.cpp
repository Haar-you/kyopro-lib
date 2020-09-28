#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class euler_tour_bfs {
    int N_;
    std::vector<int> parent_, depth_, left_, right_;
    std::vector<std::vector<int>> bfs_order_, dfs_order_;

  public:
    euler_tour_bfs(){}
    euler_tour_bfs(const tree<T> &tr, int root):
      N_(tr.size()), parent_(N_), depth_(N_), left_(N_), right_(N_)
    {
      {
        int ord = 0;
        dfs(tr, root, -1, 0, ord);
      }

      {
        std::queue<std::pair<int, int>> q;
        q.emplace(root, 0);
        int ord = 0;

        while(not q.empty()){
          auto [i, d] = q.front(); q.pop();

          if((int)bfs_order_.size() <= d) bfs_order_.emplace_back();
          bfs_order_[d].push_back(ord);
          ++ord;

          for(auto &e : tr[i]){
            if(e.to == parent_[i]) continue;
            q.emplace(e.to, d + 1);
          }
        }
      }
    }

  private:
    void dfs(const tree<T> &tr, int cur, int par, int d, int &ord){
      parent_[cur] = par;
      depth_[cur] = d;

      if((int)dfs_order_.size() <= d) dfs_order_.emplace_back();
      dfs_order_[d].push_back(ord);
      left_[cur] = ord;
      ++ord;

      for(auto &e : tr[cur]){
        if(e.to == par) continue;
        dfs(tr, e.to, cur, d + 1, ord);
      }

      right_[cur] = ord;
    }

  public:
    template <typename Func>
    void query_children(int i, int d, const Func &f) const {
      if(i != -1){
        d += depth_[i];
        if((int)bfs_order_.size() > d){
          int l = std::lower_bound(dfs_order_[d].begin(), dfs_order_[d].end(), left_[i]) - dfs_order_[d].begin();
          int r = std::lower_bound(dfs_order_[d].begin(), dfs_order_[d].end(), right_[i]) - dfs_order_[d].begin();

          if(l >= (int)bfs_order_[d].size()) return;
          if(r == l) return;

          f(bfs_order_[d][l], bfs_order_[d][r - 1] + 1);
        }
      }
    }

    template <typename Func>
    void query_at(int i, const Func &f) const {
      query_children(i, 0, f);
    }

    int get_parent(int i) const {
      if(i == -1) return -1;
      return parent_[i];
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
