#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
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
            cout << temp->data << "->";
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
        head = newNode;
    }
    void insertAtMiddle(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        Node *fast = head;
        Node *slow = head;
        while (fast->next != nullptr and fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow->next;
        slow->next = newNode;
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
    }
    void deleteAtHead()
    {
        if (isEmpty())
        {
            return;
        }
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    void deleteAtTail()
    {
        if (isEmpty())
        {

            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }
};
int main()
{
    LinkedList list;
    list.display();
    list.insertAtHead(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.display();
    // list.insertAtMiddle(33);
    list.display();
    list.deleteAtHead();
    list.display();
    return 0;
}