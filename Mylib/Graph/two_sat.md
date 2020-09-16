---
title: 2-SAT
documentation_of: Mylib/Graph/two_sat.cpp
---

## Operations

- `TwoSat(int n)`
- `add_if(int a, int b)`
	- $a \rightarrow b$を導入する。
- `add_or(int a, int b)`
	- $a \lor b$を導入する。
- `not_coexist(int a, int b)`
	- $\lnot (a \land b)$を導入する。
- `solve()`
	- 与えられた論理式をすべて`True`にするような変数の真偽値の割り当てを返す。
	- Time complexity $O(V + E)$

## Requirements

- `add_if`, `add_or`, `not_coexist`の引数は`[1, n]`または`[-n, -1]`を満たさなければならない。
	- 正数`i`は$x_i$を、負数`-i`は$\lnot x_i$を表す。

## Notes

## Problems

- [yukicoder No.274 The Wall](https://yukicoder.me/problems/no/274)
- [yukicoder No.470 Inverse S+T Problem](https://yukicoder.me/problems/no/470)
- [ARC 069 F - Flags](https://atcoder.jp/contests/arc069/tasks/arc069_d)

## References

