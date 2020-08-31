#pragma once
#include <vector>

/**
 * @title Segment tree (2D)
 * @docs segment_tree_2d.md
 */
template <typename Monoid>
class SegmentTree2D{
  using value_type = typename Monoid::value_type;
  const static Monoid M;
  
  int w, h;
  std::vector<std::vector<value_type>> data;

  value_type get_w(int l, int r, int y) const {
    l += w / 2;
    r += w / 2;

    value_type ret = M();

    while(l < r){
      if(r & 1) ret = M(ret, data[--r][y]);
      if(l & 1) ret = M(ret, data[l++][y]);
      l >>= 1, r >>= 1;
    }
    
    return ret;
  }
      
public:
  SegmentTree2D(int width, int height){
    w = 1;
    while(w < width) w *= 2;
    w = w*2;
    
    h = 1;
    while(h < height) h *= 2;
    h = h*2;
        
    data = std::vector<std::vector<value_type>>(w, std::vector<value_type>(h));
  }
     
  value_type get(std::pair<int, int> p1, std::pair<int, int> p2) const { // [(x1,y1),(x2,y2))
    const auto [x1, y1] = p1;
    const auto [x2, y2] = p2;
    int l = y1 + h / 2;
    int r = y2 + h / 2;

    value_type ret = M();

    while(l < r){
      if(r & 1) ret = M(ret, get_w(x1, x2, --r));
      if(l & 1) ret = M(ret, get_w(x1, x2, l++));
      l >>= 1, r >>= 1;
    }

    return ret;
  }
  
  value_type operator[](std::pair<int, int> p) const {
    auto [x, y] = p;
    return data[w / 2 + x][h / 2 + y];
  }
     
  void update(std::pair<int, int> p, const value_type &val){
    const auto [x, y] = p;
    const int i = x + w / 2;
    const int j = y + h / 2;
    
    data[i][j] = val;
     
    for(int X = i >> 1, Y = j; X > 0; X >>= 1){
      data[X][Y] = M(data[X << 1 | 0][Y], data[X << 1 | 1][Y]);
    }
        
    for(int Y = j >> 1; Y > 0; Y >>= 1){
      for(int X = i; X > 0; X >>= 1){
        data[X][Y] = M(data[X][Y << 1 | 0], data[X][Y << 1 | 1]);
      }
    }
  }
};
