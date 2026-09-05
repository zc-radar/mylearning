// 这个程序用于检测编译器的c++版本

#include <iostream>

const int numStandards = 7;
// c++标准代码和名称数组，c++26现在还只是一个占位符
const long stdCode[numStandards] = {199711L, 201103L, 201402L, 201703L,
                                    202002L, 202302L, 202612L};
const char* stdName[numStandards] = {"Pre-C++11", "C++11", "C++14", "C++17",
                                     "C++20",     "C++23", "C++26"};

// 返回预定义宏__cplusplus，它的值表示编译器所使用的C++标准版本
long getCPPStandard() { return __cplusplus; }

int main() {
  long standard = getCPPStandard();

  if (standard == -1) {
    std::cout << "无法确定使用的c++标准\n";
    return 0;
  }

  for (int i = 0; i < numStandards; ++i) {
    if (standard == stdCode[i]) {
      std::cout << "你的编译器用的是 " << stdName[i] << " (语言标准代号 "
                << standard << "L)\n";
      break;
    }

    if (standard < stdCode[i]) {
      std::cout << "你的编译器在用标准预览版： " << stdName[i]
                << " (语言标准代号 " << standard << "L)\n";
      break;
    }
  }

  return 0;
}
