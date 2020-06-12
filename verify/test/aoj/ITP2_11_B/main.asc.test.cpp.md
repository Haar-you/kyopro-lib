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


# :x: test/aoj/ITP2_11_B/main.asc.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ee41bb6b1ee97f3a5e094f7dfeadd68">test/aoj/ITP2_11_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP2_11_B/main.asc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Bit/for_each_superset_asc.cpp.html">Enumerate supersets (Ascending order)</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/Bit/for_each_superset_asc.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n, k; std::cin >> n >> k;

  int t = 0;
  for(auto b : input_vector<int>(k)){
    t |= 1 << b;
  }

  std::map<int, std::vector<int>> ans;
  for(int d : SupersetAsc(t, n)){
    ans[d];
    for(int i = 0; i < n; ++i){
      if(d & (1 << i)) ans[d].push_back(i);
    }
  }
  
  for(auto &[m, v] : ans){
    std::cout << m << ":";
    for(auto x : v) std::cout << " " << x;
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ITP2_11_B/main.asc.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"

#include <iostream>
#include <vector>
#include <map>
#line 2 "Mylib/Bit/for_each_superset_asc.cpp"

/**
 * @title Enumerate supersets (Ascending order)
 * @docs for_each_superset_asc.md
 */
class SupersetAsc{
  struct iter{
    int t, a, n;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      t = (t + 1) | a;
      if(t >= (1 << n)) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a, n;

public:
  SupersetAsc(int a, int n): a(a), n(n){}
  iter begin() const {return iter({a, a, n, false});}
  iter end() const {return iter();}
};
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 8 "test/aoj/ITP2_11_B/main.asc.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n, k; std::cin >> n >> k;

  int t = 0;
  for(auto b : input_vector<int>(k)){
    t |= 1 << b;
  }

  std::map<int, std::vector<int>> ans;
  for(int d : SupersetAsc(t, n)){
    ans[d];
    for(int i = 0; i < n; ++i){
      if(d & (1 << i)) ans[d].push_back(i);
    }
  }
  
  for(auto &[m, v] : ans){
    std::cout << m << ":";
    for(auto x : v) std::cout << " " << x;
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
