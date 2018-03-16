#include <iostream>
#include <string>

using namespace std;


void flipString(string &s) {
    if(s.length() <= 1) {
        return;
    }
    else{
        string mid = s.substr(1, s.size()-2);
        char l = s.at(0);
        char r = s.at(s.size()-1);
        flipString(mid);
        s = r + mid + l;
        
    }
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

   
