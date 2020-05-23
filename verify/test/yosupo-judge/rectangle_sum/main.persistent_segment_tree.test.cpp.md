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
    - Last commit date: 2020-05-22 16:55:31+09:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp.html">永続SegmentTree</a>
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

using Seg = PersistentSegmentTree<SumMonoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> x(N), y(N), w(N);
  for(int i = 0; i < N; ++i){
    std::cin >> x[i] >> y[i] >> w[i];
  }

  sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    N,
    x,
    y,
    w
  );

  std::vector<int64_t> c(x);
  std::sort(c.begin(), c.end());
  c.erase(std::unique(c.begin(), c.end()), c.end());
  for(int i = 0; i < N; ++i) x[i] = std::lower_bound(c.begin(), c.end(), x[i]) - c.begin();
  const int m = c.size();
  
  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s.at(x[i]) + w[i]));
  }
  
  for(int i = 0; i < Q; ++i){
    int64_t l, r, u, d; std::cin >> l >> d >> r >> u;
    
    l = std::lower_bound(c.begin(), c.end(), l) - c.begin();
    r = std::lower_bound(c.begin(), c.end(), r) - c.begin();

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
 * @title 永続SegmentTree
 * @docs persistent_segment_tree.md
 */
template <typename Monoid>
class PersistentSegmentTree{
  using value_type = typename Monoid::value_type;
  
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
      t = new node(pos < (int)init_list.size() ? init_list[pos] : Monoid::id());
      ++pos;
    }else{
      t = new node(Monoid::id());
      t->left = init(t->left, init_list, d+1, pos);
      t->right = init(t->right, init_list, d+1, pos);
      t->value = Monoid::op(t->left->value, t->right->value);
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
  
  PersistentSegmentTree(int size, const value_type &value = Monoid::id()){
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

      node *s = new node(Monoid::op(lp->value, rp->value));

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
    if(r <= i or j <= l) return Monoid::id();
    const int m = (l + r) >> 1;
    return Monoid::op(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
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
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 9 "test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp"

using Seg = PersistentSegmentTree<SumMonoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> x(N), y(N), w(N);
  for(int i = 0; i < N; ++i){
    std::cin >> x[i] >> y[i] >> w[i];
  }

  sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    N,
    x,
    y,
    w
  );

  std::vector<int64_t> c(x);
  std::sort(c.begin(), c.end());
  c.erase(std::unique(c.begin(), c.end()), c.end());
  for(int i = 0; i < N; ++i) x[i] = std::lower_bound(c.begin(), c.end(), x[i]) - c.begin();
  const int m = c.size();
  
  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s.at(x[i]) + w[i]));
  }
  
  for(int i = 0; i < Q; ++i){
    int64_t l, r, u, d; std::cin >> l >> d >> r >> u;
    
    l = std::lower_bound(c.begin(), c.end(), l) - c.begin();
    r = std::lower_bound(c.begin(), c.end(), r) - c.begin();

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

