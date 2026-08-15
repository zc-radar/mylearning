#include <iostream>
#include <thread>
#include <vector>

#include "Logger.hpp"

void worker(int id) {
  Logger& logger = Logger::instance();

  for (int i = 0; i < 3; ++i) {
    logger.info("线程 " + std::to_string(id) +
                " 正在执行任务，次数: " + std::to_string(i));
  }
}

int main() {
  Logger& logger = Logger::instance();

  if (!logger.setLogFile("app.log")) {
    std::cerr << "日志文件打开失败，将只输出到终端。\n";
  }

  logger.info("应用程序启动");
  logger.info("准备创建工作线程");

  std::vector<std::thread> threads;

  for (int i = 0; i < 4; ++i) {
    threads.emplace_back(worker, i);
  }

  for (auto& thread : threads) {
    thread.join();
  }

  logger.info("所有线程执行完成");
  logger.error("这是一个示例错误日志");

  std::cout << "\n总日志数: " << logger.messageCount() << '\n';

  return 0;
}