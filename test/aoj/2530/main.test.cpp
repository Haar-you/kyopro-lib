#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530"

#include <iostream>
#include <vector>
#include <bitset>
#include "Mylib/Number/Mod/mod_power.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"
 
constexpr int64_t mod = 1000000009;
 
using B = std::bitset<2500>;
 
int main(){
  int R, C; std::cin >> R >> C;
 
  std::vector<std::vector<int>> f(R, std::vector<int>(C));
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      std::cin >> f[i][j];
    }
  }
 
  std::vector<std::vector<int>> index(R, std::vector<int>(C));
  {
    int c = 0;
    for(int i = 0; i < R; ++i){
      for(int j = 0; j < C; ++j){
        index[i][j] = c;
        ++c;
      }
    }
  }
  
  std::vector<B> a(R*C);
  std::vector<bool> b(R*C);
 
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      b[index[i][j]] = f[i][j];
 
      for(int p = 0; p < R; ++p){
        for(int q = 0; q < C; ++q){
          if(abs(i-p) == abs(j-q) or i == p or j == q){
            a[index[p][q]][index[i][j]] = true;
          }
        }
      }
    }
  }
 
  auto res = binary_simultaneous_linear_equations::solve(a, b);
 
  int64_t ans = 0;
  if(res){
    ans = power(2, R*C-(*res).rank, mod);
  }
 
  std::cout << ans << std::endl;
 
  return 0;
}