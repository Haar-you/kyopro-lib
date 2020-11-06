---
title: Dual segment tree
documentation_of: ./dual_segment_tree.cpp
---

## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `DualSegmentTree(n)`
- `update(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow v \circ a_i$に更新する。
- `get(i)`
	- $a_i$を返す。
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References

