#include "ofxscenemanager.h"

#include "ofApp.h"

unique_ptr<ofxScene> ofxSceneManager::scene(new EmptyScene());
unique_ptr<ofxScene> ofxSceneManager::nextScene;

void ofxSceneManager::setup(ofxScene *&&scene)
{
    setNext(std::move(scene));
}

void ofxSceneManager::update()
{
    if (nextScene) {
        scene->exit();
        scene = std::move(nextScene);
        scene->setup();
    }

    scene->update();
}

void ofxSceneManager::draw()
{
    scene->draw();
}

void ofxSceneManager::exit()
{
    scene->exit();
}

void ofxSceneManager::keyPressed(int key)
{
    scene->keyPressed(key);
}

void ofxSceneManager::keyReleased(int key)
{
    scene->keyReleased(key);
}

void ofxSceneManager::mouseDragged(int button)
{
    scene->mouseDragged(button);
}

void ofxSceneManager::mousePressed(int button)
{
    scene->mousePressed(button);
}

void ofxSceneManager::mouseReleased(int button)
{
    scene->mouseReleased(button);
}

void ofxSceneManager::setNext(ofxScene *&&_nextScene)
{
    if (!nextScene) {
        nextScene.reset(_nextScene);
    }
}


void ofxSetNextScene(ofxScene *&&_nextScene)
{
    ofxSceneManager::setNext(std::move(_nextScene));
}

ofVec2f ofxGetMouse()
{
    return ofVec2f(ofGetMouseX(), ofGetMouseY());
}
