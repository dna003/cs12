#include "IntVector.h"
#include <iostream>
using namespace std;

int main() {
    IntVector v(5, 7); 
    //SIZE AND CAPACITY FUNCTIONS TEST
    cout << "Size Function Test: " << endl;
    cout << "Size: " << v.size() << endl << endl;
    cout << "Capacity Function Test: " << endl;
    cout << "Capacity: " << v.capacity() << endl << endl;
    //cout << "Values: ";
    //for(int i = 0; i < v.size(); ++i) {
    //    cout << 
    //}
    
    IntVector x;
    //EMPTY FUNCTION TEST
    cout << "Empty Function Test: " << endl;
    if(x.empty() == true) {
        cout << "Empty Function correctly returned false when size and capacity was 0.";
        cout << endl;
    }
    cout << endl;
    
    
    //DESTRUCTOR TEST
    cout << "Destructor Test: " << endl;
    IntVector* z = new IntVector();
    delete z;
    cout << endl << endl;
    
    //AT FUNCTION TEST
    cout << "At Function Test with Valid Index: " << endl;
    cout << v.at(1) << endl << endl;
    cout << "At Function Test with Invalid Index: " <<endl;
    cout << v.at(7) << endl;
    

}