---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/2674/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#851bd501caf05418a029865ccd3f2b9f">test/aoj/2674</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2674/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 14:34:19+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/range_freq.cpp.html">range_freq</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp.html">簡潔辞書</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp.html">WaveletMatrix</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/DataStructure/WaveletMatrix/range_freq.cpp"

int main(){
  int D; std::cin >> D;

  std::vector<uint32_t> x(D);
  for(int i = 0; i < D; ++i){
    std::cin >> x[i];
    x[i] += 100000000;
  }

  auto wm = make_wavelet_matrix_int(x);

  int Q; std::cin >> Q;

  while(Q--){
    int l, r, e; std::cin >> l >> r >> e;

    --l, --r;

    int a = std::min(x[l], x[r]);
    int b = std::max(x[l], x[r]);

    int ans = 0;

    ans += range_freq(wm, l, r+1, 0u, (uint32_t)std::max(0, a-e));
    ans += range_freq(wm, l, r+1, (uint32_t)(b+e+1), std::numeric_limits<uint32_t>::max());

    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2674/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674"

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#line 3 "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include <utility>
#include <tuple>
#include <cassert>
#include <optional>
#line 3 "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"
#include <optional>

/**
 * @title 簡潔辞書
 * @docs succinct_dictionary.md
 */

struct SuccinctDict{
  int N;

  static const int chunk_size = 256;
  static const int block_size = 64;
  std::vector<uint64_t> data;

  std::vector<std::vector<uint8_t>> blocks;

  std::vector<uint32_t> chunks;

  int chunk_num;
  static const int block_num = chunk_size / block_size;

  SuccinctDict(): N(0){}
  SuccinctDict(const std::vector<bool> &b): N(b.size()){
    chunk_num = (N + chunk_size - 1) / chunk_size;

    data.assign(chunk_num * block_num + 1, 0);

    for(int i = 0; i < N; ++i){
      if(b[i]){
        int block_index = i / block_size;
        int index = i % block_size;
        data[block_index] |= (1LL << index);
      }
    }
    
    chunks.assign(chunk_num+1, 0);
    blocks.assign(chunk_num+1, std::vector<uint8_t>(block_num, 0));

    for(int i = 0; i < chunk_num; ++i){
      for(int j = 0; j < block_num-1; ++j){
        blocks[i][j+1] = blocks[i][j] + __builtin_popcountll(data[i*block_num+j]);
      }

      chunks[i+1] = chunks[i] + blocks[i][block_num-1] + __builtin_popcountll(data[(i+1)*block_num-1]);
    }
  }

  /**
   * @return [0,index)のbの個数
   */
  inline int rank(int index, int b) const {
    if(b == 0){
      return index - rank(index, 1);
    }else{
      if(index > N) index = N;
      
      const int chunk_pos = index / chunk_size;
      const int block_pos = (index % chunk_size) / block_size;

      const uint64_t mask =
        data[chunk_pos * block_num + block_pos] & ((1LL << (index % block_size)) - 1);

      const int ret = chunks[chunk_pos] +
        blocks[chunk_pos][block_pos] +
        __builtin_popcountll(mask);

      return ret;
    }
  }
  
  /**
   * @return [l, r)のbの個数
   */
  inline int count(int l, int r, int b) const {
    return rank(r, b) - rank(l, b);
  }

  /**
   * @return b[index]
   */
  inline int access(int index) const {
    return (data[index / block_size] >> (index % block_size)) & 1;
  }

  /**
   * @note n in [1, N]
   * @return 先頭からn番目のbの位置
   */
  inline std::optional<int> select(int n, int b) const {
    assert(n >= 1);
    
    if(rank(N, b) < n) return {};

    int lb = -1, ub = N;
    while(abs(lb-ub) > 1){
      int mid = (lb+ub) / 2;
      
      if(rank(mid, b) >= n){
        ub = mid;
      }else{
        lb = mid;
      }
    }

    return {lb};
  }
};
#line 8 "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @title WaveletMatrix
 * @docs wavelet_matrix.md
 */

template <typename T, int B>
class WaveletMatrix{
public:
  const int N;

  SuccinctDict sdict[B];
  int zero_pos[B];

  WaveletMatrix(std::vector<T> data): N(data.size()){
    std::vector<bool> s(N);

    for(int k = 0; k < B; ++k){
      std::vector<T> left, right;

      for(int i = 0; i < N; ++i){
        s[i] = (data[i] >> (B-1-k)) & 1;
        if(s[i]){
          right.push_back(data[i]);
        }else{
          left.push_back(data[i]);
        }
      }

      sdict[k] = SuccinctDict(s);
      zero_pos[k] = left.size();

      std::swap(data, left);
      data.insert(data.end(), right.begin(), right.end());
    }
  }
};


/**
 * @return data[index]
 */
template <typename T, int B>
inline T access(const WaveletMatrix<T, B> &wm, int index){
  T ret = 0;

  int p = index;
  for(int i = 0; i < B; ++i){
    int t = wm.sdict[i].access(p);
    ret |= ((T)t << (B-1-i));
    p = wm.sdict[i].rank(p, t) + t * wm.zero_pos[i];
  }
    
  return ret;
}

template <typename T, int B>
inline std::pair<int,int> rank_aux(const WaveletMatrix<T, B> &wm, int index, const T &val){
  int l = 0, r = index;

  for(int i = 0; i < B; ++i){
    int t = (val >> (B-i-1)) & 1;
    l = wm.sdict[i].rank(l, t) + t * wm.zero_pos[i];
    r = wm.sdict[i].rank(r, t) + t * wm.zero_pos[i];
  }

  return std::make_pair(l, r);
}

/**
 * @return data[0, index)に含まれるvalの個数
 */
template <typename T, int B>
inline int rank(const WaveletMatrix<T, B> &wm, int index, const T &val){
  int l, r; std::tie(l, r) = rank_aux(wm, index, val);
  return r - l;
}

/*
 * @return data[l, r)に含まれるvalの個数
 */
template <typename T, int B>
inline int count(const WaveletMatrix<T, B> &wm, int l, int r, const T &val){
  return rank(wm, r, val) - rank(wm, l, val);
}
  
/**
 * @return count番目のvalの位置
 */
template <typename T, int B>
std::optional<int> select(const WaveletMatrix<T, B> &wm, int count, const T &val){
  if(count <= 0) return {};
    
  int l, r; std::tie(l, r) = rank_aux(wm, wm.N, val);
  if(r - l < count) return {};

  int p = l + count - 1;

  for(int i = B-1; i >= 0; --i){
    int t = (val >> (B-i-1)) & 1;
    p = *wm.sdict[i].select(p - t * wm.zero_pos[i] + 1, t);
  }
    
  return {p};
}

/**
 * @return data[l, r)でk(1-index)番目に小さい値
 */
template <typename T, int B>
std::optional<T> quantile(const WaveletMatrix<T, B> &wm, int l, int r, int k){
  assert(0 <= l and l < r and r <= wm.N);
  if(k == 0) return {};

  T ret = 0;

  for(int i = 0; i < B; ++i){
    const int count_1 = wm.sdict[i].rank(r, 1) - wm.sdict[i].rank(l, 1);
    const int count_0 = r - l - count_1;

    int t = 0;

    if(k > count_0){
      t = 1;
      ret |= ((T)t << (B-i-1));
      k -= count_0;
    }
      
    l = wm.sdict[i].rank(l, t) + t * wm.zero_pos[i];
    r = wm.sdict[i].rank(r, t) + t * wm.zero_pos[i];
  }
    
  return {ret};
}

template <typename T, int B>
T maximum(const WaveletMatrix<T, B> &wm, int l, int r){
  return *quantile(wm, l, r, r-l);
}

template <typename T, int B>
T minimum(const WaveletMatrix<T, B> &wm, int l, int r){
  return *quantile(wm, l, r, 1);
}


WaveletMatrix<uint32_t,32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){
  return WaveletMatrix<uint32_t, 32>(data);
}
#line 3 "Mylib/DataStructure/WaveletMatrix/range_freq.cpp"

/**
 * @title range_freq
 * @docs wavelet_matrix.md
 */

template <typename T, int B>
int range_freq_lt(const WaveletMatrix<T, B> &wm, int l, int r, T ub){
  int ret = 0;

  for(int i = 0; i < B; ++i){
    int t = (ub >> (B-i-1)) & 1;

    if(t){
      ret += wm.sdict[i].count(l, r, 0);
    }

    l = wm.sdict[i].rank(l, t) + t * wm.zero_pos[i];
    r = wm.sdict[i].rank(r, t) + t * wm.zero_pos[i];
  }
    
  return ret;
}

/**
 * @return data[l, r)内で[lb, ub)であるような値の個数
 */
template <typename T, int B>
int range_freq(const WaveletMatrix<T, B> &wm, int l, int r, T lb, T ub){
  return range_freq_lt(wm, l, r, ub) - range_freq_lt(wm, l, r, lb);
}
#line 9 "test/aoj/2674/main.test.cpp"

int main(){
  int D; std::cin >> D;

  std::vector<uint32_t> x(D);
  for(int i = 0; i < D; ++i){
    std::cin >> x[i];
    x[i] += 100000000;
  }

  auto wm = make_wavelet_matrix_int(x);

  int Q; std::cin >> Q;

  while(Q--){
    int l, r, e; std::cin >> l >> r >> e;

    --l, --r;

    int a = std::min(x[l], x[r]);
    int b = std::max(x[l], x[r]);

    int ans = 0;

    ans += range_freq(wm, l, r+1, 0u, (uint32_t)std::max(0, a-e));
    ans += range_freq(wm, l, r+1, (uint32_t)(b+e+1), std::numeric_limits<uint32_t>::max());

    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

