## Operations

- `SegmentTree2D(w, h)`
	- Space complexity $O(wh)$
- `at(x, y)`
	- $a_{x, y}$を返す。
    - Time complexity $O(1)$
- `get(x1, y1, x2, y2)`
	- $a_{x_1, y_1} \circ a_{x_1+1, y_1} \circ a_{x_1+2, y_1} \circ \ldots \circ a_{x_1, y_1+1} \circ \ldots \circ a_{x_2-1, y_2-1}$を返す。
	- Time complexity $O(\log w \log h)$
- `update(x, y, value)`
	- $a_{x, y}$を`value`に変更する。
	- Time complexity $O(\log w \log h)$

## Requirements

- `Monoid`は**可換性**・結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References
 
