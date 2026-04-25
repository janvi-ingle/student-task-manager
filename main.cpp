#include <iostream>
using namespace std;

class Task {
public:
    int id;
    string title;
    int priority;
    bool completed;
    Task* next;

    Task(int i, string t, int p) {
        id = i;
        title = t;
        priority = p;
        completed = false;
        next = NULL;
    }
};

class TaskManager {
private:
    Task* head;
    int taskCount;

public:
    TaskManager() {
        head = NULL;
        taskCount = 0;
    }

    // Add Task
    void addTask(string title, int priority) {
        taskCount++;
        Task* newTask = new Task(taskCount, title, priority);

        if (head == NULL) {
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newTask;
        }

        cout << "Task Added Successfully!\n";
    }

    // View Tasks
    void viewTasks() {
        if (head == NULL) {
            cout << "No tasks available.\n";
            return;
        }

        Task* temp = head;
        cout << "\n--- Task List ---\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | Priority: " << temp->priority
                 << " | Status: " << (temp->completed ? "Done" : "Pending")
                 << endl;

            temp = temp->next;
        }
    }

    // Mark Task Complete
    void markComplete(int id) {
        Task* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                temp->completed = true;
                cout << "Task marked as complete!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Task not found.\n";
    }
};

int main() {
    TaskManager tm;
    int choice;

    while (true) {
        cout << "\n--- Student Task Manager ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Complete\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title;
            int priority;

            cin.ignore();
            cout << "Enter task title: ";
            getline(cin, title);

            cout << "Enter priority (1-High, 2-Medium, 3-Low): ";
            cin >> priority;

            tm.addTask(title, priority);

        } else if (choice == 2) {
            tm.viewTasks();

        } else if (choice == 3) {
            int id;
            cout << "Enter task ID: ";
            cin >> id;

            tm.markComplete(id);

        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

