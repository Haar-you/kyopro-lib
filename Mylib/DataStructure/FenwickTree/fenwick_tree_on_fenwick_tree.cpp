#pragma once
#include <vector>
#include <numeric>
#include <algorithm>

#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"

template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;

  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int> c_xs;

  std::vector<std::vector<int>> c_ys;

  int x_size;

  std::vector<FenwickTree<AbelianGroup>> segs;

public:
  FenwickTree2D(){}

  void add(int64_t x, int64_t y){
    xs.push_back(x);
    ys.push_back(y);
    ++N;
  }

  void build(){
    c_xs.insert(c_xs.end(), xs.begin(), xs.end());

    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    x_size = c_xs.size();

    c_ys.resize(x_size + 1);
    segs.resize(x_size + 1);


    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j){return ys[i] < ys[j];});
    for(auto i : ord){
      int x = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();

      for(x += 1; x <= x_size; x += x & (-x)){
        c_ys[x].emplace_back(ys[i]);
      }
    }
    
    for(int i = 1; i <= x_size; ++i){
      auto &a = c_ys[i];
      a.erase(std::unique(a.begin(), a.end()), a.end());
      
      segs[i] = FenwickTree<AbelianGroup>(c_ys[i].size());
    }
  }

  inline void update(int64_t x, int64_t y, const value_type &val){
    int i = std::lower_bound(c_xs.begin(), c_xs.end(), x) - c_xs.begin();

    for(i += 1; i <= x_size; i += i & (-i)){
      int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();
      segs[i].update(j, val);
    }
  }

private:
  inline value_type get(int i, int64_t y1, int64_t y2) const {
    value_type ret = AbelianGroup::id();
    for(; i > 0; i -= i & (-i)){
      int l = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();
      int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();
      ret = AbelianGroup::op(ret, segs[i].get(l, r));
    }
    return ret;
  }

public:
  // [x1, x2), [y1, y2)
  inline value_type get(int64_t x1, int64_t y1, int64_t x2, int64_t y2) const {
    int l = std::lower_bound(c_xs.begin(), c_xs.end(), x1) - c_xs.begin();
    int r = std::lower_bound(c_xs.begin(), c_xs.end(), x2) - c_xs.begin();
    return AbelianGroup::inv(get(r, y1, y2), get(l, y1, y2));
  }
};
