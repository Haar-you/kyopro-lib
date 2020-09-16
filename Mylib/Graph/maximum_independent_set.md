---
title: Maximum independent set
documentation_of: Mylib/Graph/maximum_independent_set.cpp
---

## Operations

- `maximum_independent_set(g[n][n])`
	- 最大独立集合の一つを64bit整数で表記して返す。
	- Time complexity $O(2^{n/2} n)$

## Requirements

## Notes
- 二部グラフでは、(最大独立集合の大きさ) = (グラフの頂点数) - (最大二部マッチングの大きさ)となるので、最大二部マッチングを用いる方が良い。
	- [https://qiita.com/drken/items/7f98315b56c95a6181a4](https://qiita.com/drken/items/7f98315b56c95a6181a4)

## Problems

- [CODE THANKS FESTIVAL 2017 G - Mixture Drug](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g)
- [Codeforces Round #533 (Div. 2) E. Helping Hiasat](https://codeforces.com/contest/1105/problem/E)
- [Maximum Independent Set](https://judge.yosupo.jp/problem/maximum_independent_set)


## References

