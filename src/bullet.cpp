#include "bullet.h"

#include "ofAppRunner.h"

Bullet::Bullet(Unit &_unit, float _radius, float _attack, float _range, float _speed, ofVec2f _position, ofVec2f _direction)
    : GameObject(_radius, _position, _unit.getColor(), "Bullet")
{
    init(_unit, _radius, _attack, _range, _speed, _position, _direction);
}

void Bullet::init(Unit &_unit, float _radius, float _attack, float _range, float _speed, ofVec2f _position, ofVec2f _direction)
{
    unit = &_unit;
    attack = _attack;
    range = _range;
    speed = _speed;
    direction = _direction;
    startPosition = _position;
    radius = _radius;
    position = _position;
    color = _unit.getColor();
}

void Bullet::update()
{
    if (isActive()) {

        position += direction * speed * ofGetLastFrameTime();
        if (startPosition.distance(position) >= range) {
            setActive(false);
        }

        for (GameObject &collisionObject : collisionObjects) {
            if (collisionObject.getClassName() == "Unit") {
                Unit &collisionUnit = (Unit&)collisionObject;
                if (unit != &collisionUnit) {
                    collisionUnit.damaged(attack);
                    setActive(false);
                    return;
                }
            }
        }
    }

}
