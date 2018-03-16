#include "IntVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[sz];
    for(unsigned int i = 0; i < sz; ++i) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete[] data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if(sz == 0) {
        return true;
    }
    else {
        return false;
    }
}

const int& IntVector::at(unsigned index) const {
    if(index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

const int& IntVector::front() const {
    return data[0];
}

const int& IntVector::back() const {
    return data[sz-1];
}

int& IntVector::at(unsigned index) {
    if(index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

int& IntVector::front() {
    return data[0];
}

int& IntVector::back() {
    return data[sz-1];
}

void IntVector::expand() {
        cap = cap * 2;
        int* temp = new int[cap*2];
        for(unsigned int i = 0; i < sz; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data = temp;
}

void IntVector::expand(unsigned amount) {
        cap = cap + amount;
        int* temp = new int[cap + amount];
        for(unsigned int i = 0; i < sz; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data = temp;
}

void IntVector::push_back(int value) {
    if(cap == 0){
        expand(1);
    }
    else if(sz >= cap) {
        expand();
    }
    data[sz] = value;
    sz = sz + 1;
    
}

void IntVector::insert(unsigned index, int value) {
    if(index > sz) {
        throw out_of_range("IntVector::insert_range_check");
    }
    else if(sz >= cap) {
        if(cap == 0){
            expand(1);
        }
        else{
            expand();
        }
    }
    sz = sz + 1;
    for(unsigned int i = sz - 1; i > index; --i) {
        data[i] = data[i-1]; 
    }
    data[index] = value;
}

void IntVector::erase(unsigned index) {
    if(index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }
    else {
        for(unsigned int i = index; i < sz-1; ++i) {
            data[i] = data[i+1];
        }
        sz = sz - 1;
    }
}

void IntVector::pop_back() {
    sz = sz - 1;
}

void IntVector::clear() {
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {
    if(size < sz) {
        sz = size;
    }
    else if(size > sz) {
        if(size > cap) {
            if(cap*2 > cap + (size-cap)) {
                expand();
            }
            else {
                expand(size-cap);
            }
        }
        for(unsigned int i = sz; i < size; ++i) {
            data[i] = value;
        }
        sz = size;
    }
}

void IntVector::assign(unsigned n, int value) {
    if(n > cap) {
        if(cap*2 > cap + (n-cap)) {
            expand();
        }
        else {
            expand(n-cap);
        }
    }
    sz = n;
    for(unsigned int i = 0; i < sz; ++i) {
        data[i] = value;
    }
}

void IntVector::reserve(unsigned n) {
    if(n > cap) {
        expand(n -cap);
    }
    else {
        cout << "Reserve cannot be smaller than capacity";
    }
}


