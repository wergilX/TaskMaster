#pragma once
#include "external/crow_all.h"
#include "src/services/TaskService.h"

class TaskController {
public:
    explicit TaskController(crow::SimpleApp& app);

private:
    TaskService taskService;

    void defineRoutes(crow::SimpleApp& app);
};
