#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "ofxobject.h"
#include "camera.h"

class CameraManager : public ofxObject
{
public:
    CameraManager();

    void update();

private:
    float speed;
};

#endif // CAMERAMANAGER_H
