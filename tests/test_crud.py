import requests

BASE_URL = "http://localhost:18080"

def test_create_task():
    """Test creating a new task."""
    url = f"{BASE_URL}/tasks"
    data = {
        "name": "New Task",
        "priority": 2
    }

    response = requests.post(url, json=data)
    print(response.status_code, response.text)
    print("✅ Created")

def test_get_all_tasks():
    """Test retrieving all tasks."""
    url = f"{BASE_URL}/tasks"
    
    response = requests.get(url)
    print(response.status_code, response.text)
    print("✅ Get all")

def test_get_task_by_id():
    """Test retrieving a task by ID."""
    url = f"{BASE_URL}/tasks/{1}"
    
    response = requests.get(url)
    print(response.status_code, response.text)
    print("✅ Get by id")


def test_update_task():
    url = f"{BASE_URL}/tasks/{1}"
    data = {
        "name": "Updated Task",
        "priority": 2
    }

    response = requests.put(url, json=data)
    print(response.status_code, response.text)
    print("✅ Updated")

def test_delete_task():
    url = f"{BASE_URL}/tasks/{1}"

    response = requests.delete(url)
    print(response.status_code, response.text)
    print("✅ Deleted")


if __name__ == "__main__":
    test_create_task()
    test_get_all_tasks()
    test_get_task_by_id()
    test_update_task()
    test_delete_task()
