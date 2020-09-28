#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  struct imos_1d {
    using value_type = T;

  private:
    std::vector<T> data_;
    int n_;

  public:
    imos_1d(){}
    imos_1d(int n): data_(n), n_(n){}

    void add(int l, int r, const T& val){ // [l, r)
      data_[l] += 1;
      if(r < n_) data_[r] -= 1;
    }

    void build(){
      for(int i = 1; i < n_; ++i){
        data_[i] += data_[i - 1];
      }
    }

    T operator[](size_t i) const {return data_[i];}

    auto begin() const {return data_.begin();}
    auto end() const {return data_.end();}
  };
}
