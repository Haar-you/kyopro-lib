#pragma once
#include <vector>
#include <utility>
#include <cstdint>

namespace haar_lib {
  template <typename T, const int &N>
  struct square_matrix {
    using value_type = T;

  private:
    std::vector<std::vector<T>> data_;

  public:
    square_matrix(): data_(N, std::vector<T>(N)){}
    square_matrix(const T &val): data_(N, std::vector<T>(N, val)){}
    square_matrix(const std::vector<std::vector<T>> &matrix): data_(matrix){}

    bool operator==(const square_matrix &val) const {return data_ == val.data_;}
    bool operator!=(const square_matrix &val) const {return !(*this == val);}

    auto& operator=(const square_matrix &val){
      this->data_ = val.data_;
      return *this;
    }

    auto& operator+=(const square_matrix &val){
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
          data_[i][j] = data_[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix &val){
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
          data_[i][j] = data_[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix &val){
      std::vector<std::vector<T>> temp(N, std::vector<T>(N));
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
      square_matrix ret;
      for(int i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix &a, const square_matrix &b){
      auto ret = a; return ret += b;
    }
    friend auto operator-(const square_matrix &a, const square_matrix &b){
      auto ret = a; return ret -= b;
    }
    friend auto operator*(const square_matrix &a, const square_matrix &b){
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
