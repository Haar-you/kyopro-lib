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


# :x: test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#41749cc077979299e644c18a01e43785">test/yosupo-judge/line_add_get_min</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/line_add_get_min">https://judge.yosupo.jp/problem/line_add_get_min</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp.html">Dynamic LiChao segment tree</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto lc = DynamicLiChaoSegmentTree<int64_t, std::less<>>(INT_MIN, INT_MAX);

  for(auto [a, b] : input_tuples<int64_t, int64_t>(N)){
    lc.add_line(a, b);
  }

  for(auto [type] : input_tuples<int>(Q)){
    if(type == 0){
      int64_t a, b; std::cin >> a >> b;
      lc.add_line(a, b);
    }else{
      int64_t p; std::cin >> p;
      std::cout << *lc(p) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <climits>
#line 2 "Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp"
#include <utility>
#include <optional>

/**
 * @title Dynamic LiChao segment tree
 * @docs dynamic_lichao_segment_tree.md
 */
template <typename T, typename Comparator>
class DynamicLiChaoSegmentTree {
  using line = std::pair<T, T>;

  const Comparator cmp = Comparator();

  struct node {
    std::optional<line> value;
    int64_t l, r;
    node *l_child = nullptr, *r_child = nullptr;
    node(std::optional<line> value, int64_t l, int64_t r): value(value), l(l), r(r){}
  };

  int64_t MIN, MAX;
  node *root = nullptr;

  T chm(const T &a, const T &b) const {
    return cmp(a, b) ? a : b;
  }

public:
  DynamicLiChaoSegmentTree(int64_t MIN, int64_t MAX): MIN(MIN), MAX(MAX){}

  T apply(const line &l, const T &x) const {
    return l.first * x + l.second;
  }

private:
  node* update(node *t, line new_line, int64_t l, int64_t r){
    if(not t){
      return t = new node(new_line, l, r);
    }

    if(not t->value){
      t->value = new_line;
      return t;
    }

    if(l + 1 == r){
      if(cmp(apply(new_line, l), apply(*(t->value), l))){
        t->value = new_line;
      }
      return t;
    }

    const auto m = (l + r) / 2;

    bool left = cmp(apply(new_line, l), apply(*(t->value), l));
    bool mid = cmp(apply(new_line, m), apply(*(t->value), m));
    bool right = cmp(apply(new_line, r), apply(*(t->value), r));

    if(left and right){
      t->value = new_line;
      return t;
    }

    if(not left and not right){
      return t;
    }

    if(mid){
      std::swap(*(t->value), new_line);
    }

    if(left != mid){
      t->l_child = update(t->l_child, new_line, l, m);
    }else{
      t->r_child = update(t->r_child, new_line, m, r);
    }

    return t;
  }

  node* update_segment(node *t, line new_line, int64_t l, int64_t r, int64_t sl, int64_t sr){
    if(r < sl or sr < l) return t;
    if(sl <= l and r <= sr){
      return t = update(t, new_line, l, r);
    }

    if(l + 1 == r){
      return t;
    }

    if(not t) t = new node(std::nullopt, l, r);
    else{
      if(t->value){
        if(
          cmp(apply(*(t->value), l), apply(new_line, l)) and
          cmp(apply(*(t->value), r), apply(new_line, r))
        ){
          return t;
        }
      }
    }

    const auto m = (l + r) / 2;

    t->l_child = update_segment(t->l_child, new_line, l, m, sl, sr);
    t->r_child = update_segment(t->r_child, new_line, m, r, sl, sr);

    return t;
  }

public:
  void add_line(T a, T b){
    root = update(root, std::make_pair(a, b), MIN, MAX);
  }

  void add_segment(int64_t l, int64_t r, T a, T b){
    root = update_segment(root, std::make_pair(a, b), MIN, MAX, l, r);
  }

  auto operator()(const int64_t &x) const {
    std::optional<T> ret;
    node *cur = root;

    while(cur){
      if(cur->value){
        if(not ret) ret = apply(*(cur->value), x);
        else ret = chm(*ret, apply(*(cur->value), x));
      }

      const auto m = (cur->l + cur->r) / 2;
      if(x < m) cur = cur->l_child;
      else cur = cur->r_child;
    }

    return ret;
  }
};
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
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
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
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
#line 7 "test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto lc = DynamicLiChaoSegmentTree<int64_t, std::less<>>(INT_MIN, INT_MAX);

  for(auto [a, b] : input_tuples<int64_t, int64_t>(N)){
    lc.add_line(a, b);
  }

  for(auto [type] : input_tuples<int>(Q)){
    if(type == 0){
      int64_t a, b; std::cin >> a >> b;
      lc.add_line(a, b);
    }else{
      int64_t p; std::cin >> p;
      std::cout << *lc(p) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

