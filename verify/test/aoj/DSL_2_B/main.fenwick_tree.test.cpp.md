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


# :x: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#082039b3153b4a2410d6e14e04aca1cc">test/aoj/DSL_2_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Group/sum.cpp.html">Sum group</a>
* :x: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree.cpp.html">Fenwick tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include "Mylib/AlgebraicStructure/Group/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  auto fen = hl::fenwick_tree<hl::sum_group<int>>(n);

  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      fen.update(x - 1, y);
    }else{
      std::cout << fen.get(x - 1, y) << std::endl;
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

/**
 * @title Fenwick tree
 * @docs fenwick_tree.md
 */
namespace haar_lib {
  template <typename AbelianGroup>
  class fenwick_tree {
    using value_type = typename AbelianGroup::value_type;
    const static AbelianGroup G;

    int size;
    std::vector<value_type> data;

  public:
    fenwick_tree(){}
    fenwick_tree(int size):
      size(size), data(size + 1, G())
    {}

    void update(int i, const value_type &val){
      i += 1; // 1-index

      while(i <= size){
        data[i] = G(data[i], val);
        i += i & (-i);
      }
    }

    value_type get(int i) const { // [0, i)
      value_type ret = G();
      i += 1; // 1-index

      while(i > 0){
        ret = G(ret, data[i]);
        i -= i & (-i);
      }

      return ret;
    }

    value_type get(int l, int r) const { // [l, r)
      return G(get(r - 1), G.inv(get(l - 1)));
    }

    value_type operator[](int x) const {
      return get(x, x + 1);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Group/sum.cpp"

/**
 * @title Sum group
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_group {
    using value_type = T;

    value_type operator()() const {return 0;}
    value_type operator()(const value_type &a, const value_type &b) const {return a + b;}
    value_type inv(const value_type &a) const {return -a;}
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
#line 7 "test/aoj/DSL_2_B/main.fenwick_tree.test.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  auto fen = hl::fenwick_tree<hl::sum_group<int>>(n);

  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      fen.update(x - 1, y);
    }else{
      std::cout << fen.get(x - 1, y) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

