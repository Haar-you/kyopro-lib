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


# :warning: Garner法

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/garner.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :heavy_check_mark: <a href="Mod/mod_inv.cpp.html">mod逆数</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Number/Mod/mod_inv.cpp"

/**
 * @title Garner法
 * @docs garner.md
 */
int64_t garner_algorithm(std::vector<int64_t> r, std::vector<int64_t> m, const int64_t mod){
  m.push_back(mod);

  int n = r.size();
  std::vector<int64_t> coeffs(n+1, 1);
  std::vector<int64_t> constants(n+1, 0);

  for(int k = 0; k < n; ++k){
    int64_t t = ((r[k] - constants[k] + m[k]) % m[k] * mod_inv(coeffs[k], m[k])) % m[k];
    for(int i = k+1; i < n+1; ++i){
      (constants[i] += t * coeffs[i] % m[i]) %= m[i];
      (coeffs[i] *= m[k]) %= m[i];
    }
  }

  return constants.back();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/garner.cpp"
#include <vector>
#line 2 "Mylib/Number/Mod/mod_inv.cpp"
#include <utility>

/**
 * @title mod逆数
 * @docs mod_inv.md
 */
int64_t mod_inv(int64_t a, int64_t m){
  int64_t b = m, u = 1, v = 0;

  while(b){
    int64_t t = a / b;
    a -= t * b; std::swap(a, b);
    u -= t * v; std::swap(u, v);
  }

  u %= m;
  if(u < 0) u += m;

  return u;
}
#line 4 "Mylib/Number/garner.cpp"

/**
 * @title Garner法
 * @docs garner.md
 */
int64_t garner_algorithm(std::vector<int64_t> r, std::vector<int64_t> m, const int64_t mod){
  m.push_back(mod);

  int n = r.size();
  std::vector<int64_t> coeffs(n+1, 1);
  std::vector<int64_t> constants(n+1, 0);

  for(int k = 0; k < n; ++k){
    int64_t t = ((r[k] - constants[k] + m[k]) % m[k] * mod_inv(coeffs[k], m[k])) % m[k];
    for(int i = k+1; i < n+1; ++i){
      (constants[i] += t * coeffs[i] % m[i]) %= m[i];
      (coeffs[i] *= m[k]) %= m[i];
    }
  }

  return constants.back();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

