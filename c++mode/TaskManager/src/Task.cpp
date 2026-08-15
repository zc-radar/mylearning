#include "Task.h"


Task::Task(int id,const std::string& title)
{
    this->id=id;
    this->title=title;
    finished=false;
}


void Task::complete()
{
    finished=true;
}


int Task::getId() const
{
    return id;
}


std::string Task::getTitle() const
{
    return title;
}


bool Task::isFinished() const
{
    return finished;
}
