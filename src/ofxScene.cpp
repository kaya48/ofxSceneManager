#include "ofxscene.h"

void ofxScene::setup()
{
    for (ofxObject &object : objects) {
        object.setup();
    }
}

void ofxScene::update()
{
    for (ofxObject &object : objects) {
        object.update();
    }
}

void ofxScene::draw()
{
    for (ofxObject &object : objects) {
        object.draw();
    }
}

void ofxScene::exit()
{
    for (ofxObject &object : objects) {
        object.exit();
    }
}

void ofxScene::keyPressed(int key)
{
    for (ofxObject &object : objects) {
        object.keyPressed(key);
    }
}

void ofxScene::keyReleased(int key)
{
    for (ofxObject &object : objects) {
        object.keyReleased(key);
    }
}

void ofxScene::mouseDragged(int button)
{
    for (ofxObject &object : objects) {
        object.mouseDragged(button);
    }
}

void ofxScene::mousePressed(int button)
{
    for (ofxObject &object : objects) {
        object.mousePressed(button);
    }
}

void ofxScene::mouseReleased(int button)
{
    for (ofxObject &object : objects) {
        object.mouseReleased(button);
    }
}

void ofxScene::add(ofxObject &object)
{
    objects.push_back(object);
}

