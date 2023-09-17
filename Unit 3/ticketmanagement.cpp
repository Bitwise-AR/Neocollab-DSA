#include <iostream>
using namespace std;

const int max_capacity = 5; // maximum capacity of the queue

class Queue
{
private:
    int front;               // index of the front element
    int rear;                // index of the rear element
    int items[max_capacity]; // array to store the queue elements

public:
    Queue()
    {
        front = -1; // initialize the front index
        rear = -1;  // initialize the rear index
    }

    bool isFull()
    {
        return (rear == max_capacity - 1);
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0; // set front and rear to 0 for the first element
            }
            else
            {
                rear++; // increment the rear index
            }
            items[rear] = element; // insert the element at the rear index
            cout << element << " is inserted in the queue." << endl;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else
        {
            int deletedNumber = items[front]; // store the front element to return later
            if (front == rear)
            {
                // if there is only one element in the queue
                front = rear = -1; // reset front and rear to -1
            }
            else
            {
                front++; // increment the front index
            }
            return deletedNumber;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Elements in the queue are: ";
            for (int i = front; i <= rear; i++)
            {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue queue;

    int option;

    while (cin >> option)
    {
        if (option == 1)
        {
            int element;
            cin >> element;
            queue.enqueue(element);
        }
        else if (option == 2)
        {
            int deletedNumber = queue.dequeue();
            if (deletedNumber != -1)
            {
                cout << "Deleted number is: " << deletedNumber << endl;
            }
        }
        else if (option == 3)
        {
            queue.display();
        }
        else
        {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}