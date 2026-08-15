#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <mutex>
#include <string>

class Logger {
 public:
  // 获取全局唯一 Logger 实例
  static Logger& instance();

  // 禁止复制和赋值，确保只能存在一个实例
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;

  // 写入日志
  void info(const std::string& message);
  void error(const std::string& message);

  // 设置日志输出文件
  // 文件为空时，只打印到终端
  bool setLogFile(const std::string& filename);

  // 用于测试：获取当前写入的日志数量
  int messageCount() const;

  // 用于测试：关闭当前日志文件
  void closeLogFile();

 private:
  Logger();
  ~Logger();

  void write(const std::string& level, const std::string& message);
  std::string currentTime() const;

 private:
  mutable std::mutex mutex_;
  std::ofstream file_;
  int message_count_;
};

#endif