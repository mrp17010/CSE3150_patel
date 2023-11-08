#include "ECDungeon.h"
#include "ECFighter.h"
#include "ECMonster.h"
#include <iostream>

using namespace std;

//***********************************************************
// Dungeon simulator - Container class that handles the functionality of the simulation

// Create logic for all of ECDungeons functions:
//    int SimulateDungeon();
//    void SimulateTurn();
//    void AddMonster(ECMonster* monster);

ECDungeon::ECDungeon (ECFighter *fighterIn): turn(0), remainingMonsters(), fighter(fighterIn) {}

int ECDungeon::SimulateDungeon()
{
    int turns_taken = 0;
    ECMonster* cur_monster = remainingMonsters[0];
    while(!remainingMonsters.empty())
    {
        cout << "turn: " << turns_taken << endl;
        SimulateTurn();
        turns_taken++;
        if(fighter->IsDead())
        {
            break;
        }
    }
    return turns_taken;
}

void ECDungeon::SimulateTurn()
{
    ECMonster* cur_monster = remainingMonsters[0];
    fighter->TakeTurn(cur_monster);
    if (cur_monster->IsDead())
    {
        remainingMonsters.erase(remainingMonsters.begin());
    }
    else
    {
        cur_monster->TakeTurn(fighter);
    }

}

void ECDungeon::AddMonster(ECMonster *monster)
{
    remainingMonsters.push_back(monster);
}