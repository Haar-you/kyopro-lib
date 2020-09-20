#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include "Mylib/Typical/SubsetSumProblem/subset_sum_limited.cpp"

namespace hl = haar_lib;

int main(){
  int V, E; std::cin >> V >> E;

  hl::graph<int> g(V);
  g.read<1, false, false>(E);

  auto res = hl::check_bipartite_graph(g);

  if(std::all_of(res.begin(), res.end(), [](const auto &a){return (bool)a;})){
    int k = 0;

    std::map<int, int> c;

    for(auto &x : res){
      int a = (*x).first.size();
      int b = (*x).second.size();

      k += std::min(a, b);

      c[std::abs(a - b)] += 1;
    }

    std::vector<int> a, m;
    for(auto &p : c){
      a.push_back(p.first);
      m.push_back(p.second);
    }

    auto r = hl::subset_sum_limited(c.size(), V, a, m);

    int64_t ans = 0;

    for(int i = 0; i <= V; ++i){
      if(r[i]){
        int64_t a = k + i;
        ans = std::max(ans, a * (V - a));
      }
    }

    ans -= E;
    std::cout << ans << "\n";
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}
