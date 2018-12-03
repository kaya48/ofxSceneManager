#include "arena.h"

#include "camera.h"
#include "ofGraphics.h"

vector<reference_wrapper<GameObject>> Arena::objects;

void Arena::add(GameObject &object)
{
    objects.push_back(object);
}

Arena::Arena(float _radius)
    : radius(_radius)
{
    objects.clear();
}

void Arena::update()
{
    for (GameObject &object : objects) {
        if (object.isActive()) {
            object.update(objects);
            object.update();
        }
    }
}

void Arena::draw()
{
    Camera::setupDraw();
    ofSetColor(ofColor::white);
    int fineness = 100;
    for (int i = 0; i < getWidth() / fineness; i++) {
        ofVec2f startPosition = Camera::screenPositionFrom(ofVec2f(i * fineness, 0.f));
        ofVec2f endPosition = Camera::screenPositionFrom(ofVec2f(i * fineness, getWidth()));
        ofDrawLine(startPosition, endPosition);
    }
    for (int i = 0; i < getWidth() / fineness; i++) {
        ofVec2f startPosition = Camera::screenPositionFrom(ofVec2f(0.f, i * fineness));
        ofVec2f endPosition = Camera::screenPositionFrom(ofVec2f(getWidth(), i * fineness));
        ofDrawLine(startPosition, endPosition);
    }
    Camera::exitDraw();

    for (GameObject &object : objects) {
        if (object.isVisible()) {
            Camera::draw(object);
        }
    }
}

void Arena::exit()
{
    for (GameObject &object : objects) {
        object.exit();
    }
}

float Arena::getWidth()
{
    return radius * 2.f;
}
