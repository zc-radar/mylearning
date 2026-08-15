# C++ 单例模式示例项目

这是一个基于 C++ 17 的简单单例模式示例，核心目标是演示如何通过 `Logger` 类保证全局只有一个实例，并在多线程环境中安全地记录日志。

## 项目简介

该项目实现了一个日志器单例，用于统一管理应用程序的日志输出。它具备以下特点：

- 全局唯一实例：通过 `Logger::instance()` 获取实例
- 线程安全：使用函数内静态变量实现懒加载，C++11 以后具备线程安全初始化
- 禁止拷贝和赋值：通过删除拷贝构造函数和赋值运算符确保对象唯一
- 日志输出：支持控制台输出和文件输出
- 多线程兼容：多个线程可以安全地共享同一个日志实例

## 设计思路

单例模式的核心就是让类在整个程序生命周期中只存在一个对象实例。此项目使用典型的“懒汉式”实现：

```cpp
Logger& Logger::instance() {
  static Logger logger;
  return logger;
}
```

这样做的优点是：

- 对象在第一次使用时才创建，避免启动时占用资源
- C++11 及以上标准规定，函数内静态变量初始化是线程安全的
- 通过 `private` 构造函数和删除拷贝操作，外部无法创建多个实例

## 项目结构

```text
singleton_demo/
├── Makefile
├── README.md
├── app/
│   └── main.cpp
├── include/
│   └── Logger.hpp
├── src/
│   └── Logger.cpp
└── tests/
    └── test_logger.cpp
```

## 关键文件说明

### 1. `include/Logger.hpp`

定义了 `Logger` 类的接口，主要包括：

- `static Logger& instance()`：获取唯一实例
- `void info(const std::string&)`：记录信息日志
- `void error(const std::string&)`：记录错误日志
- `bool setLogFile(const std::string&)`：设置日志文件
- `int messageCount() const`：获取日志数量
- `void closeLogFile()`：关闭日志文件

同时通过以下方式保证单例特性：

```cpp
Logger(const Logger&) = delete;
Logger& operator=(const Logger&) = delete;
```

### 2. `src/Logger.cpp`

实现了日志对象的具体行为：

- 生成时间戳
- 输出到终端
- 如果日志文件已打开，则写入文件
- 通过互斥锁保证日志写入线程安全

### 3. `app/main.cpp`

程序入口，演示：

- 获取单例实例
- 设置日志文件
- 创建多个线程并发写日志
- 记录启动与结束信息

### 4. `tests/test_logger.cpp`

对单例模式的关键行为做了测试，包括：

- 同一实例地址是否相同
- 日志数量是否递增
- 日志是否成功写入文件
- 多线程下是否仍然返回同一实例

## 运行方式

在项目根目录执行：

```bash
make
make run
```

也可以直接执行：

```bash
make test
```

运行结果会在终端输出日志，并在当前目录生成 `app.log` 文件。

## 测试说明

该项目包含一个简单的单例测试用例，运行命令如下：

```bash
make test
```

测试会验证：

- `Logger::instance()` 返回同一个对象
- `messageCount()` 正确计数
- `setLogFile()` 能正常写入文件
- 多线程访问不会创建额外实例

## 适用场景

单例模式适合用于以下场景：

- 日志管理器
- 配置管理器
- 连接池
- 资源管理器
- 全局状态对象

不过需要注意：

- 单例模式容易引入全局状态，增加测试复杂度
- 如果滥用，可能导致模块耦合过强
- 对于多线程环境，应确保实例初始化和访问是线程安全的

## 总结

这个示例项目用最小的代码展示了单例模式的核心思想：

- 只允许一个实例
- 提供统一访问入口
- 保证在并发场景下仍然安全可靠

它非常适合初学者学习 C++ 中的单例模式和线程安全设计。

## 参考命令

```bash
make clean
make
make run
make test
```
