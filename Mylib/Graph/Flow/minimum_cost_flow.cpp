#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <tuple>
#include <cassert>

namespace haar_lib {
  namespace minimum_cost_flow_impl {
    template <typename T, typename U>
    struct edge {
      int from, to, rev;
      T cap;
      U cost;
      bool is_rev;
      edge(int from, int to, int rev, T cap, U cost, bool is_rev):
        from(from), to(to), rev(rev), cap(cap), cost(cost), is_rev(is_rev){}
    };
  }

  template <typename Capacity, typename Cost>
  class minimum_cost_flow {
  public:
    using edge = minimum_cost_flow_impl::edge<Capacity, Cost>;
    using capacity_type = Capacity;
    using cost_type = Cost;

  private:
    int size_;
    std::vector<std::vector<edge>> g_;

  public:
    minimum_cost_flow(){}
    minimum_cost_flow(int size): size_(size), g_(size){}

    void add_edge(int from, int to, Capacity cap, Cost cost){
      assert(0 <= from and from < size_);
      assert(0 <= to and to < size_);
      g_[from].emplace_back(from, to, g_[to].size(), cap, cost, false);
      g_[to].emplace_back(to, from, g_[from].size() - 1, 0, -cost, true);
    }

    std::pair<Capacity, Cost> min_cost_flow(int src, int dst, const Capacity &f){
      assert(0 <= src and src < size_);
      assert(0 <= dst and dst < size_);

      using P = std::pair<Cost, int>;
      Cost ret = 0;
      Capacity flow = f;
      std::vector<Cost> h(size_, 0), cost(size_);
      std::vector<bool> is_inf(size_, true);
      std::vector<int> prev_node(size_), prev_edge(size_);
      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      while(flow > 0){
        std::fill(is_inf.begin(), is_inf.end(), true);

        // src -> dst の最小コスト経路を探索する。 (dijkstra algorithm)
        cost[src] = 0;
        pq.emplace(0, src);
        is_inf[src] = false;

        while(not pq.empty()){
          Cost c;
          int v;
          std::tie(c, v) = pq.top(); pq.pop();

          if(cost[v] < c) continue;
          for(int i = 0; i < (int)g_[v].size(); ++i){
            edge &e = g_[v][i];
            int w = e.to;
            Capacity cap = e.cap;
            Cost cst = e.cost;
            if(cap > 0){
              if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){
                is_inf[w] = false;
                cost[w] = cost[v] + cst + h[v] - h[w];
                prev_node[w] = v;
                prev_edge[w] = i;
                pq.emplace(cost[w], w);
              }
            }
          }
        }

        if(is_inf[dst]) return {f - flow, ret}; // dstへ到達不可能

        for(int i = 0; i < size_; ++i) h[i] += cost[i];

        // src -> dst の最小コスト経路へ流せる量(df)を決定する。
        Capacity df = flow;
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          df = std::min(df, g_[prev_node[cur]][prev_edge[cur]].cap);
        }

        flow -= df;
        ret += df * h[dst];

        // capの更新
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          edge &e = g_[prev_node[cur]][prev_edge[cur]];
          e.cap -= df;
          g_[cur][e.rev].cap += df;
        }
      }

      return {f - flow, ret};
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for(auto &v : g_) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
