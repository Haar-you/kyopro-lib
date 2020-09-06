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


# :x: test/aoj/2426/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8164327ac248b119fc2025c513b12d48">test/aoj/2426</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2426/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp.html">Succinct dictionary</a>
* :x: <a href="../../../../library/Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp.html">Wavelet matrix</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/Utils/sort_simultaneously.cpp.html">Mylib/Utils/sort_simultaneously.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/Utils/sort_simultaneously.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

const int H = 1000000000;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto [x, y] = input_tuple_vector<int, int>(n);

  sort_simultaneously(
    [&](int i, int j){
      return x[i] < x[j];
    },
    x, y
  );

  for(auto &p : y) p += H;

  auto wm = make_wavelet_matrix_int(std::vector<uint32_t>(y.begin(), y.end()));

  for(auto [x1, y1, x2, y2] : input_tuples<int, int, int, int>(m)){
    const int l = std::lower_bound(x.begin(), x.end(), x1) - x.begin();
    const int r = std::upper_bound(x.begin(), x.end(), x2) - x.begin();
    int ans = wm.range_freq(l, r, y1 + H, y2 + H + 1);

    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2426/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426"

#include <iostream>
#include <vector>
#line 3 "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include <utility>
#include <tuple>
#include <cassert>
#include <optional>
#include <queue>
#line 5 "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"

/**
 * @title Succinct dictionary
 * @docs succinct_dictionary.md
 */
struct SuccinctDict {
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

    chunks.assign(chunk_num + 1, 0);
    blocks.assign(chunk_num + 1, std::vector<uint8_t>(block_num, 0));

    for(int i = 0; i < chunk_num; ++i){
      for(int j = 0; j < block_num - 1; ++j){
        blocks[i][j + 1] = blocks[i][j] + __builtin_popcountll(data[i * block_num + j]);
      }

      chunks[i + 1] = chunks[i] + blocks[i][block_num - 1] + __builtin_popcountll(data[(i + 1) * block_num - 1]);
    }
  }

  /**
   * @return [0, index)のbの個数
   */
  int rank(int index, int b) const {
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
  int count(int l, int r, int b) const {
    return rank(r, b) - rank(l, b);
  }

  /**
   * @return b[index]
   */
  int access(int index) const {
    return (data[index / block_size] >> (index % block_size)) & 1;
  }

  /**
   * @note n in [1, N]
   * @return 先頭からn番目のbの位置
   */
  std::optional<int> select(int n, int b) const {
    assert(n >= 1);

    if(rank(N, b) < n) return {};

    int lb = -1, ub = N;
    while(abs(lb - ub) > 1){
      int mid = (lb + ub) / 2;

      if(rank(mid, b) >= n){
        ub = mid;
      }else{
        lb = mid;
      }
    }

    return {lb};
  }
};
#line 9 "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @title Wavelet matrix
 * @docs wavelet_matrix.md
 */
template <typename T, int B>
class WaveletMatrix {
public:
  const int N;

  SuccinctDict sdict[B];
  int zero_pos[B];

  WaveletMatrix(std::vector<T> data): N(data.size()){
    std::vector<bool> s(N);

    for(int k = 0; k < B; ++k){
      std::vector<T> left, right;

      for(int i = 0; i < N; ++i){
        s[i] = (data[i] >> (B - 1 - k)) & 1;
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

  /**
   * @return data[index]
   */
  T access(int index){
    assert(0 <= index and index < N);
    T ret = 0;

    int p = index;
    for(int i = 0; i < B; ++i){
      int t = sdict[i].access(p);
      ret |= ((T)t << (B - 1 - i));
      p = sdict[i].rank(p, t) + t * zero_pos[i];
    }

    return ret;
  }

  std::pair<int, int> rank_aux(int index, const T &val){
    int l = 0, r = index;

    for(int i = 0; i < B; ++i){
      int t = (val >> (B - i - 1)) & 1;
      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }

    return std::make_pair(l, r);
  }

  /**
   * @return data[0, index)に含まれるvalの個数
   */
  int rank(int index, const T &val){
    auto [l, r] = rank_aux(index, val);
    return r - l;
  }

  /*
   * @return data[l, r)に含まれるvalの個数
   */
  int count(int l, int r, const T &val){
    assert(0 <= l and l <= r and r <= N);
    return rank(r, val) - rank(l, val);
  }

  /**
   * @return count(1-indexed)番目のvalの位置
   */
  std::optional<int> select(int count, const T &val){
    assert(1 <= count);

    auto [l, r] = rank_aux(N, val);
    if(r - l < count) return {};

    int p = l + count - 1;

    for(int i = B - 1; i >= 0; --i){
      int t = (val >> (B - i - 1)) & 1;
      p = *sdict[i].select(p - t * zero_pos[i] + 1, t);
    }

    return {p};
  }

  /**
   * @return data[l, r)でk(1-index)番目に小さい値
   */
  std::optional<T> quantile(int l, int r, int k){
    assert(0 <= l and l < r and r <= N);
    if(k == 0) return {};

    T ret = 0;

    for(int i = 0; i < B; ++i){
      const int count_1 = sdict[i].rank(r, 1) - sdict[i].rank(l, 1);
      const int count_0 = r - l - count_1;

      int t = 0;

      if(k > count_0){
        t = 1;
        ret |= ((T)t << (B - i - 1));
        k -= count_0;
      }

      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }

    return {ret};
  }

  T maximum(int l, int r){
    assert(l < r);
    return *quantile(l, r, r - l);
  }

  T minimum(int l, int r){
    assert(l < r);
    return *quantile(l, r, 1);
  }

  /**
   * @return data[l, r)のlb以上で最小の値
   */
  std::optional<T> next_value(int l, int r, T lb){
    int c = range_freq_lt(l, r, lb);
    return quantile(l, r, c + 1);
  }

  /**
   * @return data[l, r)のub未満で最大の値
   */
  std::optional<T> prev_value(int l, int r, T ub){
    int c = range_freq_lt(l, r, ub);
    return quantile(l, r, c);
  }

  int range_freq_lt(int l, int r, T ub){
    int ret = 0;

    for(int i = 0; i < B; ++i){
      int t = (ub >> (B - i - 1)) & 1;

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
  int range_freq(int l, int r, T lb, T ub){
    return range_freq_lt(l, r, ub) - range_freq_lt(l, r, lb);
  }

  /**
   * @return data[l, r)で[lb, ub)を満たすものを出現頻度と値のpairで返す。
   */
  auto range_freq_list(int l, int r, T lb, T ub){
    std::vector<std::pair<int, T>> ret;
    std::queue<std::tuple<int, int, int, T>> q;

    q.emplace(l, r, 0, 0);

    while(not q.empty()){
      auto [l, r, d, val] = q.front(); q.pop();

      if(d == B){
        if(lb <= val and val < ub){
          ret.emplace_back(r - l, val);
        }
        continue;
      }

      const T mask = ~(T)0 ^ (((T)1 << (B - d)) - 1);
      const T b = (T)1 << (B - d - 1);

      if(sdict[d].count(l, r, 0) != 0){
        if(val != (lb & mask) or not (lb & b)){
          int L = sdict[d].rank(l, 0);
          int R = sdict[d].rank(r, 0);
          q.emplace(L, R, d + 1, val);
        }
      }

      if(sdict[d].count(l, r, 1) != 0){
        if(val != (ub & mask) or (ub & b)){
          int L = sdict[d].rank(l, 1) + zero_pos[d];
          int R = sdict[d].rank(r, 1) + zero_pos[d];
          q.emplace(L, R, d + 1, val | b);
        }
      }
    }

    return ret;
  }

  /**
   * @return data[l, r)で出現頻度が高い順にk個を返す
   */
  auto top_k(int l, int r, int k) const {
    std::priority_queue<std::tuple<int, int, int, int, T>> q;
    std::vector<std::pair<int, T>> ret;

    q.emplace(r - l, l, r, 0, 0);

    while(not q.empty()){
      auto [len, l, r, d, val] = q.top(); q.pop();

      if(d == B){
        ret.emplace_back(len, val);
        if((int)ret.size() >= k) break;
        continue;
      }

      if(sdict[d].count(l, r, 0) != 0){
        int L = sdict[d].rank(l, 0);
        int R = sdict[d].rank(r, 0);
        q.emplace(R - L, L, R, d + 1, val);
      }

      if(sdict[d].count(l, r, 1) != 0){
        int L = sdict[d].rank(l, 1) + zero_pos[d];
        int R = sdict[d].rank(r, 1) + zero_pos[d];
        q.emplace(R - L, L, R, d + 1, val | ((T)1 << (B - d - 1)));
      }
    }

    return ret;
  }
};

WaveletMatrix<uint32_t, 32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){
  return WaveletMatrix<uint32_t, 32>(data);
}
#line 4 "Mylib/Utils/sort_simultaneously.cpp"
#include <algorithm>
#include <numeric>
#include <initializer_list>

/**
 * @docs sort_simultaneously.md
 */
template <typename Compare, typename ... Args>
void sort_simultaneously(const Compare &compare, std::vector<Args> &... args){
  const int N = std::max({args.size() ...});
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), compare);

  (void)std::initializer_list<int>{
    (void(
      [&](){
        auto temp = args;
        for(int i = 0; i < N; ++i) temp[i] = args[ord[i]];
        std::swap(temp, args);
      }()
    ), 0) ...};
}
#line 7 "Mylib/IO/input_tuple_vector.cpp"

/**
 * @docs input_tuple_vector.md
 */
template <typename T, size_t ... I>
void input_tuple_vector_init(T &val, int N, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0) ...};
}

template <typename T, size_t ... I>
void input_tuple_vector_helper(T &val, int i, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0) ...};
}

template <typename ... Args>
auto input_tuple_vector(int N){
  std::tuple<std::vector<Args> ...> ret;

  input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());
  for(int i = 0; i < N; ++i){
    input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof ... (Args)>());
  }

  return ret;
}
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 9 "test/aoj/2426/main.test.cpp"

const int H = 1000000000;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto [x, y] = input_tuple_vector<int, int>(n);

  sort_simultaneously(
    [&](int i, int j){
      return x[i] < x[j];
    },
    x, y
  );

  for(auto &p : y) p += H;

  auto wm = make_wavelet_matrix_int(std::vector<uint32_t>(y.begin(), y.end()));

  for(auto [x1, y1, x2, y2] : input_tuples<int, int, int, int>(m)){
    const int l = std::lower_bound(x.begin(), x.end(), x1) - x.begin();
    const int r = std::upper_bound(x.begin(), x.end(), x2) - x.begin();
    int ans = wm.range_freq(l, r, y1 + H, y2 + H + 1);

    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

