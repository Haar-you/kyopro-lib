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


# :x: test/yukicoder/184/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#680117a14efb0a2f09a9c186518bf55b">test/yukicoder/184</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/184/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-14 00:24:32+09:00


* see: <a href="https://yukicoder.me/problems/no/184">https://yukicoder.me/problems/no/184</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/LinearAlgebra/GaussianElimination/binary_gaussian_elimination.cpp.html">Gaussian elimination (Mod2)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/184"

#include <iostream>
#include <bitset>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/GaussianElimination/binary_gaussian_elimination.cpp"

int main(){
  int n; std::cin >> n;
  auto a = input_vector<int64_t>(n);

  int rank = gaussian_elimination(std::vector<std::bitset<64>>(a.begin(), a.end()));
  
  std::cout << (1LL << rank) << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/184/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/184"

#include <iostream>
#include <bitset>
#include <vector>
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
#line 4 "Mylib/LinearAlgebra/GaussianElimination/binary_gaussian_elimination.cpp"
#include <utility>

/**
 * @title Gaussian elimination (Mod2)
 * @docs binary_gaussian_elimination.md
 */
template <size_t N> int gaussian_elimination(std::vector<std::bitset<N>> &m){
  const int n = m.size();
  int rank = 0;

  for(size_t j = 0; j < N; ++j){
    int pivot = -1;

    for(int i = rank; i < n; ++i){
      if(m[i][j]){
        pivot = i;
        break;
      }
    }

    if(pivot == -1) continue;

    std::swap(m[pivot], m[rank]);

    for(int i = 0; i < n; ++i){
      if(i != rank and m[i][j]) m[i] ^= m[rank];
    }
    ++rank;
  }
  
  return rank;
}

template <size_t N> int gaussian_elimination(std::vector<std::bitset<N>> &&m){
  return gaussian_elimination(m);
}
#line 8 "test/yukicoder/184/main.test.cpp"

int main(){
  int n; std::cin >> n;
  auto a = input_vector<int64_t>(n);

  int rank = gaussian_elimination(std::vector<std::bitset<64>>(a.begin(), a.end()));
  
  std::cout << (1LL << rank) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

