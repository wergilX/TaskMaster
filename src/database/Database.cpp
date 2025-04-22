#include "Database.hpp"

Database::Database()
{
    if (sqlite3_open("TaskMaster.db", &m_database) == SQLITE_OK)
    {
        fprintf(stderr, "Opened database successfully\n");
    }
    else
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_database));
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS tasks ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT NOT NULL, "
                      "priority INTEGER NOT NULL);";

    char *errMsg;
    if (sqlite3_exec(m_database, sql, 0, 0, &errMsg) == SQLITE_OK)
    {
        std::cout << "Table created successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Error creating table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Database::createTask(const Task& task)
{
    const char* sql = "INSERT INTO tasks (name, priority) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(m_database, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, task.name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, task.priority);

        if (sqlite3_step(stmt) == SQLITE_DONE)
            std::cout << "Task created successfully!" << std::endl;
        else
            std::cerr << "Error inserting task: " << sqlite3_errmsg(m_database) << std::endl;

        sqlite3_finalize(stmt);
    }
    else
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(m_database) << std::endl;
    }
}

Task Database::getTask(int id)
{
    Task task;
    const char* sql = "SELECT id, name, priority FROM tasks WHERE id = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(m_database, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, id);
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            task.id = sqlite3_column_int(stmt, 0);
            task.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            task.priority = sqlite3_column_int(stmt, 2);
        }
        sqlite3_finalize(stmt);
    }

    return task;
}

std::vector<Task> Database::getAllTasks()
{
    std::vector<Task> tasks;
    const char* sql = "SELECT id, name, priority FROM tasks;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(m_database, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            Task task;
            task.id = sqlite3_column_int(stmt, 0);
            task.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            task.priority = sqlite3_column_int(stmt, 2);
            tasks.push_back(task);
        }
        sqlite3_finalize(stmt);
    }

    return tasks;
}


bool Database::deleteTask(int id)
{
    auto sql = "DELETE FROM tasks WHERE id=" + std::to_string(id);
    char *errMsg;
    if (sqlite3_exec(m_database, sql.c_str(), 0, 0, &errMsg) == SQLITE_OK)
    {
        std::cout << "Task deleted successfully!" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Error deleting task: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
}


bool Database::updateTask(const Task& task)
{
    const char* sql = "UPDATE tasks SET name = ?, priority = ? WHERE id = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(m_database, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, task.name.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 2, task.priority);
        sqlite3_bind_int(stmt, 3, task.id);

        if (sqlite3_step(stmt) == SQLITE_DONE)
        {
            sqlite3_finalize(stmt);
            return true;
        }
        else
        {
            std::cerr << "Error updating task: " << sqlite3_errmsg(m_database) << std::endl;
        }

        sqlite3_finalize(stmt);
    }
    return false;
}




Database::~Database()
{
    sqlite3_close(m_database);
}