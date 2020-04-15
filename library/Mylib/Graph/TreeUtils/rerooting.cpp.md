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


# :warning: 全方位木dp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-16 00:46:40+09:00


* see: <a href="https://null-mn.hatenablog.com/entry/2020/04/14/124151">https://null-mn.hatenablog.com/entry/2020/04/14/124151</a>
* see: <a href="https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e#step0-%E6%9C%A8%E6%A7%8B%E9%80%A0%E3%81%AE%E6%83%85%E5%A0%B1%E3%82%92%E8%A8%98%E9%8C%B2%E3%81%99%E3%82%8B">https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e#step0-%E6%9C%A8%E6%A7%8B%E9%80%A0%E3%81%AE%E6%83%85%E5%A0%B1%E3%82%92%E8%A8%98%E9%8C%B2%E3%81%99%E3%82%8B</a>
* see: <a href="https://kuretchi.github.io/blog/entries/rerooting/">https://kuretchi.github.io/blog/entries/rerooting/</a>
* see: <a href="https://atcoder.jp/contests/dp/submissions/11952346">https://atcoder.jp/contests/dp/submissions/11952346</a>
* see: <a href="https://codeforces.com/contest/1324/submission/76798350">https://codeforces.com/contest/1324/submission/76798350</a>
* see: <a href="https://atcoder.jp/contests/abc160/submissions/11960089">https://atcoder.jp/contests/abc160/submissions/11960089</a>
* see: <a href="https://atcoder.jp/contests/arc028/submissions/11961543">https://atcoder.jp/contests/arc028/submissions/11961543</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 全方位木dp
 * @see https://null-mn.hatenablog.com/entry/2020/04/14/124151
 * @see https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e#step0-%E6%9C%A8%E6%A7%8B%E9%80%A0%E3%81%AE%E6%83%85%E5%A0%B1%E3%82%92%E8%A8%98%E9%8C%B2%E3%81%99%E3%82%8B
 * @see https://kuretchi.github.io/blog/entries/rerooting/

 * @see https://atcoder.jp/contests/dp/submissions/11952346
 * @see https://codeforces.com/contest/1324/submission/76798350
 * @see https://atcoder.jp/contests/abc160/submissions/11960089
 * @see https://atcoder.jp/contests/arc028/submissions/11961543

 * @note https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d (これで解けるか不明)
 */

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
struct Rerooting{
  int N;
  Tree<T> tree;
  U id;
  Merge merge;
  EdgeF f;
  VertexF g;
  
  std::vector<std::vector<U>> dp;
  std::vector<U> result;
  
  Rerooting(Tree<T> tree, U id, Merge merge, EdgeF f, VertexF g):
    N(tree.size()), tree(tree), id(id), merge(merge), f(f), g(g), dp(N), result(N, id)
  {
    rooting(0);
    rec1(0);
    rec2(0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tree[i].size(); ++j){
        result[i] = merge(result[i], f(dp[i][j], tree[i][j]));
      }
      
      result[i] = g(result[i], i);
    }
  }

  void rooting(int cur, int par = -1){
    dp[cur].assign((int)tree[cur].size(), id);
    
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      rooting(e.to, cur);
    }
  }

  U rec1(int cur, int par = -1){
    U acc = id;
    
    for(int i = 0; i < (int)tree[cur].size(); ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;
      dp[cur][i] = rec1(e.to, cur);
      acc = merge(acc, f(dp[cur][i], e));
    }

    return g(acc, cur);
  }

  void rec2(int cur, int par, U value){
    const int l = tree[cur].size();

    for(int i = 0; i < (int)tree[cur].size(); ++i){
      if(tree[cur][i].to == par){
        dp[cur][i] = value;
      }
    }

    std::vector<U> left(l+1, id), right(l+1, id);

    for(int i = 0; i < l-1; ++i){
      auto &e = tree[cur][i];
      left[i+1] = merge(left[i], f(dp[cur][i], e));
    }

    for(int i = l-1; i >= 1; --i){
      auto &e = tree[cur][i];
      right[i-1] = merge(right[i], f(dp[cur][i], e));
    }

    for(int i = 0; i < l; ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;

      rec2(e.to, cur, g(merge(left[i], right[i]), cur));
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/rerooting.cpp"
#include <vector>

/**
 * @title 全方位木dp
 * @see https://null-mn.hatenablog.com/entry/2020/04/14/124151
 * @see https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e#step0-%E6%9C%A8%E6%A7%8B%E9%80%A0%E3%81%AE%E6%83%85%E5%A0%B1%E3%82%92%E8%A8%98%E9%8C%B2%E3%81%99%E3%82%8B
 * @see https://kuretchi.github.io/blog/entries/rerooting/

 * @see https://atcoder.jp/contests/dp/submissions/11952346
 * @see https://codeforces.com/contest/1324/submission/76798350
 * @see https://atcoder.jp/contests/abc160/submissions/11960089
 * @see https://atcoder.jp/contests/arc028/submissions/11961543

 * @note https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d (これで解けるか不明)
 */

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
struct Rerooting{
  int N;
  Tree<T> tree;
  U id;
  Merge merge;
  EdgeF f;
  VertexF g;
  
  std::vector<std::vector<U>> dp;
  std::vector<U> result;
  
  Rerooting(Tree<T> tree, U id, Merge merge, EdgeF f, VertexF g):
    N(tree.size()), tree(tree), id(id), merge(merge), f(f), g(g), dp(N), result(N, id)
  {
    rooting(0);
    rec1(0);
    rec2(0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tree[i].size(); ++j){
        result[i] = merge(result[i], f(dp[i][j], tree[i][j]));
      }
      
      result[i] = g(result[i], i);
    }
  }

  void rooting(int cur, int par = -1){
    dp[cur].assign((int)tree[cur].size(), id);
    
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      rooting(e.to, cur);
    }
  }

  U rec1(int cur, int par = -1){
    U acc = id;
    
    for(int i = 0; i < (int)tree[cur].size(); ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;
      dp[cur][i] = rec1(e.to, cur);
      acc = merge(acc, f(dp[cur][i], e));
    }

    return g(acc, cur);
  }

  void rec2(int cur, int par, U value){
    const int l = tree[cur].size();

    for(int i = 0; i < (int)tree[cur].size(); ++i){
      if(tree[cur][i].to == par){
        dp[cur][i] = value;
      }
    }

    std::vector<U> left(l+1, id), right(l+1, id);

    for(int i = 0; i < l-1; ++i){
      auto &e = tree[cur][i];
      left[i+1] = merge(left[i], f(dp[cur][i], e));
    }

    for(int i = l-1; i >= 1; --i){
      auto &e = tree[cur][i];
      right[i-1] = merge(right[i], f(dp[cur][i], e));
    }

    for(int i = 0; i < l; ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;

      rec2(e.to, cur, g(merge(left[i], right[i]), cur));
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

