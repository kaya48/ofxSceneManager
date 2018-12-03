#include "cameramanager.h"

#include "ofxscenemanager.h"
#include "ofAppRunner.h"

CameraManager::CameraManager()
{
    speed = 48 * 8;
}

void CameraManager::update()
{
    ofVec2f screenPosition = ofxGetMouse();
    ofVec2f direction = ofVec2f::zero();

    if (screenPosition.x <= 0) {
        direction.x = -1;
    }
    if (screenPosition.x >= ofGetWidth() - 1) {
        direction.x = 1;
    }
    if (screenPosition.y <= 0) {
        direction.y = -1;
    }
    if (screenPosition.y >= ofGetHeight() - 1) {
        direction.y = 1;
    }

    Camera::addPosition(direction * speed * ofGetLastFrameTime());
}
