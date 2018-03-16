#include "User.h"
#include <iostream>
using namespace std;

User::User() {
    username = "";
    password = "";
}

User::User(const string& uname, const string& pass) {
    username = uname;
    password = pass;
}

string User::getUsername() const {
    return username;
}

bool User::check(const string& uname, const string& pass) const {
    if(uname == "" || pass == "") {
        return false;
    }
    else if(uname == username && pass == password) {
        return true;
    }
    else {
        return false;
    }
}

bool User::setPassword(const string &oldpass, const string &newpass) {
    if(username == "" || password == "") {
        return false;
    }
    else if(password == oldpass) {
        password = newpass;
        return true;
    }
    else {
        return false;
    }
}

