#ifndef OBJECT_H
#define OBJECT_H

class ofxObject
{
public:
    virtual ~ofxObject() {}
    virtual void setup() {}
    virtual void update() {}
    virtual void draw() {}
    virtual void exit() {}

    virtual void keyPressed(int key) {}
    virtual void keyReleased(int key) {}
    virtual void mouseDragged(int button) {}
    virtual void mousePressed(int button) {}
    virtual void mouseReleased(int button) {}
};

#endif // OBJECT_H
