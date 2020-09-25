#pragma once
#include <vector>
#include <utility>

template <typename F>
std::pair<int, int> rho(int N, int first, F f){
  std::vector<int> check(N);

  int tail = 0, cycle = 0;
  int a = first, i = 1;
  while(true){
    check[a] = i;

    a = f(a);
    ++i;
    if(check[a] > 0){
      tail = check[a] - 1;
      cycle = i - check[a];
      break;
    }
  }

  return {tail, cycle};
}
