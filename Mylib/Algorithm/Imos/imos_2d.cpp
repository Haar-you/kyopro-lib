#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  struct imos_2d {
    using value_type = T;

  private:
    std::vector<std::vector<T>> data_;
    int n_, m_;

  public:
    imos_2d(){}
    imos_2d(int n, int m): data_(n, std::vector<T>(m)), n_(n), m_(m){}

    void update(std::pair<int, int> p1, std::pair<int, int> p2, T val){
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;

      data_[x1][y1] += val;
      if(x2 < n_ and y2 < m_) data_[x2][y2] += val;
      if(y2 < m_) data_[x1][y2] -= val;
      if(x2 < n_) data_[x2][y1] -= val;
    }

    void build(){
      for(int i = 1; i < n_; ++i){
        for(int j = 0; j < m_; ++j){
          data_[i][j] += data_[i - 1][j];
        }
      }

      for(int i = 0; i < n_; ++i){
        for(int j = 1; j < m_; ++j){
          data_[i][j] += data_[i][j - 1];
        }
      }
    }

    const std::vector<T>& operator[](size_t i) const {return data_[i];}

    auto begin() const {return data_.begin();}
    auto end() const {return data_.end();}
  };
}
