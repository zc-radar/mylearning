#include <cmath>
#include <iostream>

int main() {
  double angle = 45.0;
  // 注意：三角函数的参数是弧度，这里将角度转为弧度
  double radians = angle * M_PI / 180.0;

  // 计算正弦
  double sine_value = sin(radians);
  // 计算平方根
  double sqrt_value = sqrt(16.0);
  // 计算幂（2的3次方）
  double power_value = pow(2.0, 3.0);

  std::cout << "45度的正弦值: " << sine_value << std::endl;
  std::cout << "16的平方根: " << sqrt_value << std::endl;
  std::cout << "2的3次方: " << power_value << std::endl;

  return 0;
}
