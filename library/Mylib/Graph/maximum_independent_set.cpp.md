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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Maximum independent set

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/maximum_independent_set.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `maximum_independent_set(g[n][n])`
	- 最大独立集合の一つを64bit整数で表記して返す。
	- Time complexity $O(2^{n/2} n)$

## Requirements

## Notes
- 二部グラフでは、(最大独立集合の大きさ) = (グラフの頂点数) - (最大二部マッチングの大きさ)となるので、最大二部マッチングを用いる方が良い。
	- [https://qiita.com/drken/items/7f98315b56c95a6181a4](https://qiita.com/drken/items/7f98315b56c95a6181a4)

## Problems

- [CODE THANKS FESTIVAL 2017 G - Mixture Drug](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g)
- [Codeforces Round #533 (Div. 2) E. Helping Hiasat](https://codeforces.com/contest/1105/problem/E)
- [Maximum Independent Set](https://judge.yosupo.jp/problem/maximum_independent_set)


## References



## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/maximum_independent_set/main.test.cpp.html">test/yosupo-judge/maximum_independent_set/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cassert>

/**
 * @title Maximum independent set
 * @docs maximum_independent_set.md
 */
int64_t maximum_independent_set(const std::vector<std::vector<int>> &g){
  const int n = g.size();

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      assert((int)g[i].size() == n);
      assert(g[i][j] == g[j][i]);
    }
  }
  
  const int h1 = n/2; // V1
  const int h2 = n-h1; // V2

  std::vector<bool> dp1(1<<h1, true); // dp1[S] := Sが独立集合か?
  for(int i = 0; i < h1; ++i){
    for(int j = 0; j < h1; ++j){
      if(g[i][j]) dp1[(1<<i) | (1<<j)] = false;
    }
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    if(not dp1[s]){
      for(int j = 0; j < h1; ++j){
        dp1[s | (1<<j)] = false;
      }
    }
  }

  std::vector<bool> dp2(1<<h2, true); // dp2[S] := Sが独立集合か?
  for(int i = h1; i < n; ++i){
    for(int j = h1; j < n; ++j){
      if(g[i][j]) dp2[(1<<(i-h1)) | (1<<(j-h1))] = false;
    }
  }

  for(int s = 0; s < (1<<h2); ++s){
    if(!dp2[s]){
      for(int j = 0; j < h2; ++j){
        dp2[s | (1<<j)] = false;
      }
    }
  }
  
  std::vector<int> dp3(1<<h1, 0); // S1と接続しないV2の最大の部分集合
  dp3[0] = (1<<h2)-1;
  for(int i = 0; i < h1; ++i){
    int t = 0;
    for(int j = h1; j < n; ++j){
      if(g[i][j]){
        t |= (1<<(j-h1));
      }
    }
    dp3[1<<i] = t ^ ((1<<h2)-1);
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    for(int j = 0; j < h1; ++j){
      if((s & (1<<j)) == 0){
        dp3[s | (1<<j)] = dp3[s] & dp3[1<<j];
      }
    }
  }

  std::vector<int> dp4(1<<h2, 0); // S2の最大独立集合
  for(int i = 0; i < (1<<h2); ++i){
    if(dp2[i]){
      dp4[i] = i;
    }
  }
  
  for(int s = 0; s < (1<<h2); ++s){
    for(int j = 0; j < h2; ++j){
      if((s & (1<<j)) == 0){
        if(__builtin_popcount(dp4[s | (1<<j)]) > __builtin_popcount(dp4[s])){
          dp4[s | (1<<j)] = dp4[s | (1<<j)];
        }else{
          dp4[s | (1<<j)] = dp4[s];
        }
      }
    }
  }
  
  int64_t ans = 0;
  int size = 0;
  
  for(int s = 0; s < (1<<h1); ++s){
    if(dp1[s]){
      int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]]) << h1);

      if(__builtin_popcountll(t) > size){
        size = __builtin_popcountll(t);
        ans = t;
      }
    }
  }
  
  return ans;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/maximum_independent_set.cpp"
#include <vector>
#include <cassert>

/**
 * @title Maximum independent set
 * @docs maximum_independent_set.md
 */
int64_t maximum_independent_set(const std::vector<std::vector<int>> &g){
  const int n = g.size();

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      assert((int)g[i].size() == n);
      assert(g[i][j] == g[j][i]);
    }
  }
  
  const int h1 = n/2; // V1
  const int h2 = n-h1; // V2

  std::vector<bool> dp1(1<<h1, true); // dp1[S] := Sが独立集合か?
  for(int i = 0; i < h1; ++i){
    for(int j = 0; j < h1; ++j){
      if(g[i][j]) dp1[(1<<i) | (1<<j)] = false;
    }
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    if(not dp1[s]){
      for(int j = 0; j < h1; ++j){
        dp1[s | (1<<j)] = false;
      }
    }
  }

  std::vector<bool> dp2(1<<h2, true); // dp2[S] := Sが独立集合か?
  for(int i = h1; i < n; ++i){
    for(int j = h1; j < n; ++j){
      if(g[i][j]) dp2[(1<<(i-h1)) | (1<<(j-h1))] = false;
    }
  }

  for(int s = 0; s < (1<<h2); ++s){
    if(!dp2[s]){
      for(int j = 0; j < h2; ++j){
        dp2[s | (1<<j)] = false;
      }
    }
  }
  
  std::vector<int> dp3(1<<h1, 0); // S1と接続しないV2の最大の部分集合
  dp3[0] = (1<<h2)-1;
  for(int i = 0; i < h1; ++i){
    int t = 0;
    for(int j = h1; j < n; ++j){
      if(g[i][j]){
        t |= (1<<(j-h1));
      }
    }
    dp3[1<<i] = t ^ ((1<<h2)-1);
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    for(int j = 0; j < h1; ++j){
      if((s & (1<<j)) == 0){
        dp3[s | (1<<j)] = dp3[s] & dp3[1<<j];
      }
    }
  }

  std::vector<int> dp4(1<<h2, 0); // S2の最大独立集合
  for(int i = 0; i < (1<<h2); ++i){
    if(dp2[i]){
      dp4[i] = i;
    }
  }
  
  for(int s = 0; s < (1<<h2); ++s){
    for(int j = 0; j < h2; ++j){
      if((s & (1<<j)) == 0){
        if(__builtin_popcount(dp4[s | (1<<j)]) > __builtin_popcount(dp4[s])){
          dp4[s | (1<<j)] = dp4[s | (1<<j)];
        }else{
          dp4[s | (1<<j)] = dp4[s];
        }
      }
    }
  }
  
  int64_t ans = 0;
  int size = 0;
  
  for(int s = 0; s < (1<<h1); ++s){
    if(dp1[s]){
      int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]]) << h1);

      if(__builtin_popcountll(t) > size){
        size = __builtin_popcountll(t);
        ans = t;
      }
    }
  }
  
  return ans;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

