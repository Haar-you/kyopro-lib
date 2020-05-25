#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0575"

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/Algorithm/Search/parallel_binary_search.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M, K, Q; std::cin >> N >> M >> K >> Q;

  Graph<int> g(N);
  for(int i = 0; i < M; ++i){
    int A, B, L; std::cin >> A >> B >> L;
    --A, --B;
    add_undirected(g, A, B, L);
  }

  std::vector<int> F(K);
  for(int i = 0; i < K; ++i){
    std::cin >> F[i];
    --F[i];
  }

  std::vector<int> S(Q), T(Q);
  for(int i = 0; i < Q; ++i){
    std::cin >> S[i] >> T[i];
    --S[i], --T[i];
  }

  auto dist = Dijkstra(g, F).dist;

  std::vector<int> dist_list;
  for(auto &x : dist){
    dist_list.push_back(*x);
  }

  std::sort(dist_list.begin(), dist_list.end());
  dist_list.erase(std::unique(dist_list.begin(), dist_list.end()), dist_list.end());

  const int C = dist_list.size();

  std::vector<std::vector<std::pair<int, int>>> edges(C);
  for(int i = 0; i < N; ++i){
    for(auto &e : g[i]){
      if(*dist[e.from] <= *dist[e.to]){
        int x = std::lower_bound(dist_list.begin(), dist_list.end(), *dist[e.from]) - dist_list.begin();
        edges[x].emplace_back(e.from, e.to);
      }
    }
  }

  auto res =
    parallel_binary_search(
      C,
      Q,
      [&](const auto &f){
        UnionFind uf(N);
        f(
          [&](int i){
            for(auto [x, y] : edges[C-1-i]){
              uf.merge(x, y);
            }
          },
          [&](int i) -> bool{
            return uf.is_same(S[i], T[i]);
          }
        );
      }
    );
  
  for(auto x : res){
    std::cout << dist_list[C-x-1] << "\n";
  }  
  
  return 0;
}

