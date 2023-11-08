//
//  ECFighter2.h
//  
//

#ifndef ECFighter2_h
#define ECFighter2_h

#include "ECFighter.h"
class ECCombatant;

// Now define your new fighters here...

//***********************************************************
// Brute - A fighter that gets stronger everytime it defeats an enemy

// Create a constructor function for the class

// Create a declaration for all ECCombatant virtual functions:
//    IsDead()
//    TakeTurn()
//    ReceiveAttack()
//    Attack()

class ECBrute: public ECFighter
{
public:
    ECBrute(const std::string &IDIn, int healthIn, int damageIn);

    bool IsDead() const {return getHealth() <= 0;}
    void TakeTurn(ECCombatant* monsterToAttack);
    void ReceiveAttack(int damageSuffered);
    //void Attack(ECCombatant* target) const;
    //attack doesn't need a declaration, it can just use the fighter attack method

};


//***********************************************************
// Acrobat - A fighter that can dodge an attack every 4 turns

// Create a constructor function for the class

// Create a declaration for all ECCombatant virtual functions:
//    IsDead()
//    TakeTurn()
//    ReceiveAttack()
//    Attack()

class ECAcrobat: public ECFighter
{
public:
    ECAcrobat(const std::string &IDIn, int healthIn, int damageIn);

    bool IsDead() const {return getHealth() <= 0;}
    void TakeTurn(ECCombatant *monsterToAttack);
    void ReceiveAttack(int damageSuffered);
    int getDodgeCooldown() const {return _dodge_cooldown;}

protected:
    void setDodgeCooldown(int newCooldown) {_dodge_cooldown = newCooldown;}

private:
    int _dodge_cooldown;

};



#endif /* ECFighter2_h */
