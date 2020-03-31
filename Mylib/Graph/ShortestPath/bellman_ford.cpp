#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

template <typename T>
struct BellmanFord{
  struct Result{
    enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;
    T value;

    static auto unreachable() {return Result(Tag::UNREACHABLE);}
    static auto negloop() {return Result(Tag::NEGLOOP);}
    Result(Tag tag): tag(tag){}
    Result(T value): tag(Tag::OK), value(value){}

    bool is_unreachable() const {return tag == Tag::UNREACHABLE;}
    bool is_negloop() const {return tag == Tag::NEGLOOP;}
    bool is_ok() const {return tag == Tag::OK;}
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
          
          if(not dist[s].is_unreachable() and
             not dist[t].is_unreachable() and
             dist[s].value + d < dist[t].value and i == n-1){
            dist[t] = Result::negloop();
          }else{
            if(dist[s].is_ok()){
              if(dist[t].is_unreachable()){
                dist[t] = dist[s].value + d;
              }else{
                dist[t] = std::min(dist[t].value, dist[s].value + d);
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
