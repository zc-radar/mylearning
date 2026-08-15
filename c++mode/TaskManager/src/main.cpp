#include "TaskManager.h"
#include "FileStorage.h"


int main()
{

    TaskManager manager;


    manager.addTask(
        Task(1,"Learn C++ Design")
    );


    manager.addTask(
        Task(2,"Learn Makefile")
    );


    manager.showTasks();


    FileStorage storage;

    storage.save();


    return 0;
}