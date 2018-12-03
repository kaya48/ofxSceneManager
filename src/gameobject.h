#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "circle.h"
#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::reference_wrapper;

class GameObject : public Circle
{
public:
    GameObject(float radius, ofVec2f position, ofColor color, string _className);

    void update(vector<reference_wrapper<GameObject>> &others);

    virtual void update() {}
    virtual void exit() {}

    string getClassName();

    void setActive(bool _active);
    void setVisible(bool _visible);

    bool isActive();
    bool isVisible();

protected:
    void update(GameObject &other);

    string className;

    bool active;
    bool visible;

    vector<reference_wrapper<GameObject>> collisionObjects;
};

#endif // GAMEOBJECT_H
