## Operations

- `access(wm, int i)`
    - `i`番目(0-indexed)の要素を取得
- `rank(wm, int i, T val)`
    - `[0, i)`に含まれる`val`の個数
- `count(wm, int l, int r, T val)`
    - `[l, r)`に含まれる`val`の個数
- `select(wm, int count, T val)`
    - `count`番目(1-indexed)の`val`の位置
- `quantile(wm, int l, int r, int k)`
    - `[l, r)`で`k`番目(1-indexed)に小さい値
- `maximum(wm, int l, int r)`
    - `[l, r)`での最大値
- `minimum(wm, int l, int r)`
    - `[l, r)`での最小値
- `next_value(wm, int l, int r, T lb)`
	- `[l, r)`で`lb`以上で最小の値
- `prev_value(wm, int l, int r, T ub)`
	- `[l, r)`で`ub`未満で最大の値
- `range_freq_list(wm, int l, int r, T lb, T ub)`
	- `[l, r)`で`[lb, ub)`を満たすものを出現頻度とのペアで列挙する。
- `range_freq(wm, int l, int r, T lb, T ub)`
	- `[l, r)`で`[lb, ub)`を満たす値の個数
- `top_k(wm, int l, int r, int k)`
	- `[l, r)`で値の出現頻度が高い順に`k`個を列挙する。

## Problems

- [AOJ1549 Hard Beans](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549) (prev_value, next_value)
- [AOJ2674 Disordered Data Detection](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674) (range_freq)
- [SPOJ MKTHNUM](https://www.spoj.com/problems/MKTHNUM/) (quantile)

## References

- [http://miti-7.hatenablog.com/entry/2018/04/28/152259](http://miti-7.hatenablog.com/entry/2018/04/28/152259)
- [https://www.hamayanhamayan.com/entry/2017/06/13/103352](https://www.hamayanhamayan.com/entry/2017/06/13/103352)
