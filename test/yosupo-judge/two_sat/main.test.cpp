#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/Graph/two_sat.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::string p, cnf;
  int N,M;
  std::cin >> p >> cnf >> N >> M;

  TwoSat sat(N);

  for(int i = 0; i < M; ++i){
    int a,b,c; std::cin >> a >> b >> c;
    sat.add_or(a,b);
  }

  if(auto res = sat.solve(); res){
    std::cout << "s SATISFIABLE" << std::endl;
    std::vector<int> ans(N);

    for(int i = 0; i < N; ++i) ans[i] = (*res)[i] ? i+1 : -(i+1);

    std::cout << "v " << join(ans.begin(), ans.end()) << " " << 0;
  }else{
    std::cout << "s UNSATISFIABLE" << std::endl;
  }

  return 0;
}
