# 🚗 Car Rental Management System

A C++ console-based application designed to manage and automate car rental operations, user profiles, and vehicle availability.

---

## 📌 Project Overview

The **Car Rental Management System** is a lightweight system built in C++ that demonstrates Object-Oriented Programming (OOP) concepts. It enables users to browse available vehicles, manage rentals, and store client information effectively through an intuitive command-line interface.

### Key Features
* 🏎️ **Vehicle Management (`Car.h`):** Add, track, and manage vehicle details including brand, model, daily rental rate, and availability status.
* 👤 **User Management (`User.h`):** Register new users, authenticate credentials, and track rental history.
* 💻 **Interactive CLI (`main.cpp`):** Menu-driven console interface for smooth navigation and system interactions.

---

## 📁 Project Structure

```text
├── Car rent/
│   ├── Car.h          # Car class definition and logic
│   ├── User.h         # User class definition and logic
│   └── main.cpp       # Main entry point and CLI menu logic
├── Car rent.sln       # Visual Studio Solution File
└── README.md          # Project documentation
```

---

## 🛠️ Requirements & Setup

### Prerequisites
* **C++ Compiler:** GCC, Clang, or MSVC supporting C++11 or higher.
* **IDE/Build System:** Visual Studio 2019/2022 (recommended) or any C++ compatible IDE (VS Code, CLion).

### How to Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/YOUR_USERNAME/Car-Rental-Management-System.git
   cd Car-Rental-Management-System
   ```

2. **Run with Visual Studio:**
   * Open `Car rent.sln` in Visual Studio.
   * Select configuration (`Debug` / `Release`, `x64`).
   * Build and run the project using `Ctrl + F5`.

3. **Run via Terminal (GCC):**
   ```bash
   g++ -std=c++11 "Car rent/main.cpp" -o CarRentalSystem
   ./CarRentalSystem
   ```

---

## 📊 Project Presentation

The presentation for this project is available in the repository as [`Car rental managment.pptx`](./Car%20rental%20managment.pptx). 

---

## 🎯 Future Improvements
- [ ] Add persistent file storage or database integration (SQLite/JSON).
- [ ] Implement search and filtering for cars by price or model.
- [ ] Expand role-based access control (Admin vs. Customer).