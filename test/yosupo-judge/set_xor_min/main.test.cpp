#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "Mylib/DataStructure/Trie/binary_trie.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q;
  std::cin >> Q;

  hl::binary_trie<uint32_t, 32> t;

  for (auto [type, x] : hl::input_tuples<int, uint32_t>(Q)) {
    switch (type) {
      case 0:
        if (t.count(x) == 0) t.insert(x);
        break;
      case 1:
        if (t.count(x) == 1) t.erase(x);
        break;
      case 2:
        std::cout << (t.min_element(x) ^ x) << "\n";
        break;
    }
  }

  return 0;
}
