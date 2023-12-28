
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to display the to-do list
void displayTodoList(const vector<Task>& todoList) {
    cout << "\n--- To-Do List ---\n";
    cout << setw(5) << "Index" << setw(20) << "Status" << setw(5) << "Description\n";
    cout << "-----------------------------\n";

    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << setw(5) << i + 1 << setw(15) << (todoList[i].completed ? "Completed" : "Pending") << todoList[i].description << endl;
    }

    cout << "-----------------------------\n";
}

// Function to add a task to the to-do list
void addTask(vector<Task>& todoList, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& todoList, size_t index) {
    if (index < todoList.size()) {
        todoList[index].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

// Function to remove a task from the to-do list
void removeTask(vector<Task>& todoList, size_t index) {
    if (index < todoList.size()) {
        todoList.erase(todoList.begin() + index);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

int main() {
    vector<Task> todoList;

    cout << "Welcome to the To-Do List Manager!\n";

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. View To-Do List\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Choose an option (1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cin.ignore(); // Ignore any newline characters in the buffer
                    string taskDescription;
                    cout << "Enter task description: ";
                    getline(cin, taskDescription);
                    addTask(todoList, taskDescription);
                }
                break;
            case 2:
                displayTodoList(todoList);
                break;
            case 3:
                {
                    displayTodoList(todoList);
                    cout << "Enter the index of the task to mark as completed: ";
                    size_t index;
                    cin >> index;
                    markTaskCompleted(todoList, index - 1);
                }
                break;
            case 4:
                {
                    displayTodoList(todoList);
                    cout << "Enter the index of the task to remove: ";
                    size_t index;
                    cin >> index;
                    removeTask(todoList, index - 1);
                }
                break;
            case 5:
                cout << "Thank you for using the To-Do List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    }

    return 0;
}
