#pragma once
#include <vector>

/**
 * @title Fenwick tree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
  const static AbelianGroup G;
  
  int w, h;
  std::vector<std::vector<value_type>> data;

private:
  value_type get_w(int i, int y) const {
    value_type ret = G();
    i += 1;
    while(i > 0){
      ret = G(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }
  
  value_type get_w(int l, int r, int y) const {
    return G(get_w(r-1, y), G.inv(get_w(l-1, y)));
  }

  value_type get(int x1, int x2, int y) const {
    value_type ret = G();
    y += 1;
    while(y > 0){
      ret = G(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }
  
public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w+1, std::vector<value_type>(h+1));
  }

  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    return G(get(x1, x2, y2-1), G.inv(get(x1, x2, y1-1)));
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = G(data[i][j], val);
      }
    }
  }
};
