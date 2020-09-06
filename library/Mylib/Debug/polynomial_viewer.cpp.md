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


# :warning: Mylib/Debug/polynomial_viewer.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0f67555b3039d368e55db69bb4454f7e">Mylib/Debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Debug/polynomial_viewer.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <string>

/**
 * @docs polynomial_viewer.md
 */
template <typename Container>
class PolynomialViewer {
  Container data;

public:
  PolynomialViewer(Container data): data(data){}

  void show_x(std::ostream &s, int k) const {
    if(k == 0) return;
    else if(k == 1) s << "x";
    else{
      s << "x";

      constexpr static auto p = "⁰¹²³⁴⁵⁶⁷⁸⁹";
      for(char c : std::to_string(k)){
        int i = c - '0';
        if(i == 0) s << p[i] << p[i + 1] << p[i + 2];
        else if(1 <= i and i <= 3) s << p[1 + i * 2] << p[2 + i * 2];
        else s << p[i * 3 - 3] << p[i * 3 - 2] << p[i * 3 - 1];
      }
    }
  }

  auto& run(std::ostream &s) const {
    const int n = data.size();

    for(int i = 0; i < n; ++i){
      s << data[i];
      show_x(s, i);
      s << " ";
    }

    return s;
  }

  friend std::ostream& operator<<(std::ostream &s, const PolynomialViewer &a){
    return a.run(s);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Debug/polynomial_viewer.cpp"
#include <iostream>
#include <string>

/**
 * @docs polynomial_viewer.md
 */
template <typename Container>
class PolynomialViewer {
  Container data;

public:
  PolynomialViewer(Container data): data(data){}

  void show_x(std::ostream &s, int k) const {
    if(k == 0) return;
    else if(k == 1) s << "x";
    else{
      s << "x";

      constexpr static auto p = "⁰¹²³⁴⁵⁶⁷⁸⁹";
      for(char c : std::to_string(k)){
        int i = c - '0';
        if(i == 0) s << p[i] << p[i + 1] << p[i + 2];
        else if(1 <= i and i <= 3) s << p[1 + i * 2] << p[2 + i * 2];
        else s << p[i * 3 - 3] << p[i * 3 - 2] << p[i * 3 - 1];
      }
    }
  }

  auto& run(std::ostream &s) const {
    const int n = data.size();

    for(int i = 0; i < n; ++i){
      s << data[i];
      show_x(s, i);
      s << " ";
    }

    return s;
  }

  friend std::ostream& operator<<(std::ostream &s, const PolynomialViewer &a){
    return a.run(s);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

