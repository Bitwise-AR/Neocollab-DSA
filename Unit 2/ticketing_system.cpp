#include <iostream>
using namespace std;

struct SeatNode
{
    int seatNumber;
    SeatNode *next;
};

SeatNode *insertAtFront(SeatNode *head, int seatNumber)
{
    SeatNode *newNode = new SeatNode;
    newNode->seatNumber = seatNumber;

    if (head == nullptr)
    {
        newNode->next = newNode; 
        return newNode;
    }

    SeatNode *lastNode = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    newNode->next = head;
    lastNode->next = newNode;
    return newNode;
}

SeatNode *insertAtPosition(SeatNode *head, int seatNumber, int position)
{
    if (head == nullptr || position < 1)
    {
        cout << "Invalid position." << endl;
        return head;
    }

    SeatNode *newNode = new SeatNode;
    newNode->seatNumber = seatNumber;

    if (position == 1)
    {
        newNode->next = head;
        return newNode;
    }

    SeatNode *current = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (current->next == head)
        {
            cout << "Invalid position." << endl;
            return head;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int calculateMiddlePosition(int totalSeats)
{
    return (totalSeats + 1) / 2;
}

void displayCircularLinkedList(SeatNode *head)
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    SeatNode *current = head;
    int count = 0;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    cout << "No of nodes in the CLL is " << count << endl;

    do
    {
        cout << "|" << current->seatNumber << "| --> ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

int main()
{
    SeatNode *head = nullptr;
    int n, seatNumber, middleSeat, position, positionSeat;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seatNumber;
        head = insertAtFront(head, seatNumber);
    }
    if (n == 0)
    {
        cout << "List is empty.";
    }
    else
    {
        cin >> middleSeat;
        cin >> position;
        cin >> positionSeat;
        int middlePosition = calculateMiddlePosition(n);
        head = insertAtPosition(head, middleSeat, middlePosition);
        cout << "After inserting at middle:" << endl;
        displayCircularLinkedList(head);
        head = insertAtPosition(head, positionSeat, position);
        cout << "After inserting at position " << position << ":" << endl;
        displayCircularLinkedList(head);
    }

    return 0;
}
