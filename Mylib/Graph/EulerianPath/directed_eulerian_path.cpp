#pragma once
#include <vector>
#include <map>
#include <optional>
#include <algorithm>

namespace haar_lib {
  class directed_eulerian_path {
    int n_, edges_;
    std::vector<std::unordered_map<int, int>> g_;
    std::vector<int> indeg_, outdeg_;

    void del(int i, int j){
      if(g_[i][j] == 1) g_[i].erase(j);
      else --g_[i][j];
    }

    void dfs(int cur, std::vector<int> &path){
      if(not g_[cur].empty()){
        const int next = g_[cur].begin()->first;
        del(cur, next);
        dfs(next, path);
      }

      while(not g_[cur].empty()){
        const int next = g_[cur].begin()->first;
        del(cur, next);
        std::vector<int> temp;
        dfs(next, temp);
        path.insert(path.end(), temp.begin(), temp.end());
      }

      path.push_back(cur);
    }

  public:
    directed_eulerian_path(){}
    directed_eulerian_path(int n): n_(n), edges_(0), g_(n), indeg_(n), outdeg_(n){}

    void add_edge(int i, int j){
      ++g_[i][j];
      ++outdeg_[i];
      ++indeg_[j];
      ++edges_;
    }

    std::optional<std::vector<int>> eulerian_path(){
      int in = 0, out = 0, start = 0;

      for(int i = 0; i < n_; ++i){
        const int d = outdeg_[i] - indeg_[i];
        if(std::abs(d) > 1) return std::nullopt;
        if(d == 1){
          ++out;
          start = i;
        }else if(d == -1){
          ++in;
        }
      }

      if(not ((in == 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;

      std::vector<int> ret;

      dfs(start, ret);
      std::reverse(ret.begin(), ret.end());
      if((int)ret.size() == edges_ + 1){
        return ret;
      }else{
        return std::nullopt;
      }
    }
  };
}
