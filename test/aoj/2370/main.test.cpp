#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"


int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int a, b; std::cin >> a >> b;
    --a, --b;
    add_undirected(g, a, b, 1);
  }

  auto res = check_bipartite_graph(g);
  
  if(std::all_of(res.begin(), res.end(), [](const auto &a){return (bool)a;})){
    int k = 0;

    std::map<int, int> c;

    for(auto &x : res){
      int a = (*x).first.size();
      int b = (*x).second.size();

      k += std::min(a, b);
      
      c[std::abs(a-b)] += 1;
    }

    std::vector<int> a, m;
    for(auto &p : c){
      a.push_back(p.first);
      m.push_back(p.second);
    }

    auto r = subset_sum_limited(c.size(), V, a, m);

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
