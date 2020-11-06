---
title: Fenwick tree (2D)
documentation_of: ./fenwick_tree_2d.cpp
---

## Operations
可換群$(G, +, e)$上の二次元配列を扱う。
- `FenwickTree2D(w, h)`
- `get(x1, y1, x2, y2)`
	- $\sum_{x_1 \le i \lt x_2} \sum_{y_1 \le j \lt y_2} a_{i, j}$を返す。
	- Time complexity $O(\log w \log h)$
- `at(x, y)`
	- $a_{x, y}$を返す。
	- Time complexity $O(\log w \log h)$
- `update(x, y, v)`
	- $a_{x, y} \leftarrow a_{x, y} + v$で更新する。
	- Time complexity $O(\log w \log h)$

## Requirements

- `AbelianGroup`は可換性・結合性を満たす演算`op`と単位元`id`と逆元を与える関数`inv`をもつ。

## Notes

## Problems

## References

