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


# :heavy_check_mark: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#082039b3153b4a2410d6e14e04aca1cc">test/aoj/DSL_2_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 08:05:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Group/sum_group.cpp.html">Mylib/AlgebraicStructure/Group/sum_group.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree.cpp.html">Mylib/DataStructure/FenwickTree/fenwick_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include "Mylib/AlgebraicStructure/Group/sum_group.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto fen = FenwickTree<SumGroup<int>>(n);

  for(int i = 0; i < q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x,y; std::cin >> x >> y;
      fen.update(x-1, y);
    }else{
      int x,y; std::cin >> x >> y;
      std::cout << fen.get(x-1, y) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_B/main.fenwick_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include <vector>

template <typename AbelianGroup>
class FenwickTree{
  using value_type = typename AbelianGroup::value_type;
  
  int size;
  std::vector<value_type> data;
  
public:
  FenwickTree(){}
  FenwickTree(int size):
    size(size), data(size + 1, AbelianGroup::id())
  {}
  
  inline void update(int i, const value_type &val){
    i += 1; // 1-index
    
    while(i <= size){
      data[i] = AbelianGroup::op(data[i], val);
      i += i & (-i);
    }
  }
  
  inline value_type get(int i) const { // [0, i)
    value_type ret = AbelianGroup::id();
    i += 1; // 1-index

    while(i > 0){
      ret = AbelianGroup::op(ret, data[i]);
      i -= i & (-i);
    }

    return ret;
  }

  inline value_type get(int l, int r) const { // [l, r)
    return AbelianGroup::inv(get(r-1), get(l-1));
  }
  
  inline value_type at(int x) const {
    return get(x, x+1);
  }
};
#line 2 "Mylib/AlgebraicStructure/Group/sum_group.cpp"

template <typename T>
struct SumGroup{
  using value_type = T;

  static value_type id(){return 0;}
  static value_type op(const value_type &a, const value_type &b){return a + b;}
  static value_type inv(const value_type &a, const value_type &b){return a - b;}
};
#line 6 "test/aoj/DSL_2_B/main.fenwick_tree.test.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto fen = FenwickTree<SumGroup<int>>(n);

  for(int i = 0; i < q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x,y; std::cin >> x >> y;
      fen.update(x-1, y);
    }else{
      int x,y; std::cin >> x >> y;
      std::cout << fen.get(x-1, y) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

