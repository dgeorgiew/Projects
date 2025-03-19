#include <iostream>
#include <fstream>  // For file handling
#include <limits>
#include "list.h"

using namespace std;

// Function to display the menu
void ToDoList::showMenu() {
    cout << "\n===== TO-DO LIST =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// Function to add a task
void ToDoList::addTask() {
    cout << "Enter task description: ";
    cin.ignore(); // Clears newline character from previous input
    string task;
    getline(cin, task); // Get entire line input
    tasks.push_back(task); // Add task to the list
    cout << "Task added!\n";
}

// Function to view all tasks
void ToDoList::viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "\nYour Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl; // Display tasks with numbering
        }
    }
}

// Function to remove a task
void ToDoList::removeTask() {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
    } else {
        int taskNumber;
        cout << "Enter task number to remove: ";
        cin >> taskNumber;

        // Validate task number input
        if (cin.fail() || taskNumber < 1 || taskNumber > tasks.size()) {
            cin.clear();  // Clears error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
            cout << "Invalid task number.\n";
        } else {
            tasks.erase(tasks.begin() + (taskNumber - 1)); // Remove selected task
            cout << "Task removed!\n";
        }
    }
}

// Function to save tasks to a file
void ToDoList::saveTasks() {
    ofstream file("tasks.txt");  // Open a file for writing
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task << endl;  // Write each task on a new line
        }
        file.close();  // Close the file
        cout << "Tasks saved!\n";
    } else {
        cout << "Error saving tasks to file.\n";
    }
}

// Function to load tasks from a file
void ToDoList::loadTasks() {
    ifstream file("tasks.txt");  // Open a file for reading
    string task;
    if (file.is_open()) {
        while (getline(file, task)) {  // Read tasks line by line
            tasks.push_back(task);     // Add each task to the list
        }
        file.close();  // Close the file
    } else {
        cout << "No saved tasks found.\n";
    }
}

// Main loop for running the program
void ToDoList::run() {
    loadTasks();  // Load tasks from file at the start

    int choice; // Stores user menu selection

    while (true) { // Infinite loop to keep the menu running
        showMenu(); // Display menu options
        cin >> choice;

        // Input validation to prevent non-integer inputs
        if (cin.fail()) {
            cin.clear();  // Clears error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
            cout << "Invalid input. Please enter a number between 1-4.\n";
            continue;
        }

        // Handle menu choices
        if (choice == 1) {
            addTask();  // Add Task
        } else if (choice == 2) {
            viewTasks();  // View Tasks
        } else if (choice == 3) {
            removeTask();  // Remove Task
        } else if (choice == 4) {
            saveTasks();  // Save tasks before exiting
            cout << "Exiting program. Goodbye!\n";
            break;  // Exit the loop
        } else {
            cout << "Invalid choice. Please enter a number between 1-4.\n";
        }
    }
}
