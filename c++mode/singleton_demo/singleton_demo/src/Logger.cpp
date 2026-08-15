#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

Logger::Logger() : message_count_(0) {
  std::cout << "[Logger] 单例对象创建成功\n";
}

Logger::~Logger() {
  closeLogFile();
  std::cout << "[Logger] 单例对象销毁\n";
}

Logger& Logger::instance() {
  // C++11 起，函数内静态变量初始化是线程安全的
  static Logger logger;
  return logger;
}

bool Logger::setLogFile(const std::string& filename) {
  std::lock_guard<std::mutex> lock(mutex_);

  if (file_.is_open()) {
    file_.close();
  }

  file_.open(filename, std::ios::out | std::ios::app);

  if (!file_.is_open()) {
    std::cerr << "无法打开日志文件: " << filename << '\n';
    return false;
  }

  return true;
}

void Logger::closeLogFile() {
  std::lock_guard<std::mutex> lock(mutex_);

  if (file_.is_open()) {
    file_.close();
  }
}

void Logger::info(const std::string& message) { write("INFO", message); }

void Logger::error(const std::string& message) { write("ERROR", message); }

int Logger::messageCount() const {
  std::lock_guard<std::mutex> lock(mutex_);
  return message_count_;
}

void Logger::write(const std::string& level, const std::string& message) {
  std::lock_guard<std::mutex> lock(mutex_);

  const std::string log = "[" + currentTime() +
                          "]"
                          "[" +
                          level + "] " + message;

  // 输出到终端
  std::cout << log << '\n';

  // 如果配置了日志文件，则写文件
  if (file_.is_open()) {
    file_ << log << '\n';
    file_.flush();
  }

  ++message_count_;
}

std::string Logger::currentTime() const {
  const auto now = std::chrono::system_clock::now();
  const std::time_t now_time = std::chrono::system_clock::to_time_t(now);

  std::tm local_tm{};

#ifdef _WIN32
  localtime_s(&local_tm, &now_time);
#else
  localtime_r(&now_time, &local_tm);
#endif

  std::ostringstream oss;
  oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");

  return oss.str();
}