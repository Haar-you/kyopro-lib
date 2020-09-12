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


# :x: test/yosupo-judge/static_range_inversions_query/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6a29c5e431615f0854be5d2b0bff9042">test/yosupo-judge/static_range_inversions_query</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/static_range_inversions_query/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 05:03:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_inversions_query">https://judge.yosupo.jp/problem/static_range_inversions_query</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Algorithm/Mo/mo_algorithm.cpp.html">Mo's algorithm</a>
* :x: <a href="../../../../library/Mylib/Algorithm/Query/range_inversions_query.cpp.html">Range inversions query</a>
* :x: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp.html">Fenwick tree (Add)</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Algorithm/Query/range_inversions_query.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;
  auto A = hl::input_vector<int>(N);

  hl::range_inversions_query riq(A);

  for(auto [l, r] : hl::input_tuples<int, int>(Q)){
    riq.add(l, r);
  }

  auto ans = riq.solve();

  for(auto x : ans){
    std::cout << x << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/static_range_inversions_query/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include <vector>
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
#line 4 "Mylib/Algorithm/Query/range_inversions_query.cpp"
#include <algorithm>
#line 3 "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"

/**
 * @title Fenwick tree (Add)
 * @docs fenwick_tree_add.md
 */
namespace haar_lib {
  template <typename T>
  class fenwick_tree_add {
    using value_type = T;

    int size;
    std::vector<value_type> data;

  public:
    fenwick_tree_add(){}
    fenwick_tree_add(int size): size(size), data(size + 1, 0){}

    void update(int i, value_type val){
      i += 1; // 1-index

      while(i <= size){
        data[i] = data[i] + val;
        i += i & (-i);
      }
    }

    value_type get(int i) const { // [0, i)
      value_type ret = 0;
      i += 1; // 1-index

      while(i > 0){
        ret = ret + data[i];
        i -= i & (-i);
      }

      return ret;
    }

    value_type get(int l, int r) const { // [l, r)
      return get(r - 1) - get(l - 1);
    }
  };
}
#line 4 "Mylib/Algorithm/Mo/mo_algorithm.cpp"
#include <cassert>
#include <cmath>

/**
 * @title Mo's algorithm
 * @docs mo_algorithm.md
 */
namespace haar_lib {
  template <typename AppendLeft, typename AppendRight, typename RemoveLeft, typename RemoveRight, typename Query>
  class mo_algorithm {
    int N, Q, index, width;
    std::vector<int> left, right, ord;

    const AppendLeft append_left;
    const AppendRight append_right;
    const RemoveLeft remove_left;
    const RemoveRight remove_right;
    const Query query;

    bool is_built = false;

  public:
    mo_algorithm(
      int N, int Q,
      const AppendLeft &append_left, const AppendRight &append_right,
      const RemoveLeft &remove_left, const RemoveRight &remove_right,
      const Query &query
    ):
      N(N), Q(Q), index(0), width(std::sqrt(N)),
      left(Q), right(Q), ord(Q),
      append_left(append_left), append_right(append_right),
      remove_left(remove_left), remove_right(remove_right),
      query(query)
    {}

    // [l, r)
    void add(int l, int r){
      left[index] = l;
      right[index] = r;
      ord[index] = index;
      ++index;
    }

    void build(){
      std::sort(
        ord.begin(),
        ord.end(),
        [&](int i, int j){
          const int a = left[i] / width, b = left[j] / width;
          if(a == b){
            if(a & 1){
              return right[i] < right[j];
            }else{
              return right[i] > right[j];
            }
          }else{
            return a < b;
          }
        }
      );

      is_built = true;
    }

    void run(){
      assert(is_built);

      int q = 0;
      int l = left[ord[0]], r = left[ord[0]];

      for(int i = 0; i < Q; ++i){
        int id = ord[q++];

        while(l != left[id] or r != right[id]){
          if(l > left[id]) append_left(--l);
          if(l < left[id]) remove_left(l++);
          if(r < right[id]) append_right(r++);
          if(r > right[id]) remove_right(--r);
        }

        query(id);
      }
    }
  };
}
#line 7 "Mylib/Algorithm/Query/range_inversions_query.cpp"

/**
 * @title Range inversions query
 * @docs range_inversions_query.md
 */
namespace haar_lib {
  template <typename T>
  class range_inversions_query {
    std::vector<int> a;
    int N;
    std::vector<std::pair<int, int>> qs;

  public:
    range_inversions_query(std::vector<T> a_): N(a_.size()){
      auto b = a_;
      std::sort(b.begin(), b.end());
      b.erase(std::unique(b.begin(), b.end()), b.end());

      for(auto x : a_){
        const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();
        a.push_back(i);
      }
    }

    void add(int l, int r){ // [l, r)
      qs.emplace_back(l, r);
    }

    auto solve(){
      const int Q = qs.size();
      fenwick_tree_add<int64_t> b(N);

      int64_t t = 0;
      std::vector<int64_t> ans(Q);

      auto append_left =
        [&](int i){
          t += b.get(0, a[i]);
          b.update(a[i], 1);
        };

      auto append_right =
        [&](int i){
          t += b.get(a[i] + 1, N);
          b.update(a[i], 1);
        };

      auto remove_left =
        [&](int i){
          t -= b.get(0, a[i]);
          b.update(a[i], -1);
        };

      auto remove_right =
        [&](int i){
          t -= b.get(a[i] + 1, N);
          b.update(a[i], -1);
        };

      auto query = [&](int i){ans[i] = t;};

      auto mo =
        mo_algorithm(
          N, Q, append_left, append_right, remove_left, remove_right, query
        );

      for(auto [l, r] : qs){
        mo.add(l, r);
      }

      mo.build();
      mo.run();

      return ans;
    }
  };
}
#line 8 "test/yosupo-judge/static_range_inversions_query/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;
  auto A = hl::input_vector<int>(N);

  hl::range_inversions_query riq(A);

  for(auto [l, r] : hl::input_tuples<int, int>(Q)){
    riq.add(l, r);
  }

  auto ans = riq.solve();

  for(auto x : ans){
    std::cout << x << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
