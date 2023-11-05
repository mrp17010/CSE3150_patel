//
//  ECMonster.h
//  
//  DON'T CHANGE THIS FILE!!
//


#ifndef ECMonster_h
#define ECMonster_h

#include <string>
#include "ECCombatant.h"

class Fighter;

//***********************************************************
// Generic simulation monster

class ECMonster : public ECCombatant
{
public:
    // Each monster has an id (for keeping track when testing)
    ECMonster(const std::string &ID);
    
    // Does the monster have health left? If no, return false and remove this monster from the dungeon.
    virtual bool IsDead() const = 0;

    // Perform actions this turn
    virtual void TakeTurn(ECCombatant* target) = 0;
    
    // Damage the fighter who just attacked this monster.
    virtual void Attack(ECCombatant* target) const;

    // Receieve attack from a fighter
    virtual void ReceiveAttack(int damageSuffered) = 0;

};

//***********************************************************
// Simple slime: a monster that does nothing except retaliate by dealing damage every turn.

class ECSlime : public ECMonster
{
public:
    ECSlime(const std::string &tid, int tmStart, int tmEnd);
    
    // Does the monster have health left? If no, return false and remove this monster from the dungeon.
    bool IsDead() const;
    
    // Perform actions this turn
    virtual void TakeTurn(ECCombatant* target);

    // Receieve attack from a fighter
    void ReceiveAttack(int sufferedDamage);

    // Getters for Health/Damage
    int getHealth() const { return health; }
    int getDamage() const { return damage; }

protected:
    // Getters for Health/Damage
    void setHealth(int newHealth) { health = newHealth; }
    void setDamage(int newDamage) { damage = newDamage; }

    // Damage the fighter who just attacked this monster.
    void Attack(ECCombatant* fighter) const;
private:
    int health;
    int damage;
};

#endif /* ECMonster_h */
