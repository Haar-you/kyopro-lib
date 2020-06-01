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


# :x: test/aoj/ALDS1_10_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6691093001380fa1883257c26243406e">test/aoj/ALDS1_10_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_10_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/String/longest_common_subsequence.cpp.html">Longest common subsequence</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#include "Mylib/String/longest_common_subsequence.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int q; std::cin >> q;
  
  for(auto [x, y] : input_tuples<std::string, std::string>(q)){
    std::cout << lcs(x, y) << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_10_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#line 2 "Mylib/String/longest_common_subsequence.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Longest common subsequence
 * @docs longest_common_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lcs(const Container &a, const Container &b){
  const int n = a.size(), m = b.size();
  
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
    
  return dp[n][m];
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  template <typename T, size_t ... I>
  static void input_tuple_helper(T &val, std::index_sequence<I...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)), 0)...};
  }
  
  struct iter{
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool get = false;
    int N;
    int c = 0;

    value_type operator*(){
      if(get) return value;
      else{
        input_tuple_helper(value, std::make_index_sequence<sizeof...(Args)>());
        return value;
      }
    }

    void operator++(){
      ++c;
      get = false;
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
#line 7 "test/aoj/ALDS1_10_C/main.test.cpp"

int main(){
  int q; std::cin >> q;
  
  for(auto [x, y] : input_tuples<std::string, std::string>(q)){
    std::cout << lcs(x, y) << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

