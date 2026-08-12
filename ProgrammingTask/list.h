#pragma once


//Doubly Linked List.

class LinkedList
{
private:
    struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(const int& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    size_t size_;
public:
    //Create empty LinkedList.
    LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {} 
    LinkedList& operator=(const LinkedList& other);
    //Delete LinckedList.
    ~LinkedList();

    //Add new element at the end.
    void pushBack(const int& value);
    //Delete element by index.
    void deleteElement(size_t index);
    //Show element.
    int& operator[](size_t index);
    //Get size.
    size_t getSize() const;
    //Removes duplicate elements.
    void clearRepetition();
};



