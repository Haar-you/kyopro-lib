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


# :x: test/aoj/2842/main.fenwick_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#64e19fd3e4193a1559ce21d32ec43623">test/aoj/2842</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2842/main.fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Group/sum.cpp.html">Sum group</a>
* :x: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp.html">Fenwick tree (2D)</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>
#include "Mylib/AlgebraicStructure/Group/sum.cpp"
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, T, Q; std::cin >> H >> W >> T >> Q;

  hl::fenwick_tree_2d<hl::sum_group<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int, int, int>> q;

  for(auto [t, c] : hl::input_tuples<int, int>(Q)){
    while(q.size()){
      auto &a = q.front();

      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);

        seg1.update({x, y}, 1);
        seg2.update({x, y}, -1);

        q.pop();
      }else{
        break;
      }
    }

    if(c == 0){
      int h, w; std::cin >> h >> w;
      --h, --w;

      seg2.update({h, w}, 1);
      q.emplace(h, w, t);
    }else if(c == 1){
      int h, w; std::cin >> h >> w;
      --h, --w;

      if(seg1[{h, w}] == 1) seg1.update({h, w}, -1);
    }else{
      int h1, w1, h2, w2; std::cin >> h1 >> w1 >> h2 >> w2;
      --h1, --w1;

      std::cout << seg1.get({h1, w1}, {h2, w2}) << " " << seg2.get({h1, w1}, {h2, w2}) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2842/main.fenwick_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>
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
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp"
#include <vector>

/**
 * @title Fenwick tree (2D)
 * @docs fenwick_tree_2d.md
 */
namespace haar_lib {
  template <typename AbelianGroup>
  class fenwick_tree_2d {
    using value_type = typename AbelianGroup::value_type;
    const static AbelianGroup G;

    int w, h;
    std::vector<std::vector<value_type>> data;

  private:
    value_type get_w(int i, int y) const {
      value_type ret = G();
      i += 1;
      while(i > 0){
        ret = G(ret, data[i][y]);
        i -= i & (-i);
      }
      return ret;
    }

    value_type get_w(int l, int r, int y) const {
      return G(get_w(r - 1, y), G.inv(get_w(l - 1, y)));
    }

    value_type get(int x1, int x2, int y) const {
      value_type ret = G();
      y += 1;
      while(y > 0){
        ret = G(ret, get_w(x1, x2, y));
        y -= y & (-y);
      }
      return ret;
    }

  public:
    fenwick_tree_2d(int width, int height){
      w = width;
      h = height;
      data = std::vector<std::vector<value_type>>(w + 1, std::vector<value_type>(h + 1));
    }

    value_type get(std::pair<int, int> p1, std::pair<int, int> p2) const { // [(x1, y1), (x2, y2))
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      return G(get(x1, x2, y2 - 1), G.inv(get(x1, x2, y1 - 1)));
    }

    value_type operator[](std::pair<int, int> p) const {
      const auto [x, y] = p;
      return get({x, y}, {x + 1, y + 1});
    }

    void update(std::pair<int, int> p, const value_type &val){
      auto [x, y] = p;
      x += 1;
      y += 1;

      for(int i = x; i <= w; i += i & (-i)){
        for(int j = y; j <= h; j += j & (-j)){
          data[i][j] = G(data[i][j], val);
        }
      }
    }
  };
}
#line 5 "Mylib/IO/input_tuples.cpp"
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
#line 9 "test/aoj/2842/main.fenwick_tree.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, T, Q; std::cin >> H >> W >> T >> Q;

  hl::fenwick_tree_2d<hl::sum_group<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int, int, int>> q;

  for(auto [t, c] : hl::input_tuples<int, int>(Q)){
    while(q.size()){
      auto &a = q.front();

      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);

        seg1.update({x, y}, 1);
        seg2.update({x, y}, -1);

        q.pop();
      }else{
        break;
      }
    }

    if(c == 0){
      int h, w; std::cin >> h >> w;
      --h, --w;

      seg2.update({h, w}, 1);
      q.emplace(h, w, t);
    }else if(c == 1){
      int h, w; std::cin >> h >> w;
      --h, --w;

      if(seg1[{h, w}] == 1) seg1.update({h, w}, -1);
    }else{
      int h1, w1, h2, w2; std::cin >> h1 >> w1 >> h2 >> w2;
      --h1, --w1;

      std::cout << seg1.get({h1, w1}, {h2, w2}) << " " << seg2.get({h1, w1}, {h2, w2}) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

