#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

void readData(const string &fileName, vector<double> &flightAngle, vector<double> &c);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main() {
    string file;
    vector<double> a;
    vector<double> b;
    double angle;
    
    cout << "Enter name of input data file:" << endl << endl;
    cin >> file;
    readData(file, a, b);
    if(!isOrdered(a)) {
        reorder(a, b);
    }
    
    
    cout << "Flight path angle: ";
    cin >> angle;
    cout << "Coefficent is:" << interpolation(angle, a, b) << endl;
}

void readData(const string &fileName, vector<double> &flightAngle, vector<double> &c) {
    ifstream inFS;
    double x;
    double z;
    
    inFS.open(fileName.c_str());
    if(!inFS.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    while(inFS >> x >> z) {
        flightAngle.push_back(x);
        c.push_back(z);
    }
}

double interpolation(double pathAngle, const vector<double> &flightAngle, const vector<double> &cof) {
    double fa = 0.0;
    double fc = 0.0;
    double c = 0.0;
    double a = 0.0;
    double b = 0.0;
    
    for(unsigned int i = 0; i < flightAngle.size(); ++i) {
        
        if(abs(pathAngle - flightAngle.at(i)) < 0.0001) {
            return cof.at(i);
        }
    
        if(pathAngle < flightAngle.at(i)) {
            a = flightAngle.at(i-1);
            fa = cof.at(i-1);
            c = flightAngle.at(i);
            fc = cof.at(i);
            b = fa + (pathAngle - a)/(c - a) * (fc - fa);
            cout << a << " " << fa << endl;
            cout << c << " " << fc << endl;
            return b;
        }
    }
    return 0;
}

bool isOrdered(const vector<double> &flightAngle) {
    if(flightAngle.size() <= 1) {
        return true;
    }
    for(unsigned int i = 0; i < flightAngle.size()-1; ++i) {
        if(flightAngle.at(i) > flightAngle.at(i+1)) {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightAngle, vector<double> &c) {
    for(unsigned int i = 0; i < flightAngle.size(); ++i) {
        int minIndex = i;
        for(unsigned int j = i+1; j < flightAngle.size(); ++j) {
            if(flightAngle.at(minIndex) > flightAngle.at(j)) {
                minIndex = j;
            }
        }
        swap(flightAngle.at(minIndex), flightAngle.at(i));
        swap(c.at(minIndex), c.at(i));
    }
    for(unsigned int i = 0; i < flightAngle.size(); ++i) {
        cout << flightAngle.at(i) << " ";
        cout << c.at(i) << endl;
    }
}