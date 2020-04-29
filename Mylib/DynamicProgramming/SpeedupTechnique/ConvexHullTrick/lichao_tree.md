## Operations

- `LiChaoSegmentTree(xs)`
- `add_line(T a, T b)`
	- 直線`f(x) = a*x + b`を追加する。
	- Time complexity $O(\log N)$
- `add_segment(T l, T r, T a, T b)`
	- 線分`x in [l, r), f(x) = a*x + b`を追加する。
	- Time complexity $O(\log^2 N)$
- `query(T x)`
	- `Comparator = std::greater<T>`の場合は、`x`での最大値
	- `Comparator = std::less<T>`の場合は、`x`での最小値
	- Time complexity $O(\log N)$

## Problems

- [Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)
- [Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)

## References

- [https://smijake3.hatenablog.com/entry/2018/06/16/144548](https://smijake3.hatenablog.com/entry/2018/06/16/144548)
