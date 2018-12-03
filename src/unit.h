#ifndef UNIT_H
#define UNIT_H

#include "gameobject.h"
#include "skill.h"
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

#define UNIT_RADIUS 48

class Unit : public GameObject
{
public:
    Unit(ofColor color, float _maxHP, float _attack, float _speed);

    void update();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseDragged(int button);
    void mousePressed(int button);
    void damaged(float amount);
    void heal(float amount);
    void add(Skill *&&skill);

    float getAttack();
    ofVec2f getTargetPosition();

private:
    void updatePosition();
    void updateSkills();

    float hp;
    float maxHP;
    float attack;
    float speed;

    vector<unique_ptr<Skill>> skills;

    ofVec2f targetPosition;
};

#endif // UNIT_H
