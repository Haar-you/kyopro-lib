#pragma once
#include <vector>
#include <algorithm>

namespace haar_lib {
  template <typename T>
  class compressor {
    std::vector<T> data_;

  public:
    auto& add(const T &val){
      data_.push_back(val);
      return *this;
    }

    auto& add(const std::vector<T> &vals){
      data_.insert(data_.end(), vals.begin(), vals.end());
      return *this;
    }

    template <typename U, typename ... Args>
    auto& add(const U &val, const Args &... args){
      add(val);
      return add(args ...);
    }

    auto& build(){
      std::sort(data_.begin(), data_.end());
      data_.erase(std::unique(data_.begin(), data_.end()), data_.end());
      return *this;
    }

    int get_index(const T &val) const {
      return std::lower_bound(data_.begin(), data_.end(), val) - data_.begin();
    }

    auto& compress(std::vector<T> &vals) const {
      for(auto &x : vals) x = get_index(x);
      return *this;
    }

    auto& compress(T &val) const {
      val = get_index(val);
      return *this;
    }

    template <typename U, typename ... Args>
    auto& compress(U &val, Args &... args) const {
      compress(val);
      return compress(args ...);
    }

    auto& decompress(std::vector<T> &vals) const {
      for(auto &x : vals) x = data_[x];
      return *this;
    }

    auto& decompress(T &val) const {
      val = data_[val];
      return *this;
    }

    template <typename U, typename ... Args>
    auto& decompress(U &val, Args &... args) const {
      decompress(val);
      return decompress(args ...);
    }

    int size() const {return data_.size();}
    T operator[](int index) const {return data_[index];}
  };
}
