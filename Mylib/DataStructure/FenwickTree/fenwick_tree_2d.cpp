#pragma once
#include <vector>
#include <cassert>

namespace haar_lib {
  template <typename AbelianGroup>
  class fenwick_tree_2d {
  public:
    using value_type = typename AbelianGroup::value_type;

  private:
    AbelianGroup G_;

    int w_, h_;
    std::vector<std::vector<value_type>> data_;

  private:
    value_type get_w(int i, int y) const {
      value_type ret = G_();
      while(i > 0){
        ret = G_(ret, data_[i][y]);
        i -= i & (-i);
      }
      return ret;
    }

    value_type get_w(int l, int r, int y) const {
      return G_(get_w(r, y), G_.inv(get_w(l, y)));
    }

    value_type get(int x1, int x2, int y) const {
      value_type ret = G_();
      while(y > 0){
        ret = G_(ret, get_w(x1, x2, y));
        y -= y & (-y);
      }
      return ret;
    }

  public:
    fenwick_tree_2d(){}
    fenwick_tree_2d(int width, int height):
      w_(width), h_(height), data_(w_ + 1, std::vector<value_type>(h_ + 1, G_())){}

    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      assert(0 <= x1 and x1 <= x2 and x2 <= w_);
      assert(0 <= y1 and y1 <= y2 and y2 <= h_);
      return G_(get(x1, x2, y2), G_.inv(get(x1, x2, y1)));
    }

    value_type operator[](std::pair<int, int> p) const {
      const auto [x, y] = p;
      return fold({x, y}, {x + 1, y + 1});
    }

    void update(std::pair<int, int> p, const value_type &val){
      auto [x, y] = p;
      assert(0 <= x and x < w_);
      assert(0 <= y and y < h_);
      x += 1;
      y += 1;

      for(int i = x; i <= w_; i += i & (-i)){
        for(int j = y; j <= h_; j += j & (-j)){
          data_[i][j] = G_(data_[i][j], val);
        }
      }
    }
  };
}
