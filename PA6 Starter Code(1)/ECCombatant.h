//
//  ECCombatant.cpp
//  
//  DON'T CHANGE THIS FILE!!
//

#ifndef ECCombatant_h
#define ECCombatant_h

#include <string>

//***********************************************************
// Generic simulation Combatant

class ECCombatant {
public:
    // Each monster has an id (for keeping track when testing)
    ECCombatant(const std::string &ID);
    
    // Return the combatants ID
    std::string GetID() const { return ID; }
    
    // Does the combatant have health left?
    virtual bool IsDead() const = 0;

    // Perform actions this turn
    virtual void TakeTurn(ECCombatant* target) = 0;

    // Receieve attack from a combatant
    virtual void ReceiveAttack(int damageSuffered) = 0;

protected:
    // Damage the combatant who just attacked this combatant.
    virtual void Attack(ECCombatant* target) const;
private:
    std::string ID;
};


#endif /* ECCombatant_h */
