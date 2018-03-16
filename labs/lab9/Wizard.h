#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class Wizard : public Character {
    private:
        int rank;
        
    public:
        Wizard(const string& name, double health, double attackStrength, int rank);
        void attack(Character &opponent);
};
#endif

