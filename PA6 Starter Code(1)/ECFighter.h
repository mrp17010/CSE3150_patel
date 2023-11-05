//
//  ECFighter.h
//  
//  DON'T CHANGE THIS FILE!!

#ifndef ECFighter_h
#define ECFighter_h

#include <vector>
#include <string>
#include "ECCombatant.h"

class ECMonster;

//***********************************************************
// Simulation fighter

class ECFighter : public ECCombatant {
public:
    ECFighter(const std::string &IDIn, int healthIn, int damageIn);
    
    // Perform actions this turn
    virtual void TakeTurn(ECCombatant* target) = 0;

    virtual void ReceiveAttack(int damageSuffered) = 0;

    // If the fighter has no health, they are dead and the dungeon is failed.
    bool IsDead() const { return health <= 0; }

    // Getters for Health/Damage
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    
    // Get currently encountered monster
    ECMonster* GetCurrentMonster() const { return currentMonster; }
    
protected:
    // Getters for Health/Damage
    void setHealth(int newHealth) { health = newHealth; }
    void setDamage(int newDamage) { damage = newDamage; }

    // Damage the combatant who just attacked this combatant.
    virtual void Attack(ECCombatant* monsterToAttack);
    
private:
    int health;
    int damage;
    // currently encountered monster
    ECMonster* currentMonster;
};

//***********************************************************
// Knight - basic fighter

class ECKnight : public ECFighter
{
public:
    ECKnight(const std::string &IDIn, int healthIn, int damageIn);
    
    void TakeTurn(ECCombatant* monsterToAttack);

    void ReceiveAttack(int damageInflicted);
};

#endif /* ECFighter_h */
