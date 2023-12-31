//
//  ECMonster2.cpp
//
//
#include <algorithm>
#include <vector>
#include <iostream>

#include "ECMonster2.h"
#include "ECCombatant.h"
#include "ECDungeon.h"

using namespace std;

//***********************************************************
// Replicator: a monster that can make an exact copy of itself every turn.

// Create a constructor function for the class

// Create a declaration for all ECCombatant virtual functions:
//    IsDead()
//    TakeTurn()
//    ReceiveAttack()
//    Attack()


ECReplicator::ECReplicator(const std::string &mID, ECDungeon *dungeon ,int health, int damage): ECMonster(mID), dungeon(dungeon), health(health), damage(damage), on_heap(false){}
ECReplicator::ECReplicator(const std::string &mID, ECDungeon *dungeon ,int health, int damage, bool on_heap): ECMonster(mID), dungeon(dungeon), health(health), damage(damage), on_heap(on_heap){}

bool ECReplicator:: IsDead() const
{
    return health <= 0;
}
bool ECReplicator::OnHeap() const
{
    return on_heap;
}

void ECReplicator::TakeTurn(ECCombatant *target)
{
    Attack(target);
    dungeon->AddMonster(MakeCopy());
}
ECReplicator* ECReplicator::MakeCopy() const
{
    ECReplicator *replication = new ECReplicator("copy of "+GetID(), getDungeon(), getHealth(), getDamage(),true);
    return replication;
}
void ECReplicator::Attack(ECCombatant *fighter) const 
{
    cout << GetID() << " Attacks " << fighter->GetID() << ". ";
    fighter->ReceiveAttack(damage);
}


void ECReplicator::ReceiveAttack(int sufferedDamage) 
{
    health -= sufferedDamage;
    cout << "It deals " << to_string(sufferedDamage) << endl;
}

//***********************************************************
// Horde: a collection of monsters that can all attack in one turn but can only be attacked one at a time.

// Create a constructor function for the class

// Create a declaration for all ECCombatant virtual functions:
//    IsDead()
//    TakeTurn()
//    ReceiveAttack()
//    Attack()

ECHorde::ECHorde(const std::string &mID):ECMonster(mID), _monsters() {}
bool ECHorde::IsDead() const
{
    return _monsters.empty();
}
void ECHorde::TakeTurn(ECCombatant *target)
{
    Attack(target);
}
void ECHorde::Attack(ECCombatant *fighter) const
{
    for(auto iter = _monsters.begin(); iter != _monsters.end(); iter++)
    {
        ECMonster *cur_monster = *iter;
        cur_monster->TakeTurn(fighter);
    }
}
void ECHorde::ReceiveAttack(int sufferedDamage)
{
    ECMonster *cur_monster = getCurrentMonster();
    cur_monster->ReceiveAttack(sufferedDamage);
    if(cur_monster->IsDead())
    {
        _monsters.erase(_monsters.begin());
    }
}
void ECHorde::AddMonster(ECMonster *monster)
{
    _monsters.push_back(monster);
}