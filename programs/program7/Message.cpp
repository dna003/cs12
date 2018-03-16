#include <iostream>
#include "Message.h"
using namespace std;

Message::Message() {
    author = "";
    subject = "";
    body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id) {
    author = athr;
    subject = sbjct;
    this -> body = body;
    this -> id = id;
}

Message::~Message() {
    for(unsigned int i = 0; i < childList.size(); ++i) {
        delete childList.at(i);
    }
}

void Message::print(unsigned indentation) const {
    string empty = "";
    string bodyText = body;
    
    for(unsigned int i = 0; i < indentation; ++i) {
        empty = empty + "  ";
    }
    if(isReply()) {
        cout << endl;
    }
    cout << empty << "Message #" << getID() << ": " << getSubject() << endl << empty;
    cout << "from " << author << ": ";
    
    for(unsigned int i = 0; i < (bodyText.size()-1); ++i) {
        if(bodyText.at(i) == '\n') {
            bodyText.insert(i+1, empty);
        }
    }
    cout << bodyText << endl;
    if(childList.size() != 0) {
        for(unsigned i = 0; i < childList.size(); ++i) {
            childList.at(i) -> print(indentation + 1);
        }
    }
}

const string& Message::getSubject() const {
    return subject;
}

unsigned Message::getID() const {
    return id;
}

void Message::addChild(Message* child) {
    childList.push_back(child);
}


