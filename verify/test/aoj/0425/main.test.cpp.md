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


# :heavy_check_mark: test/aoj/0425/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8073d21660828a144ab73bbb931100aa">test/aoj/0425</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0425/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 05:03:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Algorithm/Mo/mo_algorithm.cpp.html">Mo's algorithm</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425"

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <utility>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Algorithm/Mo/mo_algorithm.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, K, Q; std::cin >> N >> K >> Q;

  auto [a, b] = hl::input_tuple_vector<int, int>(K);
  for(auto &x : a) --x;
  for(auto &x : b) --x;

  std::vector<std::tuple<int, int, int, int>> qs;
  for(auto [type, s, t, x] : hl::input_tuples<int, int, int, int>(Q)){
    --s, --t, --x;
    qs.emplace_back(type, s, t, x);
  }

  std::vector<int> p(N), q(N);
  std::iota(p.begin(), p.end(), 0);
  std::iota(q.begin(), q.end(), 0);

  std::vector<int> ans(Q);

  auto left =
    [&](int i){
      std::swap(q[p[q[a[i]]]], q[p[q[b[i]]]]);
      std::swap(p[q[a[i]]], p[q[b[i]]]);
    };

  auto right =
    [&](int i){
      std::swap(q[p[a[i]]], q[p[b[i]]]);
      std::swap(p[a[i]], p[b[i]]);
    };

  auto query =
    [&](int i){
      if(std::get<0>(qs[i]) == 1) ans[i] = p[std::get<3>(qs[i])] + 1;
      else ans[i] = q[std::get<3>(qs[i])] + 1;
    };

  auto mo = hl::mo_algorithm(N, Q, left, right, left, right, query);

  for(int i = 0; i < Q; ++i) mo.add(std::get<1>(qs[i]), std::get<2>(qs[i]) + 1);
  mo.build();
  mo.run();

  for(int i = 0; i < Q; ++i) std::cout << ans[i] << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0425/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425"

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <utility>
#line 6 "Mylib/IO/input_tuple_vector.cpp"
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
namespace haar_lib {
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
}
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
#line 3 "Mylib/Algorithm/Mo/mo_algorithm.cpp"
#include <algorithm>
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
#line 11 "test/aoj/0425/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, K, Q; std::cin >> N >> K >> Q;

  auto [a, b] = hl::input_tuple_vector<int, int>(K);
  for(auto &x : a) --x;
  for(auto &x : b) --x;

  std::vector<std::tuple<int, int, int, int>> qs;
  for(auto [type, s, t, x] : hl::input_tuples<int, int, int, int>(Q)){
    --s, --t, --x;
    qs.emplace_back(type, s, t, x);
  }

  std::vector<int> p(N), q(N);
  std::iota(p.begin(), p.end(), 0);
  std::iota(q.begin(), q.end(), 0);

  std::vector<int> ans(Q);

  auto left =
    [&](int i){
      std::swap(q[p[q[a[i]]]], q[p[q[b[i]]]]);
      std::swap(p[q[a[i]]], p[q[b[i]]]);
    };

  auto right =
    [&](int i){
      std::swap(q[p[a[i]]], q[p[b[i]]]);
      std::swap(p[a[i]], p[b[i]]);
    };

  auto query =
    [&](int i){
      if(std::get<0>(qs[i]) == 1) ans[i] = p[std::get<3>(qs[i])] + 1;
      else ans[i] = q[std::get<3>(qs[i])] + 1;
    };

  auto mo = hl::mo_algorithm(N, Q, left, right, left, right, query);

  for(int i = 0; i < Q; ++i) mo.add(std::get<1>(qs[i]), std::get<2>(qs[i]) + 1);
  mo.build();
  mo.run();

  for(int i = 0; i < Q; ++i) std::cout << ans[i] << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

