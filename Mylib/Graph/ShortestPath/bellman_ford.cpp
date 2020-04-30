#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Bellman-Ford法
 * @docs bellman_ford.md
 */
template <typename T>
struct BellmanFord{
  struct Result{
    enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
    T val;

  public:
    static auto unreachable() {return Result(Tag::UNREACHABLE);}
    static auto negloop() {return Result(Tag::NEGLOOP);}
    Result(Tag tag): tag(tag){}
    Result(T val): tag(Tag::OK), val(val){}

    bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
    bool is_negloop() const {return tag == Tag::NEGLOOP;}
    bool is_ok() const {return tag == Tag::OK;}

    T value() const {
      assert(tag == Tag::OK);
      return val;
    }
  };
  
  int n;
  std::vector<Result> dist;
  
  BellmanFord(const Graph<T> &graph, int src):
    n(graph.size()),
    dist(n, Result::unreachable())
  {
    dist[src] = 0;
    
    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : graph[s]){
          int t = e.to;
          T d = e.cost;
          
          if(dist[s].is_ok() and
             dist[t].is_ok() and
             dist[s].value() + d < dist[t].value() and i == n-1){
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
        for(auto &e : graph[s]){
          if(dist[s].is_negloop()){
            dist[e.to] = Result::negloop();
          }
        }
      }
    }
  }
};
