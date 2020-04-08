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


# :heavy_check_mark: 簡潔辞書

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#def74daadbbb39361c0a507a6463f6db">Mylib/DataStructure/WaveletMatrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-08 16:48:10+09:00




## Required by

* :heavy_check_mark: <a href="prev_next_value.cpp.html">prev_value / next_value</a>
* :heavy_check_mark: <a href="range_freq.cpp.html">range_freq</a>
* :warning: <a href="range_freq_list.cpp.html">range_freq_list</a>
* :warning: <a href="top_k.cpp.html">top_k</a>
* :heavy_check_mark: <a href="wavelet_matrix.cpp.html">Wavelet matrix</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1549/main.test.cpp.html">test/aoj/1549/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/2674/main.test.cpp.html">test/aoj/2674/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/range_kth_smallest/main.test.cpp.html">test/yosupo-judge/range_kth_smallest/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 簡潔辞書
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"
#include <vector>

/**
 * @title 簡潔辞書
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

