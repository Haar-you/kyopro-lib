#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615"

#include <iostream>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/Graph/Flow/max_flow_with_lower_bound.cpp"
#include "Mylib/Graph/Flow/dinic.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m;

  while(std::cin >> n >> m, n){
    auto [u, v] = hl::input_tuple_vector<int, int>(m);
    for(auto &x : u) --x;
    for(auto &x : v) --x;

    auto check =
      [&](int lb, int ub) -> bool {
        hl::max_flow_with_lower_bound<hl::dinic<int>> flow(n + m + 2);

        const int s = n + m, t = s + 1;

        for(int i = 0; i < m; ++i){
          flow.add_edge(s, i, 1, 1);
          flow.add_edge(i, m + u[i], 0, 1);
          flow.add_edge(i, m + v[i], 0, 1);
        }

        for(int i = 0; i < n; ++i){
          flow.add_edge(m + i, t, lb, ub);
        }

        return flow.max_flow(s, t).value_or(-1) == m;
      };

    int lb = 0, ub = n;
    for(int l = 0, r = 0; r <= n; ++r){
      while(l <= r and check(l, r)){
        lb = l;
        ub = r;
        ++l;
      }
    }

    std::cout << lb << " " << ub << "\n";
  }

  return 0;
}
