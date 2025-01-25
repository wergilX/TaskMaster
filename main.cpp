#include <iostream>
#include "external/crow/crow_all.h"

using namespace std;

int main() {
	crow::SimpleApp app;
	

	// Указываем порт и запускаем сервер
	app.port(18080).multithreaded().run();

	return 0;
}
