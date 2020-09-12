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


# :x: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9102555d140c20ca7196c4db584ea7b6">test/yosupo-judge/rectangle_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Sum monoid</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp.html">Persistent segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/Utils/compressor.cpp.html">Compressor</a>
* :x: <a href="../../../../library/Mylib/Utils/sort_simultaneously.cpp.html">Mylib/Utils/sort_simultaneously.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#include "Mylib/Utils/sort_simultaneously.cpp"
#include "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/Utils/compressor.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using Seg = hl::persistent_segment_tree<hl::sum_monoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = hl::input_tuple_vector<int64_t, int64_t, int64_t>(N);

  hl::sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    x, y, w
  );

  auto c = hl::compressor<int64_t>().add(x).build().compress(x);
  const int m = c.size();

  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s[x[i]] + w[i]));
  }

  for(auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
    l = c.get_index(l);
    r = c.get_index(r);

    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();
    d = std::lower_bound(y.begin(), y.end(), d) - y.begin();

    auto ans = seg[u].get(l, r) - seg[d].get(l, r);
    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>
#line 3 "Mylib/Utils/sort_simultaneously.cpp"
#include <utility>
#include <algorithm>
#include <numeric>
#include <initializer_list>

/**
 * @docs sort_simultaneously.md
 */
namespace haar_lib {
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
}
#line 3 "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"

/**
 * @title Persistent segment tree
 * @docs persistent_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class persistent_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type value;
      node *left = nullptr, *right = nullptr;
      node(const value_type &value): value(value){}
    };

    int depth;
    node *root = nullptr;

    persistent_segment_tree(int depth, node *root): depth(depth), root(root){}

    node* init(node *t, const std::vector<value_type> &init_list, int d, int &pos){
      if(d == depth){
        t = new node(pos < (int)init_list.size() ? init_list[pos] : M());
        ++pos;
      }else{
        t = new node(M());
        t->left = init(t->left, init_list, d + 1, pos);
        t->right = init(t->right, init_list, d + 1, pos);
        t->value = M(t->left->value, t->right->value);
      }
      return t;
    }

  public:
    persistent_segment_tree(const std::vector<value_type> &init_list){
      const int size = init_list.size();
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, init_list, 1, pos);
    }

    persistent_segment_tree(int size, const value_type &value = M()){
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, std::vector<value_type>(size, value), 1, pos);
    }

  protected:
    node* update(node *t, int l, int r, int pos, const value_type &val) const {
      if(r <= pos or pos + 1 <= l){
        return t;
      }else if(pos <= l and r <= pos + 1){
        return new node(val);
      }else{
        const int m = (l + r) >> 1;
        auto lp = update(t->left, l, m, pos, val);
        auto rp = update(t->right, m, r, pos, val);

        node *s = new node(M(lp->value, rp->value));

        s->left = lp;
        s->right = rp;

        return s;
      }
    }

  public:
    persistent_segment_tree update(int i, const value_type &val) const {
      node *t = update(root, 0, 1 << (depth - 1), i, val);
      return persistent_segment_tree(depth, t);
    }

  protected:
    value_type get(node *t, int i, int j, int l, int r) const {
      if(i <= l and r <= j) return t->value;
      if(r <= i or j <= l) return M();
      const int m = (l + r) >> 1;
      return M(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
    }

  public:
    value_type get(int i, int j) const {
      return get(root, i, j, 0, 1 << (depth - 1));
    }

    value_type operator[](int i) const {
      return get(i, i + 1);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @title Sum monoid
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_monoid {
    using value_type = T;
    value_type operator()() const {return 0;}
    value_type operator()(value_type a, value_type b) const {return a + b;}
  };
}
#line 4 "Mylib/Utils/compressor.cpp"

/**
 * @title Compressor
 * @docs compressor.md
 */
namespace haar_lib {
  template <typename T>
  class compressor {
    std::vector<T> data;

  public:
    auto& add(const T &val){
      data.push_back(val);
      return *this;
    }

    auto& add(const std::vector<T> &vals){
      data.insert(data.end(), vals.begin(), vals.end());
      return *this;
    }

    template <typename U, typename ... Args>
    auto& add(const U &val, const Args &... args){
      add(val);
      return add(args ...);
    }

    auto& build(){
      std::sort(data.begin(), data.end());
      data.erase(std::unique(data.begin(), data.end()), data.end());
      return *this;
    }

    int get_index(const T &val) const {
      return std::lower_bound(data.begin(), data.end(), val) - data.begin();
    }

    auto& compress(std::vector<T> &vals) const {
      for(auto &x : vals) x = get_index(x);
      return *this;
    }

    auto& compress(T &val) const {
      val = get_index(val);
      return *this;
    }

    template <typename U, typename ... Args>
    auto& compress(U &val, Args &... args) const {
      compress(val);
      return compress(args ...);
    }

    auto& decompress(std::vector<T> &vals) const {
      for(auto &x : vals) x = data[x];
      return *this;
    }

    auto& decompress(T &val) const {
      val = data[val];
      return *this;
    }

    template <typename U, typename ... Args>
    auto& decompress(U &val, Args &... args) const {
      decompress(val);
      return decompress(args ...);
    }

    int size() const {return data.size();}
    T operator[](int index) const {return data[index];}
  };
}
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#line 7 "Mylib/IO/input_tuple_vector.cpp"

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
#line 11 "test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp"

namespace hl = haar_lib;

using Seg = hl::persistent_segment_tree<hl::sum_monoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = hl::input_tuple_vector<int64_t, int64_t, int64_t>(N);

  hl::sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    x, y, w
  );

  auto c = hl::compressor<int64_t>().add(x).build().compress(x);
  const int m = c.size();

  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s[x[i]] + w[i]));
  }

  for(auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
    l = c.get_index(l);
    r = c.get_index(r);

    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();
    d = std::lower_bound(y.begin(), y.end(), d) - y.begin();

    auto ans = seg[u].get(l, r) - seg[d].get(l, r);
    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

