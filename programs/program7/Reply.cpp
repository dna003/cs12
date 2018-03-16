#include "Message.h"
#include "Reply.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Reply::Reply()
 : Message()
 {}
 
Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id) 
 : Message(athr, sbjct, body, id)
 {}
 
bool Reply::isReply() const {
    return true;
}

string Reply::toFormattedString() const {
    stringstream x;
    x << "<begin_reply>" << endl;
    x << ":id: " << id << endl;
    x << ":subject: " << subject << endl;
    x << ":from: " << author << endl;
    if(childList.size() != 0) {
        x << ":children: ";
        for(unsigned int i = 0; i < childList.size(); ++i) {
            x << childList.at(i) -> getID();
            if(i != childList.size() - 1) {
                x << " ";
            } 
        }
        x << endl;
    }
    x << ":body: " << body << endl;
    x << "<end>" << endl;
    return x.str();
}