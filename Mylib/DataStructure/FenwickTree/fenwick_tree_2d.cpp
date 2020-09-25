#pragma once
#include <vector>

namespace haar_lib {
  template <typename AbelianGroup>
  class fenwick_tree_2d {
    using value_type = typename AbelianGroup::value_type;
    const static AbelianGroup G;

    int w, h;
    std::vector<std::vector<value_type>> data;

  private:
    value_type get_w(int i, int y) const {
      value_type ret = G();
      while(i > 0){
        ret = G(ret, data[i][y]);
        i -= i & (-i);
      }
      return ret;
    }

    value_type get_w(int l, int r, int y) const {
      return G(get_w(r, y), G.inv(get_w(l, y)));
    }

    value_type get(int x1, int x2, int y) const {
      value_type ret = G();
      while(y > 0){
        ret = G(ret, get_w(x1, x2, y));
        y -= y & (-y);
      }
      return ret;
    }

  public:
    fenwick_tree_2d(int width, int height){
      w = width;
      h = height;
      data = std::vector<std::vector<value_type>>(w + 1, std::vector<value_type>(h + 1));
    }

    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      return G(get(x1, x2, y2), G.inv(get(x1, x2, y1)));
    }

    value_type operator[](std::pair<int, int> p) const {
      const auto [x, y] = p;
      return fold({x, y}, {x + 1, y + 1});
    }

    void update(std::pair<int, int> p, const value_type &val){
      auto [x, y] = p;
      x += 1;
      y += 1;

      for(int i = x; i <= w; i += i & (-i)){
        for(int j = y; j <= h; j += j & (-j)){
          data[i][j] = G(data[i][j], val);
        }
      }
    }
  };
}
