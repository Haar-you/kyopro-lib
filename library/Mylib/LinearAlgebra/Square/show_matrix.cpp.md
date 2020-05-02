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


# :warning: Mylib/LinearAlgebra/Square/show_matrix.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/show_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

/**
 * @docs show_matrix.md
 */
template <typename M, typename T = typename M::value_type>
void show_matrix(const M &m, int w = 10){
#ifdef DEBUG
  const int N = m.size();
  
  std::cerr << "⎛" << std::string((w+1)*N, ' ') << "⎞" << std::endl;
  for(int i = 0; i < N; ++i){
    std::cerr << "⎜";
    for(int j = 0; j < N; ++j) std::cerr << std::setw(w) << m[i][j] << " ";
    std::cerr << "⎟";
    std::cerr << std::endl;
  }
  std::cerr << "⎝" << std::string((w+1)*N, ' ') << "⎠" << std::endl;
#endif
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/show_matrix.cpp"
#include <iostream>

/**
 * @docs show_matrix.md
 */
template <typename M, typename T = typename M::value_type>
void show_matrix(const M &m, int w = 10){
#ifdef DEBUG
  const int N = m.size();
  
  std::cerr << "⎛" << std::string((w+1)*N, ' ') << "⎞" << std::endl;
  for(int i = 0; i < N; ++i){
    std::cerr << "⎜";
    for(int j = 0; j < N; ++j) std::cerr << std::setw(w) << m[i][j] << " ";
    std::cerr << "⎟";
    std::cerr << std::endl;
  }
  std::cerr << "⎝" << std::string((w+1)*N, ' ') << "⎠" << std::endl;
#endif
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

