#pragma once
#include<vector>
class TaskRepository {
public:
	
	std::vector<Task> getAll();
	Task getId(int id);
	void create(const Task& task);
	bool update(const Task& task);
	bool remove(int id);
private:

};
