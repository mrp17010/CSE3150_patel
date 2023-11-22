//
//  ECFighter2.cpp
//  
//
//

#include <vector>
#include <iostream>

#include "ECFighter2.h"
#include "ECCombatant.h"

using namespace std;

//***********************************************************
// Brute - A fighter that gets stronger everytime it defeats an enemy

ECBrute::ECBrute (const std::string &IDIn, int healthIn, int damageIn): ECFighter(IDIn, healthIn, damageIn) {}

void ECBrute::TakeTurn(ECCombatant *monsterToAttack)
{
    Attack(monsterToAttack);
    if (monsterToAttack->IsDead()) //if monster is dead after attack
    {
        int new_damage = getDamage() + 2;
        setDamage(new_damage);
    }
}

//this should honestly go into fighter. It'll be the same for everybody except 
//acrobat who can override it.
void ECBrute::ReceiveAttack(int damageInflicted)
{
    setHealth(getHealth() - damageInflicted);
    cout << "It deals " << to_string(damageInflicted) << endl;
}

//***********************************************************
// Acrobat - A fighter that can dodge an attack every 4 turns

ECAcrobat::ECAcrobat (const std::string &IDIn, int healthIn, int damageIn): ECFighter(IDIn, healthIn, damageIn), _dodge_cooldown(0) {}

void ECAcrobat::TakeTurn(ECCombatant *monsterToAttack)
{
    int cur_cooldown = getDodgeCooldown();
    Attack(monsterToAttack);
    if(cur_cooldown != 0)
    {
        int new_cooldown = cur_cooldown-1;
        setDodgeCooldown(new_cooldown);
    }
}

void ECAcrobat::ReceiveAttack(int damageInflicted)
{
    if(getDodgeCooldown() == 0)
    {
        cout << "Dodged!" << endl;
        setDodgeCooldown(3);
    }
    else
    {
        setHealth(getHealth() - damageInflicted);
        cout << "It deals " << to_string(damageInflicted) << endl;
    }

}