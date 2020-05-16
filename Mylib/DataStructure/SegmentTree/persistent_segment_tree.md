## Operations

- `PersistentSegmentTree(n)`
- `PersistentSegmentTree(a[n])`
- `update(i, v)`
	- $a_i \leftarrow a_i \circ v$で更新した`PersistentSegmentTree`を返す。
	- Time complexity $O(\log N$)
- `get(i, j)`
	- $a_i \circ \ldots \circ a_{j-1}$を返す。
	- Time complexity $O(\log N$)
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(\log N$)

## Requirements

## Notes

- 2次元矩形領域中の点の総和を求めるようなクエリを処理できる。
	- 逆元が必要。 (総和, xorなど)

## Problems

- [yukicoder No.877 Range ReLU Query](https://yukicoder.me/problems/no/877)
- [Codeforces Round #276 (Div. 1) E. Sign on Fence](https://codeforces.com/contest/484/problem/E)

## References

- [http://sigma425.hatenablog.com/entry/2014/12/30/164148](http://sigma425.hatenablog.com/entry/2014/12/30/164148)
- [http://omochan.hatenablog.com/entry/2017/09/07/002323](http://omochan.hatenablog.com/entry/2017/09/07/002323)
- [https://qiita.com/hotman78/items/9c643feae1de087e6fc5](https://qiita.com/hotman78/items/9c643feae1de087e6fc5)
