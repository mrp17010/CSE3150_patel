//
//  ECFighter.cpp
//  
//  DON'T CHANGE THIS FILE!!
//

#include <vector>
#include <iostream>

#include "ECFighter.h"
#include "ECMonster.h"
#include "ECCombatant.h"

using namespace std;

//***********************************************************
// Simulation fighter

ECFighter::ECFighter(const std::string &IDIn, int healthIn, int damageIn): ECCombatant(IDIn), health(healthIn), damage(damageIn) {}

void ECFighter::Attack(ECCombatant* monsterToAttack) {
    cout << GetID() << " Attacks " << monsterToAttack->GetID() << ". ";
    monsterToAttack->ReceiveAttack(getDamage());
}

//***********************************************************
// Knight - basic fighter

ECKnight::ECKnight(const std::string &IDIn, int healthIn, int damageIn): ECFighter(IDIn, healthIn, damageIn) {}

void ECKnight::TakeTurn(ECCombatant* monsterToAttack) {
    Attack(monsterToAttack);
}

void ECKnight::ReceiveAttack(int damageInflicted) {
    setHealth(getHealth() - damageInflicted);
    cout << "It deals " << to_string(damageInflicted) << endl;
}
