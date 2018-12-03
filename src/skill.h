#ifndef SKILL_H
#define SKILL_H

#include "arena.h"

class Unit;

class Skill
{
public:
    static void instance(GameObject &object);

    Skill(Unit &_unit, int _key, float _coolTime);
    virtual ~Skill() {}

    void updateTimer();

    void keyPressed(int _key);
    void keyReleased(int _key);

    virtual void update() {}
    virtual void keyPressed() {}
    virtual void keyReleased() {}

protected:
    Unit&   unit;
    int     key;
    float   coolTime;
    float   timer;
    bool    ready;
};

#endif // SKILL_H
