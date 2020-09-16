#pragma once
#include <array>
#include <initializer_list>
#include <utility>

namespace haar_lib {
  template <typename T, int N>
  struct square_matrix_const {
    using value_type = T;

    std::array<std::array<T, N>, N> matrix;

    square_matrix_const(){
      for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
    }
    square_matrix_const(const T &val){
      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
    }
    square_matrix_const(std::initializer_list<std::initializer_list<T>> list){
      int i = 0;
      for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
        int j = 0;
        for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
          matrix[i][j] = *it2;
        }
      }
    }

    bool operator==(const square_matrix_const &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix_const &val) const {return !(*this == val);}

    auto& operator=(const square_matrix_const &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix_const &val){
      std::array<std::array<T, N>, N> temp = {};
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return N;}

    static auto make_unit(){
      square_matrix_const ret;
      for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret *= b; return ret;}
  };
}
