#pragma once
#include <array>
#include <initializer_list>
#include <utility>

namespace haar_lib {
  template <typename T, int N>
  struct square_matrix_const {
    using value_type = T;

  private:
    std::array<std::array<T, N>, N> data_;

  public:
    square_matrix_const(){
      for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) data_[i][j] = 0;
    }
    square_matrix_const(const T &val){
      for(size_t i = 0; i < N; ++i) data_[i].fill(val);
    }
    square_matrix_const(std::initializer_list<std::initializer_list<T>> list){
      int i = 0;
      for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
        int j = 0;
        for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
          data_[i][j] = *it2;
        }
      }
    }

    bool operator==(const square_matrix_const &val) const {return data_ == val.data_;}
    bool operator!=(const square_matrix_const &val) const {return !(*this == val);}

    auto& operator=(const square_matrix_const &val){
      this->data_ = val.data_;
      return *this;
    }

    auto& operator+=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
          data_[i][j] = data_[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
          data_[i][j] = data_[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix_const &val){
      std::array<std::array<T, N>, N> temp = {};
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
          for(int k = 0; k < N; ++k)
            temp[i][j] += data_[i][k] * val[k][j];
      std::swap(data_, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return data_[i];}
    auto& operator[](size_t i){return data_[i];}
    int size() const {return N;}

    static auto unit(){
      square_matrix_const ret;
      for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix_const &a, const square_matrix_const &b){
      auto ret = a; return ret += b;
    }
    friend auto operator-(const square_matrix_const &a, const square_matrix_const &b){
      auto ret = a; return ret -= b;
    }
    friend auto operator*(const square_matrix_const &a, const square_matrix_const &b){
      auto ret = a; return ret *= b;
    }

    auto pow(uint64_t p) const {
      auto ret = unit();
      auto a = *this;

      while(p > 0){
        if(p & 1) ret *= a;
        a *= a;
        p >>= 1;
      }

      return ret;
    }
  };
}
