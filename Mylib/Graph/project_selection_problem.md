## Operations

- `ProjectSelectionProblem(N)`
- `penalty_if_red(int i, T c)`
	- `i`を<font color="red">赤</font>に塗ると`c`の損失になる。
- `gain_if_red(int i, T c)`
	- `i`を<font color="red">赤</font>に塗ると`c`の利益を得る。
- `penalty_if_blue(int i, T c)`
	- `i`を<font color="blue">青</font>に塗ると`c`の損失になる。
- `gain_if_blue(int i, T c)`
	- `i`を<font color="blue">青</font>にぬると`c`の利益を得る。
- `penalty_if_red_blue(int i, int j, T c)`
	- `i`を<font color="red">赤</font>、且つ`j`を<font color="blue">青</font>に塗ると`c`の損失になる。
- `penalty_if_different(int i, int j, T c)`
	- `i`と`j`の色が異なると`c`の損失になる。
- `must_be_red(int i)`
	- `i`は<font color="red">赤</font>でなければならない。
- `must_be_blue(int i)`
	- `i`は<font color="blue">青</font>でなければならない。
- `if_red_then_must_be_red(int i, int j)`
	- `i`が<font color="red">赤</font>ならば、`j`は<font color="red">赤</font>でなければならない。
- `gain_if_red_red(int i, int j, T c)`
	- `i`と`j`をともに<font color="red">赤</font>に塗ると`c`の利益を得る。
- `gain_if_blue_blue(int i, int j, T c)`
	- `i`と`j`をともに<font color="blue">青</font>に塗ると`c`の利益を得る。
- `solve()`

## Requirements

- 頂点`s`は<font color="red">赤</font>に、頂点`t`は<font color="blue">青</font>に塗られる。

## Notes

## Problems

- [ARC 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AOJ 3058 Ghost](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058)
- [AOJ 2903 Board](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903)

## References

- [https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/](https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/)
- [https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html](https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html)
- [https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C](https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C)
