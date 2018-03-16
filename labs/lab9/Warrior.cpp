#include "Character.h"
#include "Warrior.h"
#include <iostream>
#include <string>

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance)
 : Character(WARRIOR, name, health, attackStrength),
 allegiance(allegiance)
 {}
 
void Warrior::attack(Character &opponent) {
    if(opponent.getType() ==  WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.allegiance == this -> allegiance) {
            cout << "Warrior " << this -> name << " does not attack Warrior " << opponent.getName();
            cout << "." << endl;
            cout << "They share an allegiance with " << this -> allegiance << "." << endl;
        }
        else {
            double d = (this -> health / MAX_HEALTH) * (this -> attackStrength);
            opponent.damage(d);
            cout << "Warrior " << this -> name << " attacks " << opponent.getName();
            cout << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage." << endl;
        }
    }
    else {
        double d = (this -> health / MAX_HEALTH) * (this -> attackStrength);
        opponent.damage(d);
        cout << "Warrior " << this -> name << " attacks " << opponent.getName();
        cout << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
    }
}