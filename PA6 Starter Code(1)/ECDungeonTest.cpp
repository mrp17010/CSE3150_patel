// Build: g++ -std=c++11 ECCombatant.cpp ECFighter.cpp ECFighter2.cpp ECMonster.cpp ECMonster2.cpp ECDungeon.cpp ECDungeonTest.cpp -o ECDungeonTest.exe

#include "ECDungeon.h"
#include "ECMonster.h"
#include "ECMonster2.h"
#include "ECFighter.h"
#include "ECFighter2.h"
#include <iostream>
using namespace std;

template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

// Dungeon Test - King and Slime
static void Test0()
{
    cout << "****Test0\n";
    ECKnight f1("f1", 10, 3);
    ECSlime m1("m1", 3, 2);
    ECSlime m2("m2", 4, 2);
    ECDungeon dungeon(&f1);
    dungeon.AddMonster(&m1);
    dungeon.AddMonster(&m2);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 3);
    ASSERT_EQ(f1.getHealth(), 8);
    ASSERT_EQ(m1.IsDead(), true);
    ASSERT_EQ(m2.IsDead(), true);
}

// Dungeon Test - King and Slime 2
static void Test1()
{
    cout << "****Test1\n";
    ECKnight f1("f1", 10, 3);
    ECSlime m1("m1", 3, 2);
    ECSlime m2("m2", 4, 5);
    ECSlime m3("m3", 10, 2);
    ECDungeon dungeon(&f1);
    dungeon.AddMonster(&m1);
    dungeon.AddMonster(&m2);
    dungeon.AddMonster(&m3);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 6);
    ASSERT_EQ(f1.IsDead(), true);
    ASSERT_EQ(m1.IsDead(), true);
    ASSERT_EQ(m2.IsDead(), true);
    ASSERT_EQ(m3.getHealth(), 1);
}

// Fighter Test - Brute and Slime
static void Test2()
{
    cout << "****Test2\n";
    ECBrute f1("f1", 1, 1);
    ECDungeon dungeon(&f1);
    ECSlime m1("m1", 1, 20);
    ECSlime m2("m2", 3, 20);
    ECSlime m3("m3", 5, 20);
    ECSlime m4("m4", 7, 20);
    ECSlime m5("m5", 9, 20);
    ECSlime m6("m6", 11, 20);

    dungeon.AddMonster(&m1);
    dungeon.AddMonster(&m2);
    dungeon.AddMonster(&m3);
    dungeon.AddMonster(&m4);
    dungeon.AddMonster(&m5);
    dungeon.AddMonster(&m6);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 6);
    ASSERT_EQ(f1.getHealth(), 1);
    ASSERT_EQ(f1.getDamage(), 13);
    ASSERT_EQ(m1.IsDead(), true);
    ASSERT_EQ(m2.IsDead(), true);
    ASSERT_EQ(m3.IsDead(), true);
    ASSERT_EQ(m4.IsDead(), true);
    ASSERT_EQ(m5.IsDead(), true);
    ASSERT_EQ(m6.IsDead(), true);
}

// Fighter Test - Acrobat and Slime
static void Test3()
{
    cout << "****Test3\n";
    ECAcrobat f1("f1", 10, 2);
    ECDungeon dungeon(&f1);
    ECSlime m1("m1", 3, 50);
    ECSlime m2("m2", 2, 1);
    ECSlime m3("m3", 3, 50);

    dungeon.AddMonster(&m1);
    dungeon.AddMonster(&m2);
    dungeon.AddMonster(&m3);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 5);
    ASSERT_EQ(f1.getHealth(), 10);
    ASSERT_EQ(m1.IsDead(), true);
    ASSERT_EQ(m2.IsDead(), true);
    ASSERT_EQ(m3.IsDead(), true);
}

//Monster Test - Knight and Replicator
static void Test4()
{
    cout << "****Test4\n";
    ECKnight f1("f1", 15, 3);
    ECDungeon dungeon(&f1);
    ECReplicator rm1("rm1", &dungeon, 4, 1);
    dungeon.AddMonster(&rm1);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 3);
    ASSERT_EQ(f1.IsDead(), false);
    ASSERT_EQ(rm1.IsDead(), true);
}

// Monster Test - Knight and Replicator
static void Test5()
{
    cout << "****Test5\n";
    ECKnight f1("f1", 15, 3);
    ECDungeon dungeon(&f1);
    ECReplicator rm1("rm1", &dungeon, 7, 1);
    dungeon.AddMonster(&rm1);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 6);
    ASSERT_EQ(f1.IsDead(), false);
    ASSERT_EQ(rm1.IsDead(), true);
}

// Monster Test - Knight and Horde
static void Test6()
{
    cout << "****Test6\n";
    ECKnight f1("f1", 50, 3);
    ECDungeon dungeon(&f1);
    ECHorde hm1("hm1");
    ECSlime m2("m2", 2, 2);
    ECSlime m3("m3", 2, 2);
    ECSlime m4("m4", 2, 3);
    ECSlime m5("m5", 1, 2);
    hm1.AddMonster(&m2);
    hm1.AddMonster(&m3);
    hm1.AddMonster(&m4);
    hm1.AddMonster(&m5);

    dungeon.AddMonster(&hm1);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 4);
    ASSERT_EQ(f1.IsDead(), false);
    ASSERT_EQ(f1.getHealth(), 36);
    ASSERT_EQ(hm1.IsDead(), true);
    ASSERT_EQ(m2.IsDead(), true);
    ASSERT_EQ(m3.IsDead(), true);
    ASSERT_EQ(m4.IsDead(), true);
    ASSERT_EQ(m5.IsDead(), true);
}

// Combo Test - Brute and Horde/Replicator
static void Test7()
{
    cout << "****Test7\n";
    ECBrute f1("f1", 50, 3);
    ECDungeon dungeon(&f1);
    ECHorde hm1("hm1");
    ECSlime m2("m2", 2, 2);
    ECReplicator m3("m3", &dungeon, 9, 4);
    ECSlime m4("m4", 4, 3);
    ECSlime m5("m5", 8, 2);
    ECReplicator m6("m6", &dungeon, 14, 2);
    hm1.AddMonster(&m2);
    hm1.AddMonster(&m3);
    hm1.AddMonster(&m4);
    hm1.AddMonster(&m5);

    dungeon.AddMonster(&hm1);
    dungeon.AddMonster(&m6);
    int turnsCompleted = dungeon.SimulateDungeon();

    ASSERT_EQ(turnsCompleted, 13);
    ASSERT_EQ(f1.IsDead(), true);
    ASSERT_EQ(f1.getHealth(), -1);
    ASSERT_EQ(hm1.IsDead(), true);
    ASSERT_EQ(m2.IsDead(), true);
    ASSERT_EQ(m3.IsDead(), true);
    ASSERT_EQ(m4.IsDead(), true);
    ASSERT_EQ(m5.IsDead(), true);
    ASSERT_EQ(m6.IsDead(), true);
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
}
