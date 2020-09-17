#pragma once
#include <vector>
#include <algorithm>

namespace haar_lib {
  namespace ford_fulkerson_impl {
    template <typename T>
    struct edge {
      int from, to, rev;
      T cap;
      bool is_rev;
      edge(int from, int to, int rev, T cap, bool is_rev):
        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}
    };
  }

  template <typename T>
  class ford_fulkerson {
    using edge = ford_fulkerson_impl::edge<T>;

    int size;
    std::vector<std::vector<edge>> g;
    std::vector<bool> visit;

    T dfs(int from, int to, T flow){
      if(from == to) return flow;
      visit[from] = true;

      for(auto &e : g[from]){
        if(!visit[e.to] and e.cap > 0){
          T d = dfs(e.to, to, std::min(flow, e.cap));
          if(d > 0){
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }

  public:
    ford_fulkerson(){}
    ford_fulkerson(int size): size(size), g(size), visit(size){}

    void add_edge(int from, int to, T c){
      g[from].emplace_back(from, to, (int)g[to].size(), c, false);
      g[to].emplace_back(to, from, (int)g[from].size() - 1, 0, true);
    }

    void reset_flow(){
      for(auto &v : g){
        for(auto &e : v){
          if(e.is_rev){
            g[e.to][e.rev].cap += e.cap;
            e.cap = 0;
          }
        }
      }
    }

    T solve(int s, int t){
      T ret = 0;

      while(1){
        visit.assign(size, false);
        T flow = dfs(s, t, std::numeric_limits<T>::max());
        if(flow == 0) return ret;
        ret += flow;
      }
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
