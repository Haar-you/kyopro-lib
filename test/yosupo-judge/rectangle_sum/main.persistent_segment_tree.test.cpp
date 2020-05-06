#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>

#include "Mylib/Misc/sort_all.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/persistent_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

using Seg = PersistentSegmentTree<SumMonoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> x(N), y(N), w(N);
  for(int i = 0; i < N; ++i){
    std::cin >> x[i] >> y[i] >> w[i];
  }

  sort_all::run([&](int i, int j){return y[i] < y[j];}, N, x, y, w);

  std::vector<int64_t> c(x);
  std::sort(c.begin(), c.end());
  c.erase(std::unique(c.begin(), c.end()), c.end());
  for(int i = 0; i < N; ++i) x[i] = std::lower_bound(c.begin(), c.end(), x[i]) - c.begin();
  const int m = c.size();
  
  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s.at(x[i]) + w[i]));
  }
  
  for(int i = 0; i < Q; ++i){
    int64_t l, r, u, d; std::cin >> l >> d >> r >> u;
    
    l = std::lower_bound(c.begin(), c.end(), l) - c.begin();
    r = std::lower_bound(c.begin(), c.end(), r) - c.begin();

    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();
    d = std::lower_bound(y.begin(), y.end(), d) - y.begin();

    auto ans = seg[u].get(l, r) - seg[d].get(l, r);
    std::cout << ans << "\n";
  }
  
  return 0;
}
