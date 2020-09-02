## Operations
モノイド$(M, \oplus, e)$上の二次元配列を扱う。
- `SegmentTree2D(w, h)`
	- Space complexity $O(wh)$
- `at(x, y)`
	- $a_{x, y}$を返す。
    - Time complexity $O(1)$
- `get(x1, y1, x2, y2)`
	- $\bigoplus_{x1 \le x \lt x2}\bigoplus_{y1 \le y \lt y2} a_{x,y}$を返す。
	- Time complexity $O(\log w \log h)$
- `update(x, y, value)`
	- $a_{x, y}$を`value`に変更する。
	- Time complexity $O(\log w \log h)$

## Requirements

- `Monoid`は**可換性**・結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References

