#include "TaskManager.h"
#include <iostream>


void TaskManager::addTask(const Task& task)
{
    tasks.push_back(task);
}



void TaskManager::showTasks()
{

    for(auto& task:tasks)
    {
        std::cout
        << task.getId()
        << " "
        << task.getTitle()
        << std::endl;
    }

}