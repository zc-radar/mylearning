#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "Logger.hpp"

void testSingletonAddress() {
  Logger& logger1 = Logger::instance();
  Logger& logger2 = Logger::instance();

  // 两次获得的地址必须相同
  assert(&logger1 == &logger2);

  std::cout << "[PASS] testSingletonAddress\n";
}

void testMessageCount() {
  Logger& logger = Logger::instance();

  const int before = logger.messageCount();

  logger.info("测试 info 日志");
  logger.error("测试 error 日志");

  const int after = logger.messageCount();

  assert(after == before + 2);

  std::cout << "[PASS] testMessageCount\n";
}

void testLogFile() {
  const std::string filename = "test_logger.log";

  Logger& logger = Logger::instance();

  // 先删除之前可能残留的文件
  std::remove(filename.c_str());

  const bool opened = logger.setLogFile(filename);
  assert(opened);

  const std::string test_text = "这是一条写入文件的测试日志";
  logger.info(test_text);
  logger.closeLogFile();

  std::ifstream file(filename);
  assert(file.is_open());

  std::string content;
  std::string line;

  while (std::getline(file, line)) {
    content += line + "\n";
  }

  file.close();

  // 检查日志内容是否写进了文件
  assert(content.find(test_text) != std::string::npos);

  std::cout << "[PASS] testLogFile\n";
}

void testMultiThreadSingleton() {
  constexpr int thread_count = 10;

  std::vector<Logger*> addresses(thread_count);
  std::vector<std::thread> threads;

  for (int i = 0; i < thread_count; ++i) {
    threads.emplace_back(
        [&addresses, i]() { addresses[i] = &Logger::instance(); });
  }

  for (auto& thread : threads) {
    thread.join();
  }

  for (int i = 1; i < thread_count; ++i) {
    // 多线程下拿到的对象仍必须是同一个
    assert(addresses[i] == addresses[0]);
  }

  std::cout << "[PASS] testMultiThreadSingleton\n";
}

int main() {
  std::cout << "开始执行 Logger 单例测试...\n\n";

  testSingletonAddress();
  testMessageCount();
  testLogFile();
  testMultiThreadSingleton();

  std::cout << "\n所有测试通过！\n";

  return 0;
}