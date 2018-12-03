#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "ofxobject.h"

using std::vector;
using std::reference_wrapper;

class ofxScene
{
public:
    virtual ~ofxScene() {}

    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseDragged(int button);
    void mousePressed(int button);
    void mouseReleased(int button);

    void add(ofxObject &object);

private:
    vector<reference_wrapper<ofxObject>> objects;
};

#endif // SCENE_H
