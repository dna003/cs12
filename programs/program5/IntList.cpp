#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    head = 0;
    tail = 0;
}

IntList::~IntList() {
    IntNode* current = 0;
    while(head != 0) {
        current = head;
        head = head -> next;
        delete current;
    }
}

void IntList::display() const {
    if(empty()) {
        return;
    }
    IntNode* current = head;
    while(current != 0) {
        cout << current -> data;
        if(current -> next != 0) {
            cout << " ";
        }
        current = current -> next;
    }
}


void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);
    if(empty()) {
        head = temp;
        tail = temp;
    }
    else {
        temp -> next = head;
        head = temp;    
    }
}

void IntList::pop_front() {
    if(head == 0) {
        return;
    }
    else if(head == tail) {
        delete head;
        head = 0;
        tail = 0;
        return;
    }
    else {
        IntNode* temp = head -> next;
        delete head;
        head = temp;
    }
}

bool IntList::empty() const {
    if(head == 0) {
        return true;
    }
    else {
        return false;
    }
}

void IntList::push_back(int value) {
    IntNode* source = new IntNode(value);
    if(empty()) {
        head = source;
        tail = source;
    }
    else {
        tail -> next = source;
        tail = source;
        tail -> next = 0;
    }
}

void IntList::clear() {
    IntNode* current = 0;
    while(head != 0) {
        current = head;
        head = head -> next;
        delete current;
    }
    head = 0;
    tail = 0;
}

IntList::IntList(const IntList &cpy) {
    IntNode* current = cpy.head;
    while(current != 0) {
        push_back(current -> data);
        current = current -> next;
    }
}
    
IntList& IntList::operator=(const IntList &rhs) {
    if(this != &rhs) {
        clear();
        IntNode* current = rhs.head;
        while(current != 0) {
            push_back(current -> data);
            current = current -> next;
    }
    return *this;
    }
}

void IntList::selection_sort() {
    for(IntNode* i = head; i != 0; i = i -> next) {
        IntNode* minIndex = i;
        for(IntNode* j = i -> next; j != 0; j = j -> next) {
            if(minIndex -> data > j -> data) {
                minIndex = j;
            }
        }
        int temp = i -> data;
        i -> data = minIndex -> data;
        minIndex -> data = temp;
    }
}

void IntList::insert_ordered(int value) {
    if(empty()) {
        push_front(value);
    }
    else if(head == tail) {
        if(head -> data >= value) {
            push_front(value);
        }
        else {
            push_back(value);
        }
    }
    else if(head -> data > value) {
        push_front(value);
    }
    else {
        IntNode* add = new IntNode(value);
        IntNode* i = head;
        while(i -> next != 0 && i -> data < value && (i -> next -> data) < value) {
            i = i -> next;
        }
        add -> next = i -> next;
        i -> next = add;
    }
}

