#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyList {
public:
    Node* head;
    Node* tail;

    MyList() {
        this->head = NULL;
        this->tail = NULL;
    }

    MyList(Node* &head, Node* &tail) {
        this->head = head;
        this->tail = tail;
    }

    void insertAtHead(int data) {
        Node* temp = new Node(data);
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertAtTail(int data) {
        Node* temp = new Node(data);
        if (!tail) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position == 1) {
            insertAtHead(data);
        } else {
            Node* prev = head;
            Node* curr = prev->next;
            int cnt = 1;
            while (cnt < position - 1) {
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            Node* temp = new Node(data);
            prev->next = temp;
            temp->prev = prev;
            temp->next = curr;
            curr->prev = temp;
        }
    }

    void deleteNode(int position) {
        if (!head || position <= 0) {
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete temp;
        } else {
            Node* prev = head;
            Node* current = prev->next;
            int cnt = 1;
            while (current && cnt < position - 1) {
                prev = current;
                current = current->next;
                cnt++;
            }
            if (current) {
                prev->next = current->next;
                if (current->next) {
                    current->next->prev = prev;
                } else {
                    tail = prev;
                }
                delete current;
            }
        }
    }

    void printData() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Node* node1 = new Node(42);
    MyList dd(node1, node1);
    dd.insertAtHead(7);
    dd.insertAtHead(5);
    dd.insertAtHead(3);
    dd.insertAtTail(99);
    dd.insertAtPosition(22, 4);
    dd.printData();
    cout << endl;
    dd.deleteNode(3);
    cout << endl;
    dd.printData();

    // Clean up memory by deleting nodes
    Node* current = dd.head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
