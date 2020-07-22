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


# :heavy_check_mark: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9102555d140c20ca7196c4db584ea7b6">test/yosupo-judge/rectangle_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp.html">Persistent segment tree</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/compressor.cpp.html">Compressor</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/sort_simultaneously.cpp.html">Mylib/Misc/sort_simultaneously.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>

#include "Mylib/Misc/sort_simultaneously.cpp"
#include "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/Misc/compressor.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

using Seg = PersistentSegmentTree<SumMonoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = input_tuple_vector<int64_t, int64_t, int64_t>(N);

  sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    N, x, y, w
  );

  auto c = Compressor<int64_t>().add(x).build().compress(x);
  const int m = c.size();
  
  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s.at(x[i]) + w[i]));
  }
  
  for(auto [l, d, r, u] : input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
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

#line 3 "Mylib/Misc/sort_simultaneously.cpp"
#include <utility>
#include <algorithm>
#include <numeric>

/**
 * @docs sort_simultaneously.md
 */
template <typename T>
void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
  std::vector<T> temp(N);
  for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
  std::swap(temp, a);
}

template <typename T, typename ...Args>
void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a, Args&... args){
  std::vector<T> temp(N);
  for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
  std::swap(temp, a);
  sort_with_ord(ord, N, args...);
}

template <typename Compare, typename ...Args>
void sort_simultaneously(const Compare &compare, int N, Args&... args){
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), compare);

  sort_with_ord(ord, N, args...);
}
#line 3 "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"

/**
 * @title Persistent segment tree
 * @docs persistent_segment_tree.md
 */
template <typename Monoid>
class PersistentSegmentTree{
  using value_type = typename Monoid::value_type;
  constexpr static Monoid M = Monoid();
  
  struct node{
    value_type value;
    node *left = nullptr, *right = nullptr;
    node(const value_type &value): value(value){}
  };

  int depth;
  node *root = nullptr;

  PersistentSegmentTree(int depth, node *root): depth(depth), root(root){}
  
  node* init(node *t, const std::vector<value_type> &init_list, int d, int &pos){
    if(d == depth){
      t = new node(pos < (int)init_list.size() ? init_list[pos] : M.id());
      ++pos;
    }else{
      t = new node(M.id());
      t->left = init(t->left, init_list, d+1, pos);
      t->right = init(t->right, init_list, d+1, pos);
      t->value = M.op(t->left->value, t->right->value);
    }
    return t;
  }
  
public:
  PersistentSegmentTree(const std::vector<value_type> &init_list){
    const int size = init_list.size();
    depth = size == 1 ? 1 : 32 - __builtin_clz(size-1) + 1;
    int pos = 0;
    root = init(root, init_list, 1, pos);
  }
  
  PersistentSegmentTree(int size, const value_type &value = M.id()){
    depth = size == 1 ? 1 : 32 - __builtin_clz(size-1) + 1;
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

      node *s = new node(M.op(lp->value, rp->value));

      s->left = lp;
      s->right = rp;
      
      return s;
    }
  }

public:
  PersistentSegmentTree update(int i, const value_type &val) const {
    node *t = update(root, 0, 1 << (depth-1), i, val);
    return PersistentSegmentTree(depth, t);
  }

protected:
  value_type get(node *t, int i, int j, int l, int r) const {
    if(i <= l and r <= j) return t->value;
    if(r <= i or j <= l) return M.id();
    const int m = (l + r) >> 1;
    return M.op(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
  }

public:
  value_type get(int i, int j) const {
    return get(root, i, j, 0, 1 << (depth-1));
  }

  value_type at(int i) const {
    return get(i, i+1);
  }
};
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  value_type id() const {return 0;}
  value_type op(value_type a, value_type b) const {return a + b;}
};
#line 4 "Mylib/Misc/compressor.cpp"

/**
 * @title Compressor
 * @docs compressor.md
 */
template <typename T>
class Compressor{
  std::vector<T> data;

public:
  auto& add(const T &val) {data.push_back(val); return *this;}
  auto& add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end()); return *this;}
  template <typename U, typename ...Args> auto& add(const U &val, const Args&... args) {add(val); return add(args...);}

  auto& build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
    return *this;
  }

  int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  auto& compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x); return *this;}
  auto& compress(T &val) const {val = get_index(val);return *this;}
  template <typename U, typename ...Args> auto& compress(U &val, Args&... args) const {compress(val); return compress(args...);}

  auto& decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x]; return *this;}
  auto& decompress(T &val) const {val = data[val]; return *this;}
  template <typename U, typename ...Args> auto& decompress(U &val, Args&... args) const {decompress(val); return decompress(args...);}
  
  int size() const {return data.size();}
  T operator[](int index) const {return data[index];}
};
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuple_vector.cpp"
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
template <typename T, size_t ... I>
void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0)...};
}

template <typename T, size_t ... I>
void input_tuple_vector_helper(T &val, int i, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0)...};
}

template <typename ... Args>
auto input_tuple_vector(int N){
  std::tuple<std::vector<Args>...> ret;

  input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());
  for(int i = 0; i < N; ++i){
    input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());
  }

  return ret;
}
#line 6 "Mylib/IO/input_tuples.cpp"
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
#line 12 "test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp"

using Seg = PersistentSegmentTree<SumMonoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = input_tuple_vector<int64_t, int64_t, int64_t>(N);

  sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    N, x, y, w
  );

  auto c = Compressor<int64_t>().add(x).build().compress(x);
  const int m = c.size();
  
  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s.at(x[i]) + w[i]));
  }
  
  for(auto [l, d, r, u] : input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
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

