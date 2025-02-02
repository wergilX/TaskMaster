import pytest
import requests

BASE_URL = "http://localhost:18080"


#@pytest.fixture
#def test_create():
#    """Test item creation."""
#    response = requests.post(f"{BASE_URL}/tasks", json={"name": "TestItem"})
#    assert response.status_code == 200
#    data = response.json()
#    assert "id" in data

def test_read():
    """Test reading an existing item."""
    response = requests.get(f"{BASE_URL}/tasks")
    assert response.status_code == 200
    data = response.json()
    print(data)
    #assert data["id"] == item_id
    #assert data["name"] == "TestItem"

# Run tests
if __name__ == "__main__":
    pytest.main()
