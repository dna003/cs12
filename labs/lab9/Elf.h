#ifndef ELF_H
#define ELF_H
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Elf : public Character {
    private:
        string family;
        
    public: 
        Elf(const string &name, double health, double attackStrength, const string &family);
        void attack(Character &opponent);
};
#endif