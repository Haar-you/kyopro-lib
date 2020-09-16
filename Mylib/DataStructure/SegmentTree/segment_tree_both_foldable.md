---
title: Segment tree (Both foldable)
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp
---

## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `SegmentTreeBothFoldable()`
- `operator[](i)`
- `at(i)`
	- $a_i$を返す。
- `fold_left(x, y)`
	- $a_l \circ a_{l+1} \circ \ldots a_{r-2} \circ a_{r-1}$を返す。
- `fold_right(x, y)`
	- $a_{r-1} \circ a_{r-2} \circ \ldots \circ a_{l+1} \circ a_l$を返す。
- `update(i, value)`
	- $a_i$を`value`に変更する。
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References

