#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include "Mylib/Misc/fix_point.cpp"
#include "Mylib/DataStructure/Heap/binomial_heap.cpp"
#include "Mylib/Misc/merge_technique.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int n, m; std::cin >> n >> m;

  auto edges = input_edges<int64_t, 1, true>(m);
  auto g = convert_to_graph<int64_t, false>(n, edges);

  std::map<std::pair<int,int>, int> index;
  for(int i = 0; i < m; ++i){
    const auto &e = edges[i];
    index[{e.from, e.to}] = index[{e.to, e.from}] = i;
  }

  auto res = prim(g);

  std::vector<int64_t> ans(m, -1);

  if((int)res.size() == n-1){
    int64_t s = 0;
    Tree<int64_t> tree(n);

    for(auto &e : res){
      s += e.cost;
      tree[e.from].push_back(e);
    }

    ans.assign(m, s);

    std::vector<
      BinomialHeap<std::tuple<int64_t, int, int>, std::greater<std::tuple<int64_t, int, int>>>
      > sh(n);
    
    std::vector<std::set<int>> sub(n);

    make_fix_point(
      [&](auto &&f, int cur, int par, int64_t cost) -> void{
        for(auto &e : g[cur]){
          sh[cur].push({e.cost, e.from, e.to});
        }

        sub[cur].insert(cur);

        for(auto &e : tree[cur]){
          if(e.to == par) continue;
          f(e.to, cur, e.cost);

          sh[cur].meld(sh[e.to]);
          merge_technique(sub[cur], sub[cur], sub[e.to]);
        }

        if(par != -1){
          while(not sh[cur].empty()){
            auto [c, i, j] = sh[cur].top();
            if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or
               (i == cur and j == par) or (i == par and j == cur)){
              sh[cur].pop();
            }else{
              break;
            }
          }

          if(not sh[cur].empty()){
            ans[index[{cur, par}]] = s - cost + std::get<0>(sh[cur].top());
          }else{
            ans[index[{cur, par}]] = -1;
          }
        }
      }
    )(0, -1, 0);
  }

  for(auto x : ans){
    std::cout << x << std::endl;
  }

  return 0;
}
