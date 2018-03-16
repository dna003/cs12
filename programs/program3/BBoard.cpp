#include "BBoard.h"
#include "Message.h"
#include "User.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

BBoard::BBoard() {
    title = "";
    
}

BBoard::BBoard(const string &t) {
    title = t;
}

bool BBoard::loadUsers(const string &fileName) {
    string id;
    string pass;
    ifstream inFS;
    inFS.open(fileName.c_str());
    if(!inFS.is_open()) {
        return false;
    }
    else {
      while(id != "end") {
          inFS >> id;
          if(id != "end") {
              inFS >> pass;
              userList.push_back(User(id, pass));
          }
      }
    }
    inFS.close();
    return true;
}

bool BBoard::login() {
    string id;
    string pass;
    bool invalidUser = true;
    
    cout << "Welcome to " << title << endl;
    
    
    while(invalidUser) {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> id;
        cout << endl;
    
        if(id == "Q" || id == "q") {
            cout << "Bye!" << endl;
            return false;
            exit(1);
        }
        else {
            cout << "Enter your password: ";
            cin >> pass;
            cout << endl;
            for(unsigned i = 0; i < userList.size(); ++i) {
                if(userList.at(i).check(id, pass)) {
                    currentUser = userList.at(i);
                    cout << "Welcome back " << currentUser.getUsername() << '!' << endl << endl;
                    return true;
                    invalidUser = false;
                }
            }
        }
        cout << "Invalid Username or Password!" << endl << endl;
    }
    return true;
}

void BBoard::run() {
    char x;
    string b;
    string s;
    
    while(x != 'D' || x != 'd') {
        cout << "Menu" << endl;
        cout << "- Display Messages ('D' or 'd')" << endl;
        cout << "- Add New Message ('N' or 'n')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> x;
        cout << endl;
        
        if(x == 'D' || x == 'd') {
            if(messageList.size() < 1) {
                cout << "Nothing to Display." << endl << endl;
            }
            else{
                for(unsigned i = 0; i < messageList.size(); ++i) {
                    cout << "---------------------------------------------------------" << endl;
                    cout << "Message #" << i+1 << ": ";
                    messageList.at(i).display();
                    cout << endl;
                }
                cout << "---------------------------------------------------------" << endl << endl;
            }
        }
        if(x == 'N' || x == 'n') {
            cin.ignore();
            cout << "Enter Subject: ";
            getline(cin, s);
            cout << endl;
            cout << "Enter Body: ";
            getline(cin, b);
            cout << endl;
            cout << "Message Recorded!" << endl << endl;
            messageList.push_back(Message(currentUser.getUsername(),s, b));
        }
        else if(x == 'Q' || x == 'q') {
            cout << "Bye!" << endl;
            exit(1);
        }
    }
}




