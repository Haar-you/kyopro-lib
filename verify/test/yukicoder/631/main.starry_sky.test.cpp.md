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


# :x: test/yukicoder/631/main.starry_sky.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0b2f27755ad8078580256305f9366a63">test/yukicoder/631</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/631/main.starry_sky.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 21:04:10+09:00


* see: <a href="https://yukicoder.me/problems/no/631">https://yukicoder.me/problems/no/631</a>


## Depends on

* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp.html">Starry-sky tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>
#include <functional>

#include "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;
  
  auto seg = StarrySkyTree<int64_t, std::greater<>>(N-1);

  auto T = input_vector<int64_t>(N-1);
    
  for(int i = 0; i < N-1; ++i){
    T[i] += 3 * (N-1-i);
  }

  seg.init_with_vector(T);
    
  int M; std::cin >> M;

  for(auto [L, R, D] : input_tuples<int, int, int>(M)){
    --L, --R;

    seg.update(L, R+1, D);
      
    auto ans = seg.get(0, N-1);
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/631/main.starry_sky.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>
#include <functional>

#line 3 "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include <optional>
#include <algorithm>

/**
 * @title Starry-sky tree
 * @docs StarrySkyTree.md
 */
template <typename T, typename Compare>
class StarrySkyTree{
  int depth, size, hsize;
  std::vector<T> data;

  Compare compare = Compare();

  T f(T a, T b) const {
    return compare(a, b) ? a : b;
  }

  void bottom_up(int i){
    if(i > size) return;

    while(i >= 1){
      if(i < hsize){
        const auto d = f(data[i << 1 | 0], data[i << 1 | 1]);
        
        data[i << 1 | 0] -= d;
        data[i << 1 | 1] -= d;
        data[i] += d;
      }

      i >>= 1;
    }
  }
  
  std::optional<T> get(int i, int l, int r, int s, int t, T val) const {
    if(r <= s or t <= l) return std::nullopt;
    if(s <= l and r <= t) return val + data[i];

    auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data[i]);
    auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data[i]);

    if(not a) return b;
    if(not b) return a;
    return f(*a, *b);
  }

public:
  StarrySkyTree(int n):
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
    return *get(1, 0, hsize, l, r, 0);
  }

  template <typename U>
  void init_with_vector(std::vector<U> &a){
    for(int i = 0; i < (int)a.size(); ++i){
      data[hsize + i] = a[i];
    }

    for(int i = hsize - 1; i >= 1; --i){
      data[i] = f(data[i << 1 | 0], data[i << 1 | 1]);
    }

    for(int i = size - 1; i > 1; --i){
      data[i] -= data[i >> 1];
    }
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
#line 10 "test/yukicoder/631/main.starry_sky.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;
  
  auto seg = StarrySkyTree<int64_t, std::greater<>>(N-1);

  auto T = input_vector<int64_t>(N-1);
    
  for(int i = 0; i < N-1; ++i){
    T[i] += 3 * (N-1-i);
  }

  seg.init_with_vector(T);
    
  int M; std::cin >> M;

  for(auto [L, R, D] : input_tuples<int, int, int>(M)){
    --L, --R;

    seg.update(L, R+1, D);
      
    auto ans = seg.get(0, N-1);
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

