#include "gameobject.h"

GameObject::GameObject(float radius, ofVec2f position, ofColor color, std::string _className)
    : Circle(radius, position, color)
    , className(_className)
    , active(true)
    , visible(true)
    , collisionObjects()
{

}

void GameObject::update(vector<reference_wrapper<GameObject> > &others)
{
    collisionObjects.clear();
    for (GameObject &other : others) {
        update(other);
    }
}

std::string GameObject::getClassName()
{
    return className;
}

void GameObject::setActive(bool _active)
{
    active = visible = _active;
}

void GameObject::setVisible(bool _visible)
{
    visible = _visible;
}

bool GameObject::isActive()
{
    return active;
}

bool GameObject::isVisible()
{
    return visible;
}

void GameObject::update(GameObject &other)
{
    if (other.isActive()) {
        if (inside(other)) {
            if (this != &other) {
                collisionObjects.push_back(other);
            }
        }
    }
}
