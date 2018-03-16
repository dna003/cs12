#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <iostream>
using namespace std;

class IntVector {
    private:
        unsigned sz;
        unsigned cap;
        int* data;
    public:
        IntVector();
        IntVector(unsigned size, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int& at(unsigned index) const;
        const int& front() const;
        const int &back() const;
        
};
#endif

