#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058"

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "Mylib/Graph/project_selection_problem.cpp"
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N, M; std::cin >> N >> M;
  std::string U; std::cin >> U;

  auto A = hl::input_vector<int>(N);

  hl::project_selection_problem<int, hl::ford_fulkerson<int>> psp(N);
  // red: right, blue: left

  for(int i = 0; i < N; ++i){
    if(U[i] == 'R'){
      psp.penalty_if_blue(i, A[i]);
    }else{
      psp.penalty_if_red(i, A[i]);
    }
  }

  for(auto [s, t, b] : hl::input_tuples<int, int, int>(M)){
    --s, --t;
    if(s > t) std::swap(s, t);
    psp.penalty_if_red_blue(s, t, b);
  }

  auto ans = -psp.solve();
  std::cout << ans << std::endl;

  return 0;
}
