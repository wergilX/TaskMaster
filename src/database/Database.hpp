#pragma once
#include <sqlite3.h>
#include <string>
#include "src/models/Task.h"

class Database{
public: 
    Database();
    void createTask(Task task);
    ~Database();
private:
    sqlite3* m_database;
};

