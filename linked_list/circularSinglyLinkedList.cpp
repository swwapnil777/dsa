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
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "nullptr" << endl;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            insertAtHead(data);
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtMiddle(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            insertAtHead(data);
            return;
        }

        Node *slow = head;
        Node *fast = head;
        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        newNode->next = slow->next;
        slow->next = newNode;
    }

    void deleteAtHead()
    {
        if (isEmpty())
        {
            return;
        }

        Node *toDelete = head;

        if (head->next == head)
        {
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
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
        Node *prev = nullptr;

        while (fast->next != head && fast->next->next != head)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        delete slow;
    }

    void deleteAtTail()
    {
        if (isEmpty())
        {
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *prev = nullptr;
        Node *temp = head;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }
};

int main()
{
    LinkedList list;
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtMiddle(33);
    list.display();

    list.deleteAtHead();
    list.display();

    list.deleteAtMiddle();
    list.display();

    list.deleteAtTail();
    list.display();

    return 0;
}
