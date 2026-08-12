#include "test.h"
#include "list.h"
#include <iostream>
#include <cassert>

//Add element in list.
void TestPush(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    assert(list.getSize() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
};

//Delete element in list.
void TestDel(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.deleteElement(2);
    assert(list.getSize() == 2);
    assert(list[0] == 1);
    assert(list[1] == 2);
};

//Delete element in empty list.
void TestDelEmptyList(){
    LinkedList list;
    list.deleteElement(0);
    assert(list.getSize() == 0);
};

//Delete element out of list.
void TestDelOutOfRange(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.deleteElement(4);
    assert(list.getSize() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
};

//Delete repetition.
void TestDelRep(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(2);
    list.pushBack(3);
    
    list.clearRepetition();
    
    assert(list.getSize() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
};

//Try delete repetition without repetition.
void TestTryDelRep(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    
    list.clearRepetition();
    
    assert(list.getSize() == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
};

void RunTests() {
    TestPush();
    TestDel();
    TestDelEmptyList();
    TestDelOutOfRange();
    TestDelRep();
    TestTryDelRep();
    std::cout << "All tests passed" << std::endl;
};

