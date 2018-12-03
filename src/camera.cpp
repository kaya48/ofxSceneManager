#include "camera.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "ofxscenemanager.h"

float   Camera::width = 2560;
float   Camera::height = 1440;
ofVec2f Camera::position = ofVec2f::zero();

void Camera::draw(Circle &circle)
{
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(screenPositionFrom(circle.getPosition()));
    ofScale(ofGetWidth() / width, ofGetHeight() / height);
    if (circle.isFill()) {
        ofFill();
    } else {
        ofNoFill();
    }
    ofSetColor(circle.getColor());
    ofDrawCircle(0.f, 0.f, circle.getRadius());
    ofPopStyle();
    ofPopMatrix();
}

void Camera::setupDraw()
{
    ofPushMatrix();
    ofPushStyle();
    ofScale(ofGetWidth() / width, ofGetHeight() / height);
}

void Camera::exitDraw()
{
    ofPopStyle();
    ofPopMatrix();
}

ofVec2f Camera::screenPositionFrom(ofVec2f world)
{
    ofVec2f screenPosition = world - position;
    screenPosition.x = ofGetWidth()  * screenPosition.x / width;
    screenPosition.y = ofGetHeight() * screenPosition.y / height;
    return screenPosition;
}

ofVec2f Camera::worldPositionFrom(ofVec2f screen)
{
    ofVec2f worldPosition = position;
    worldPosition.x += width  * screen.x / ofGetWidth();
    worldPosition.y += height * screen.y / ofGetHeight();
    return worldPosition;
}

ofVec2f Camera::getWorldMouse()
{
    return worldPositionFrom(ofxGetMouse());
}

float Camera::getWidth()
{
    return width;
}

float Camera::getHeight()
{
    return height;
}

ofVec2f Camera::getPosition()
{
    return position;
}

void Camera::setPosition(ofVec2f _position)
{
    position = _position;
}

void Camera::addPosition(ofVec2f _position)
{
    position += _position;
}

