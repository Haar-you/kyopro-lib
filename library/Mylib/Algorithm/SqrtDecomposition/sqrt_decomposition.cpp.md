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


# :warning: 平方分割

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c78b3868045887a7ae97845e4050078a">Mylib/Algorithm/SqrtDecomposition</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>

/**
 * @title 平方分割
 */
struct SqrtDecomposition{
  const int N;
  const int BLOCK_SIZE;
  const int BLOCK_NUM;

  SqrtDecomposition(int N):
    N(N), BLOCK_SIZE((int)sqrt(N)), BLOCK_NUM((N + BLOCK_SIZE - 1) / BLOCK_SIZE)
  {
  }

  template <typename Func>
  void init(const Func &f){
    for(int i = 0; i < BLOCK_NUM; ++i){
      const int L = i * BLOCK_SIZE;
      const int R = std::min<int>(N, (i+1) * BLOCK_SIZE);
      f(i, L, R);
    }
  }

  template <typename FuncBlock, typename FuncRange>
  void query(int l, int r, const FuncBlock &func_block, const FuncRange &func_range){ // [l, r)
    for(int i = 0; i < BLOCK_NUM; ++i){
      const int L = i * BLOCK_SIZE;
      const int R = std::min<int>(N, (i+1) * BLOCK_SIZE);

      if(l <= L and R <= r){
        func_block(i, L, R);
      }else if((L <= l and l < R) or (L < r and r <= R)){
        func_range(i, L, R, std::max(l, L), std::min(r, R));
      }
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp"
#include <algorithm>

/**
 * @title 平方分割
 */
struct SqrtDecomposition{
  const int N;
  const int BLOCK_SIZE;
  const int BLOCK_NUM;

  SqrtDecomposition(int N):
    N(N), BLOCK_SIZE((int)sqrt(N)), BLOCK_NUM((N + BLOCK_SIZE - 1) / BLOCK_SIZE)
  {
  }

  template <typename Func>
  void init(const Func &f){
    for(int i = 0; i < BLOCK_NUM; ++i){
      const int L = i * BLOCK_SIZE;
      const int R = std::min<int>(N, (i+1) * BLOCK_SIZE);
      f(i, L, R);
    }
  }

  template <typename FuncBlock, typename FuncRange>
  void query(int l, int r, const FuncBlock &func_block, const FuncRange &func_range){ // [l, r)
    for(int i = 0; i < BLOCK_NUM; ++i){
      const int L = i * BLOCK_SIZE;
      const int R = std::min<int>(N, (i+1) * BLOCK_SIZE);

      if(l <= L and R <= r){
        func_block(i, L, R);
      }else if((L <= l and l < R) or (L < r and r <= R)){
        func_range(i, L, R, std::max(l, L), std::min(r, R));
      }
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

