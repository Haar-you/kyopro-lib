---
title: Euler tour (BFS)
documentation_of: Mylib/Graph/TreeUtils/euler_tour_bfs.cpp
---

## Operations

- `EulerTourBFS(tree, int root)`
- `query_children(int i, int d, f)`
	- `i`の`d`個下の子孫に`f`を適用する。
- `query_at(int i, f)`
	- `query_children(i, 0, f)`と同等。
- `get_parent`
	- `i`の親を返す。
- `get_ancestor(int i, int k)`
	- `i`の`k`個遡った祖先を返す。
	- `get_ancestor(i, 0) = i`
	- `get_ancestor(i, 1) = get_parent(i)`
	- Time complexity $O(k)$

## Requirements

## Notes

## Problems

- [yukicoder No.899 γatheree](https://yukicoder.me/problems/no/899)

## References

- [https://niuez.hatenablog.com/entry/2019/10/05/002503](https://niuez.hatenablog.com/entry/2019/10/05/002503)
- [https://niuez.github.io/posts/entry/2019/10/05/002503/](https://niuez.github.io/posts/entry/2019/10/05/002503/)

