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


# :x: test/yosupo-judge/line_add_get_min/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#41749cc077979299e644c18a01e43785">test/yosupo-judge/line_add_get_min</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/line_add_get_min/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/line_add_get_min">https://judge.yosupo.jp/problem/line_add_get_min</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp.html">LiChao segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <tuple>
#include "Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

using Query = std::variant<std::pair<int64_t,int64_t>, int64_t>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> xs;

  std::vector<std::pair<int64_t, int64_t>> lines;

  for(auto [a, b] : input_tuples<int64_t, int64_t>(N)){
    lines.emplace_back(a, b);
  }

  std::vector<Query> query;

  for(auto [type] : input_tuples<int>(Q)){
    switch(type){
    case 0: {
      int64_t a, b; std::cin >> a >> b;
      query.push_back(std::make_pair(a, b));
      break;
    }
    case 1: {
      int64_t p; std::cin >> p;
      query.push_back(p);
      xs.push_back(p);
      break;
    }
    }
  }

  auto lc = make_lichao_min(xs);

  for(auto [a, b] : lines){
    lc.add_line(a, b);
  }
  
  for(auto &q : query){
    if(q.index() == 0){
      auto [a, b] = std::get<0>(q);
      lc.add_line(a, b);
    }else{
      auto p = std::get<1>(q);
      auto res = lc.query(p);

      std::cout << *res << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/line_add_get_min/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <tuple>
#line 4 "Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp"
#include <algorithm>
#include <optional>

/**
 * @title LiChao segment tree
 * @docs lichao_segment_tree.md
 */
template <typename T, typename Comparator>
class LiChaoSegmentTree{
  using line = std::pair<T,T>;

  const Comparator cmp = Comparator();
  std::vector<T> xs;
  int n;

  std::vector<std::optional<line>> data;
  std::vector<std::pair<int,int>> range;

  inline T chm(const T &a, const T &b) const {
    return cmp(a, b) ? a : b;
  }

  void init_range(int i, int left, int right){
    if(i >= 2*n) return;

    range[i] = std::make_pair(left, right);
    int mid = (left + right) / 2;
    init_range(i << 1 | 0, left, mid);
    init_range(i << 1 | 1, mid, right);
  }

public:
  LiChaoSegmentTree(std::vector<T> xs_): xs(xs_){
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    n = 1;
    while(n < (int)xs.size()) n *= 2;

    const auto m = xs.back();
    xs.resize(n, m);

    data.assign(2*n, std::nullopt);

    range.resize(2*n);
    init_range(1, 0, n);
  }

  inline T apply(const line &l, const T &x) const {
    return l.first * x + l.second;
  }

private:
  void update(int i, line new_line, int l, int r){
    if(not data[i]){
      data[i] = new_line;
      return;
    }

    int m = (l + r) / 2;

    auto lx = xs[l], mx = xs[m], rx = xs[r-1];

    bool left = cmp(apply(new_line, lx), apply(*data[i], lx));
    bool mid = cmp(apply(new_line, mx), apply(*data[i], mx));
    bool right = cmp(apply(new_line, rx), apply(*data[i], rx));

    if(left and right){
      data[i] = new_line;
      return;
    }

    if(not left and not right){
      return;
    }

    if(mid){
      std::swap(*data[i], new_line);
    }

    if(left != mid){
      update(i << 1 | 0, new_line, l, m);
    }else{
      update(i << 1 | 1, new_line, m, r);
    }
  }
  
public:
  inline void add_line(T a, T b){
    update(1, std::make_pair(a, b), 0, n);
  }

  // [l, r)
  inline void add_segment(T l, T r, T a, T b){
    int left = std::lower_bound(xs.begin(), xs.end(), l) - xs.begin();
    int right = std::lower_bound(xs.begin(), xs.end(), r) - xs.begin();

    int L = left + n;
    int R = right + n;

    while(L < R){
      if(R & 1){
        --R;
        update(R, std::make_pair(a, b), range[R].first, range[R].second);
      }

      if(L & 1){
        update(L, std::make_pair(a, b), range[L].first, range[L].second);
        ++L;
      }

      L >>= 1;
      R >>= 1;
    }
  }

public:
  inline auto query(const T &x) const {
    const int i = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    int k = i + n;
    
    std::optional<T> ret;

    while(k > 0){
      if(data[k]){
        if(not ret) ret = apply(*data[k], xs[i]);
        else ret = chm(*ret, apply(*data[k], xs[i]));
      }
      k >>= 1;
    }

    return ret;
  }
};

template <typename T>
auto make_lichao_min(const std::vector<T> &xs){
  return LiChaoSegmentTree<T, std::less<T>>(xs);
}

template <typename T>
auto make_lichao_max(const std::vector<T> &xs){
  return LiChaoSegmentTree<T, std::greater<T>>(xs);
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
#line 10 "test/yosupo-judge/line_add_get_min/main.test.cpp"

using Query = std::variant<std::pair<int64_t,int64_t>, int64_t>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> xs;

  std::vector<std::pair<int64_t, int64_t>> lines;

  for(auto [a, b] : input_tuples<int64_t, int64_t>(N)){
    lines.emplace_back(a, b);
  }

  std::vector<Query> query;

  for(auto [type] : input_tuples<int>(Q)){
    switch(type){
    case 0: {
      int64_t a, b; std::cin >> a >> b;
      query.push_back(std::make_pair(a, b));
      break;
    }
    case 1: {
      int64_t p; std::cin >> p;
      query.push_back(p);
      xs.push_back(p);
      break;
    }
    }
  }

  auto lc = make_lichao_min(xs);

  for(auto [a, b] : lines){
    lc.add_line(a, b);
  }
  
  for(auto &q : query){
    if(q.index() == 0){
      auto [a, b] = std::get<0>(q);
      lc.add_line(a, b);
    }else{
      auto p = std::get<1>(q);
      auto res = lc.query(p);

      std::cout << *res << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
