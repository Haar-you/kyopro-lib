#pragma once
#include <vector>
#include <algorithm>
#include <limits>

/**
 * @title Starry-sky tree (Min)
 * @docs starry_sky_tree_min.md
 */
template <typename T>
class StarrySkyTreeMin{
  int depth, size, hsize;
  std::vector<T> data;

  const T id = std::numeric_limits<T>::max();

  void bottom_up(int i){
    if(i > size) return;

    while(i >= 1){
      if(i < hsize){
        const auto d = std::min(data[i << 1 | 0], data[i << 1 | 1]);
        
        data[i << 1 | 0] -= d;
        data[i << 1 | 1] -= d;
        data[i] += d;
      }

      i >>= 1;
    }
  }
  
  T get(int i, int l, int r, int s, int t, T val) const {
    if(r <= s or t <= l) return id;
    if(s <= l and r <= t) return val + data[i];
    return std::min(get(i << 1 | 0, l, (l + r) / 2, s, t, val + data[i]),
                    get(i << 1 | 1, (l + r) / 2, r, s, t, val + data[i]));
  }

public:
  StarrySkyTreeMin(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),    
    data(size, 0)
  {}

  void update(int l, int r, T val){
    int L = l + hsize;
    int R = r + hsize;

    while(L < R){
      if(R & 1) --R, data[R] += val;
      if(L & 1) data[L] += val, ++L;
      L >>= 1;
      R >>= 1;
    }

    bottom_up(l + hsize);
    bottom_up(r + hsize);
  }

  T get(int l, int r) const {
    return get(1, 0, hsize, l, r, 0);
  }

  template <typename U>
  void init_with_vector(std::vector<U> &a){
    for(int i = 0; i < (int)a.size(); ++i){
      data[hsize + i] = a[i];
    }

    for(int i = hsize - 1; i >= 1; --i){
      data[i] = std::min(data[i << 1 | 0], data[i << 1 | 1]);
    }

    for(int i = size - 1; i > 1; --i){
      data[i] -= data[i >> 1];
    }
  }
};
