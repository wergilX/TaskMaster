#include "TaskService.h"
#include "external/crow_all.h"


crow::json::wvalue TaskService::getAllTasks() {
    auto tasks = m_taskRepository.getAll();
    
    crow::json::wvalue::list list;
    for(auto& task : tasks)
    {
        list.push_back(task.to_json());
    }

    crow::json::wvalue json_response;
    json_response["tasks"] = std::move(list);

    return json_response;
}

crow::json::wvalue TaskService::getIdTask(int id)
{
    auto task = m_taskRepository.getId(id);
    crow::json::wvalue json_response;
    json_response["tasks"] = crow::json::wvalue::list({task.to_json()});
    return json_response;
}

crow::response TaskService::createTask(const std::string& body) {
    auto json_data = crow::json::load(body);
    if (!json_data) return crow::response(400, "Invalid JSON");

    Task new_task;
    new_task.name = json_data["name"].s();
    new_task.priority = json_data["priority"].i();

    m_taskRepository.create(new_task);
    return crow::response(201, "Task created");
}

crow::response TaskService::updateTask(int id, const std::string& body) {
    auto json_data = crow::json::load(body);
    if (!json_data) return crow::response(400, "Invalid JSON");

    Task updated_task;
    updated_task.id = id;
    updated_task.name = json_data["name"].s();
    updated_task.priority = json_data["priority"].i();

    if (m_taskRepository.update(updated_task)) {
        return crow::response(200, "Task updated");
    }
    else {
        return crow::response(404, "Task not found");
    }
}

crow::response TaskService::deleteTask(int id) {
    if (m_taskRepository.remove(id)) {
        return crow::response(200, "Task deleted");
    }
    else {
        return crow::response(404, "Task not found");
    }
}
