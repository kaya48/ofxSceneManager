#ifndef SHOT_H
#define SHOT_H

#include "skill.h"
#include "unit.h"
#include "bullet.h"
#include "ofMath.h"
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

using std::reference_wrapper;

class Shot : public Skill
{
public:
    Shot(Unit &unit, int key);

    void keyReleased();

private:

    float speed;
    float range;
    vector<unique_ptr<Bullet>> bullets;
};

#endif // SHOT_H
