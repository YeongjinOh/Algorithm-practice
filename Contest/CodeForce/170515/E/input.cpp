#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <queue>

void genE(std::ostream& out) {
  const int v = 1000;
  out << v + 6 << " " << 3 * v + 3 << std::endl;
  for (int i = 0; i < 6; i++) {
    out << 1 << " " << 1 + i / 3 << std::endl;
  }
  for (int i = 0; i < v; i++) {
    out << 3 << " " << 4 << std::endl;
  }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  genE(std::cout);
  return 0;
}


