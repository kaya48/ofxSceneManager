#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include "ofxobject.h"
#include "unit.h"

class UnitManager : public ofxObject
{
public:
    UnitManager(Unit &_unit);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseDragged(int button);
    void mousePressed(int button);
    void mouseReleased(int button);

    Unit &unit;
};

#endif // UNITMANAGER_H
