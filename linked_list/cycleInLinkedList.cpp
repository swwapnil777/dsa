#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int data) {
        Node *newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool hasCycle() {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
    }

    void createCycle(int pos) {
        if (pos < 0 || pos >= size()) {
            cout << "Invalid position for cycle!" << endl;
            return;
        }

        if (isEmpty() || pos == size() - 1)
            return;

        Node *temp = head;
        int count = 0;

        while (count < pos) {
            temp = temp->next;
            count++;
        }

        tail->next = temp;
    }

    int size() {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    list.createCycle(2);

    if (list.hasCycle()) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
