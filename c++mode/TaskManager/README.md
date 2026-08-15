# C++ 任务管理器小项目

这是一个基于 C++ 17 的简单面向对象设计示例，用于演示如何使用类、对象和职责分离来实现一个基础的任务管理系统。

## 项目简介

这个项目以“任务管理”为主题，主要包含以下三类对象：

- `Task`：表示一个任务对象
- `TaskManager`：负责管理任务列表
- `FileStorage`：负责保存数据的存储抽象

项目的目标是让初学者理解：

- 类如何表示真实对象
- 对象如何协作
- 数据和方法如何封装在类中
- 一个简单的业务逻辑如何拆分为多个类

## 设计思路

该项目采用了典型的面向对象编程思路，将不同职责分配到不同的类中：

- `Task` 类负责存储任务的基本信息，例如编号、标题和完成状态
- `TaskManager` 类负责管理多个任务，例如添加任务、展示任务
- `FileStorage` 类负责数据保存逻辑，当前版本中仅演示了保存接口

这种设计体现了“单一职责原则”：

- 一个类只负责一个相对明确的功能
- 业务逻辑更容易扩展和维护
- 后续可以继续增加删除、更新、过滤、持久化等功能

## 项目结构

```text
TaskManager/
├── Makefile
├── README.md
├── include/
│   ├── FileStorage.h
│   ├── Task.h
│   └── TaskManager.h
├── src/
│   ├── FileStorage.cpp
│   ├── Task.cpp
│   ├── TaskManager.cpp
│   └── main.cpp
└── task
```

## 关键类说明

### 1. `Task` 类

用于表示一个待办事项，包含以下成员：

- `id`：任务编号
- `title`：任务标题
- `finished`：任务是否完成

主要方法：

- `Task(int id, const std::string& title)`：构造函数
- `void complete()`：标记任务已完成
- `int getId() const`：获取任务编号
- `std::string getTitle() const`：获取任务标题
- `bool isFinished() const`：判断是否完成

### 2. `TaskManager` 类

用于管理一组任务，内部使用 `std::vector<Task>` 保存所有任务。

主要方法：

- `void addTask(const Task& task)`：添加新任务
- `void showTasks()`：输出所有任务

在这个版本中，任务管理器简单但完整，适合用来展示面向对象的基本组织方式。

### 3. `FileStorage` 类

这个类表示文件存储模块，主要用于处理任务持久化保存。

目前版本中只是一个接口示例：

```cpp
void save();
```

实际输出为：

```cpp
std::cout << "save data" << std::endl;
```

这说明它目前仅是一个占位实现，后续可以扩展为真正的文件读写逻辑。

## 程序入口

`src/main.cpp` 是整个项目的入口文件，演示了以下流程：

```cpp
TaskManager manager;
manager.addTask(Task(1, "Learn C++ Design"));
manager.addTask(Task(2, "Learn Makefile"));
manager.showTasks();

FileStorage storage;
storage.save();
```

运行后会输出两个任务，并调用保存逻辑。

## 运行方式

在项目根目录执行：

```bash
make
./task
```

如果需要清理编译产物：

```bash
make clean
```

## Makefile 说明

项目的 `Makefile` 使用了简单的自动编译流程：

- 编译所有 `src/*.cpp`
- 生成可执行文件 `task`
- 使用 `-Iinclude` 让编译器能找到头文件

这也是一个典型的 C++ 小项目构建方式，非常适合初学者理解编译和链接过程。

## 面向对象特征体现

这个项目简单但完整地体现了几个 OOP 核心思想：

- 封装：数据和方法放在类中
- 抽象：将任务、管理器、存储器分别抽象为对象
- 组合：`TaskManager` 通过容器管理多个 `Task` 对象
- 分层：业务逻辑与存储逻辑分开处理

## 可扩展方向

这个项目非常适合进一步扩展，后续可以加入：

- 删除任务
- 修改任务标题
- 标记任务完成状态
- 按状态筛选任务
- 从文件读取任务
- 写入 JSON 或 TXT 文件
- 任务排序功能

## 适用场景

这个项目适合用于：

- 学习类和对象的定义
- 理解对象状态和行为
- 练习 `std::vector` 在对象管理中的应用
- 初步掌握 C++ 面向对象编程思想

## 总结

这个项目是一个非常适合入门的 C++ 面向对象小例子。虽然功能简单，但它清晰展示了：

- 如何抽象业务对象
- 如何把逻辑拆分到不同类中
- 如何通过简单的交互实现一个小型管理系统

对于初学者而言，它是理解 OOP 基本思想的不错起点。

## 参考命令

```bash
make
./task
make clean
```