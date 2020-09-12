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
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0502/main.test.cpp.html">test/aoj/0502/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

/**
 * @title Dice
 * @docs dice.md
 */
namespace haar_lib {
  struct dice {
    int top, bottom, front, back, right, left;

    dice(): top(), bottom(), front(), back(), right(), left(){}
    dice(int top, int bottom, int front, int back, int right, int left):
      top(top), bottom(bottom), front(front), back(back), right(right), left(left){}

    dice rot_left() const {
      return dice(right, left, front, back, bottom, top);
    }

    dice rot_right() const {
      return dice(left, right, front, back, top, bottom);
    }

    dice rot_front() const {
      return dice(back, front, top, bottom, right, left);
    }

    dice rot_back() const {
      return dice(front, back, bottom, top, right, left);
    }

    dice rot_clockwise() const {
      return dice(top, bottom, right, left, back, front);
    }

    dice rot_counterclockwise() const {
      return dice(top, bottom, left, right, front, back);
    }

    friend std::ostream& operator<<(std::ostream &s, const dice &a){
      s << "("
        << a.top << ", "
        << a.bottom << ", "
        << a.front << ", "
        << a.back << ", "
        << a.right << ", "
        << a.left << ")";
      return s;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/dice.cpp"
#include <iostream>

/**
 * @title Dice
 * @docs dice.md
 */
namespace haar_lib {
  struct dice {
    int top, bottom, front, back, right, left;

    dice(): top(), bottom(), front(), back(), right(), left(){}
    dice(int top, int bottom, int front, int back, int right, int left):
      top(top), bottom(bottom), front(front), back(back), right(right), left(left){}

    dice rot_left() const {
      return dice(right, left, front, back, bottom, top);
    }

    dice rot_right() const {
      return dice(left, right, front, back, top, bottom);
    }

    dice rot_front() const {
      return dice(back, front, top, bottom, right, left);
    }

    dice rot_back() const {
      return dice(front, back, bottom, top, right, left);
    }

    dice rot_clockwise() const {
      return dice(top, bottom, right, left, back, front);
    }

    dice rot_counterclockwise() const {
      return dice(top, bottom, left, right, front, back);
    }

    friend std::ostream& operator<<(std::ostream &s, const dice &a){
      s << "("
        << a.top << ", "
        << a.bottom << ", "
        << a.front << ", "
        << a.back << ", "
        << a.right << ", "
        << a.left << ")";
      return s;
    }
  };
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

