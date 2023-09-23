#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::rearrange() {
    Node* current = head;
    Node* prev = nullptr;
    Node* negativeHead = nullptr;
    Node* negativeTail = nullptr;
    Node* positiveHead = nullptr;
    Node* positiveTail = nullptr;

    while (current != nullptr) {
        Node* next = current->next;

        if (current->data < 0) {
            if (negativeHead == nullptr) {
                negativeHead = current;
                negativeTail = current;
                negativeHead->next = nullptr;
            } else {
                current->next = negativeHead;
                negativeHead = current;
            }
        } else {
            if (positiveTail == nullptr) {
                positiveHead = current;
                positiveTail = current;
                positiveHead->next = nullptr;
            } else {
                positiveTail->next = current;
                positiveTail = current;
                positiveTail->next = nullptr;
            }
        }

        current = next;
    }

    if (negativeHead != nullptr) {
        head = negativeHead;
        negativeTail->next = positiveHead;
    } else {
        head = positiveHead;
    }
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int LinkedList::getSize() const {
    int size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}

int LinkedList::get(int index) const {
    if (index < 0) {
        return 0;
    }
    int currentIndex = 0;
    Node* current = head;
    while (current != nullptr) {
        if (currentIndex == index) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }
    return 0;
}

bool LinkedList::remove(int index) {
    if (index < 0) {
        return false;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    int currentIndex = 1;
    Node* current = head;
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }
    if (current != nullptr && current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }
    return false;
}

LinkedList::Node* LinkedList::getHead() const {
    return head;
}


