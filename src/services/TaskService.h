#pragma once
#include "../../external/crow/crow_all.h"
#include "../repositories/TaskRepository.h"

class TaskService {
public:
	crow::response getAllTasks();
	crow::response getIdTask(int id);
	crow::response createTask(const std::string& body);
	crow::response updateTask(int id, const std::string& body);
	crow::response deleteTask(int id);

private:
	TaskRepository m_taskRepository;
};
