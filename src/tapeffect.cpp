#include "tapeffect.h"

void TapEffect::setup()
{
    radius = 0.f;
    radiusMax = 16.f;
    speed = 88.f;
    isVisible = false;
}

void TapEffect::update()
{
    if (radius < radiusMax) {
        radius += speed * ofGetLastFrameTime();
    } else {
        isVisible = false;
    }
}

void TapEffect::draw()
{
    if (isVisible) {
        ofPushStyle();
        ofNoFill();
        ofSetColor(ofColor::black);
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), radius);
        ofFill();
        ofPopStyle();
    }
}

void TapEffect::mousePressed(int button)
{
    radius = 0;
    isVisible = true;
}

void TapEffect::mouseDragged(int button)
{
    mousePressed(button);
}
