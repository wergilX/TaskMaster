#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>
#include "src/models/Task.h"

class Database {
public: 
    Database();
    void createTask(const Task& task);
    bool deleteTask(int id);
    bool updateTask(const Task& task);
    Task getTask(int id);
    std::vector<Task> getAllTasks();
    ~Database();

private:
    sqlite3* m_database;
};
