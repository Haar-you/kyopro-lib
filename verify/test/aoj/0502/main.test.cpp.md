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


# :heavy_check_mark: test/aoj/0502/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f070aafcfc9617f5a2bf249d6bfa024f">test/aoj/0502</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0502/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/dice.cpp.html">Dice</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502"

#include <iostream>
#include <string>
#include "Mylib/Misc/dice.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N;
  while(std::cin >> N, N){
    auto d = Dice(1, 6, 2, 5, 3, 4);

    int ans = 1;

    for(auto [s] : input_tuples<std::string>(N)){
      if(s == "North") d = d.rot_back(), ans += d.top;
      if(s == "East") d = d.rot_right(), ans += d.top;
      if(s == "West") d = d.rot_left(), ans += d.top;
      if(s == "South") d = d.rot_front(), ans += d.top;
      if(s == "Right") d = d.rot_clockwise(), ans += d.top;
      if(s == "Left") d = d.rot_counterclockwise(), ans += d.top;
    }
    
    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0502/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502"

#include <iostream>
#include <string>
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
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 7 "test/aoj/0502/main.test.cpp"

int main(){
  int N;
  while(std::cin >> N, N){
    auto d = Dice(1, 6, 2, 5, 3, 4);

    int ans = 1;

    for(auto [s] : input_tuples<std::string>(N)){
      if(s == "North") d = d.rot_back(), ans += d.top;
      if(s == "East") d = d.rot_right(), ans += d.top;
      if(s == "West") d = d.rot_left(), ans += d.top;
      if(s == "South") d = d.rot_front(), ans += d.top;
      if(s == "Right") d = d.rot_clockwise(), ans += d.top;
      if(s == "Left") d = d.rot_counterclockwise(), ans += d.top;
    }
    
    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

