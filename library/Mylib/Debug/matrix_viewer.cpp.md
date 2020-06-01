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


# :warning: Mylib/Debug/matrix_viewer.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0f67555b3039d368e55db69bb4454f7e">Mylib/Debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Debug/matrix_viewer.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-28 23:09:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

/**
 * @docs matrix_viewer.md
 */
template <typename M, typename T = typename M::value_type>
struct MatrixViewer{
  M m;
  int w;

  MatrixViewer(const M &m, int w = 10): m(m), w(w){}

  friend std::ostream& operator<<(std::ostream &s, const MatrixViewer &viewer){
    int w = viewer.w;
    const auto m = viewer.m;
    const int N = m.size();

    s << "⎛" << std::string((w+1)*N, ' ') << "⎞" << std::endl;
    for(int i = 0; i < N; ++i){
      s << "⎜";
      for(int j = 0; j < N; ++j) s << std::setw(w) << m[i][j] << " ";
      s << "⎟";
      s << std::endl;
    }
    s << "⎝" << std::string((w+1)*N, ' ') << "⎠" << std::endl;

    return s;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Debug/matrix_viewer.cpp"
#include <iostream>
#include <string>
#include <iomanip>

/**
 * @docs matrix_viewer.md
 */
template <typename M, typename T = typename M::value_type>
struct MatrixViewer{
  M m;
  int w;

  MatrixViewer(const M &m, int w = 10): m(m), w(w){}

  friend std::ostream& operator<<(std::ostream &s, const MatrixViewer &viewer){
    int w = viewer.w;
    const auto m = viewer.m;
    const int N = m.size();

    s << "⎛" << std::string((w+1)*N, ' ') << "⎞" << std::endl;
    for(int i = 0; i < N; ++i){
      s << "⎜";
      for(int j = 0; j < N; ++j) s << std::setw(w) << m[i][j] << " ";
      s << "⎟";
      s << std::endl;
    }
    s << "⎝" << std::string((w+1)*N, ' ') << "⎠" << std::endl;

    return s;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

