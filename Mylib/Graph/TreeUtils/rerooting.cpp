#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Rerooting DP
 * @docs rerooting.md
 */
namespace haar_lib {
  namespace rerooting_impl {
    template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
    T rec1(
      tree<U> &tr,
      T id,
      const Merge &merge,
      const EdgeF &f,
      const VertexF &g,
      std::vector<std::vector<T>> &dp,
      int cur,
      int par = -1
    ){
      T acc = id;

      for(int i = 0; i < (int)tr[cur].size(); ++i){
        auto &e = tr[cur][i];
        if(e.to == par) continue;
        dp[cur][i] = rec1(tr, id, merge, f, g, dp, e.to, cur);
        acc = merge(acc, f(dp[cur][i], e));
      }

      return g(acc, cur);
    }

    template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
    void rec2(
      const tree<U> &tr,
      T id,
      const Merge &merge,
      const EdgeF &f,
      const VertexF &g,
      std::vector<std::vector<T>> &dp,
      int cur,
      int par,
      T value
    ){
      const int l = tr[cur].size();

      for(int i = 0; i < l; ++i){
        if(tr[cur][i].to == par){
          dp[cur][i] = value;
        }
      }

      std::vector<T> left(l + 1, id), right(l + 1, id);

      for(int i = 0; i < l - 1; ++i){
        const auto &e = tr[cur][i];
        left[i + 1] = merge(left[i], f(dp[cur][i], e));
      }

      for(int i = l - 1; i >= 1; --i){
        const auto &e = tr[cur][i];
        right[i - 1] = merge(right[i], f(dp[cur][i], e));
      }

      for(int i = 0; i < l; ++i){
        const auto &e = tr[cur][i];
        if(e.to == par) continue;

        rec2(tr, id, merge, f, g, dp, e.to, cur, g(merge(left[i], right[i]), cur));
      }
    }
  }

  template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
  auto rerooting(tree<U> tr, T id, Merge merge, EdgeF f, VertexF g){
    const int N = tr.size();
    std::vector<std::vector<T>> dp(N);
    std::vector<T> ret(N, id);

    for(int i = 0; i < N; ++i) dp[i].assign(tr[i].size(), id);
    rerooting_impl::rec1(tr, id, merge, f, g, dp, 0);
    rerooting_impl::rec2(tr, id, merge, f, g, dp, 0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tr[i].size(); ++j){
        ret[i] = merge(ret[i], f(dp[i][j], tr[i][j]));
      }

      ret[i] = g(ret[i], i);
    }

    return ret;
  }
}
