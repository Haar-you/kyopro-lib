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


# :heavy_check_mark: Project Selection Problem

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/project_selection_problem.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 20:22:17+09:00




## Operations

- `ProjectSelectionProblem(N)`
- `penalty_if_red(int i, T c)`
	- `i`を<font color="red">赤</font>に塗ると`c`の損失になる。
- `gain_if_red(int i, T c)`
	- `i`を<font color="red">赤</font>に塗ると`c`の利益を得る。
- `penalty_if_blue(int i, T c)`
	- `i`を<font color="blue">青</font>に塗ると`c`の損失になる。
- `gain_if_blue(int i, T c)`
	- `i`を<font color="blue">青</font>にぬると`c`の利益を得る。
- `penalty_if_red_blue(int i, int j, T c)`
	- `i`を<font color="red">赤</font>、且つ`j`を<font color="blue">青</font>に塗ると`c`の損失になる。
- `penalty_if_different(int i, int j, T c)`
	- `i`と`j`の色が異なると`c`の損失になる。
- `must_be_red(int i)`
	- `i`は<font color="red">赤</font>でなければならない。
- `must_be_blue(int i)`
	- `i`は<font color="blue">青</font>でなければならない。
- `if_red_then_must_be_red(int i, int j)`
	- `i`が<font color="red">赤</font>ならば、`j`は<font color="red">赤</font>でなければならない。
- `gain_if_red_red(int i, int j, T c)`
	- `i`と`j`をともに<font color="red">赤</font>に塗ると`c`の利益を得る。
- `gain_if_blue_blue(int i, int j, T c)`
	- `i`と`j`をともに<font color="blue">青</font>に塗ると`c`の利益を得る。
- `solve()`

## Requirements

- 頂点`s`は<font color="red">赤</font>に、頂点`t`は<font color="blue">青</font>に塗られる。

## Notes

## Problems

- [ARC 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AOJ 3058 Ghost](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058)
- [AOJ 2903 Board](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903)

## References

- [https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/](https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/)
- [https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html](https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html)
- [https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C](https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C)


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2903/main.test.cpp.html">test/aoj/2903/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3058/main.test.cpp.html">test/aoj/3058/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <cassert>
#include <limits>

/*
 * @title Project Selection Problem
 * @docs project_selection_problem.md
 */
template <typename T, typename Flow>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

  constexpr static T INF = std::numeric_limits<T>::max();

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[i].emplace_back(t, c);
  }

  void gain_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    default_gain += c;
    penalty_if_blue(i, c);
  }
  
  void penalty_if_blue(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[s].emplace_back(i, c);
  }

  void gain_if_blue(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    default_gain += c;
    penalty_if_red(i, c);
  }

  void penalty_if_red_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
  }

  void must_be_red(int i){
    assert(0 <= i and i < N);
    penalty_if_blue(i, INF);
  }

  void must_be_blue(int i){
    assert(0 <= i and i < N);
    penalty_if_red(i, INF);
  }

  void if_red_then_must_be_red(int i, int j){
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    penalty_if_red_blue(i, j, INF);
  }

  void gain_if_red_red(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Flow flow(graph);
    return default_gain - flow.solve(s, t);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/project_selection_problem.cpp"
#include <vector>
#include <utility>
#include <cassert>
#include <limits>

/*
 * @title Project Selection Problem
 * @docs project_selection_problem.md
 */
template <typename T, typename Flow>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

  constexpr static T INF = std::numeric_limits<T>::max();

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[i].emplace_back(t, c);
  }

  void gain_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    default_gain += c;
    penalty_if_blue(i, c);
  }
  
  void penalty_if_blue(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[s].emplace_back(i, c);
  }

  void gain_if_blue(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    default_gain += c;
    penalty_if_red(i, c);
  }

  void penalty_if_red_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
  }

  void must_be_red(int i){
    assert(0 <= i and i < N);
    penalty_if_blue(i, INF);
  }

  void must_be_blue(int i){
    assert(0 <= i and i < N);
    penalty_if_red(i, INF);
  }

  void if_red_then_must_be_red(int i, int j){
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    penalty_if_red_blue(i, j, INF);
  }

  void gain_if_red_red(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Flow flow(graph);
    return default_gain - flow.solve(s, t);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

