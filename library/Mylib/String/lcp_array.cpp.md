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


# :heavy_check_mark: LCP(Longest Common Prefix)配列

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/lcp_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :heavy_check_mark: <a href="suffix_array.cpp.html">接尾辞配列</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/number_of_substrings/main.test.cpp.html">test/yosupo-judge/number_of_substrings/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/String/suffix_array.cpp"

/**
 * @title LCP(Longest Common Prefix)配列
 * @docs lcp_array.md
 */
template <typename T>
struct LCPArray{
  const int n;
  std::vector<int> rank, lcp_array;

  LCPArray(const SuffixArray<T> &sa): n(sa.n), rank(n), lcp_array(n-1){
    for(int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0;
    for(int i = 0; i < n; ++i){
      if(rank[i] == 0) continue;
      int j = sa[rank[i]-1];

      if(h) --h;
      while(j+h < n and i+h < n){
        if(sa.str[j+h] != sa.str[i+h]) break;
        ++h;
      }

      lcp_array[rank[i]-1] = h;
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/lcp_array.cpp"
#include <vector>
#line 3 "Mylib/String/suffix_array.cpp"
#include <tuple>

/**
 * @title 接尾辞配列
 * @docs suffix_array.md
 */
template <typename T> class SuffixArray{
public:
  const T str;
  const int n;
  std::vector<int> suffix_array;
  
  const int ALPHABET = 256;
  
  SuffixArray(const T &s): str(s), n(s.size()), suffix_array(n){
    std::vector<int> temp(n);
    for(int i = 0; i < n; ++i) temp[i] = s[i];

    {
      std::vector<int> table(ALPHABET);
      for(auto c : s) table[c] = 1;
      for(int i = 1; i < ALPHABET; ++i) table[i] += table[i-1];

      for(int i = 0; i < n; ++i){
        temp[i] = table[s[i]]; 
      }
    }

    for(int l = 1; l < n; l *= 2){
      std::vector<std::tuple<int,int,int>> m(n);
      for(int i = 0; i < n; ++i){
        m[i] = std::make_tuple(temp[i], i+l >= n ? 0 : temp[i + l], i);
      }
      
      {
        std::vector<std::vector<std::tuple<int,int,int>>> table(n+1);

        for(int i = 0; i < n; ++i){
          table[std::get<1>(m[i])].push_back(m[i]);
        }

        m.clear();

        for(int i = 0; i <= n; ++i){
          for(auto &t : table[i]){
            m.push_back(t);
          }
        }
      }
      
      {
        std::vector<std::vector<std::tuple<int,int,int>>> table(n+1);

        for(int i = 0; i < n; ++i){
          table[std::get<0>(m[i])].push_back(m[i]);
        }

        m.clear();

        for(int i = 0; i <= n; ++i){
          for(auto &t : table[i]){
            m.push_back(t);
          }
        }
      }
      
      int h = 1;
      for(int i = 0; i < n; ++i){
        if(i > 0 and (std::get<0>(m[i-1]) != std::get<0>(m[i]) or std::get<1>(m[i-1]) != std::get<1>(m[i]))){
          ++h;
        }
        
        temp[std::get<2>(m[i])] = h;
      }
    }
    
    for(int i = 0; i < n; ++i) suffix_array[temp[i]-1] = i;
  }

  int operator[](int i) const {return suffix_array[i];}

  bool starts_with(const T &s, int k) const {
    if(s.size() <= str.size() - k){
      for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] != str[k+i]) return false;
      }
      return true;
    }
    return false;
  }

  int lower_bound(const T &s) const {
    auto check =
      [&](int x){
        for(int i = 0; i < (int)s.size(); ++i){
          if(suffix_array[x]+i >= (int)str.size()) return false;
          if(s[i] < str[suffix_array[x]+i]) return true;
          if(s[i] > str[suffix_array[x]+i]) return false;
        }
        return true;
      };

    int lb = -1, ub = n;
    while(abs(lb-ub) > 1){
      int mid = (lb+ub)/2;

      if(check(mid)){
        ub = mid;
      }else{
        lb = mid;
      }
    }
    
    return ub;
  }

  int upper_bound(const T &s) const {
    T t(s);

    t.back()++;
    int ret = lower_bound(t);
    t.back()--;
    return ret;
  }
};
#line 4 "Mylib/String/lcp_array.cpp"

/**
 * @title LCP(Longest Common Prefix)配列
 * @docs lcp_array.md
 */
template <typename T>
struct LCPArray{
  const int n;
  std::vector<int> rank, lcp_array;

  LCPArray(const SuffixArray<T> &sa): n(sa.n), rank(n), lcp_array(n-1){
    for(int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0;
    for(int i = 0; i < n; ++i){
      if(rank[i] == 0) continue;
      int j = sa[rank[i]-1];

      if(h) --h;
      while(j+h < n and i+h < n){
        if(sa.str[j+h] != sa.str[i+h]) break;
        ++h;
      }

      lcp_array[rank[i]-1] = h;
    }
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

