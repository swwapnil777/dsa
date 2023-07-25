#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "nullptr";
        cout << endl;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtMiddle(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        Node *slow = head;
        Node *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        newNode->next = slow->next;
        if (slow->next != nullptr)
        {
            slow->next->prev = newNode;
        }
        slow->next = newNode;
        newNode->prev = slow;
    }

    void deleteAtHead()
    {
        if (isEmpty())
        {
            return;
        }
        Node *toDelete = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete toDelete;
    }

    void deleteAtMiddle()
    {
        if (isEmpty())
        {
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == head)
        {
            deleteAtHead();
            return;
        }

        slow->prev->next = slow->next;
        if (slow->next != nullptr)
        {
            slow->next->prev = slow->prev;
        }
        delete slow;
    }
};

int main()
{
    DoublyLinkedList list;
    list.display();
    list.insertAtHead(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.display();

    list.insertAtMiddle(6);
    list.display();

    list.deleteAtMiddle();
    list.display();

    return 0;
}
