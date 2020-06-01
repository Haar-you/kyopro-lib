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


# :warning: Real solutions of quadratic equation

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c20232aa0a6a3c1c77a782d17f007d0b">Mylib/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Math/quadratic_equation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>
#include <vector>

/**
 * @title Real solutions of quadratic equation
 * @docs quadratic_equation.md
 */
std::vector<double> quadratic_equation(double a, double b, double c){
  double d = b*b - 4*a*c;
  if(d < 0) return {};
  
  double x1 = (-b - std::sqrt(d)) / (2 * a);
  double x2 = (-b + std::sqrt(d)) / (2 * a);
  return {x1, x2};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Math/quadratic_equation.cpp"
#include <cmath>
#include <vector>

/**
 * @title Real solutions of quadratic equation
 * @docs quadratic_equation.md
 */
std::vector<double> quadratic_equation(double a, double b, double c){
  double d = b*b - 4*a*c;
  if(d < 0) return {};
  
  double x1 = (-b - std::sqrt(d)) / (2 * a);
  double x2 = (-b + std::sqrt(d)) / (2 * a);
  return {x1, x2};
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

