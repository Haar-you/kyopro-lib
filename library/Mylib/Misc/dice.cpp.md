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


# :warning: サイコロ

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/dice.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title サイコロ
 * @docs dice.md
 */
struct Dice{
  int top, bottom, left, right, front, back;

  Dice(){}
  Dice(int top, int bottom, int left, int right, int front, int back):
    top(top), bottom(bottom), left(left), right(right), front(front), back(back){}

  Dice rot_left() const {
    return Dice(right, left, top, bottom, front, back);
  }

  Dice rot_right() const {
    return Dice(left, right, bottom, top, front, back);
  }

  Dice rot_front() const {
    return Dice(back, front, left, right, top, bottom);
  }
  
  Dice rot_back() const {
    return Dice(front, back, left, right, bottom, top);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/dice.cpp"

/**
 * @title サイコロ
 * @docs dice.md
 */
struct Dice{
  int top, bottom, left, right, front, back;

  Dice(){}
  Dice(int top, int bottom, int left, int right, int front, int back):
    top(top), bottom(bottom), left(left), right(right), front(front), back(back){}

  Dice rot_left() const {
    return Dice(right, left, top, bottom, front, back);
  }

  Dice rot_right() const {
    return Dice(left, right, bottom, top, front, back);
  }

  Dice rot_front() const {
    return Dice(back, front, left, right, top, bottom);
  }
  
  Dice rot_back() const {
    return Dice(front, back, left, right, bottom, top);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

