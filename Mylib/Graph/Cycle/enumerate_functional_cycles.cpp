#pragma once
#include <vector>
#include <optional>
#include <algorithm>

/**
 * @title Enumerate cycles in functional graph
 * @docs enumerate_functional_cycles.md
 */
std::vector<std::vector<int>> enumerate_functional_cycles(std::vector<int> g){
  const int n = g.size();

  std::vector<std::vector<int>> ret;
  std::vector<int> check(n);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      const int i = g[cur];

      if(auto res = rec(rec, i, temp); res){
        if(*res != -1){
          temp.push_back(i);
          if(*res == cur){
            check[cur] = SEARCHED;
            return {-1};
          }
        }

        check[cur] = SEARCHED;
        return res;
      }

      check[cur] = SEARCHED;
      return std::nullopt;
    };

  for(int i = 0; i < n; ++i){
    if(check[i] == 0){
      std::vector<int> temp;
      auto res = rec(rec, i, temp);
      if(res){
        std::reverse(temp.begin(), temp.end());
        ret.push_back(temp);
      }
    }
  }

  return ret;
}
