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


# :heavy_check_mark: test/aoj/0390/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#bb3fee2cd4c16ae4cccadc50c17505dc">test/aoj/0390</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0390/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Group/dihedral.cpp.html">Dihedral group</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390"

#include <iostream>
#include <variant>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/AlgebraicStructure/Group/dihedral.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

namespace hl = haar_lib;

struct tag {};
using M = hl::dihedral_group<tag>;

int main(){
  int K, N, Q; std::cin >> K >> N >> Q;
  auto A = hl::input_vector<int>(N);

  M::K = K;

  hl::segment_tree<M> seg(N);

  for(int i = 0; i < N; ++i){
    if(A[i] > 0){
      seg.update(i, M::R({A[i] % K}));
    }else if(A[i] < 0){
      seg.update(i, M::R({A[i] % K + K}));
    }else{
      seg.update(i, M::S({0}));
    }
  }

  for(auto [L, R] : hl::input_tuples<int, int>(Q)){
    --L, --R;

    auto x = seg[L];
    auto y = seg[R];
    seg.update(L, y);
    seg.update(R, x);

    auto res = seg.get(0, N);

    if(std::holds_alternative<M::R>(res)){
      int ans = (K - std::get<M::R>(res).value) % K + 1;
      std::cout << ans << "\n";
    }else{
      int ans = -(std::get<M::S>(res).value + 1);
      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0390/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390"

#include <iostream>
#include <variant>
#line 3 "Mylib/IO/input_vector.cpp"
#include <vector>

/**
 * @docs input_vector.md
 */
namespace haar_lib {
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
#line 4 "Mylib/AlgebraicStructure/Group/dihedral.cpp"

/**
 * @title Dihedral group
 * @docs dihedral.md
 */
namespace haar_lib {
  template <typename Tag>
  struct dihedral_group {
    struct R {
      int value = 0;
      friend std::ostream& operator<<(std::ostream &s, const R &a){
        s << "R(" << a.value << ")";
        return s;
      }
    };

    struct S {
      int value = 0;
      friend std::ostream& operator<<(std::ostream &s, const S &a){
        s << "S(" << a.value << ")";
        return s;
      }
    };

    static int K;

    using value_type = std::variant<R, S>;

    value_type operator()() const {
      return R({0});
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(std::holds_alternative<R>(a)){
        if(std::holds_alternative<R>(b)){
          return R({(std::get<R>(a).value + std::get<R>(b).value) % K});
        }else{
          return S({(std::get<S>(b).value - std::get<R>(a).value + K) % K});
        }
      }else{
        if(std::holds_alternative<R>(b)){
          return S({(std::get<S>(a).value + std::get<R>(b).value) % K});
        }else{
          return R({(std::get<S>(b).value - std::get<S>(a).value + K) % K});
        }
      }
    }

    value_type inv(const value_type &a) const {
      if(std::holds_alternative<R>(a)){
        const int i = std::get<R>(a).value;
        return R({i == 0 ? 0 : K - i});
      }else{
        return a;
      }
    }
  };

  template <typename Tag> int dihedral_group<Tag>::K;
}
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
#line 9 "test/aoj/0390/main.test.cpp"

namespace hl = haar_lib;

struct tag {};
using M = hl::dihedral_group<tag>;

int main(){
  int K, N, Q; std::cin >> K >> N >> Q;
  auto A = hl::input_vector<int>(N);

  M::K = K;

  hl::segment_tree<M> seg(N);

  for(int i = 0; i < N; ++i){
    if(A[i] > 0){
      seg.update(i, M::R({A[i] % K}));
    }else if(A[i] < 0){
      seg.update(i, M::R({A[i] % K + K}));
    }else{
      seg.update(i, M::S({0}));
    }
  }

  for(auto [L, R] : hl::input_tuples<int, int>(Q)){
    --L, --R;

    auto x = seg[L];
    auto y = seg[R];
    seg.update(L, y);
    seg.update(R, x);

    auto res = seg.get(0, N);

    if(std::holds_alternative<M::R>(res)){
      int ans = (K - std::get<M::R>(res).value) % K + 1;
      std::cout << ans << "\n";
    }else{
      int ans = -(std::get<M::S>(res).value + 1);
      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

