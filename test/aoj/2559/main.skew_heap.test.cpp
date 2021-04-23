#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559"

#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
#include "Mylib/DataStructure/Heap/skew_heap.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Misc/merge_technique.cpp"
#include "Mylib/Utils/fix_point.cpp"

namespace hl = haar_lib;

int main() {
  int n, m;
  std::cin >> n >> m;

  hl::graph<int64_t> g(n);
  g.read<1, false>(m);

  std::map<std::pair<int, int>, int> index;
  for (auto &a : g) {
    for (auto &e : a) index[{e.from, e.to}] = e.index;
  }

  auto res = hl::prim(g);

  std::vector<int64_t> ans(m, -1);

  if ((int) res.size() == n - 1) {
    int64_t s = 0;
    hl::tree<int64_t> tree(n);

    for (auto &e : res) {
      s += e.cost;
      tree[e.from].push_back(e);
    }

    ans.assign(m, s);

    std::vector<hl::skew_heap<std::tuple<int64_t, int, int>, std::greater<>>> heaps(n);

    std::vector<std::set<int>> sub(n);

    hl::make_fix_point(
        [&](auto &&f, int cur, int par, int64_t cost) -> void {
          for (auto &e : g[cur]) {
            heaps[cur].push({e.cost, e.from, e.to});
          }

          sub[cur].insert(cur);

          for (auto &e : tree[cur]) {
            if (e.to == par) continue;
            f(e.to, cur, e.cost);

            heaps[cur].meld(heaps[e.to]);
            hl::merge_technique(sub[cur], sub[cur], sub[e.to]);
          }

          if (par != -1) {
            while (not heaps[cur].empty()) {
              auto [c, i, j] = heaps[cur].top();
              if ((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or
                  (i == cur and j == par) or (i == par and j == cur)) {
                heaps[cur].pop();
              } else {
                break;
              }
            }

            if (not heaps[cur].empty()) {
              ans[index[{cur, par}]] = s - cost + std::get<0>(heaps[cur].top());
            } else {
              ans[index[{cur, par}]] = -1;
            }
          }
        })(0, -1, 0);
  }

  for (auto x : ans) {
    std::cout << x << std::endl;
  }

  return 0;
}
