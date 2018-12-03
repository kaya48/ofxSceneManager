#include "skill.h"

#include "unit.h"
#include "ofAppRunner.h"

void Skill::instance(GameObject &object)
{
    Arena::add(object);
}

Skill::Skill(Unit &_unit, int _key, float _coolTime)
    : unit(_unit)
    , key(_key)
    , coolTime(_coolTime)
    , timer(_coolTime)
    , ready(true)
{

}

void Skill::updateTimer()
{
    if (timer > 0) {
        timer -= ofGetLastFrameTime();
    }
}

void Skill::keyPressed(int _key)
{
    if (key == _key) {
        keyPressed();
    }
}

void Skill::keyReleased(int _key)
{
    if (key == _key) {
        if (timer <= 0) {
            timer = coolTime;
            keyReleased();
        }
    }
}
