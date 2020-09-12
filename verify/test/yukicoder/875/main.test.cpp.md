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


# :x: test/yukicoder/875/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#85bd684f532fe6c6e7e3dd42beff3eb5">test/yukicoder/875</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/875/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00


* see: <a href="https://yukicoder.me/problems/no/875">https://yukicoder.me/problems/no/875</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/min.cpp.html">Min monoid</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/with_min_index.cpp.html">Mylib/AlgebraicStructure/Monoid/with_min_index.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples_with_index.cpp.html">Mylib/IO/input_tuples_with_index.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/AlgebraicStructure/Monoid/with_min_index.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

using Mon = hl::with_min_index<hl::min_monoid<int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::segment_tree<Mon> seg(N);

  std::vector<Mon::value_type> a(N);
  for(auto [i, x] : hl::input_tuples_with_index<int>(N)){
    a[i] = std::make_pair(x, i);
  }

  seg.init_with_vector(a);

  for(auto [type, l, r] : hl::input_tuples<int, int, int>(Q)){
    switch(type){
    case 1: {
      --l, --r;

      auto x = seg[l].first;
      auto y = seg[r].first;

      seg.update(l, std::make_pair(y, l));
      seg.update(r, std::make_pair(x, r));

      break;
    }
    case 2: {
      --l, --r;

      std::cout << seg.get(l, r + 1).second + 1 << "\n";

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
#line 1 "test/yukicoder/875/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <algorithm>
#include <functional>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    int depth, size, hsize;
    std::vector<value_type> data;

  public:
    segment_tree(){}
    segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, M())
    {}

    auto operator[](int i) const {return data[hsize + i];}

    auto get(int x, int y) const {
      value_type ret_left = M();
      value_type ret_right = M();

      int l = x + hsize, r = y + hsize;
      while(l < r){
        if(r & 1) ret_right = M(data[--r], ret_right);
        if(l & 1) ret_left = M(ret_left, data[l++]);
        l >>= 1, r >>= 1;
      }

      return M(ret_left, ret_right);
    }

    void update(int i, const value_type &x){
      i += hsize;
      data[i] = x;
      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize, val));
    }

  private:
    template <bool Lower, typename F>
    int bound(const int l, const int r, value_type x, F f) const {
      std::vector<int> pl, pr;
      int L = l + hsize;
      int R = r + hsize;
      while(L < R){
        if(R & 1) pr.push_back(--R);
        if(L & 1) pl.push_back(L++);
        L >>= 1, R >>= 1;
      }

      std::reverse(pr.begin(), pr.end());
      pl.insert(pl.end(), pr.begin(), pr.end());

      value_type a = M();

      for(int i : pl){
        auto b = M(a, data[i]);

        if((Lower and not f(b, x)) or (not Lower and f(x, b))){
          while(i < hsize){
            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not Lower and f(x, c))){
              i = i << 1 | 0;
            }else{
              a = c;
              i = i << 1 | 1;
            }
          }

          return i - hsize;
        }

        a = b;
      }

      return r;
    }

  public:
    template <typename F = std::less<value_type>>
    int lower_bound(int l, int r, value_type x, F f = F()) const {
      return bound<true>(l, r, x, f);
    }

    template <typename F = std::less<value_type>>
    int upper_bound(int l, int r, value_type x, F f = F()) const {
      return bound<false>(l, r, x, f);
    }
  };
}
#line 3 "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include <optional>

/**
 * @title Min monoid
 * @docs min.md
 */
namespace haar_lib {
  template <typename T>
  struct min_monoid {
    using value_type = std::optional<T>;

    value_type operator()() const {return {};}
    value_type operator()(const value_type &a, const value_type &b) const {
      if(not a) return b;
      if(not b) return a;
      return {std::min(*a, *b)};
    }
  };
}
#line 3 "Mylib/AlgebraicStructure/Monoid/with_min_index.cpp"
#include <limits>
#line 5 "Mylib/AlgebraicStructure/Monoid/with_min_index.cpp"

/**
 * @docs with_min_index.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct with_min_index {
    using value_type = std::pair<typename Monoid::value_type, int64_t>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), std::numeric_limits<int64_t>::max()};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(a.first == b.first) return {a.first, std::min(a.second, b.second)};
      if(M(a.first, b.first) == a.first) return a;
      else return b;
    }
  };
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
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
#line 8 "Mylib/IO/input_tuples_with_index.cpp"

/**
 * @docs input_tuples_with_index.md
 */
namespace haar_lib {
  template <typename ... Args>
  class InputTuplesWithIndex {
    struct iter {
      using value_type = std::tuple<int, Args ...>;
      value_type value;
      bool fetched = false;
      int N;
      int c = 0;

      value_type operator*(){
        if(not fetched){
          std::tuple<Args ...> temp; std::cin >> temp;
          value = std::tuple_cat(std::make_tuple(c), temp);
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
    InputTuplesWithIndex(int N): N(N){}

    iter begin() const {return iter(N);}
    iter end() const {return iter(N);}
  };

  template <typename ... Args>
  auto input_tuples_with_index(int N){
    return InputTuplesWithIndex<Args ...>(N);
  }
}
#line 11 "test/yukicoder/875/main.test.cpp"

namespace hl = haar_lib;

using Mon = hl::with_min_index<hl::min_monoid<int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::segment_tree<Mon> seg(N);

  std::vector<Mon::value_type> a(N);
  for(auto [i, x] : hl::input_tuples_with_index<int>(N)){
    a[i] = std::make_pair(x, i);
  }

  seg.init_with_vector(a);

  for(auto [type, l, r] : hl::input_tuples<int, int, int>(Q)){
    switch(type){
    case 1: {
      --l, --r;

      auto x = seg[l].first;
      auto y = seg[r].first;

      seg.update(l, std::make_pair(y, l));
      seg.update(r, std::make_pair(x, r));

      break;
    }
    case 2: {
      --l, --r;

      std::cout << seg.get(l, r + 1).second + 1 << "\n";

      break;
    }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

