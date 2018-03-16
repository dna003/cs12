#include "BBoard.h"
#include "Message.h"
#include "User.h"
#include "Reply.h"
#include "Topic.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

BBoard::BBoard() {
    title = "";
    currentUser = 0;
    messageList.clear();
    
}

BBoard::BBoard(const string &t) {
    title = t;
    currentUser = 0;
    messageList.clear();
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
        if(id == "Q" || id == "q") {
            cout << "Bye!" << endl;
            return false;
            exit(1);
        }
        else {
            cout << "Enter your password: ";
            cin >> pass;
            for(unsigned i = 0; i < userList.size(); ++i) {
                if(userList.at(i).check(id, pass)) {
                    currentUser = &userList.at(i);
                    cout << endl << "Welcome back " << currentUser -> getUsername() << '!' << endl << endl;
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
    
    if(currentUser != 0) {
        while(x != 'Q' && x != 'q') {
            cout << "Menu" << endl;
            cout << "- Display Messages ('D' or 'd')" << endl;
            cout << "- Add New Topic ('N' or 'n')" << endl;
            cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
            cout << "- Quit ('Q' or 'q')" << endl;
            cout << "Choose an action: ";
            cin >> x;
            if(x == 'Q' || x == 'q') {
                cout << "Bye!" << endl;
                currentUser = 0;
                break;
            }
            else if(x == 'D' || x == 'd') {
                if(messageList.size() < 1) {
                    cout << endl << "Nothing to Display." << endl;
                }
                else{
                    cout << endl;
                    for(unsigned i = 0; i < messageList.size(); ++i) {
                        if(!messageList.at(i)->isReply()) {
                            cout << "---------------------------------------------------------" << endl;
                            messageList.at(i)->print(0);
                        }
                    }
                    cout << "---------------------------------------------------------" << endl;
                }
                cout << endl;
            }
            else if(x == 'N' || x == 'n') {
                addTopic();
                cout << endl;
            }
            else if(x == 'R' || x == 'r') {
                addReply();
                cout << endl;
            }
        }
    }
    else {
        exit(0);
    }
    return;
}

BBoard::~BBoard() {
    for(unsigned int i = 0; i < messageList.size(); ++i) {
        if(messageList.at(i) != 0) {
            delete messageList.at(i);
        }
    }
}

bool BBoard::loadMessages(const string &datafile) {
    ifstream inFS;
    inFS.open(datafile.c_str());
    if(!inFS.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }
    //Variables
    int numMessages = 0;
    int id = 0;
    int childID = 0;
    string messageType;
    string subject;
    string from;
    string body;
    string input;
    string children;
    vector<string> childNum;
    Message* topic = 0;
    Message* reply = 0;
    //Take in the number of messages
    inFS >> numMessages;
    while(numMessages != 0) {
        children = "";
        inFS >> messageType;
           while(inFS >> input) {
                if(input == ":id:") {
                    inFS >> id;
            }
                else if(input == ":subject:") {
                    getline(inFS, subject);
                    subject = subject.substr(1);
            }
                else if(input == ":from:") {
                    inFS >> from;
            }
                else if(input == ":children:") {
                    getline(inFS, children);
                    children = children.substr(1);
            }
                else if(input == ":body:") {
                    getline(inFS, body);
                    while(getline(inFS, input)) {
                        if(input != "<end>")
                            body = body + '\n' + input;
                        else {
                            break;
                        }
                    }
                    body = body.substr(1);
                    break;
                }
           }
           childNum.push_back(children);
           --numMessages;
           if(messageType == "<begin_topic>") {
               topic = new Topic(from, subject, body, id);
               messageList.push_back(topic);
           }
           if(messageType == "<begin_reply>") {
               reply = new Reply(from, subject, body, id);
               messageList.push_back(reply);
           }
    }
    inFS.close();
    for(unsigned int i = 0; i < childNum.size(); ++i) {
        istringstream x(childNum.at(i));
        while(x >> childID) {
            messageList.at(i) -> addChild(messageList.at(childID-1));
        }
    }
    return true;
}

bool BBoard::saveMessages(const string &datafile) {
    ofstream outFS;
    outFS.open(datafile.c_str());
    if(!outFS.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }
    outFS << messageList.size() << endl;
    for(unsigned int i = 0; i < messageList.size(); ++i) {
        outFS << messageList.at(i) -> toFormattedString();
        }
    outFS.close();
    return true;
}

void BBoard::addTopic() {
    string subject; 
    string body;
    string newBody;
    
    cin.ignore();
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Body: ";
    getline(cin, body);
    getline(cin, newBody);
    while(!newBody.empty()) {
        body = body + '\n' + newBody;
        getline(cin, newBody);
    }
    Topic* topic = new Topic(currentUser -> getUsername(), subject, body, messageList.size() + 1);
    messageList.push_back(topic);
}

void BBoard::addReply() {
    bool correctID = false;
    int msgID;
    int id = messageList.size() + 1;
    string subject;
    string body;
    string newBody;
    
    
    while(correctID == false) {
        cout << "Enter Message ID: (-1 for Menu): ";
        cin >> msgID;
        if(msgID > static_cast<int>(messageList.size())) {
            cout << "Invalid Message ID!!" << endl << endl;
        }
        else if(msgID <= -1) {
            return;
        }
        else {
            correctID = true;
        }
    }
    cout << "Enter Body: ";
    cin.ignore();
    getline(cin, body);
    getline(cin, newBody);
    while(!newBody.empty()) {
        body = body + '\n' + newBody;
        getline(cin, newBody);
    }
    subject = "Re: " + messageList.at(msgID-1) -> getSubject();
    Reply* reply = new Reply(currentUser -> getUsername(), subject, body, id);
    messageList.push_back(reply);
    messageList.at(msgID-1) -> addChild(reply);
}


