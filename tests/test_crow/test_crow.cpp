#include "src/controllers/TaskController.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "external/crow/crow_all.h"

using namespace ::testing;

// Mock TaskService
class MockTaskService : public TaskService {
public:
    MOCK_METHOD(std::vector<Task>, getAllTasks, (), (override));
    MOCK_METHOD(Task, getIdTask, (int id), (override));
    MOCK_METHOD(void, createTask, (const Task& task), (override));
    MOCK_METHOD(void, updateTask, (int id, const Task& task), (override));
    MOCK_METHOD(void, deleteTask, (int id), (override));
};

// Test TaskController
class TaskControllerTest : public ::testing::Test {
protected:
    crow::SimpleApp app;        // Crow app for testing
    MockTaskService mockService; // Mock service
    TaskController* controller; // Controller under test

    void SetUp() override {
        controller = new TaskController(app, mockService);
    }

    void TearDown() override {
        delete controller;
    }
};

TEST_F(TaskControllerTest, GetAllTasks) {
    // Arrange: Mock response from TaskService
    std::vector<Task> tasks = { {1, "Task 1", 1}, {2, "Task 2", 2} };
    EXPECT_CALL(mockService, getAllTasks()).WillOnce(Return(tasks));

    // Act: Simulate HTTP GET request
    crow::request req;
    crow::response res;
    app.handle(req, res, "/tasks", crow::HTTPMethod::GET);

    // Assert: Check response
    EXPECT_EQ(res.code, 200);
    EXPECT_THAT(res.body, HasSubstr("Task 1"));
    EXPECT_THAT(res.body, HasSubstr("Task 2"));
}

TEST_F(TaskControllerTest, GetTaskById) {
    // Arrange: Mock response for specific task
    Task task = {1, "Task 1", 1};
    EXPECT_CALL(mockService, getIdTask(1)).WillOnce(Return(task));

    // Act: Simulate HTTP GET request with an ID
    crow::request req;
    crow::response res;
    app.handle(req, res, "/tasks/1", crow::HTTPMethod::GET);

    // Assert: Validate response
    EXPECT_EQ(res.code, 200);
    EXPECT_THAT(res.body, HasSubstr("Task 1"));
}

TEST_F(TaskControllerTest, CreateTask) {
    // Arrange: Prepare JSON body for task creation
    std::string jsonBody = R"({"name": "New Task", "priority": 3})";
    crow::request req;
    req.body = jsonBody;

    // Expect `createTask` to be called with correct parameters
    EXPECT_CALL(mockService, createTask(Property(&Task::name, "New Task")))
        .Times(1);

    // Act: Simulate HTTP POST request
    crow::response res;
    app.handle(req, res, "/tasks", crow::HTTPMethod::POST);

    // Assert: Validate response
    EXPECT_EQ(res.code, 201);
    EXPECT_THAT(res.body, HasSubstr("Task created"));
}
