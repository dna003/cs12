#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance() {
    this -> feet = 0;
    this -> inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    this -> feet = ft;
    this -> inches = in;
    init();

}

Distance::Distance(double in) {
    this -> feet = 0;
    this -> inches = in;
    init();
}



unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    double value = 0.0;
    value = (feet * 12) + inches;
    return value;
}

double Distance::distanceInFeet() const {
    double value = 0.0;
    value = feet + (inches / 12);
    return value;
}

double Distance::distanceInMeters() const {
    return (distanceInInches() * 0.0254);
}

const Distance Distance::operator+(const Distance &rhs) const {
    Distance sum;
    sum.feet = feet + rhs.feet;
    sum.inches = inches + rhs.inches;
    sum.init();
    return sum;
}

const Distance Distance::operator-(const Distance &rhs) const {
    Distance diff;
    diff = distanceInInches() - rhs.distanceInInches();
    diff.init();
    return diff;
    
}

ostream & operator<<(ostream& out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init() {
    int rft = 0;
    
    if(feet < 0) {
        feet = feet * -1;
    }
    if(inches < 0) {
        inches = inches * -1;
    }
    while(inches >= 12) {
        inches = inches - 12;
        rft = rft + 1;
    }
    feet = feet + rft;
}

