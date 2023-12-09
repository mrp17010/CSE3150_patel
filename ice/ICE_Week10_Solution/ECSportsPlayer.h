#ifndef _EC_SPORTS_PLAYER_H
#define _EC_SPORTS_PLAYER_H

// ********************************************
// Sports Tournament
class ECTournament
{
public:
  ECTournament(int mon, int mr) : month(mon), minRank(mr) {}
  int GetMonth() const { return month; }
  int GetMinRank() const { return minRank; }

private:
  int month;
  int minRank;
};

// ********************************************
// Generic player
class ECSportsPlayer
{
public:
  virtual bool CanPlay(ECTournament &tr) const
  {
    if( NegativePlay(tr) == true )
    {
      return false;
    }
    return PositivePlay(tr);
  }

  // return true if there is a POSITIVE rule letting player to play
  virtual bool PositivePlay(ECTournament &tr) const { return false; }
  // return true if there is NEGATIVE rule preventing player to play
  virtual bool NegativePlay(ECTournament &tr) const { return false; }
};

// ********************************************
// Ranked player
class ECSportsPlayerRanked : public ECSportsPlayer
{
public:
  ECSportsPlayerRanked(int r) : r(r) {}
  // return true if there is a POSITIVE rule letting player to play
  virtual bool PositivePlay(ECTournament &tr) const { return r <= tr.GetMinRank(); }

private:
  int r;
};

// ********************************************
// Decorator pattern: generic
class ECSportsPlayerDec : public ECSportsPlayer
{
public:
  ECSportsPlayerDec(ECSportsPlayer &player) : player(player) {} 
  // return true if there is a POSITIVE rule letting player to play 
  virtual bool PositivePlay(ECTournament &tr) const { return player.PositivePlay(tr); }
  // return true if there is NEGATIVE rule preventing player to play
  virtual bool NegativePlay(ECTournament &tr) const { return player.NegativePlay(tr); }

private:
  ECSportsPlayer &player;
}; 

// ********************************************
// Wildcard player: qualify for any tournament 
class ECSportsPlayerWildcard : public ECSportsPlayerDec 
{
public:
  ECSportsPlayerWildcard(ECSportsPlayer &playerOrig) : ECSportsPlayerDec(playerOrig) {}
  virtual bool PositivePlay(ECTournament &tr) const { return true; }
};

// ********************************************
// Displined player: cannot attend any tournament during the period of probation
class ECSportsPlayerDisciplined : public ECSportsPlayerDec 
{
public:
  ECSportsPlayerDisciplined(ECSportsPlayer &playerOrig, int mStart, int mEnd)  : ECSportsPlayerDec(playerOrig), mStart(mStart), mEnd(mEnd) {}
  virtual bool NegativePlay(ECTournament &tr) const { 
    int tm = tr.GetMonth();
    if( mStart <= tm && mEnd >= tm )
    {
      return true;
    }
   return ECSportsPlayerDec :: NegativePlay(tr); 
  }


private:
  int mStart;
  int mEnd;
};

// ********************************************
// Injured player: cannot attend any tournament during the period of injury(injury occurs at a single month) 
class ECSportsPlayerInjured : public ECSportsPlayerDec 
{
public:
  ECSportsPlayerInjured(ECSportsPlayer &playerOrig, int m) : ECSportsPlayerDec(playerOrig), m(m) {}
  virtual bool NegativePlay(ECTournament &tr) const {
    int tm = tr.GetMonth();
    if( tm == m )
    { 
      return true;
    }
   return ECSportsPlayerDec :: NegativePlay(tr);
  }

private:
  int m;
};

#endif
