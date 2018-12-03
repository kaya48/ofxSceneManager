#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "ofxscene.h"
#include "ofVec2f.h"
#include <memory>

using std::unique_ptr;

class ofxSceneManager
{
public:
    static void setup(ofxScene *&&scene);
    static void update();
    static void draw();
    static void exit();

    static void keyPressed(int key);
    static void keyReleased(int key);
    static void mouseDragged(int button);
    static void mousePressed(int button);
    static void mouseReleased(int button);

    static void setNext(ofxScene *&&_nextScene);

private:

    static unique_ptr<ofxScene> scene;
    static unique_ptr<ofxScene> nextScene;
};

class EmptyScene : public ofxScene {};

void ofxSetNextScene(ofxScene *&&_nextScene);
ofVec2f ofxGetMouse();

#endif // SCENEMANAGER_H
