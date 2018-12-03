#include "predictline.h"
#include "ofGraphics.h"
#include "camera.h"

PredictLine::PredictLine(Unit &_unit)
    : unit(_unit)
{

}

void PredictLine::draw()
{
    ofPushStyle();
    ofSetColor(ofColor::black);
    ofVec2f startPosisition = Camera::screenPositionFrom(unit.getPosition());
    ofVec2f endPosition     = Camera::screenPositionFrom(unit.getTargetPosition());
    ofDrawLine(startPosisition, endPosition);
    ofPopStyle();
}
