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


# :warning: Timer

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/timer.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <chrono>
#include <iostream>

/**
 * @title Timer
 * @docs timer.md
 */
namespace haar_lib {
template <typename F>
void timer(F f){
  auto s = std::chrono::system_clock::now();
  f();
  auto t = std::chrono::system_clock::now();
  auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t - s).count();
  std::cerr << d << "ms" << "\n";
};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/timer.cpp"
#include <chrono>
#include <iostream>

/**
 * @title Timer
 * @docs timer.md
 */
namespace haar_lib {
template <typename F>
void timer(F f){
  auto s = std::chrono::system_clock::now();
  f();
  auto t = std::chrono::system_clock::now();
  auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t - s).count();
  std::cerr << d << "ms" << "\n";
};
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

