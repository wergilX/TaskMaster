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

    // SQL command to create a table
    const char *sql = "CREATE TABLE IF NOT EXISTS tasks ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "name TEXT NOT NULL, "
                      "priority INTEGER NOT NULL);";

    // Execute the SQL command
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

void Database::createTask(Task task)
{
    // SQL statement to insert data
    const char* sql = "INSERT INTO users (name, age) VALUES ('Alice', 25), ('Bob', 30), ('Charlie', 28);";
}

Database::~Database()
{
    sqlite3_close(m_database);
}