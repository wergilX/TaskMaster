#include "TaskController.h"

TaskController::TaskController(crow::SimpleApp& app) : taskService() {
	defineRoutes(app);
}

void TaskController::defineRoutes(crow::SimpleApp& app) {
	// get all
	CROW_ROUTE(app, "/tasks")
		.methods("GET"_method)([this]() {
		crow::response tasks = taskService.getAllTasks();
		return tasks;
			});

	// get id
	CROW_ROUTE(app, "/tasks/<int>")
		.methods("GET"_method)([this](int id) {
		auto tasks = taskService.getIdTask(id);
		//return crow::response(200, crow::json::wvalue({ {"task", tasks} }));
		return tasks;
			});

	// create
	/*CROW_ROUTE(app, "/tasks")
		.methods("POST"_method)([this](const crow::request& req) {
		auto body = crow::json::load(req.body);
		if (!body) {
			return crow::response(400, "Invalid JSON");
		}

		Task task;
		task.name = body["name"].s();
		task.priority = body["priority"].i();

		taskService.createTask(task);
		return crow::response(201, "Task created");
			});

	// update
	CROW_ROUTE(app, "/tasks/<int>")
		.methods("PUT"_method)([this](int id, const crow::request& req) {
		auto body = crow::json::load(req.body);
		if (!body) {
			return crow::response(400, "Invalid JSON");
		}

		Task task;
		task.id = body["id"].i();
		task.name = body["name"].s();
		task.priority = body["priority"].i();

		taskService.updateTask(id, task);
		return crow::response(200, "Task updated");
			});

	// delete
	CROW_ROUTE(app, "/tasks/<int>")
		.methods("DELETE"_method)([this](int id) {

		taskService.deleteTask(id);
		return crow::response(200, "Task deleted");
			});
			*/
}
