//
//  ECMonster.cpp
//  
//  DON'T CHANGE THIS FILE!!
//

#include "ECMonster.h"
#include "ECFighter.h"
#include "ECCombatant.h"

#include <iostream>
using namespace std;

//***********************************************************
// Generic simulation monster


// Each monster has a name
ECMonster :: ECMonster(const std :: string &IDIn) : ECCombatant(IDIn) {}

void ECMonster::Attack(ECCombatant *target) const {}

//***********************************************************
// Simple slime: a monster that does nothing except retaliate by dealing damage every turn.

ECSlime::ECSlime(const std::string &mID, int health, int damage) : ECMonster(mID), health(health), damage(damage) {}


// Does the monster have health left? If no, return false and remove this monster from the dungeon.
bool ECSlime::IsDead() const {
    return health <= 0;
}

void ECSlime::TakeTurn(ECCombatant *target) {
    Attack(target);
}

void ECSlime::Attack(ECCombatant *fighter) const {
    cout << GetID() << " Attacks " << fighter->GetID() << ". ";
    fighter->ReceiveAttack(damage);
}

void ECSlime::ReceiveAttack(int sufferedDamage) {
    health -= sufferedDamage;
    cout << "It deals " << to_string(sufferedDamage) << endl;
}
