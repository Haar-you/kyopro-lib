#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <tuple>

namespace haar_lib {
  template <typename T, typename U>
  class minimum_cost_flow {
  public:
    struct edge {
      int from, to;
      T cap;
      U cost;
      int rev;
      bool is_rev;
      edge(int from, int to, T cap, U cost, int rev, bool is_rev):
        from(from), to(to), cap(cap), cost(cost), rev(rev), is_rev(is_rev){}
    };

  private:
    int size;
    std::vector<std::vector<edge>> g;

  public:
    minimum_cost_flow(){}
    minimum_cost_flow(int size): size(size), g(size){}

    void add_edge(int from, int to, T cap, U cost){
      g[from].emplace_back(from, to, cap, cost, g[to].size(), false);
      g[to].emplace_back(to, from, 0, -cost, g[from].size() - 1, true);
    }

    std::pair<T, U> solve(int src, int dst, const T &f){
      using P = std::pair<U, int>;
      U ret = 0;
      T flow = f;
      std::vector<U> h(size, 0), cost(size);
      std::vector<bool> is_inf(size, true);
      std::vector<int> prev_node(size), prev_edge(size);
      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      while(flow > 0){
        std::fill(is_inf.begin(), is_inf.end(), true);

        // src -> dst の最小コスト経路を探索する。 (dijkstra algorithm)
        cost[src] = 0;
        pq.emplace(0, src);
        is_inf[src] = false;

        while(!pq.empty()){
          U c;
          int v;
          std::tie(c, v) = pq.top(); pq.pop();

          if(cost[v] < c) continue;
          for(int i = 0; i < (int)g[v].size(); ++i){
            edge &e = g[v][i];
            int w = e.to;
            T cap = e.cap;
            U cst = e.cost;
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

        for(int i = 0; i < size; ++i) h[i] += cost[i];

        // src -> dst の最小コスト経路へ流せる量(df)を決定する。
        T df = flow;
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);
        }

        flow -= df;
        ret += df * h[dst];

        // capの更新
        for(int cur = dst; cur != src; cur = prev_node[cur]){
          edge &e = g[prev_node[cur]][prev_edge[cur]];
          e.cap -= df;
          g[cur][e.rev].cap += df;
        }
      }

      return {f - flow, ret};
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
