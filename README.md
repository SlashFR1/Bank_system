To complete your project at a high engineering standard, here is the updated **README.md**. It now includes the **GUI (Qt) component**, the **CMake build system**, and the specific **libraries/dependencies** required for different operating systems.

***

```markdown
# Advanced Bank Management System (C++ OOP & Qt GUI)

## 📌 Project Overview
This project is a modular **Bank Management System** developed in C++ using Object-Oriented Programming (OOP) principles. It has evolved from a simple CLI to a professional **Desktop Application** using the **Qt Framework**.

The system simulates a real-world banking environment where different types of accounts (Savings and Checking) coexist, transactions are logged, and data is persisted into external CSV files.

---

## 🛠 File Structure & Roles

The project follows a **Model-View-Controller (MVC)** inspired architecture to ensure a "Separation of Concerns" (SoC).

### 1. Core Logic & Data (The Model)
*   **`Transaction.h`**: A structure recording metadata of financial movements (Type, Amount, Timestamp).
*   **`Account.h`**: The **Abstract Base Class (ABC)** defining the blueprint for all accounts using **Encapsulation**.
*   **`SavingsAccount.h` / `CheckingAccount.h`**: Derived classes implementing specific banking rules (Interest rates vs. Overdraft limits).

### 2. System Management (The Controller)
*   **`Bank.h` / `Bank.cpp`**: The engine that manages the `std::vector` of smart pointers (`unique_ptr`). It handles account searching and **CSV File I/O**.

### 3. Graphical User Interface (The View)
*   **`MainWindow.h` / `MainWindow.cpp`**: Implements the desktop window, buttons, and input fields. It uses **Qt Signals & Slots** to communicate with the `Bank` logic.
*   **`main.cpp`**: The entry point that initializes the Qt Application loop.

### 4. Build System
*   **`CMakeLists.txt`**: The configuration file that manages dependencies, Meta-Object Compiler (MOC) generation, and linking.

---

## 📦 Requirements & Installation

To build the GUI version, you must install the **Qt Framework** and **CMake**.

### 1. Install Dependencies
#### **Windows**
1. Download the [Qt Online Installer](https://www.qt.io/download-open-source).
2. Install **Qt 6.x** and **MinGW** (or MSVC) compiler.
3. Install [CMake](https://cmake.org/download/).

#### **macOS**
```bash
brew install qt cmake
```

#### **Linux (Ubuntu/Debian)**
```bash
sudo apt update
sudo apt install build-essential qt6-base-dev cmake
```

---

## 🚀 How to Compile and Run

Because this project uses the Qt Framework, standard `g++` commands will not work. You must use **CMake**.

### Option A: Professional CLI Way (Recommended)
Navigate to the project root folder:

```bash
# 1. Create a dedicated build directory
mkdir build
cd build

# 2. Configure the project
cmake ..

# 3. Build the executable
# (Use 'make' on Linux/Mac or 'cmake --build .' on Windows)
make

# 4. Launch the application
./BankSystemGUI
```

### Option B: IDE Way
1. Open **Qt Creator**.
2. Select **Open Project** and browse to the `CMakeLists.txt` file.
3. Select your kit (Compiler).
4. Click the **Green Play Button** (Run).

---

## ⚙️ Engineering Concepts Applied

1.  **Polymorphism**: All accounts are stored as `Account*` pointers. The app calls the correct `withdraw()` logic at runtime based on the object type.
2.  **RAII & Smart Pointers**: `std::unique_ptr` ensures zero memory leaks. Memory is automatically reclaimed when an account is closed or the app exits.
3.  **Event-Driven Programming**: The GUI does not run linearly; it waits for "Events" (button clicks) and processes them via the **Qt Event Loop**.
4.  **Data Persistence**: Account states are synchronized with `bank_data.csv` for interoperability with tools like Excel or Python.
5.  **MOC (Meta-Object Compiler)**: Utilized Qt's pre-processor to enable advanced introspection and signal-handling capabilities.

---

## 📊 How to Use the GUI
1.  **Launch**: The window opens showing the current bank database.
2.  **Selection**: Enter the **Account ID** and the **Amount** in the respective text fields.
3.  **Action**: Click **Deposit** or **Withdraw**. The balance updates instantly on the screen.
4.  **Validation**: If you attempt to withdraw more than the limit, a **QMessageBox** (Pop-up) will appear with an error message.
5.  **Save**: Closing the window automatically triggers the `saveToFile()` function.

---

## 📈 Future Improvements
- [ ] **Thread Safety**: Implement `QMutex` to allow safe operations from multiple background threads.
- [ ] **Styling**: Use **Qt Style Sheets (QSS)** to create a modern dark-mode interface.
- [ ] **Security**: Implement XOR encryption for the saved CSV data.
```

***

### Final Engineering Tip:
When you hand this in, make sure your folder contains **all** the `.h` and `.cpp` files, and the `CMakeLists.txt`. This shows you understand how professional C++ software is packaged and distributed!