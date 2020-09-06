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


# :warning: Simulated annealing

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8196a7a5355e165a1b784acd0a3f4854">Mylib/Heuristic</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Heuristic/simulated_annealing.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <chrono>
#include <cmath>

/**
 * @title Simulated annealing
 * @docs simulated_annealing.md
 */
template <typename Func>
void simulated_annealing(int duration, double T0, double T1, Func f){
  using namespace std::chrono;

  auto s = system_clock::now();

  while(true){
    auto t = system_clock::now();
    int d = duration_cast<milliseconds>(t - s).count();
    if(d >= duration) break;

    double now = (double)d / duration;

    double T = std::pow(T0, 1.0 - now) * std::pow(T1, now);

    f(d, T);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Heuristic/simulated_annealing.cpp"
#include <chrono>
#include <cmath>

/**
 * @title Simulated annealing
 * @docs simulated_annealing.md
 */
template <typename Func>
void simulated_annealing(int duration, double T0, double T1, Func f){
  using namespace std::chrono;

  auto s = system_clock::now();

  while(true){
    auto t = system_clock::now();
    int d = duration_cast<milliseconds>(t - s).count();
    if(d >= duration) break;

    double now = (double)d / duration;

    double T = std::pow(T0, 1.0 - now) * std::pow(T1, now);

    f(d, T);
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

