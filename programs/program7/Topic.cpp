#include "Message.h"
#include "Topic.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Topic::Topic()
 : Message()
 {}
 
Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned id)
 : Message(athr, sbjct, body, id)
 {}
 
bool Topic::isReply() const {
 return false;
}

string Topic::toFormattedString() const {
    stringstream gay;
    gay << "<begin_topic>" << endl;
    gay << ":id: " << id << endl;
    gay << ":subject: " << subject << endl;
    gay << ":from: " << author  << endl;
    if(childList.size() != 0) {
        gay << ":children: ";
        for(unsigned int i = 0; i < childList.size(); ++i) {
            gay << childList.at(i) -> getID();
            if(i != childList.size() - 1) {
                gay << " ";
            }
        }
        gay << endl;
    }
    gay << ":body: " << body << endl;
    gay << "<end>" << endl;
    return gay.str();
}