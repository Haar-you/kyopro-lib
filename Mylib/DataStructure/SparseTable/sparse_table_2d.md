---
title: Sparse table (2D)
documentation_of: ./sparse_table_2d.cpp
---

## Operations

- `SparseTable2D(v[n][m])`
	- Time complexity $O(nm\log n \log m)$
- `get(int r1, int c1, int r2, int c2)`
	- `[r1, r2), [c1, c2)`を`Semilattice::op`でfoldする。
	- Time complexity $O(1)$

## Requirements

- `Semilattice`は冪等性・可換性・結合性を満たす`op`を持つ。
	- `max`, `min`, `gcd`, `lcm`, `and`, `or`など

## Notes

## Problems

- [Codeforces Round #619 (Div. 2) E. Nanosoft](https://codeforces.com/contest/1301/problem/E)

## References

- [https://codeforces.com/blog/entry/45485](https://codeforces.com/blog/entry/45485)
