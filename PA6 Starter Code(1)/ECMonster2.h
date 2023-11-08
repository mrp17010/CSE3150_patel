//
//  ECMonster2.h
//  
//  Simulation task: different types
//

#ifndef ECMonster2_h
#define ECMonster2_h

#include <string>
#include <vector>
#include "ECMonster.h"
class ECDungeon;
class ECCombatant;

// Now your need to define the following different kinds of monsters...

//***********************************************************
// Replicator: a monster that can make an exact copy of itself every turn.

// Create a constructor function for the class

// Create a declaration for all ECCombatant virtual functions:
//    IsDead()
//    TakeTurn()
//    ReceiveAttack()
//    Attack()

class ECReplicator: public ECMonster
{
public:
    ECReplicator(const std::string &tid, ECDungeon* dungeon ,int tmStart, int tmEnd);
    ECReplicator(const std::string &tid, ECDungeon* dungeon ,int tmStart, int tmEnd, bool onheap);
    bool IsDead() const;
    void TakeTurn(ECCombatant* target);
    void ReceiveAttack(int sufferedDamage);
    void Attack(ECCombatant* fighter) const;
    ECDungeon* getDungeon() const {return dungeon;}
    bool OnHeap() const;
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
private:
    ECReplicator* MakeCopy() const;
    ECDungeon* dungeon;
    int health;
    int damage;
    bool on_heap;
};

//***********************************************************
// Horde: a collection of monsters that can all attack in one turn but can only be attacked one at a time.

// Create a constructor function for the class

// Create a declaration for all ECCombatant virtual functions:
//    IsDead()
//    TakeTurn()
//    ReceiveAttack()
//    Attack()



#endif /* ECMonster2_h */
