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


# :heavy_check_mark: test/aoj/1549/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5debddf061bad06c63c05622838965f1">test/aoj/1549</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1549/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 09:56:17+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/prev_next_value.cpp.html">Mylib/DataStructure/WaveletMatrix/prev_next_value.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/range_freq.cpp.html">Mylib/DataStructure/WaveletMatrix/range_freq.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp.html">Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp.html">Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/DataStructure/WaveletMatrix/prev_next_value.cpp"

int main(){
  int N; std::cin >> N;

  std::vector<uint32_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto wm = make_wavelet_matrix_int(a);
  
  int Q; std::cin >> Q;

  while(Q--){
    int l, r, d; std::cin >> l >> r >> d;

    ++r;

    int ans = INT_MAX;

    {
      int x = wm.prev_value(l, r, d);
      if(x != -1) ans = std::min(ans, std::abs(x - d));
    }

    {
      int x = wm.next_value(l, r, d);
      if(x != -1) ans = std::min(ans, std::abs(x - d));
    }


    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1549/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#line 3 "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include <utility>
#include <tuple>
#include <cassert>
#line 3 "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"

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
   * @return [s, e)のbの個数
   */
  inline int count(int s, int e, int b) const {
    return rank(e, b) - rank(s, b);
  }

  /**
   * @return b[index]
   */
  inline int access(int index) const {
    return (data[index / block_size] >> (index % block_size)) & 1;
  }

  /**
   * @note n in [1, N]
   * @retval 0<= 先頭からn番目のbの位置
   * @retval -1 n番目のbが存在しない
   */
  inline int select(int n, int b) const {
    assert(n >= 1);
    
    if(rank(N, b) < n) return -1;

    int lb = -1, ub = N;
    while(abs(lb-ub) > 1){
      int mid = (lb+ub) / 2;
      
      if(rank(mid, b) >= n){
        ub = mid;
      }else{
        lb = mid;
      }
    }

    return lb;
  }
};
#line 7 "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549 (prev_value, next_value)
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674 (range_freq)
 * @see https://www.spoj.com/problems/MKTHNUM/ (quantile)
 */
template <typename T, int B>
class WaveletMatrix{
  const int N;

  SuccinctDict sdict[B];
  int zero_pos[B];

public:
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

public:
  /**
   * @return data[index]
   */
  inline T access(int index) const {
    T ret = 0;

    int p = index;
    for(int i = 0; i < B; ++i){
      int t = sdict[i].access(p);
      ret |= ((T)t << (B-1-i));
      p = sdict[i].rank(p, t) + t * zero_pos[i];
    }
    
    return ret;
  }

private:
  inline std::pair<int,int> rank_aux(int index, const T &val) const {
    int l = 0, r = index;

    for(int i = 0; i < B; ++i){
      int t = (val >> (B-i-1)) & 1;
      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }

    return std::make_pair(l, r);
  }

public:
  /**
   * @return data[0,index)に含まれるvalの個数
   */
  inline int rank(int index, const T &val) const {
    int l, r; std::tie(l, r) = rank_aux(index, val);
    return r - l;
  }

public:
  /*
   * @return data[s,e)に含まれるvalの個数
   */
  inline int count(int s, int e, const T &val) const {
    return rank(e, val) - rank(s, val);
  }
  
public:
  /**
   * @retval 0<= count番目のvalの位置
   * @retval -1 count番目のvalが存在しない
   */
  int select(int count, const T &val) const {
    if(count <= 0) return -1;
    
    int l, r; std::tie(l, r) = rank_aux(N, val);
    if(r - l < count) return -1;

    int p = l + count - 1;

    for(int i = B-1; i >= 0; --i){
      int t = (val >> (B-i-1)) & 1;
      p = sdict[i].select(p - t * zero_pos[i] + 1, t);
    }
    
    return p;
  }

public:
  /**
   * @return data[l,r)でk(1-index)番目に小さい値
   */
  T quantile(int l, int r, int k) const {
    assert(0 <= l and l < r and r <= N);
    if(k == 0) return -1;

    T ret = 0;

    for(int i = 0; i < B; ++i){
      const int count_1 = sdict[i].rank(r, 1) - sdict[i].rank(l, 1);
      const int count_0 = r - l - count_1;

      int t = 0;

      if(k > count_0){
        t = 1;
        ret |= ((T)t << (B-i-1));
        k -= count_0;
      }
      
      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }
    
    return ret;
  }

public:
  T maximum(int s, int e) const {
    return quantile(s, e, e-s);
  }

public:
  T minimum(int s, int e) const {
    return quantile(s, e, 1);
  }

public:
  int range_freq_lt(int, int, T) const;
  int range_freq(int, int, T, T) const;
  std::vector<std::pair<int,T>> range_freq_list(int, int, T, T) const;
  T next_value(int, int, T) const;
  T prev_value(int, int, T) const;
  std::vector<std::pair<int,T>> top_k(int, int, int) const;
};


WaveletMatrix<uint32_t,32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){
  return WaveletMatrix<uint32_t, 32>(data);
}
#line 3 "Mylib/DataStructure/WaveletMatrix/range_freq.cpp"

template <typename T, int B>
int WaveletMatrix<T,B>::range_freq_lt(int l, int r, T ub) const {
  int ret = 0;

  for(int i = 0; i < B; ++i){
    int t = (ub >> (B-i-1)) & 1;

    if(t){
      ret += sdict[i].count(l, r, 0);
    }

    l = sdict[i].rank(l, t) + t * zero_pos[i];
    r = sdict[i].rank(r, t) + t * zero_pos[i];
  }
    
  return ret;
}

/**
 * @return data[l, r)内で[lb, ub)であるような値の個数
 */
template <typename T, int B>
int WaveletMatrix<T,B>::range_freq(int l, int r, T lb, T ub) const {
  return range_freq_lt(l, r, ub) - range_freq_lt(l, r, lb);
}
#line 4 "Mylib/DataStructure/WaveletMatrix/prev_next_value.cpp"

// BEGIN

/**
 * @return data[l, r)のlb以上で最小の値
 */
template <typename T, int B>
T WaveletMatrix<T,B>::next_value(int l, int r, T lb) const {
  int c = range_freq_lt(l, r, lb);
  return quantile(l, r, c+1);
}
  
/**
 * @return data[l, r)のub未満で最大の値
 */
template <typename T, int B>
T WaveletMatrix<T,B>::prev_value(int l, int r, T ub) const {
  int c = range_freq_lt(l, r, ub);
  return quantile(l, r, c);
}

#line 9 "test/aoj/1549/main.test.cpp"

int main(){
  int N; std::cin >> N;

  std::vector<uint32_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto wm = make_wavelet_matrix_int(a);
  
  int Q; std::cin >> Q;

  while(Q--){
    int l, r, d; std::cin >> l >> r >> d;

    ++r;

    int ans = INT_MAX;

    {
      int x = wm.prev_value(l, r, d);
      if(x != -1) ans = std::min(ans, std::abs(x - d));
    }

    {
      int x = wm.next_value(l, r, d);
      if(x != -1) ans = std::min(ans, std::abs(x - d));
    }


    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

