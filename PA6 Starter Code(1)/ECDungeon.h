//
//  ECDungeon.h
//  
//  DON'T CHANGE THIS FILE!!

#ifndef ECDungeon_h
#define ECDungeon_h

#include <vector>

class ECFighter;
class ECMonster;

//***********************************************************
// Dungeon simulator - Container class that handles the functionality of the simulation

class ECDungeon {
public:
    ECDungeon(ECFighter *fighterIn);
    
    int SimulateDungeon();

    void SimulateTurn();
    
    void AddMonster(ECMonster *monster);
    
private:
    int turn;
    std::vector<ECMonster*> remainingMonsters;
    ECFighter* fighter;
};


#endif /* ECDungeon_h */
