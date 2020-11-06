---
title: Partially persistent union-find
documentation_of: ./partially_persistent_unionfind.cpp
---

## Operations

- `PartiallyPersistentUnionFind(N)`
- `root_of(int i, int t)`
	- 時刻`t`での`i`の属する連結成分のrootを返す。
- `is_same(int u, int v, int t)`
	- 時刻`t`での`u`と`v`が同じ連結成分に属するかを判定する。
- `size_of(int u, int t)`
	- 時刻`t`での`u`が属する連結成分の大きさを返す。
- `merge(int u, int v)`
	- 最新の状態で`u`と`v`を連結する。

## Requirements

## Notes

## Problems

- [CODE THANKS FESTIVAL 2017 H - Union Sets](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h)
- [AGC 002 D - Stamp Rally](https://atcoder.jp/contests/agc002/tasks/agc002_d)

## References

- [https://camypaper.bitbucket.io/2016/12/18/adc2016/](https://camypaper.bitbucket.io/2016/12/18/adc2016/)
