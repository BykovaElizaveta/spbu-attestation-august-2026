#include "list.h"
#include <iostream>

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        LinkedList temp(other);
        std::swap(head_, temp.head_);
        std::swap(tail_, temp.tail_);
        std::swap(size_, temp.size_);
    }
    return *this;
}

LinkedList::~LinkedList() {
    Node* current = head_;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::pushBack(const int& value){
    Node* newNode = new Node(value);
    if (head_ == nullptr) {
        head_ = tail_ = newNode;
    } else {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    }
    ++size_;
};

void LinkedList::deleteElement(size_t index){
    if (index >= size_) {
        std::cout << "Index out of range" << std::endl;
        return;
    }

    Node* current = head_;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head_ = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail_ = current->prev;
    }

    delete current;
    --size_;
};

int& LinkedList::operator[](size_t index){
    if (index >= size_) {
        std::cout << "Index out of range" << std::endl;
        throw "Index out of range";
    }
    Node* current = head_;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
};

size_t LinkedList::getSize() const {
    return this->size_;
};

void LinkedList::clearRepetition() {
    if (head_ == nullptr) {
        return;
    }
    for (size_t i = 0; i < getSize(); ) {
        bool isDuplicate = false;
        for (size_t j = 0; j < i; ++j) {
            if ((*this)[i] == (*this)[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {
            deleteElement(i);
        } else {
            i++;
        }
    }
};