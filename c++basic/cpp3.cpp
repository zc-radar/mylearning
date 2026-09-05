#include <iostream>

int main() {
  // Here's some math/physics values that we copy-pasted from elsewhere
  double pi{3.14159};
  double gravity{9.8};
  double phi{1.61803};

  std::cout << pi << '\n';   // pi is used
  std::cout << phi << '\n';  // phi is used

  // The compiler will likely complain about gravity being defined but unused

  return 0;
}
