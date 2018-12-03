#ifndef TAPEFFECT_H
#define TAPEFFECT_H

#include "ofColor.h"
#include "ofxobject.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"

class TapEffect : public ofxObject
{
    void setup();
    void update();
    void draw();
    void mousePressed(int button);
    void mouseDragged(int button);

    bool isVisible;
    float radius;
    float radiusMax;
    float speed;
};

#endif // MOUSEPOINTEREFFECT_H
