---
title: Segment tree beats
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp
---

## Operations

- `SegmentTreeBeats(n)`
- `chmin(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow \min(a_i, v)$で更新。
- `chmax(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow \max(a_i, v)$で更新。
- `add(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow a_i + v$で更新。
- `get_sum(l, r)`
	- $\sum_{l \le i \lt r} a_i$を返す。
- `init_with_vector(a)`

## Requirements

## Notes

## Problems

- [Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)

## References

- [https://codeforces.com/blog/entry/57319](https://codeforces.com/blog/entry/57319)
- [https://smijake3.hatenablog.com/entry/2019/04/28/021457](https://smijake3.hatenablog.com/entry/2019/04/28/021457)

