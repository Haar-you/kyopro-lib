#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Bellman-Ford algorithm
 * @docs bellman_ford.md
 */
namespace haar_lib {
  namespace bellman_ford_impl {
    template <typename T>
    struct Result {
      enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
      T val;
      Result(Tag tag): tag(tag){}

    public:
      static auto unreachable() {return Result(Tag::UNREACHABLE);}
      static auto negloop() {return Result(Tag::NEGLOOP);}
      Result(T val): tag(Tag::OK), val(val){}

      bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
      bool is_negloop() const {return tag == Tag::NEGLOOP;}
      bool is_ok() const {return tag == Tag::OK;}

      T value() const {
        assert(tag == Tag::OK);
        return val;
      }

      friend std::ostream& operator<<(std::ostream &s, const Result &a){
        if(a.is_unreachable()) s << "∞";
        else if(a.is_negloop()) s << "-∞";
        else s << a.value();
        return s;
      }
    };
  }

  template <typename T>
  auto bellman_ford(const Graph<T> &g, int src){
    using Result = bellman_ford_impl::Result<T>;
    const int n = g.size();
    std::vector<Result> dist(n, Result::unreachable());

    dist[src] = 0;

    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : g[s]){
          int t = e.to;
          T d = e.cost;

          if(dist[s].is_ok() and
             dist[t].is_ok() and
             dist[s].value() + d < dist[t].value() and i == n - 1){
            dist[t] = Result::negloop();
          }else{
            if(dist[s].is_ok()){
              if(dist[t].is_unreachable()){
                dist[t] = dist[s].value() + d;
              }else if(dist[t].is_ok()){
                dist[t] = std::min(dist[t].value(), dist[s].value() + d);
              }
            }
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : g[s]){
          if(dist[s].is_negloop()){
            dist[e.to] = Result::negloop();
          }
        }
      }
    }

    return dist;
  }
}
