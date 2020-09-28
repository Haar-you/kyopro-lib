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
  public:
    using edge = dinic_impl::edge<T>;
    using capacity_type = T;

  private:
    std::vector<std::vector<edge>> g_;
    std::vector<int> level_;

    bool build_level(int s, int t){
      std::fill(level_.begin(), level_.end(), 0);
      level_[s] = 1;
      std::queue<int> q;
      q.push(s);
      while(not q.empty()){
        int cur = q.front(); q.pop();
        for(auto &e : g_[cur]){
          if(level_[e.to] == 0 and e.cap > 0){
            level_[e.to] = level_[e.from] + 1;
            q.push(e.to);
          }
        }
      }
      return level_[t] != 0;
    }

    void dfs(std::vector<edge*> &path, T &flow, int cur, int t){
      if(cur == t){
        T f = std::numeric_limits<T>::max();

        for(auto e : path){
          f = std::min(f, (*e).cap);
        }

        for(auto e : path){
          (*e).cap -= f;
          g_[e->to][e->rev].cap += f;
        }

        flow += f;
      }else{
        for(auto &e : g_[cur]){
          if(e.cap > 0 and level_[e.to] > level_[e.from]){
            path.emplace_back(&e);
            dfs(path, flow, e.to, t);
            path.pop_back();
          }
        }
      }
    }

  public:
    dinic(){}
    dinic(int size): g_(size), level_(size){}

    void add_edge(int from, int to, T c){
      g_[from].emplace_back(from, to, (int)g_[to].size(), c, false);
      g_[to].emplace_back(to, from, (int)g_[from].size() - 1, 0, true);
    }

    T max_flow(int s, int t){
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
      for(auto &v : g_) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
