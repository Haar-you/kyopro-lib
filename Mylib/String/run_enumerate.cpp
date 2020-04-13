#pragma once
#include <string>
#include <tuple>
#include <map>
#include <utility>
#include <algorithm>
#include "Mylib/String/z_algorithm.cpp"

/**
 * @title run enumerate
 */
struct RunEnumerate{
  std::vector<std::tuple<int,int,int>> result;

private:
  auto aux(const std::string &first, const std::string &second){
    std::vector<std::tuple<int,int,int>> ret;

    const int N = first.size(), M = second.size();
  
    auto a = z_algorithm(std::string(first.rbegin(), first.rend()));

    std::string t = second + '\0' + first + second;
    auto b = z_algorithm(t);

    for(int i = 1; i < N; ++i){
      int l1 = a[i];
      int l2 = b[second.size() + first.size() - i + 1];

      if(l1 + i == N or l2 == M or i > l1 + l2) continue;

      int l = N - i - l1, r = N + l2;
      int t = i;
      ret.emplace_back(t, l, r);
    }

    return ret;
  }

  void run(std::string s, int left = 0){
    if(s.size() == 1) return;

    const int N = s.size();
    const int m = N / 2;
    const std::string first = s.substr(0, m), second = s.substr(m);
  
    {
      auto res = aux(first, second);

      for(auto &[t, l, r] : res){
        result.emplace_back(t, left + l, left + r);
      }
    }

    {
      auto res = aux(std::string(second.rbegin(), second.rend()), std::string(first.rbegin(), first.rend()));

      for(auto &[t, l, r] : res){
        result.emplace_back(t, left + N - r, left + N - l);
      }
    }

    run(first, left);
    run(second, left + first.size());
  }

  void sub(std::string s){
    const int N = s.size();
    
    {
      auto a = z_algorithm(s);

      for(int i = 1; i < N; ++i){
        if(i <= a[i]){
          result.emplace_back(i, 0, i + a[i]);
        }
      }
    }
    
    {
      auto a = z_algorithm(std::string(s.rbegin(), s.rend()));

      for(int i = 1; i < N; ++i){
        if(i <= a[i]){
          result.emplace_back(i, N - i - a[i], N);
        }
      }
    }
  }

public:
  RunEnumerate(const std::string &s){
    run(s);
    sub(s);

    std::map<std::pair<int,int>, int> m;

    for(auto &[t,l,r] : result){
      auto p = std::make_pair(l, r);

      if(m.find(p) != m.end()){
        m[p] = std::min(m[p], t);
      }else{
        m[p] = t;
      }
    }

    result.clear();

    for(auto &[p, t] : m){
      result.emplace_back(t, p.first, p.second);
    }

    std::sort(result.begin(), result.end());
  }
};
