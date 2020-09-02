## Operations
可換群$(G, +, e)$上の列を扱う。
- `FenwickTree(n)`
- `update(i, v)`
	- $a_i \leftarrow a_i + v$に更新する。
	- Time complexity $O(\log n)$
- `get(i)`
	- $a_0 + a_1 + \ldots + a_{i-1}$を返す。
	- Time complexity $O(\log n)$
- `get(l, r)`
	- $a_l + a_{l+1} + \ldots + a_{r-1}$を返す。
	- Time complexity $O(\log n)$
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(\log n)$

## Requirements

- `AbelianGroup`は可換性・結合性を満たす演算`op`と単位元`id`と逆元を与える関数`inv`をもつ。

## Notes

## Problems

## References

