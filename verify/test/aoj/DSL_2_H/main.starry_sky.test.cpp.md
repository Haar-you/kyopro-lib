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


# :x: test/aoj/DSL_2_H/main.starry_sky.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#dff63cd4dbbcc206af021772ba80d157">test/aoj/DSL_2_H</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_H/main.starry_sky.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp.html">Starry-sky tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include <functional>
#include "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::starry_sky_tree<int, std::less<>> seg(n);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.get(s, t + 1) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_H/main.starry_sky.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include <functional>
#line 2 "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include <vector>
#include <optional>
#include <algorithm>

/**
 * @title Starry-sky tree
 * @docs starry_sky_tree.md
 */
namespace haar_lib {
  template <typename T, typename Compare>
  class starry_sky_tree {
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
    starry_sky_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
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
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
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
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
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
}
#line 7 "test/aoj/DSL_2_H/main.starry_sky.test.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::starry_sky_tree<int, std::less<>> seg(n);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.get(s, t + 1) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

