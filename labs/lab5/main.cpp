#include <iostream>
#include <cstdlib>
using namespace std;

double mean(const double array[], int arraySize) {
    double mean = 0;
    double totalValue = 0;
    for(int i = 0; i < arraySize; ++i) {
        totalValue = totalValue + array[i];
    }
    mean = totalValue / arraySize;
    return mean;
}

void remove(double array[], int &arraySize, int index) {
    for(int i = index; i < arraySize - 1; ++i) {
        array[i] = array[i+1];
    }
    arraySize--;
}

void display(const double array[], int arraySize) {
    for(int i = 0; i < arraySize; ++i) {
        if(i == arraySize-1) {
            cout << array[i];
        }
        else {
            cout << array[i] << ", ";
        }
    }
}


int main() { 
    int size = 10;
    double arrayList[size];
    double input = 0.0;
    cout << "Enter 10 values:" << endl;
    for(int i = 0; i < 10; ++i) {
        cin >> input;
        arrayList[i] = input;
    }
    cout << endl;
    cout << "Mean: " << mean(arrayList, size) << endl;
    
    int index = 0;
    cout << endl;
    cout << "Enter index of value to be removed: ";
    cin >> index;
    cout << endl;
    
    cout << "Before removing value: ";
    display(arrayList, size);
    cout << endl;
    cout << "After removing value: ";
    remove(arrayList, size, index);
    display(arrayList, size);
    cout << endl;
}