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


# :heavy_check_mark: test/aoj/1337/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a61f1640cc9f3ae71d742eade5b6fb71">test/aoj/1337</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1337/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337</a>


## Depends on

* :question: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/Utils/compressor.cpp.html">Compressor</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337"

#include <iostream>
#include <vector>
#include "Mylib/Utils/compressor.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

const int H = 200;
const int W = 200;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;

  while(std::cin >> n, n){
    auto [l, t, r, b] = hl::input_tuple_vector<int, int, int, int>(n);

    int64_t a[H][W] = {};

    hl::compressor<int>().add(l, r, -1).build().compress(l, r);
    hl::compressor<int>().add(t, b, -1).build().compress(t, b);

    for(int i = 0; i < n; ++i){
      for(int x = l[i]; x < r[i]; ++x){
        for(int y = b[i]; y < t[i]; ++y){
          a[x][y] |= (1LL << i);
        }
      }
    }

    hl::unionfind uf(H * W);
    int index[H][W];
    {
      int k = 0;
      for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
          index[i][j] = k;
          ++k;
        }
      }
    }

    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(i + 1 < H and a[i][j] == a[i + 1][j]) uf.merge(index[i][j], index[i + 1][j]);
        if(j + 1 < W and a[i][j] == a[i][j + 1]) uf.merge(index[i][j], index[i][j + 1]);
      }
    }

    int ans = uf.count_groups();

    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1337/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337"

#include <iostream>
#include <vector>
#line 3 "Mylib/Utils/compressor.cpp"
#include <algorithm>

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
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>
#line 5 "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Union-find
 * @docs unionfind.md
 */
namespace haar_lib {
  class unionfind {
    int n;
    mutable std::vector<int> parent;
    std::vector<int> depth, size;
    int count;

  public:
    unionfind(){}
    unionfind(int n): n(n), parent(n), depth(n, 1), size(n, 1), count(n){
      std::iota(parent.begin(), parent.end(), 0);
    }

    int root_of(int i) const {
      if(parent[i] == i) return i;
      else return parent[i] = root_of(parent[i]);
    }

    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}

    int merge(int i, int j){
      const int ri = root_of(i), rj = root_of(j);
      if(ri == rj) return ri;
      else{
        --count;
        if(depth[ri] < depth[rj]){
          parent[ri] = rj;
          size[rj] += size[ri];
          return rj;
        }else{
          parent[rj] = ri;
          size[ri] += size[rj];
          if(depth[ri] == depth[rj]) ++depth[ri];
          return ri;
        }
      }
    }

    int size_of(int i) const {return size[root_of(i)];}

    int count_groups() const {return count;}

    auto get_groups() const {
      std::vector<std::vector<int>> ret(n);

      for(int i = 0; i < n; ++i){
        ret[root_of(i)].push_back(i);
      }

      ret.erase(
        std::remove_if(
          ret.begin(), ret.end(),
          [](const auto &a){return a.empty();}
        ),
        ret.end()
      );

      return ret;
    }
  };
}
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#include <utility>
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
#line 8 "test/aoj/1337/main.test.cpp"

namespace hl = haar_lib;

const int H = 200;
const int W = 200;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;

  while(std::cin >> n, n){
    auto [l, t, r, b] = hl::input_tuple_vector<int, int, int, int>(n);

    int64_t a[H][W] = {};

    hl::compressor<int>().add(l, r, -1).build().compress(l, r);
    hl::compressor<int>().add(t, b, -1).build().compress(t, b);

    for(int i = 0; i < n; ++i){
      for(int x = l[i]; x < r[i]; ++x){
        for(int y = b[i]; y < t[i]; ++y){
          a[x][y] |= (1LL << i);
        }
      }
    }

    hl::unionfind uf(H * W);
    int index[H][W];
    {
      int k = 0;
      for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
          index[i][j] = k;
          ++k;
        }
      }
    }

    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(i + 1 < H and a[i][j] == a[i + 1][j]) uf.merge(index[i][j], index[i + 1][j]);
        if(j + 1 < W and a[i][j] == a[i][j + 1]) uf.merge(index[i][j], index[i][j + 1]);
      }
    }

    int ans = uf.count_groups();

    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

