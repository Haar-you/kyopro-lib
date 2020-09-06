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


# :warning: Mylib/Debug/grid_viewer.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0f67555b3039d368e55db69bb4454f7e">Mylib/Debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Debug/grid_viewer.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>

/**
 * @docs grid_viewer.md
 */
template <typename C>
void grid_viewer([[maybe_unused]] const C &A, [[maybe_unused]] int width = 10){
#ifdef DEBUG
  const int H = A.size();
  const int W = A[0].size();

  std::cerr << "    ";
  for(int j = 0; j < W; ++j){
    std::cerr << "\e[1;32m" << std::left << std::setw(width) << j << "\e[m";
  }
  std::cerr << "\n";
  std::cerr << std::right;

  for(int i = 0; i < H; ++i){
    std::cerr << "\e[1;32m" << std::setw(2) << i << "|\e[m ";

    for(int j = 0; j < W; ++j){
      std::stringstream ss;
      ss << A[i][j];
      auto s = ss.str();
      if(s.size() > width){
        s.resize(width);
      }else{
        while(s.size() < width) s.push_back(' ');
      }

      std::cerr << s << "";
    }

    std::cerr << "\n";
  }

  std::cerr << std::right;
  std::cerr << std::setw(0);
#endif
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Debug/grid_viewer.cpp"
#include <iostream>
#include <string>
#include <functional>
#include <vector>

/**
 * @docs grid_viewer.md
 */
template <typename C>
void grid_viewer([[maybe_unused]] const C &A, [[maybe_unused]] int width = 10){
#ifdef DEBUG
  const int H = A.size();
  const int W = A[0].size();

  std::cerr << "    ";
  for(int j = 0; j < W; ++j){
    std::cerr << "\e[1;32m" << std::left << std::setw(width) << j << "\e[m";
  }
  std::cerr << "\n";
  std::cerr << std::right;

  for(int i = 0; i < H; ++i){
    std::cerr << "\e[1;32m" << std::setw(2) << i << "|\e[m ";

    for(int j = 0; j < W; ++j){
      std::stringstream ss;
      ss << A[i][j];
      auto s = ss.str();
      if(s.size() > width){
        s.resize(width);
      }else{
        while(s.size() < width) s.push_back(' ');
      }

      std::cerr << s << "";
    }

    std::cerr << "\n";
  }

  std::cerr << std::right;
  std::cerr << std::setw(0);
#endif
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

