#pragma once
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>

namespace haar_lib {
  template <typename F>
  std::vector<int> tsp_2_opt(int N, int src, F dist){
    std::mt19937 rand(0);
    std::vector<int> path(N, -1);

    std::unordered_set<int> nodes;
    for(int i = 0; i < N; ++i) if(i != src) nodes.insert(i);

    int cur = src;
    for(int i = 0; i < N - 1; ++i){
      auto it = std::min_element(
        nodes.begin(), nodes.end(),
        [&](const auto &a, const auto &b){return dist(cur, a) < dist(cur, b);}
      );

      path[cur] = *it;
      cur = *it;

      nodes.erase(it);
    }

    path[cur] = src;

    {
      int LOOP = 10000;

      while(LOOP--){
        int i = rand() % N;
        int j = rand() % N;

        int a = path[i];
        int b = path[j];

        if(a == b or i == j or i == a or i == b or j == a or j == b) continue;

        if(dist(i, j) + dist(a, b) < dist(i, a) + dist(j, b)){

          int x = a;
          int y;
          int z = path[x];

          while(true){
            y = z;
            z = path[y];

            path[y] = x;

            x = y;

            if(x == j) break;
          }

          path[i] = j;
          path[a] = b;
        }
      }
    }

    std::vector<int> ret;

    {
      int cur = src;
      std::vector<bool> check(N);

      do{
        ret.push_back(cur);
        check[cur] = true;

        int next = path[cur];
        cur = next;
      }while((int)ret.size() < N);
    }

    return ret;
  }
}
