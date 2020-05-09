#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 座標圧縮
 * @docs compressor.md
 */
template <typename T>
class Compressor{
  std::vector<T> data;

public:
  auto& add(const T &val) {data.push_back(val); return *this;}
  auto& add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end()); return *this;}
  template <typename U, typename ...Args> auto& add(const U &val, const Args&... args) {add(val); return add(args...);}

  auto& build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
    return *this;
  }

  int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  auto& compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x); return *this;}
  auto& compress(T &val) const {val = get_index(val);return *this;}
  template <typename U, typename ...Args> auto& compress(U &val, Args&... args) const {compress(val); return compress(args...);}

  auto& decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x]; return *this;}
  auto& decompress(T &val) const {val = data[val]; return *this;}
  template <typename U, typename ...Args> auto& decompress(U &val, Args&... args) const {decompress(val); return decompress(args...);}
  
  int size() const {return data.size();}
  T operator[](int index) const {return data[index];}
};
