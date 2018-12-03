#include "ofApp.h"

#include "testui.h"

void ofApp::setup()
{
    ofSetFullscreen(true);
    ofSetVerticalSync(true);

    ofxSceneManager::setup(new TestUI());
}

void ofApp::update()
{
    ofxSceneManager::update();
}

void ofApp::draw()
{
    ofxSceneManager::draw();
}

void ofApp::exit()
{
    ofxSceneManager::exit();
}

void ofApp::keyPressed(int key)
{
    ofxSceneManager::keyPressed(key);
}

void ofApp::keyReleased(int key)
{
    ofxSceneManager::keyReleased(key);
}

void ofApp::mouseDragged(int x, int y, int button)
{
    ofxSceneManager::mouseDragged(button);
}

void ofApp::mousePressed(int x, int y, int button)
{
    ofxSceneManager::mousePressed(button);
}

void ofApp::mouseReleased(int x, int y, int button)
{
    ofxSceneManager::mouseReleased(button);
}
