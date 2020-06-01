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


# :heavy_check_mark: Dice

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/dice.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0502/main.test.cpp.html">test/aoj/0502/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Dice
 * @docs dice.md
 */
struct Dice{
  int top, bottom, front, back, right, left;

  Dice(){}
  Dice(int top, int bottom, int front, int back, int right, int left):
    top(top), bottom(bottom), front(front), back(back), right(right), left(left){}

  Dice rot_left() const {
    return Dice(right, left, front, back, bottom, top);
  }

  Dice rot_right() const {
    return Dice(left, right, front, back, top, bottom);
  }

  Dice rot_front() const {
    return Dice(back, front, top, bottom, right, left);
  }
  
  Dice rot_back() const {
    return Dice(front, back, bottom, top, right, left);
  }

  Dice rot_clockwise() const {
    return Dice(top, bottom, right, left, back, front);
  }

  Dice rot_counterclockwise() const {
    return Dice(top, bottom, left, right, front, back);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/dice.cpp"

/**
 * @title Dice
 * @docs dice.md
 */
struct Dice{
  int top, bottom, front, back, right, left;

  Dice(){}
  Dice(int top, int bottom, int front, int back, int right, int left):
    top(top), bottom(bottom), front(front), back(back), right(right), left(left){}

  Dice rot_left() const {
    return Dice(right, left, front, back, bottom, top);
  }

  Dice rot_right() const {
    return Dice(left, right, front, back, top, bottom);
  }

  Dice rot_front() const {
    return Dice(back, front, top, bottom, right, left);
  }
  
  Dice rot_back() const {
    return Dice(front, back, bottom, top, right, left);
  }

  Dice rot_clockwise() const {
    return Dice(top, bottom, right, left, back, front);
  }

  Dice rot_counterclockwise() const {
    return Dice(top, bottom, left, right, front, back);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

