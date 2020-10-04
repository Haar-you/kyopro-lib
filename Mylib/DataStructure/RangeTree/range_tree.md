---
title: Range tree
documentation_of: Mylib/DataStructure/RangeTree/range_tree.cpp
---

## Operations

- `add(int x, int y)`
	- 点`(x, y)`を追加する。
- `build()`
	- `RangeTree`を構築する。
	- Time complexity $O(N \log N)$
- `get(int sx, int sy, int tx, int ty)`
	- `[sx, tx), [sy, ty)`内の点を列挙する。
	- Time complexity $O(\log^2 N + K)$

## Requirements

- `build`は唯一回だけ呼び出される。
- 必ず`add`, `build`, `get`の順で実行する。

## Notes

## Problems

- [AOJ DSL_2_C Range Search (kD Tree)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)

## References
