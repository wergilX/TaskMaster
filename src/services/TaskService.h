#pragma once
#include "external/crow_all.h"
#include "src/repositories/TaskRepository.h"

class TaskService {
public:
	crow::json::wvalue getAllTasks();
	crow::json::wvalue getIdTask(int id);
	crow::response createTask(const std::string& body);
	crow::response updateTask(int id, const std::string& body);
	crow::response deleteTask(int id);

private:
	TaskRepository m_taskRepository;
};
