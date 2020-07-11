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


# :x: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0eb662a8a4a1c93b539f9938a9be975d">test/yosupo-judge/range_chmin_chmax_add_range_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-08 12:08:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum">https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp.html">Segment tree beats</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  SegmentTreeBeats seg(N);

  auto a = input_vector<int64_t>(N);
  seg.init_with_vector(a);
  
  for(auto [type, l, r] : input_tuples<int, int, int>(Q)){
    switch(type){
    case 0: {
      int64_t b; std::cin >> b;
      seg.chmin(l, r, b);
      break;
    }
    case 1: {
      int64_t b; std::cin >> b;
      seg.chmax(l, r, b);
      break;
    }
    case 2: {
      int64_t b; std::cin >> b;
      seg.add(l, r, b);
      break;
    }
    case 3: {
      auto ans = seg.get_sum(l, r);
      std::cout << ans << "\n"; 
      break; 
    }
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp"
#include <limits>
#include <algorithm>

/**
 * @title Segment tree beats
 * @docs segment_tree_beats.md
 */
class SegmentTreeBeats{
  using value_type = int64_t;

  const int depth, size, hsize;

  std::vector<value_type> fst_max, snd_max;
  std::vector<int> max_count;

  std::vector<value_type> fst_min, snd_min;
  std::vector<int> min_count;
  
  std::vector<value_type> sum, lazy_add;

public:
  SegmentTreeBeats(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),

    fst_max(size, std::numeric_limits<value_type>::min()),
    snd_max(size, std::numeric_limits<value_type>::min()),
    max_count(size, 0),

    fst_min(size, std::numeric_limits<value_type>::max()),
    snd_min(size, std::numeric_limits<value_type>::max()),
    min_count(size, 0),
    
    sum(size, 0),
    lazy_add(size, 0)
  {}

private:
  int lc(int i) const {return i << 1 | 0;} // left child
  int rc(int i) const {return i << 1 | 1;} // right child
  
  void update_node_max(int i, value_type x){
    sum[i] += (x - fst_max[i]) * max_count[i];

    if(fst_max[i] == fst_min[i]) fst_max[i] = fst_min[i] = x;
    else if(fst_max[i] == snd_min[i]) fst_max[i] = snd_min[i] = x;
    else fst_max[i] = x;
  }

  void update_node_min(int i, value_type x){
    sum[i] += (x - fst_min[i]) * min_count[i];

    if(fst_max[i] == fst_min[i]) fst_max[i] = fst_min[i] = x;
    else if(snd_max[i] == fst_min[i]) snd_max[i] = fst_min[i] = x;
    else fst_min[i] = x;
  }

  void update_node_add(int i, value_type x){
    const int len = hsize >> (31 - __builtin_clz(i));

    sum[i] += x * len;
    fst_max[i] += x;
    if(snd_max[i] != std::numeric_limits<value_type>::min()) snd_max[i] += x;
    fst_min[i] += x;
    if(snd_min[i] != std::numeric_limits<value_type>::max()) snd_min[i] += x;

    lazy_add[i] += x;
  }
  
  void propagate(int i){
    if(i >= hsize) return;

    if(lazy_add[i] != 0){
      update_node_add(lc(i), lazy_add[i]);
      update_node_add(rc(i), lazy_add[i]);
      lazy_add[i] = 0;
    }

    if(fst_max[i] < fst_max[lc(i)]) update_node_max(lc(i), fst_max[i]);
    if(fst_min[i] > fst_min[lc(i)]) update_node_min(lc(i), fst_min[i]);

    if(fst_max[i] < fst_max[rc(i)]) update_node_max(rc(i), fst_max[i]);
    if(fst_min[i] > fst_min[rc(i)]) update_node_min(rc(i), fst_min[i]);
  }

  void bottom_up(int i){
    const int L = lc(i);
    const int R = rc(i);
    
    sum[i] = sum[L] + sum[R];

    fst_max[i] = std::max(fst_max[L], fst_max[R]);
    
    if(fst_max[L] < fst_max[R]){
      max_count[i] = max_count[R];
      snd_max[i] = std::max(fst_max[L], snd_max[R]);
    }else if(fst_max[L] > fst_max[R]){
      max_count[i] = max_count[L];
      snd_max[i] = std::max(snd_max[L], fst_max[R]);
    }else{
      max_count[i] = max_count[L] + max_count[R];
      snd_max[i] = std::max(snd_max[L], snd_max[R]);
    }

    fst_min[i] = std::min(fst_min[L], fst_min[R]);
    
    if(fst_min[L] > fst_min[R]){
      min_count[i] = min_count[R];
      snd_min[i] = std::min(fst_min[L], snd_min[R]);
    }else if(fst_min[L] < fst_min[R]){
      min_count[i] = min_count[L];
      snd_min[i] = std::min(snd_min[L], fst_min[R]);
    }else{
      min_count[i] = min_count[L] + min_count[R];
      snd_min[i] = std::min(snd_min[L], snd_min[R]);
    }
  }
  
private:
  void chmin(int i, int l, int r, int s, int t, value_type x){
    if(r <= s or t <= l or fst_max[i] <= x) return;
    if(s <= l and r <= t and snd_max[i] < x){
      update_node_max(i, x);
      return;
    }

    propagate(i);    
    chmin(lc(i), l, (l + r) / 2, s, t, x);
    chmin(rc(i), (l + r) / 2, r, s, t, x);
    bottom_up(i);
  }

public:
  void chmin(int l, int r, value_type x){chmin(1, 0, hsize, l, r, x);}

private:
  void chmax(int i, int l, int r, int s, int t, value_type x){
    if(r <= s or t <= l or fst_min[i] >= x) return;
    if(s <= l and r <= t and snd_min[i] > x){
      update_node_min(i, x);
      return;
    }

    propagate(i);
    chmax(lc(i), l, (l + r) / 2, s, t, x);
    chmax(rc(i), (l + r) / 2, r, s, t, x);
    bottom_up(i);
  }

public:
  void chmax(int l, int r, value_type x){chmax(1, 0, hsize, l, r, x);}

private:
  void add(int i, int l, int r, int s, int t, value_type x){
    if(r <= s or t <= l) return;
    if(s <= l and r <= t){
      update_node_add(i, x);
      return;
    }

    propagate(i);
    add(lc(i), l, (l + r) / 2, s, t, x);
    add(rc(i), (l + r) / 2, r, s, t, x);
    bottom_up(i);
  }

public:
  void add(int l, int r, value_type x){add(1, 0, hsize, l, r, x);}
  
private:
  value_type get_sum(int i, int l, int r, int s, int t){
    if(r <= s or t <= l) return 0;
    if(s <= l and r <= t) return sum[i];

    propagate(i);
    return get_sum(lc(i), l, (l + r) / 2, s, t) + get_sum(rc(i), (l + r) / 2, r, s, t);
  }

public:
  value_type get_sum(int l, int r){return get_sum(1, 0, hsize, l, r);}


public:  
  void init_with_vector(const std::vector<value_type> &v){
    fst_max.assign(size, std::numeric_limits<value_type>::min());
    snd_max.assign(size, std::numeric_limits<value_type>::min());
    max_count.assign(size, 1);

    fst_min.assign(size, std::numeric_limits<value_type>::max());
    snd_min.assign(size, std::numeric_limits<value_type>::max());
    min_count.assign(size, 1);
    
    sum.assign(size, 0);
    lazy_add.assign(size, 0);

    for(int i = 0; i < (int)v.size(); ++i){
      fst_max[hsize + i] = v[i];
      max_count[hsize + i] = 1;
      fst_min[hsize + i] = v[i];
      min_count[hsize + i] = 1;
      sum[hsize + i] = v[i];
    }

    for(int i = hsize - 1; i > 0; --i) bottom_up(i);
  }
};
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 8 "test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  SegmentTreeBeats seg(N);

  auto a = input_vector<int64_t>(N);
  seg.init_with_vector(a);
  
  for(auto [type, l, r] : input_tuples<int, int, int>(Q)){
    switch(type){
    case 0: {
      int64_t b; std::cin >> b;
      seg.chmin(l, r, b);
      break;
    }
    case 1: {
      int64_t b; std::cin >> b;
      seg.chmax(l, r, b);
      break;
    }
    case 2: {
      int64_t b; std::cin >> b;
      seg.add(l, r, b);
      break;
    }
    case 3: {
      auto ans = seg.get_sum(l, r);
      std::cout << ans << "\n"; 
      break; 
    }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

