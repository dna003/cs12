#include "Character.h"
#include "Wizard.h"
#include <iostream>
#include <string>

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
 :Character(WIZARD, name, health, attackStrength),
 rank(rank)
 {}
 
 void Wizard::attack(Character &opponent) {
     if(opponent.getType() == WIZARD) {
         Wizard &opp = dynamic_cast<Wizard &>(opponent);
         double d = (this -> attackStrength) * (this -> rank * 1.0 / opp.rank);
         opponent.damage(d);
         cout << "Wizard " << this -> name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
         cout << opponent.getName() << " takes " << d << " damage." << endl;
     }
     else {
         double d = this -> attackStrength;
         opponent.damage(d);
         cout << "Wizard " << this -> name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
         cout << opponent.getName() << " takes " << d << " damage." << endl;
     }
 }