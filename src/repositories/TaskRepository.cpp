#include "TaskRepository.h"

std::vector<Task> TaskRepository::getAll() {
    return m_database.getAllTasks();
}

Task TaskRepository::getId(int id) {
    return m_database.getTask(id);
}

void TaskRepository::create(const Task& task) {
    
    m_database.createTask(task);
}

bool TaskRepository::update(const Task& task) {
    return m_database.updateTask(task);
}

bool TaskRepository::remove(int id) {
    return m_database.deleteTask(id) ;
}
