#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 座標圧縮
 */
template <typename T>
class Compressor{
  std::vector<T> data;

public:
  inline void add(const T &val) {data.push_back(val);}
  inline void add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end());}
  template <typename U> inline void add_all(const U &val) {add(val);}
  template <typename U, typename ...Args> inline void add_all(const U &val, const Args&... args) {add(val); add_all(args...);}

  inline void build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
  }

  inline int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  inline void compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x);}
  inline void compress(T &val) const {val = get_index(val);}
  template <typename U> inline void compress_all(U &val) const {compress(val);}
  template <typename U, typename ...Args> inline void compress_all(U &val, Args&... args) const {compress(val); compress_all(args...);}

  inline void decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x];}
  inline void decompress(T &val) const {val = data[val];}
  template <typename U> inline void decompress_all(U &val) const {decompress(val);}
  template <typename U, typename ...Args> inline void decompress_all(U &val, Args&... args) const {decompress(val); decompress_all(args...);}
  
  inline int size() const {return data.size();}
  inline T operator[](int index) const {return data[index];}
};
