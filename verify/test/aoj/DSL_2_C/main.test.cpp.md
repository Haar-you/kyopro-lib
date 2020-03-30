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


# :heavy_check_mark: test/aoj/DSL_2_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2bc6b10df76ee628f0328e9237d1fcac">test/aoj/DSL_2_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 06:18:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/RangeTree/range_tree.cpp.html">Mylib/DataStructure/RangeTree/range_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "Mylib/DataStructure/RangeTree/range_tree.cpp"

int main(){
  int n; std::cin >> n;
  RangeTree rt;

  std::map<std::pair<int,int>, int> m;

  for(int i = 0; i < n; ++i){
    int x, y; std::cin >> x >> y;
    rt.add(x,y);
    m[{x,y}] = i;
  }
  rt.build();

  int q; std::cin >> q;

  for(int i = 0; i < q; ++i){
    int sx, tx, sy, ty; std::cin >> sx >> tx >> sy >> ty;

    auto res = rt.get(sx, sy, tx+1, ty+1);

    std::vector<int> ans;
    for(auto &p : res) ans.push_back(m[p]);

    std::sort(ans.begin(), ans.end());
    for(auto &x : ans){
      std::cout << x << "\n";
    }
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#line 4 "Mylib/DataStructure/RangeTree/range_tree.cpp"
#include <algorithm>
#include <iterator>

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

  /**
   * @attention time complexity O(N log N)
   */
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
   * @attention time complexity O(log^2 N + K)
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
#line 8 "test/aoj/DSL_2_C/main.test.cpp"

int main(){
  int n; std::cin >> n;
  RangeTree rt;

  std::map<std::pair<int,int>, int> m;

  for(int i = 0; i < n; ++i){
    int x, y; std::cin >> x >> y;
    rt.add(x,y);
    m[{x,y}] = i;
  }
  rt.build();

  int q; std::cin >> q;

  for(int i = 0; i < q; ++i){
    int sx, tx, sy, ty; std::cin >> sx >> tx >> sy >> ty;

    auto res = rt.get(sx, sy, tx+1, ty+1);

    std::vector<int> ans;
    for(auto &p : res) ans.push_back(m[p]);

    std::sort(ans.begin(), ans.end());
    for(auto &x : ans){
      std::cout << x << "\n";
    }
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

