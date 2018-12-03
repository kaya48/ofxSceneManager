#ifndef CAMERA_H
#define CAMERA_H

#include "ofVec2f.h"
#include "circle.h"

class Camera
{
public:
    static void draw(Circle &circle);

    static void setupDraw();
    static void exitDraw();

    static ofVec2f screenPositionFrom(ofVec2f world);
    static ofVec2f worldPositionFrom(ofVec2f screen);

    static ofVec2f getWorldMouse();

    static float    getWidth();
    static float    getHeight();
    static ofVec2f  getPosition();

    static void setPosition(ofVec2f _position);
    static void addPosition(ofVec2f _position);

private:

    static float   width;
    static float   height;
    static ofVec2f position;
};

#endif // CAMERA_H
