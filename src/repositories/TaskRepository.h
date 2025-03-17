#pragma once
#include "src/models/Task.h"
#include "src/database/Database.hpp"
#include <vector>

class TaskRepository {
public:
	
	std::vector<Task> getAll();
	Task getId(int id);
	void create(const Task& task);
	bool update(const Task& task);
	bool remove(int id);
private:
	Database m_database;
};
