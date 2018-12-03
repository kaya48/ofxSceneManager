#include "shot.h"

#include "camera.h"
#include "ofxscenemanager.h"

Shot::Shot(Unit &unit, int key)
    : Skill(unit, key, 0.2f)
    , range(480 * 4)
    , speed(480 * 4)
{

}

void Shot::keyReleased()
{

    ofVec2f world = Camera::worldPositionFrom(ofxGetMouse());
    ofVec2f direction;
    if (world != unit.getPosition()) {
        direction = (world - unit.getPosition()).getNormalized();
    } else {
        float theta = ofRandom(2 * PI);
        direction = ofVec2f(cos(theta), sin(theta));
    }

    for (int i = 0; i < bullets.size(); i++) {

        if (!bullets[i]->isActive()) {
            bullets[i]->init(unit, unit.getRadius() / 3.f, unit.getAttack(), range, speed, unit.getPosition(), direction);
            bullets[i]->setActive(true);
            return;
        }
    }

    unique_ptr<Bullet> newBullet (new Bullet(unit, unit.getRadius() / 3.f, unit.getAttack(), range, speed, unit.getPosition(), direction));
    instance(*newBullet);
    bullets.push_back(std::move(newBullet));
}
