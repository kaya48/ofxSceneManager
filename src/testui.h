#ifndef TESTUI_H
#define TESTUI_H

#include "ofxscene.h"
#include "ofxUI.h"

class TestUI : public ofxScene
{
public:
    TestUI();

    void uiEvent(ofxUIEventArgs &event);

    ofxUICanvas canvas;
};

#endif // TESTUI_H
