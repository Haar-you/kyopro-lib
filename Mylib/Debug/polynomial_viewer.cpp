#pragma once
#include <iostream>
#include <string>

template <typename Container>
class PolynomialViewer {
  Container data;

public:
  PolynomialViewer(Container data) : data(data) {}

  void show_x(std::ostream &s, int k) const {
    if (k == 0)
      return;
    else if (k == 1)
      s << "x";
    else {
      s << "x";

      constexpr static auto p = "⁰¹²³⁴⁵⁶⁷⁸⁹";
      for (char c : std::to_string(k)) {
        int i = c - '0';
        if (i == 0)
          s << p[i] << p[i + 1] << p[i + 2];
        else if (1 <= i and i <= 3)
          s << p[1 + i * 2] << p[2 + i * 2];
        else
          s << p[i * 3 - 3] << p[i * 3 - 2] << p[i * 3 - 1];
      }
    }
  }

  auto &run(std::ostream &s) const {
    const int n = data.size();

    for (int i = 0; i < n; ++i) {
      s << data[i];
      show_x(s, i);
      s << " ";
    }

    return s;
  }

  friend std::ostream &operator<<(std::ostream &s, const PolynomialViewer &a) {
    return a.run(s);
  }
};
