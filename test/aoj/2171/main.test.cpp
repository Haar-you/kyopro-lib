#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171"
#define ERROR 1e-8

#include <iostream>
#include <vector>
#include <iomanip>

#include "Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/float_simultaneous_linear_equations.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n,s,t;
  while(std::cin >> n >> s >> t, n){
    --s, --t;

    std::vector<int> q(n);
    for(int i = 0; i < n; ++i) std::cin >> q[i];
    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        std::cin >> g[i][j];
      }
    }

    auto dist = WarshallFloyd<int, 0>(g).dist;

    if(not dist[s][t]){
      std::cout << "impossible" << std::endl;
      continue;
    }

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);

    for(int i = 0; i < n; ++i){
      if(i == t){
        a[i][i] = 1;
        b[i] = 0;
        continue;
      }

      if(q[i]){
        int d = *dist[i][t];

        int k = 0;
        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){
            ++k;
          }
        }

        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      }else{
        int k = 0;
        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0){
            ++k;
          }
        }

        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0){
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }
	
        a[i][i] += k;
      }
    }


    auto res = float_simultaneous_linear_equations::solve(a, b, ERROR);
    
    double ans = (*res).solution[s];
    std::cout << std::setprecision(12) << std::fixed << ans << std::endl;
  }
  
  return 0;
}
