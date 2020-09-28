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

    void add(int a1, int b1, int a2, int b2){ // [a1, a2) [b1, b2)
      data_[a1][b1] += 1;
      if(a2 < n_ and b2 < m_) data_[a2][b2] += 1;
      if(b2 < m_) data_[a1][b2] -= 1;
      if(a2 < n_) data_[a2][b1] -= 1;
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
