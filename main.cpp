#include <iostream>
#include "external/crow_all.h"
#include "src/controllers/TaskController.h"

using namespace std;

int main() {
	crow::SimpleApp app;
	TaskController tc(app);
	app.port(8080).multithreaded().run();

	return 0;
}
