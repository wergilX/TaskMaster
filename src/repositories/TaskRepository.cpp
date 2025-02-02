#include "TaskRepository.h"
#include "external/json.hpp"

std::vector<Task> TaskRepository::getAll() {
    // Заглушка: Реальная реализация будет работать с БД
    return { Task{1, "Task 1", 3}, Task{2, "Task 2", 1} };
}

Task TaskRepository::getId(int id) {
    // Заглушка: Реальная реализация будет работать с БД
    return Task{id, "Task " + std::to_string(id), 3};
}

void TaskRepository::create(const Task& task) {
    // Реализация для добавления задачи в БД
}

bool TaskRepository::update(const Task& task) {
    // Реализация для обновления задачи в БД
    return true; // Заглушка
}

bool TaskRepository::remove(int id) {
    // Реализация для удаления задачи из БД
    return true; // Заглушка
}
