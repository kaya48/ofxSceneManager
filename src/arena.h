#ifndef ARENA_H
#define ARENA_H

#include "ofxobject.h"
#include "gameobject.h"

class Arena : public ofxObject
{
public:
    static void add(GameObject &object);

    Arena(float _radius);

    void update();
    void draw();
    void exit();

    float getWidth();

private:
    static vector<reference_wrapper<GameObject>> objects;

    float radius;
};

#endif // ARENA_H
