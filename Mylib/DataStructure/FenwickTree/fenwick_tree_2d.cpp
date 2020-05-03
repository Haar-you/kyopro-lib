#pragma once
#include <vector>

/**
 * @title FenwickTree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
      
  int w, h;
  std::vector<std::vector<value_type>> data;
      
public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w+1, std::vector<value_type>(h+1));
  }

private:
  inline value_type get_w(int i, int y) const {
    value_type ret = AbelianGroup::id();
    i += 1;
    while(i > 0){
      ret = AbelianGroup::op(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }
  
  inline value_type get_w(int l, int r, int y) const {
    return AbelianGroup::op(get_w(r-1, y), AbelianGroup::inv(get_w(l-1, y)));
  }

  inline value_type get(int x1, int x2, int y) const {
    value_type ret = AbelianGroup::id();
    y += 1;
    while(y > 0){
      ret = AbelianGroup::op(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }
  
public:
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    return AbelianGroup::op(get(x1, x2, y2-1), AbelianGroup::inv(get(x1, x2, y1-1)));
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = AbelianGroup::op(data[i][j], val);
      }
    }
  }
};