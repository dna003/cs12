#include <iostream>
using namespace std;

bool diophantine(int a, int b, int c, int &x, int &y);

int gcd(int a, int b);

int main() {

    int a, b, c, x, y;

    cout << "Enter a b c";
    cout << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}

/* Returns true if a solution was found and false if there is no solution.
  x and y will contain a solution if a solution was found. 
  This function will NOT output anything.
*/

int gcd(int a, int b){
    
    if(a % b == 0){
    
        return b;
    
        
    }
    
    int x = a % b;
    
    return gcd(b, x);

    
}


bool diophantine(int a, int b, int c, int &x, int &y){

    if(c % gcd(a,b) != 0){

        return false;

    }

    if(a % b == 0){

        x = 0;

        y = c/b;

        return true;

    }

    int q = (a / b);

    int r = a % b;

    int s=0;

    int z=0;

    diophantine(b, r, c, s, z);


    x = z;

    y = s - q * x; 

    return true;

    
}

