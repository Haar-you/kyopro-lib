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


# :heavy_check_mark: test/yukicoder/631/main.starry_sky.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0b2f27755ad8078580256305f9366a63">test/yukicoder/631</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/631/main.starry_sky.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 21:52:04+09:00


* see: <a href="https://yukicoder.me/problems/no/631">https://yukicoder.me/problems/no/631</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/StarrySkyTree/starry_sky_tree_max.cpp.html">StarrySkyTree (Max)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>

#include "Mylib/DataStructure/SegmentTree/Static/StarrySkyTree/starry_sky_tree_max.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N;
  while(std::cin >> N){
    auto seg = StarrySkyTreeMax<int64_t>(N-1);
        
    std::vector<int64_t> T(N-1);
    for(auto &x : T) std::cin >> x;
    
    for(int i = 0; i < N-1; ++i){
      T[i] += 3 * (N-1-i);
    }

    seg.init_with_vector(T);
    
    int M; std::cin >> M;

    for(int i = 0; i < M; ++i){
      int L, R, D; std::cin >> L >> R >> D;
      --L, --R;

      seg.update(L, R+1, D);
      
      auto ans = seg.get(0, N-1);
      std::cout << ans << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/631/main.starry_sky.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>

#line 3 "Mylib/DataStructure/SegmentTree/Static/StarrySkyTree/starry_sky_tree_max.cpp"
#include <algorithm>
#include <limits>

/**
 * @title StarrySkyTree (Max)
 * @docs starry_sky_tree_max.md
 */
template <typename T>
class StarrySkyTreeMax{
  int depth, size, hsize;
  std::vector<T> data;

  const T id = std::numeric_limits<T>::lowest();

  void bottom_up(int i){
    if(i > size) return;

    while(i >= 1){
      if(i < hsize){
        const auto d = std::max(data[i << 1 | 0], data[i << 1 | 1]);
        
        data[i << 1 | 0] -= d;
        data[i << 1 | 1] -= d;
        data[i] += d;
      }

      i >>= 1;
    }
  }
  
  T get(int i, int l, int r, int s, int t, T val) const {
    if(r <= s or t <= l) return id;
    if(s <= l and r <= t) return val + data[i];
    return std::max(get(i << 1 | 0, l, (l + r) / 2, s, t, val + data[i]),
                    get(i << 1 | 1, (l + r) / 2, r, s, t, val + data[i]));
  }

public:
  StarrySkyTreeMax(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),    
    data(size, 0)
  {}

  void update(int l, int r, T val){
    int L = l + hsize;
    int R = r + hsize;

    while(L < R){
      if(R & 1) --R, data[R] += val;
      if(L & 1) data[L] += val, ++L;
      L >>= 1;
      R >>= 1;
    }

    bottom_up(l + hsize);
    bottom_up(r + hsize);
  }

  T get(int l, int r) const {
    return get(1, 0, hsize, l, r, 0);
  }

  template <typename U>
  void init_with_vector(std::vector<U> &a){
    for(int i = 0; i < (int)a.size(); ++i){
      data[hsize + i] = a[i];
    }

    for(int i = hsize - 1; i >= 1; --i){
      data[i] = std::max(data[i << 1 | 0], data[i << 1 | 1]);
    }

    for(int i = size - 1; i > 1; --i){
      data[i] -= data[i >> 1];
    }
  }
};
#line 7 "test/yukicoder/631/main.starry_sky.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N;
  while(std::cin >> N){
    auto seg = StarrySkyTreeMax<int64_t>(N-1);
        
    std::vector<int64_t> T(N-1);
    for(auto &x : T) std::cin >> x;
    
    for(int i = 0; i < N-1; ++i){
      T[i] += 3 * (N-1-i);
    }

    seg.init_with_vector(T);
    
    int M; std::cin >> M;

    for(int i = 0; i < M; ++i){
      int L, R, D; std::cin >> L >> R >> D;
      --L, --R;

      seg.update(L, R+1, D);
      
      auto ans = seg.get(0, N-1);
      std::cout << ans << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

