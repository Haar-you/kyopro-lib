#pragma once
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

namespace haar_lib {
  namespace dinic_impl {
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
  class dinic {
    using edge = dinic_impl::edge<T>;

    int size;
    std::vector<std::vector<edge>> g;
    std::vector<int> level;

    bool build_level(int s, int t){
      std::fill(level.begin(), level.end(), 0);
      level[s] = 1;
      std::queue<int> q;
      q.push(s);
      while(not q.empty()){
        int cur = q.front(); q.pop();
        for(auto &e : g[cur]){
          if(level[e.to] == 0 and e.cap > 0){
            level[e.to] = level[e.from] + 1;
            q.push(e.to);
          }
        }
      }
      return level[t] != 0;
    }

    void dfs(std::vector<edge*> &path, T &flow, int cur, int t){
      if(cur == t){
        T f = std::numeric_limits<T>::max();

        for(auto e : path){
          f = std::min(f, (*e).cap);
        }

        for(auto e : path){
          (*e).cap -= f;
          g[e->to][e->rev].cap += f;
        }

        flow += f;
      }else{
        for(auto &e : g[cur]){
          if(e.cap > 0 and level[e.to] > level[e.from]){
            path.emplace_back(&e);
            dfs(path, flow, e.to, t);
            path.pop_back();
          }
        }
      }
    }

  public:
    dinic(){}
    dinic(int size): size(size), g(size), level(size){}

    void add_edge(int from, int to, T c){
      g[from].emplace_back(from, to, (int)g[to].size(), c, false);
      g[to].emplace_back(to, from, (int)g[from].size() - 1, 0, true);
    }

    T solve(int s, int t){
      T f = 0;
      while(build_level(s, t)){
        T a = 0;
        std::vector<edge*> path;
        dfs(path, a, s, t);
        f += a;
      }
      return f;
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
