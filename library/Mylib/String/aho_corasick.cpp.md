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


# :x: Aho-Corasick法

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/aho_corasick.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :x: <a href="../../../verify/test/yukicoder/430/main.aho_corasick.test.cpp.html">test/yukicoder/430/main.aho_corasick.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

/**
 * @title Aho-Corasick法
 * @docs aho_corasick.md
 */
class AhoCorasick{
public:
  int n;
  std::vector<std::unordered_map<char,int>> trie;
  std::vector<int> failure_edge;
  std::vector<std::string> dict;
  std::vector<std::vector<int>> dict_index;
  
  AhoCorasick(): n(1), trie(1), failure_edge(1){}

  void add(const std::string &s){
    dict.push_back(s);

    int cur = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      char c = s[i];

      if(trie[cur].find(c) != trie[cur].end()){
        cur = trie[cur][c];
      }else{
        ++n;
        trie.resize(n);

        trie[cur][c] = n-1;
	
        cur = trie[cur][c];
      }
    }

    dict_index.resize(n);
    dict_index[cur].push_back(dict.size()-1);
  }

  void build(){
    failure_edge.resize(n);
    
    std::queue<int> dq;
    dq.push(0);

    while(not dq.empty()){
      int cur = dq.front(); dq.pop();

      for(auto &kv : trie[cur]){
        char c = kv.first;
        int next = kv.second;

        if(cur == 0){
          failure_edge[next] = 0;

        }else{
          int i = failure_edge[cur];
          int j = 0;
	
          while(1){
            if(trie[i].find(c) != trie[i].end()){
              j = trie[i][c];
              break;
            }else{
              if(i == 0) break;
              i = failure_edge[i];
            }
          }
	
          failure_edge[next] = j;

          for(auto k : dict_index[failure_edge[next]]){
            dict_index[next].push_back(k);
          }
        }
	
        dq.push(next);
      }
    }
  }

  template <typename Func> // function<void(int,int)>
  void match(const std::string &s, const Func &f){
    int cur = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      char c = s[i];

      while(cur != 0 and trie[cur].find(c) == trie[cur].end()){
        cur = failure_edge[cur];
      }

      cur = trie[cur][c];

      for(auto j : dict_index[cur]){
        int len = dict[j].size();
        f(i-len+1, len);
      }
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/aho_corasick.cpp"
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

/**
 * @title Aho-Corasick法
 * @docs aho_corasick.md
 */
class AhoCorasick{
public:
  int n;
  std::vector<std::unordered_map<char,int>> trie;
  std::vector<int> failure_edge;
  std::vector<std::string> dict;
  std::vector<std::vector<int>> dict_index;
  
  AhoCorasick(): n(1), trie(1), failure_edge(1){}

  void add(const std::string &s){
    dict.push_back(s);

    int cur = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      char c = s[i];

      if(trie[cur].find(c) != trie[cur].end()){
        cur = trie[cur][c];
      }else{
        ++n;
        trie.resize(n);

        trie[cur][c] = n-1;
	
        cur = trie[cur][c];
      }
    }

    dict_index.resize(n);
    dict_index[cur].push_back(dict.size()-1);
  }

  void build(){
    failure_edge.resize(n);
    
    std::queue<int> dq;
    dq.push(0);

    while(not dq.empty()){
      int cur = dq.front(); dq.pop();

      for(auto &kv : trie[cur]){
        char c = kv.first;
        int next = kv.second;

        if(cur == 0){
          failure_edge[next] = 0;

        }else{
          int i = failure_edge[cur];
          int j = 0;
	
          while(1){
            if(trie[i].find(c) != trie[i].end()){
              j = trie[i][c];
              break;
            }else{
              if(i == 0) break;
              i = failure_edge[i];
            }
          }
	
          failure_edge[next] = j;

          for(auto k : dict_index[failure_edge[next]]){
            dict_index[next].push_back(k);
          }
        }
	
        dq.push(next);
      }
    }
  }

  template <typename Func> // function<void(int,int)>
  void match(const std::string &s, const Func &f){
    int cur = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      char c = s[i];

      while(cur != 0 and trie[cur].find(c) == trie[cur].end()){
        cur = failure_edge[cur];
      }

      cur = trie[cur][c];

      for(auto j : dict_index[cur]){
        int len = dict[j].size();
        f(i-len+1, len);
      }
    }
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

