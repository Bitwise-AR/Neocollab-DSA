#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

int getDecimalValue(Node *head)
{
    int dec = 0;

    while (head != nullptr)
    {
        dec = (dec << 1) | head->val;
        head = head->next;
    }

    return dec;
}

int main()
{
    Node *head = nullptr;
    Node *curr = nullptr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Node *newNode = new Node;
        newNode->val = val;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            curr = newNode;
        }
        else
        {
            curr->next = newNode;
            curr = newNode;
        }
    }

    int dec = getDecimalValue(head);

    if (n == 0)
    {
        cout << "Linked List: Empty linked list" << endl;
    }
    else
    {
        cout << "Linked List: ";
        curr = head;
        while (curr != nullptr)
        {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << endl;
    }

    cout << "Decimal Value: " << dec << endl;

    while (head != nullptr)
    {
        curr = head;
        head = head->next;
        delete curr;
    }

    return 0;
}
