#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>


class TaskManager
{

private:

    std::vector<Task> tasks;


public:

    void addTask(const Task& task);

    void showTasks();

};


#endif