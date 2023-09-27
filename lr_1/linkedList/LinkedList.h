
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void append(int value);
    void rearrange();
    bool isEmpty() const;
    void display() const;
    int getSize() const;
    int get(int index) const;
    bool remove(int index);
    Node* getHead() const;
};

#endif
