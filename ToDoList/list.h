#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>

class ToDoList {
public:
    void showMenu();                 // Displays the menu
    void addTask();                  // Adds a task to the list
    void viewTasks();                // Displays all tasks
    void removeTask();               // Removes a task
    void run();                      // Starts the main loop
    void saveTasks();                // Saves tasks to a file
    void loadTasks();                // Loads tasks from a file

private:
    std::vector<std::string> tasks;  // Container to hold tasks
};

#endif

