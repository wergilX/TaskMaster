# TaskMaster

**TaskMaster** is a cross-platform task tracker focused on performance and scalability.

---

## Main Components

### Backend API (C++)
- **Framework:** Using **Drogon** or **Crow** to create a RESTful API.
- **Features:**
  - User authentication (JWT).
  - CRUD (Create, Read, Update, Delete) for tasks.
  - WebSocket support for real-time notifications.
- **Why C++?**
  - High performance.
  - Good integration with modern databases like PostgreSQL or SQLite.

### Database
- **Data Models:** Using a C++ ORM like **Oat++** or built-in SQL libraries.
- **System:** PostgreSQL or SQLite.
- **Example Data Structure:**
  - Tables: `users`, `tasks`, `projects`, `notifications`.

### Desktop Application (C++ with Qt)
- **Platforms:** Windows, Linux, macOS.
- **Features:**
  - Kanban board.
  - Task sorting and filtering.
  - Data visualization (charts and graphs with **Qt Charts**).
- **Key Aspects:**
  - Connects to Backend API via HTTP/HTTPS.
  - Works offline with a local database (SQLite) and syncs later.
- **Why Qt?**
  - Powerful tool for cross-platform GUI applications.

### Mobile Application (C++ + Flutter)
- **Core Logic:** Business logic written in C++ (via FFI).
- **UI:** Built with Flutter for cross-platform support.
- **Features:**
  - Task management on the go.
  - Push notifications (via Firebase).

### Notification System (C++)
- **Uses:** **Boost.Asio** for network communication.
- **Features:**
  - Push notifications and email reminders.
- **Why C++?**
  - Efficient handling of asynchronous operations.

### External Service Integrations (Python)
- Python is used for quick integration with external services:
  - Google Calendar (task synchronization).
  - Telegram Bot (task management via messenger).
- **Why Python?**
  - Ease of working with external APIs.
  - Fast implementation.

### Reporting & Analytics (C++ + Python)
- **Data Processing:** C++ (using **Eigen** for math operations).
- **Visualization:** Python (**Matplotlib**, **ReportLab** for PDF reports).
- **Example Reports:**
  - Task completion charts.
  - Average task completion time.

### Deployment Automation (Docker + CMake)
- **Containerization:** Using Docker for Backend API, database, and other components.
- **Build System:** CMake for cross-platform compatibility.
- **CI/CD:** GitHub Actions for automated deployment.

---

## Project Goals

1. **Deepen C++ Skills:**
   - Multithreading (Boost.Asio).
   - ORM, HTTP frameworks, asynchronous programming.
2. **Master Qt:**
   - Develop a fully functional GUI application.
3. **Focus on Cross-Platform Development:**
   - Support for Windows, Linux and Android.
4. **Utilize Modern Tools:**
   - Docker, CI/CD, OAuth2 for authentication.

---

## Phase 1: Developing the Core Application

### 1. Implementing a Minimal Backend API in C++ (Task CRUD)

   - Create (POST)
   - Read (GET)
   - Update (PUT)
   - Delete (DELETE)

### 2. Creating a Prototype Desktop Application with Basic Features

   - Implement UI for task management (view, add, edit, delete).
   - Set up basic integration with the Backend API.

### 3. Integrating SQLite for Offline Mode

   - Set up a local SQLite database for task storage.
   - Implement data synchronization with the Backend API.

### 4. Setting Up Docker for Deployment

   - Create a Docker container for the Backend API.
   - Set up Docker Compose for database integration.

### Phase 1: Outcome

   - [ ] Working C++ Backend API with CRUD for tasks.
   - [ ] Prototype desktop application with basic features.
   - [ ] SQLite integration for offline mode.
   - [ ] Docker setup for deployment.

---

## Phase 2: Expanding Functionality

### 1. Authentication and Authorization

   - Implement user registration and authentication.
   - Add user roles (e.g., administrator, user).
   - Protect API routes requiring authentication.

### 2. Adding Synchronization Between Offline and Online Modes

   - Implement a synchronization mechanism between the local SQLite database and the server.

### 3. Notifications and Reminders

   - Add local notifications for tasks.
   - Implement support for push notifications for a future mobile app.
    
### 4. Task Visualization

   - Enhance the desktop interface for task management.
   - Introduce a Kanban board view for tasks.

### 5. Initial Deployment Automation

   - Set up an initial CI/CD system for automated build and deployment.

### Phase 2 Outcome

   - [ ] Authentication and synchronization between client and server added.
   - [ ] Desktop application functionalities expanded (Kanban board, notifications).
   - [ ] Initial CI/CD setup for automated build and testing.

---

## Phase 3: Advanced Functionality

### 1. Reports and Analytics

   - Implement reports on user performance (e.g., completed tasks per week).
   - Create charts and graphs.
    
### 2. Extended Integration with External Services
    
   - Integration with Google Calendar for event synchronization.
   - Webhooks for third-party applications.

### 3. Offline Mode with Automatic Recovery

   - Fully autonomous operation mode so the application does not rely on a server connection.

### 4. Mobile Application

   - Begin developing a mobile application (Flutter/Dart).
   - Synchronize it with the Backend API.

### 5. CI/CD Improvements

   - Fully automated application deployment on the server.
   - Add monitoring and logging.

### 6. Database Expansion

   - Migrate from SQLite to PostgreSQL for scalability.
   - Implement database backups.

---

## Phase 4: Optimization and Release Preparation

### 1. Code and Performance Optimization

   - Perform profiling and eliminate bottlenecks.
   - Minimize API request latency.

### 2. Testing

   - Write comprehensive unit tests and integration tests for the API and application.
   - Conduct load testing for the Backend.

### 3. Release Preparation

   - Configure the distribution package for the desktop application.
   - Deploy the Backend API on a production server.
   - Prepare documentation for users and developers.