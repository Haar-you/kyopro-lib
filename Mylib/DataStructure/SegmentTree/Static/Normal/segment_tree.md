## Operations

- `SegmentTree(n)`
- `operator[](i)`
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(1)$
- `get(l, r)`
	- $a_l \circ a_{l+1} \circ \ldots \circ a_{r-1}$を返す。
	- Time complexity $O(\log n)$
- `update(i, value)`
	- $a_i$を`value`に変更する。
	- Time complexity $O(\log n)$
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References
 
