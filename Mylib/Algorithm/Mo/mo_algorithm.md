## Operations

- `MoAlgorithm`
- `add(int l, int r)`
	- クエリ`[l, r)`を追加する。
- `build()`
- `run()`
	- Time complexity $O(N\sqrt{Q})$
- `make_mo`

## Requirements

- `append(int i)`
	- `i`番目の要素を追加する操作。
- `remove(int i)`
	- `i`番目の要素を削除する操作。
- `query(int i)`
	- `i`番目のクエリを処理する操作。
- 必ず`add`, `build`, `run`の順で実行する。

## Problems

- [Yandex.Algorithm 2011: Round 2 D. Powerful array](https://codeforces.com/contest/86/problem/D) (出現数)
- [SPOJ DQUERY](https://www.spoj.com/problems/DQUERY/) (種類数)
- [第3回 ドワンゴからの挑戦状 本選 B - ニワンゴくんの約数](https://atcoder.jp/contests/dwacon2017-honsen/tasks/dwango2017final_b) (積の約数の個数)
- [Codeforces Round #221 (Div. 1) D. Tree and Queries](https://codeforces.com/contest/375/problem/D) (部分木 / 出現数k以上の種類数)
- [Unique Art](https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem) (出現数1の種類数)

## References

- [https://ei1333.hateblo.jp/entry/2017/09/11/211011](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
- [https://snuke.hatenablog.com/entry/2016/07/01/000000](https://snuke.hatenablog.com/entry/2016/07/01/000000)
- [https://www.hamayanhamayan.com/entry/2017/04/18/012937](https://www.hamayanhamayan.com/entry/2017/04/18/012937)