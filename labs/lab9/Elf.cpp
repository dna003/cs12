#include "Elf.h"
#include <iostream>
#include <string>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
 :Character(ELF, name, health, attackStrength),
 family(family)
 {}
 
void Elf::attack(Character &opponent) {
    if(opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.family == this -> family) {
            cout << "Elf " << this -> name << " does not attack Elf " << opponent.getName() << ".";
            cout << endl << "They are both members of the " << this -> family << " family." << endl;
        }
        else {
            double d = (this -> health / MAX_HEALTH) * (this -> attackStrength);
            opponent.damage(d);
            cout << "Elf " << this -> name << " shoots an arrow at " << opponent.getName();
            cout << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage." << endl;
        }
    }
    else {
        double d = (this -> health / MAX_HEALTH) * (this -> attackStrength);
        opponent.damage(d);
        cout << "Elf " << this -> name << " shoots an arrow at " << opponent.getName();
        cout << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
    }
}