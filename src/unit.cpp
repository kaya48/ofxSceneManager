#include "unit.h"

#include "ofApp.h"
#include "ofxscenemanager.h"
#include "camera.h"

Unit::Unit(ofColor color, float _maxHP, float _attack, float _speed)
    : GameObject(UNIT_RADIUS, ofVec2f::zero(), color, "Unit")
    , hp(_maxHP)
    , maxHP(_maxHP)
    , attack(_attack)
    , speed(_speed)
    , skills()
    , targetPosition(position)
{

}

void Unit::update()
{
    updatePosition();
    updateSkills();
}

void Unit::keyPressed(int key)
{
    for (vector<unique_ptr<Skill>>::iterator
         begin = skills.begin(),
         end = skills.end();
         begin != end;
         begin++) {
        (*begin)->keyPressed(key);
    }
}

void Unit::keyReleased(int key)
{
    for (vector<unique_ptr<Skill>>::iterator
         begin = skills.begin(),
         end = skills.end();
         begin != end;
         begin++) {
        (*begin)->keyReleased(key);
    }
}

void Unit::mouseDragged(int button)
{
    mousePressed(button);
}

void Unit::mousePressed(int button)
{
    if (button == OF_MOUSE_BUTTON_RIGHT) {
        targetPosition = Camera::worldPositionFrom(ofxGetMouse());
    }
}

void Unit::damaged(float amount)
{
    if (amount > 0) {
        hp = std::max(0.f, hp - amount);
    }
}

void Unit::heal(float amount)
{
    if (amount > 0) {
        hp = std::min(hp + amount, maxHP);
    }
}

void Unit::add(Skill *&&skill)
{
    skills.push_back(unique_ptr<Skill>(skill));
}

float Unit::getAttack()
{
    return attack;
}

ofVec2f Unit::getTargetPosition()
{
    return targetPosition;
}

void Unit::updatePosition()
{
    float movement = speed * ofGetLastFrameTime();
    ofVec2f direction = targetPosition - position;

    if ((direction.length() * 2) > movement) {
        position += direction.getNormalized() * movement;
    } else {
        position = targetPosition;
    }
}

void Unit::updateSkills()
{
    for (vector<unique_ptr<Skill>>::iterator
         begin = skills.begin(),
         end = skills.end();
         begin != end;
         begin++) {
        (*begin)->update();
        (*begin)->updateTimer();
    }
}
