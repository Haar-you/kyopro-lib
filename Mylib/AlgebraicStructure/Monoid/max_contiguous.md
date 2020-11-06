---
title: Max contiguous monoid
documentation_of: ./max_contiguous.cpp
---

## Operations

- `id()`
	- 長さ`0`の列を表す。
	- `return (0, 0, 0, 0)`
- `op(a, b)`
	- `a`の右隣に`b`を隣接させる。

## Requirements

## Notes

- 連続する`1`の最大長を管理する。
	- `value_type = (最大連続長, 左側最大連続長, 右側最大連続長, セグメント長)`

## Problems

- [Codeforces Round #276 (Div. 1) E. Sign on Fence](https://codeforces.com/contest/484/problem/E)

## References

