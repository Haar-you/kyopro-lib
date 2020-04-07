#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903"

#include <iostream>
#include <vector>
#include <string>

#include "Mylib/Graph/project_selection_problem.cpp"
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"

int main(){
  int R, C; std::cin >> R >> C;
  std::vector<std::string> S(R);
  for(int i = 0; i < R; ++i) std::cin >> S[i];

  ProjectSelectionProblem<int, FordFulkerson<int>> psp(R*C);
  // red: horizontal
  // blue: vertical

  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      if(S[i][j] == '#'){
        int k = i*C+j;
        psp.penalty_if_red(k, 1);
        psp.penalty_if_blue(k, 1);
      }
    }
  }

  for(int i = 1; i < R; ++i){
    for(int j = 0; j < C; ++j){
      if(S[i][j] == '#' and S[i-1][j] == '#'){
        psp.gain_if_blue_blue(i*C+j, (i-1)*C+j, 1);
      }
    }
  }

  for(int i = 0; i < R; ++i){
    for(int j = 1; j < C; ++j){
      if(S[i][j] == '#' and S[i][j-1] == '#'){
        psp.gain_if_red_red(i*C+j, i*C+(j-1), 1);
      }
    }
  }
  
  int ans = -psp.solve();
  std::cout << ans << std::endl;

  return 0;
}
