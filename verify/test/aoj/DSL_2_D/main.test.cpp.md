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


# :heavy_check_mark: test/aoj/DSL_2_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1cab81d9204e4e9816afce7019c71879">test/aoj/DSL_2_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/update_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/update_monoid.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Dual/dual_segment_tree.cpp.html">双対セグメント木</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/Static/Dual/dual_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/update_monoid.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = DualSegmentTree<UpdateMonoid<int>>(n);
  seg.init(INT_MAX);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int s,t,x; std::cin >> s >> t >> x;
      seg.update(s, t+1, x);
    }else{
      int i; std::cin >> i;
      std::cout << *seg.get(i) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <iostream>
#include <climits>
#line 2 "Mylib/DataStructure/SegmentTree/Static/Dual/dual_segment_tree.cpp"
#include <vector>

/**
 * @title 双対セグメント木
 */
template <typename Monoid>
class DualSegmentTree{
  using value_type = typename Monoid::value_type;
  
private:
  const int depth, size, hsize;
  std::vector<value_type> data;
  
  inline void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = Monoid::op(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = Monoid::op(data[i], data[i << 1 | 1]);
      data[i] = Monoid::id();
    }
  }

  inline void propagate_top_down(int i){
    std::vector<int> temp;
    while(i > 1){
      i >>= 1;
      temp.push_back(i);
    }

    for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
  }
  
public:
  DualSegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, Monoid::id())
  {}

  inline void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;
    
    while(L < R){
      if(R & 1) --R, data[R] = Monoid::op(x, data[R]);
      if(L & 1) data[L] = Monoid::op(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  inline value_type get(int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &a){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};
#line 2 "Mylib/AlgebraicStructure/Monoid/update_monoid.cpp"
#include <optional>

template <typename T>
struct UpdateMonoid{
  using value_type = std::optional<T>;
  constexpr inline static value_type id(){return std::nullopt;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return (a ? a : b);}
};
#line 7 "test/aoj/DSL_2_D/main.test.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = DualSegmentTree<UpdateMonoid<int>>(n);
  seg.init(INT_MAX);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int s,t,x; std::cin >> s >> t >> x;
      seg.update(s, t+1, x);
    }else{
      int i; std::cin >> i;
      std::cout << *seg.get(i) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
