#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Task {
    int priority;
    int deadline;
    string name;

    Task(int p, int d, const string& n) : priority(p), deadline(d), name(n) {}
};

class PriorityQueue {
private:
    vector<Task> tasks;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (compare(tasks[index], tasks[parentIndex])) {
                swap(tasks[index], tasks[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    bool compare(const Task& task1, const Task& task2) {
        if (task1.priority != task2.priority) {
            return task1.priority > task2.priority;
        } else {
            return task1.deadline < task2.deadline;
        }
    }

public:
    void push(const Task& task) {
        tasks.push_back(task);
        int index = tasks.size() - 1;
        heapifyUp(index);
    }

    Task pop() {
        if (tasks.empty()) {
            throw runtime_error("Queue is empty.");
        }

        Task highestPriorityTask = tasks[0];
        tasks[0] = tasks.back();
        tasks.pop_back();

        int index = 0;
        while (true) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int largestIndex = index;

            if (leftChildIndex < tasks.size() && compare(tasks[leftChildIndex], tasks[largestIndex])) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex < tasks.size() && compare(tasks[rightChildIndex], tasks[largestIndex])) {
                largestIndex = rightChildIndex;
            }

            if (largestIndex != index) {
                swap(tasks[index], tasks[largestIndex]);
                index = largestIndex;
            } else {
                break;
            }
        }

        return highestPriorityTask;
    }

    Task top() {
        if (tasks.empty()) {
            throw runtime_error("Queue is empty.");
        }
        return tasks[0];
    }

    bool empty() {
        return tasks.empty();
    }
};

int main() {
    int N;
    cin >> N;

    PriorityQueue pqueue;
    vector<Task> executedTasks;

    for (int i = 0; i < N; i++) {
        int priority, deadline;
        string name;
        cin >> priority >> deadline >> name;
        Task task(priority, deadline, name);
        pqueue.push(task);
    }

    cout << "Executed Tasks:" << endl;
    while (!pqueue.empty()) {
        Task task = pqueue.pop();
        executedTasks.push_back(task);
        cout << task.name << endl;
    }

    return 0;
}
