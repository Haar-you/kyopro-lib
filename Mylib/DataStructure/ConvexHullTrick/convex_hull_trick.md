---
title: Convex hull trick
documentation_of: ./convex_hull_trick.cpp
---

## Operations

- `Comparator = std::greater<T>`の場合
	- `add(T a, T b)`
		- `a`は単調減少
		- 直線`f(x) = a*x + b`を追加する。
	- `query(T x)`
		- `x`は単調増加
		- `f(x)`の最小値を得る。

- `Comparator = std::less<T>`の場合
	- `add(T a, T b)`
		- `a`は単調増加
		- 直線`f(x) = a*x + b`を追加する。
	- `query(T x)`
		- `x`は単調増加
		- `f(x)`の最大値を得る。

## Requirements

## Notes

## Problems

- [EDPC Z - Frog 3](https://atcoder.jp/contests/dp/tasks/dp_z) (Minクエリ)
- [Codeforces Round #464 (Div. 2) E. Maximize!](https://codeforces.com/contest/939/problem/E) (Maxクエリ)

## References

- [http://satanic0258.hatenablog.com/entry/2016/08/16/181331](http://satanic0258.hatenablog.com/entry/2016/08/16/181331)
