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


# :x: test/yukicoder/776/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a8c189a9cd3b51f204ab4e40b62c7dab">test/yukicoder/776</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/776/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00


* see: <a href="https://yukicoder.me/problems/no/776">https://yukicoder.me/problems/no/776</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp.html">Max partial sum monoid</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/776"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using Mon = hl::max_partial_sum_monoid<int64_t>;

int main(){
  int N, Q; std::cin >> N >> Q;

  hl::segment_tree<Mon> seg(N);

  auto a = hl::input_vector<int64_t>(N);
  for(int i = 0; i < N; ++i){
    seg.update(i, Mon::max_partial_sum(a[i]));
  }

  for(auto [type] : hl::input_tuples<std::string>(Q)){
    if(type == "set"){
      int i, x; std::cin >> i >> x;
      --i;
      seg.update(i, Mon::max_partial_sum(x));
      a[i] = x;
    }else{
      int l1, l2, r1, r2; std::cin >> l1 >> l2 >> r1 >> r2;
      --l1, --l2, --r1, --r2;

      r1 = std::max(l1, r1);
      l2 = std::min(l2, r2);

      int64_t ans = LLONG_MIN;

      auto f =
        [&](int L1, int L2, int R1, int R2){
          auto ret =
            seg.get(L1, L2 + 1).value_or(Mon::max_partial_sum(0)).right_max +
            seg.get(L2 + 1, R1).value_or(Mon::max_partial_sum(0)).sum +
            seg.get(R1, R2 + 1).value_or(Mon::max_partial_sum(0)).left_max;

          if(L2 == R1) ret -= a[L2];

          return ret;
        };

      if(l2 <= r1){
        ans = f(l1, l2, r1, r2);
      }else{
        ans = std::max(ans, f(l1, r1, r1, r2));
        ans = std::max(ans, f(l1, l2, l2, r2));
        ans = std::max(ans, seg.get(r1, l2 + 1)->partial_max);
      }

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
#line 1 "test/yukicoder/776/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/776"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#line 2 "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include <optional>
#line 5 "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"

/**
 * @title Max partial sum monoid
 * @docs max_partial_sum.md
 */
namespace haar_lib {
  template <typename T>
  struct max_partial_sum_monoid {
    struct max_partial_sum {
      T sum, left_max, right_max, partial_max;
      max_partial_sum(T x): sum(x), left_max(x), right_max(x), partial_max(x){}
      max_partial_sum(T sum, T left_max, T right_max, T partial_max): sum(sum), left_max(left_max), right_max(right_max), partial_max(partial_max){}

      friend std::ostream& operator<<(std::ostream &s, const max_partial_sum &a){
        s << "(" << "sum: " << a.sum << ", "
          << "left_max: " << a.left_max << ", "
          << "right_max: " << a.right_max << ", "
          << "partial_max: " << a.partial_max << ")";
        return s;
      }
    };

    using value_type = std::optional<max_partial_sum>;

    value_type operator()() const {
      return std::nullopt;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(not a) return b;
      if(not b) return a;

      return max_partial_sum(
        a->sum + b->sum,
        std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
        std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
        std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
      );
    }
  };
}
#line 4 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
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
#line 4 "Mylib/IO/input_vector.cpp"

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
#line 12 "test/yukicoder/776/main.test.cpp"

namespace hl = haar_lib;

using Mon = hl::max_partial_sum_monoid<int64_t>;

int main(){
  int N, Q; std::cin >> N >> Q;

  hl::segment_tree<Mon> seg(N);

  auto a = hl::input_vector<int64_t>(N);
  for(int i = 0; i < N; ++i){
    seg.update(i, Mon::max_partial_sum(a[i]));
  }

  for(auto [type] : hl::input_tuples<std::string>(Q)){
    if(type == "set"){
      int i, x; std::cin >> i >> x;
      --i;
      seg.update(i, Mon::max_partial_sum(x));
      a[i] = x;
    }else{
      int l1, l2, r1, r2; std::cin >> l1 >> l2 >> r1 >> r2;
      --l1, --l2, --r1, --r2;

      r1 = std::max(l1, r1);
      l2 = std::min(l2, r2);

      int64_t ans = LLONG_MIN;

      auto f =
        [&](int L1, int L2, int R1, int R2){
          auto ret =
            seg.get(L1, L2 + 1).value_or(Mon::max_partial_sum(0)).right_max +
            seg.get(L2 + 1, R1).value_or(Mon::max_partial_sum(0)).sum +
            seg.get(R1, R2 + 1).value_or(Mon::max_partial_sum(0)).left_max;

          if(L2 == R1) ret -= a[L2];

          return ret;
        };

      if(l2 <= r1){
        ans = f(l1, l2, r1, r2);
      }else{
        ans = std::max(ans, f(l1, r1, r1, r2));
        ans = std::max(ans, f(l1, l2, l2, r2));
        ans = std::max(ans, seg.get(r1, l2 + 1)->partial_max);
      }

      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

