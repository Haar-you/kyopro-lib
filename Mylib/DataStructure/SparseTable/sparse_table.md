---
title: Sparse table
documentation_of: ./sparse_table.cpp
---

## Operations

- `SparseTable(v[n])`
    - Time complexity $O(n \log n)$
- `get(int s, int t)`
	- `[s, t)`を`Semilattice::op`でfoldする。
	- Time complexity $O(1)$

## Requirements

- `Semilattice`は冪等性・可換性・結合性を満たす`op`を持つ。
	- `max`, `min`, `gcd`, `lcm`, `and`, `or`など

## Notes

## Problems

## References
