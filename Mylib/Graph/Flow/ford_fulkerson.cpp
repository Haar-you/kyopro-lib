#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Ford-Fulkerson algorithm
 * @docs ford_fulkerson.md
 */
namespace haar_lib {
  template <typename T>
  class ford_fulkerson {
  public:
    struct edge {
      int from, to, rev;
      T cap;
      bool is_rev;
    };

  private:
    int size;

    std::vector<std::vector<edge>> graph;
    std::vector<bool> visit;

    T dfs(int from, int to, T flow){
      if(from == to) return flow;
      visit[from] = true;

      for(auto &e : graph[from]){
        if(!visit[e.to] and e.cap > 0){
          T d = dfs(e.to, to, std::min(flow, e.cap));
          if(d > 0){
            e.cap -= d;
            graph[e.to][e.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }

  public:
    ford_fulkerson(){}
    ford_fulkerson(int size): size(size), graph(size), visit(size){}

    void add_edge(int from, int to, const T &cap){
      graph[from].push_back({from, to, (int)graph[to].size(), cap, false});
      graph[to].push_back({to, from, (int)graph[from].size() - 1, 0, true});
    }

    void reset_flow(){
      for(auto &v : graph){
        for(auto &e : v){
          if(e.is_rev){
            graph[e.to][e.rev].cap += e.cap;
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
      for(auto &v : graph) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
