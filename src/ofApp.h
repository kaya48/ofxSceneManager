#ifndef OFAPP_H
#define OFAPP_H

#include "ofMain.h"
#include "ofxscenemanager.h"

class ofApp : public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    void exit() override;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
};

#endif // OFAPP_H
