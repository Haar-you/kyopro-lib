#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <limits>

namespace haar_lib {
  namespace push_relabel_impl {
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
  class push_relabel {
  public:
    using edge = push_relabel_impl::edge<T>;
    using capacity_type = T;

  private:
    int N;
    std::vector<std::vector<edge>> g;
    std::vector<T> excess;
    std::vector<int> height;
    std::queue<int> next_active_vertex;
    constexpr static T inf = std::numeric_limits<T>::max();

    void init(int s, int t){
      excess[s] = inf;

      for(auto &e : g[s]){
        push(e, s, t);
      }

      {
        for(int i = 0; i < N; ++i){
          height[i] = N;
        }

        std::queue<int> q;
        std::vector<bool> check(N);
        q.push(t);
        height[t] = 0;

        while(not q.empty()){
          const int i = q.front(); q.pop();

          if(check[i]) continue;
          check[i] = true;

          for(auto &e : g[i]){
            if(not e.is_rev) continue;
            if(height[e.from] + 1 < height[e.to]){
              height[e.to] = height[e.from] + 1;
              q.push(e.to);
            }
          }
        }

        height[s] = N;
      }
    }

    bool is_pushable(const edge &e){
      if(excess[e.from] == 0) return false;
      if(height[e.from] != height[e.to] + 1) return false;
      if(e.cap == 0) return false;
      return true;
    }

    void push(edge &e, int, int){
      auto &r = g[e.to][e.rev];

      T flow = std::min(e.cap, excess[e.from]);

      e.cap -= flow;
      r.cap += flow;

      excess[e.from] -= flow;
      excess[e.to] += flow;

      if(excess[e.to] == flow) next_active_vertex.push(e.to);
    }

    void relabel(int i, int, int){
      int a = std::numeric_limits<int>::max() / 2;
      for(auto &e : g[i]){
        if(e.cap > 0) a = std::min(a, height[e.to]);
      }

      height[i] = a + 1;
    }

  public:
    push_relabel(){}
    push_relabel(int N): N(N), g(N), excess(N), height(N){}

    void add_edge(int from, int to, T c){
      g[from].emplace_back(from, to, (int)g[to].size(), c, false);
      g[to].emplace_back(to, from, (int)g[from].size() - 1, 0, true);
    }

    T max_flow(int s, int t){
      init(s, t);

      while(true){
        int index = -1;

        while(not next_active_vertex.empty()){
          int i = next_active_vertex.front();
          if(i != s and i != t and excess[i] > 0){
            index = i;
            break;
          }
          next_active_vertex.pop();
        }

        if(index == -1) break;

        bool ok = false;
        for(auto &e : g[index]){
          if(is_pushable(e)){
            push(e, s, t);
            ok = true;
            break;
          }
        }

        if(not ok){
          relabel(index, s, t);
        }
      }

      return excess[t];
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}
