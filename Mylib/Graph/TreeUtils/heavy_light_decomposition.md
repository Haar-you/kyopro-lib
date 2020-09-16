---
title: Heavy-light decomposition
documentation_of: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
---

## Operations

- `HLDecomposition(tree, root)`
- `path_query_vertex(int x, int y, f)`
	- `x`, `y`間のパス上の頂点に`f`を適用する。
- `path_query_vertex(int x, int y, f, g)`
- `path_query_edge(int x, int y, f)`
	- `x`, `y`間のパス上の辺に`f`を適用する。
- `subtree_query_vertext(int x, f)`
	- `x`の部分木の頂点に`f`を適用する。
- `subtree_query_edge(int x, f)`
	- `x`の部分木の辺に`f`を適用する。
- `get_edge_id(int u, int v)`
	- 辺`(u, v)`に対応するidを返す。
- `parent(int x)`
	- `x`の親を返す。
- `lca(int u, int v)`
	- `u`と`v`の最小共通祖先を返す。
- `get_id(int x)`
	- 頂点`x`に対応する`id[x]`を返す。

## Requirements

## Notes

## Problems

- [yukicoder No.399 動的な領主](https://yukicoder.me/problems/no/399) (パスに対する頂点クエリ)
- [AOJ 2667 Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667) (パス・部分木に対する辺クエリ)
- [Codeforces Round #329 (Div. 2) D. Happy Tree Party](https://codeforces.com/contest/593/problem/D) (パスに対する辺クエリ)
- [yukicoder No.650 行列木クエリ](https://yukicoder.me/problems/no/650) (パスに対する辺クエリ)
- [Codeforces Round #200 (Div. 1) D. Water Tree](https://codeforces.com/contest/343/problem/D) (パス・部分木に対する頂点クエリ)

## References

- [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [https://beet-aizu.hatenablog.com/entry/2017/12/12/235950](https://beet-aizu.hatenablog.com/entry/2017/12/12/235950)
- [https://www.hamayanhamayan.com/entry/2017/04/10/172636](https://www.hamayanhamayan.com/entry/2017/04/10/172636)

