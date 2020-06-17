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


# :heavy_check_mark: Mylib/DataStructure/RangeTree/range_tree.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#51d0b2ed49c1a9da73d4d3864cf91f26">Mylib/DataStructure/RangeTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/RangeTree/range_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 20:58:13+09:00




## Operations

- `add(int x, int y)`
	- 点`(x, y)`を追加する。
- `build()`
	- `RangeTree`を構築する。
	- Time complexity $O(N \log N)$
- `get(int sx, int sy, int tx, int ty)`
	- `[sx, tx), [sy, ty)`内の点を列挙する。
	- Time complexity $O(\log^2 N + K)$

## Requirements

- `build`は唯一回だけ呼び出される。
- 必ず`add`, `build`, `get`の順で実行する。

## Problems

- [AOJ DSL_2_C Range Search (kD Tree)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_2_C/main.test.cpp.html">test/aoj/DSL_2_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

/**
 * @docs range_tree.md
 */
class RangeTree{
  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int64_t> c_xs;

  int size;
  std::vector<std::vector<std::pair<int64_t, int>>> data;
  
public:
  RangeTree(){}

  void add(int64_t x, int64_t y){
    ++N;
    xs.push_back(x);
    ys.push_back(y);
  }

  void build(){
    c_xs = xs;
    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    int M = c_xs.size();
    size = 1 << (M > 1 ? 32 - __builtin_clz(M - 1) + 1 : 1);

    data.resize(size);

    for(int i = 0; i < N; ++i){
      int j = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();
      data[size / 2 + j].emplace_back(ys[i], j);
    }

    for(int i = size / 2; i < size; ++i){
      std::sort(data[i].begin(), data[i].end());
    }

    for(int i = size / 2 - 1; i > 0; --i){
      auto &a = data[i << 1 | 0];
      auto &b = data[i << 1 | 1];

      std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(data[i]));
    }
  }

  /**
   * @attention [sx, tx), [sy, ty)
   */
  std::vector<std::pair<int64_t, int64_t>> get(int64_t sx, int64_t sy, int64_t tx, int64_t ty) const {
    std::vector<std::pair<int64_t, int64_t>> ret;
    
    int L = std::lower_bound(c_xs.begin(), c_xs.end(), sx) - c_xs.begin();
    int R = std::lower_bound(c_xs.begin(), c_xs.end(), tx) - c_xs.begin();
    
    L += size / 2;
    R += size / 2;

    while(L < R){
      if(R & 1){
        auto &a = data[--R];

        auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

        while(it != a.end()){
          if(it->first >= ty) break;
          
          ret.emplace_back(c_xs[it->second], it->first);

          ++it;
        }
      }

      if(L & 1){
        auto &a = data[L++];

        auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

        while(it != a.end()){
          if(it->first >= ty) break;
          
          ret.emplace_back(c_xs[it->second], it->first);

          ++it;
        }
      }

      L >>= 1;
      R >>= 1;
    }

    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/RangeTree/range_tree.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

/**
 * @docs range_tree.md
 */
class RangeTree{
  int N = 0;
  std::vector<int64_t> xs, ys;
  std::vector<int64_t> c_xs;

  int size;
  std::vector<std::vector<std::pair<int64_t, int>>> data;
  
public:
  RangeTree(){}

  void add(int64_t x, int64_t y){
    ++N;
    xs.push_back(x);
    ys.push_back(y);
  }

  void build(){
    c_xs = xs;
    std::sort(c_xs.begin(), c_xs.end());
    c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

    int M = c_xs.size();
    size = 1 << (M > 1 ? 32 - __builtin_clz(M - 1) + 1 : 1);

    data.resize(size);

    for(int i = 0; i < N; ++i){
      int j = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();
      data[size / 2 + j].emplace_back(ys[i], j);
    }

    for(int i = size / 2; i < size; ++i){
      std::sort(data[i].begin(), data[i].end());
    }

    for(int i = size / 2 - 1; i > 0; --i){
      auto &a = data[i << 1 | 0];
      auto &b = data[i << 1 | 1];

      std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(data[i]));
    }
  }

  /**
   * @attention [sx, tx), [sy, ty)
   */
  std::vector<std::pair<int64_t, int64_t>> get(int64_t sx, int64_t sy, int64_t tx, int64_t ty) const {
    std::vector<std::pair<int64_t, int64_t>> ret;
    
    int L = std::lower_bound(c_xs.begin(), c_xs.end(), sx) - c_xs.begin();
    int R = std::lower_bound(c_xs.begin(), c_xs.end(), tx) - c_xs.begin();
    
    L += size / 2;
    R += size / 2;

    while(L < R){
      if(R & 1){
        auto &a = data[--R];

        auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

        while(it != a.end()){
          if(it->first >= ty) break;
          
          ret.emplace_back(c_xs[it->second], it->first);

          ++it;
        }
      }

      if(L & 1){
        auto &a = data[L++];

        auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

        while(it != a.end()){
          if(it->first >= ty) break;
          
          ret.emplace_back(c_xs[it->second], it->first);

          ++it;
        }
      }

      L >>= 1;
      R >>= 1;
    }

    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

