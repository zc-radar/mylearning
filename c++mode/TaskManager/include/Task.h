#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
private:
    int id;
    std::string title;
    bool finished;

public:

    Task(int id, const std::string& title);

    void complete();

    int getId() const;

    std::string getTitle() const;

    bool isFinished() const;
};

#endif