#pragma once
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class segment_tree_2d {
  public:
    using value_type = typename Monoid::value_type;

  private:
    Monoid M_;
    int w_, h_;
    std::vector<std::vector<value_type>> data_;

    value_type get_w(int l, int r, int y) const {
      l += w_ / 2;
      r += w_ / 2;

      value_type ret = M_();

      while(l < r){
        if(r & 1) ret = M_(ret, data_[--r][y]);
        if(l & 1) ret = M_(ret, data_[l++][y]);
        l >>= 1, r >>= 1;
      }

      return ret;
    }

  public:
    segment_tree_2d(){}
    segment_tree_2d(int width, int height){
      w_ = 1;
      while(w_ < width) w_ *= 2;
      w_ = w_ * 2;

      h_ = 1;
      while(h_ < height) h_ *= 2;
      h_ = h_ * 2;

      data_ = std::vector(w_, std::vector<value_type>(h_, M_()));
    }

    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      int l = y1 + h_ / 2;
      int r = y2 + h_ / 2;

      value_type ret = M_();

      while(l < r){
        if(r & 1) ret = M_(ret, get_w(x1, x2, --r));
        if(l & 1) ret = M_(ret, get_w(x1, x2, l++));
        l >>= 1, r >>= 1;
      }

      return ret;
    }

    value_type operator[](std::pair<int, int> p) const {
      auto [x, y] = p;
      return data_[w_ / 2 + x][h_ / 2 + y];
    }

    void set(std::pair<int, int> p, const value_type &val){
      const auto [x, y] = p;
      const int i = x + w_ / 2;
      const int j = y + h_ / 2;

      data_[i][j] = val;

      for(int X = i >> 1, Y = j; X > 0; X >>= 1){
        data_[X][Y] = M_(data_[X << 1 | 0][Y], data_[X << 1 | 1][Y]);
      }

      for(int Y = j >> 1; Y > 0; Y >>= 1){
        for(int X = i; X > 0; X >>= 1){
          data_[X][Y] = M_(data_[X][Y << 1 | 0], data_[X][Y << 1 | 1]);
        }
      }
    }

    void update(std::pair<int, int> p, const value_type &val){
      set(p, M_((*this)[p], val));
    }
  };
}
