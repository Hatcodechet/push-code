#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType {/* TODO: */};

class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent;

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;

public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

class ArmyKnights {
private:
    int cnt_Knight;
    BaseKnight* Knight;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseItem {

public:
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};

class Events {
private:
    int cnt_evemts;
    int* events;
public:
    Events(const string&);
    int count() const;
    int get(int i) const;
    ~Events();
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

// Base Knight -----------------------------------------

static BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    this->id = id;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;

}

// Army Knight --------------------------------------

ArmyKnights::ArmyKnights(const string& file_armyknights)
{
    ifstream ifs(file_armyknights);
    ifs >> cnt_Knight;
    Knight = new int[cnt_Knight];
    for (int i = 0; i < cnt_Knight; i++)
    {
        ifs >> Knight[i].hp;

    }
}

// Events -----------------------------------------

Events::Events(const string& file_events)
{
    ifstream ifs(file_events);
    ifs >> cnt_events;
    events = new int[cnt_evemts];
    for (int i = 0; i < cnt_events; i++)
    {
        ifs >> events[i];
    }
    ifs.close();
}

int Events::count() const
{
    return cnt_events;
}

int Events::get(int i) const
{
    return events[i];
}

Events::~Events()
{
    delete[] events;
}


#endif // __KNIGHT2_H__