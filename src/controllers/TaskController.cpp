#include "TaskController.h"

TaskController::TaskController(crow::SimpleApp &app) : taskService()
{
	defineRoutes(app);
}

void TaskController::defineRoutes(crow::SimpleApp &app)
{
	// get all
	CROW_ROUTE(app, "/tasks")
		.methods("GET"_method)([this]()
							   { return taskService.getAllTasks(); });

	// get id
	CROW_ROUTE(app, "/tasks/<int>")
		.methods("GET"_method)([this](int id)
							   { return taskService.getIdTask(id); });

	// create
	CROW_ROUTE(app, "/tasks")
		.methods("POST"_method)([this](const crow::request &req)
								{ return taskService.createTask(req.body); });

	// update
	CROW_ROUTE(app, "/tasks/<int>")
		.methods("PUT"_method)([this](const crow::request &req, int id)
							   { return taskService.updateTask(id, req.body); });

	// delete
	CROW_ROUTE(app, "/tasks/<int>")
		.methods("DELETE"_method)([this](int id)
								  { return taskService.deleteTask(id); });
};
