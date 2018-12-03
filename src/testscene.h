#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "ofxscene.h"
#include "arena.h"
#include "unit.h"
#include "unitmanager.h"
#include "shot.h"
#include "tapeffect.h"
#include "cameramanager.h"
#include "predictline.h"

class TestScene : public ofxScene
{
public:
    TestScene();

    Arena arena;
    CameraManager cameraManager;
    Unit unit;
    UnitManager unitManager;
    TapEffect tapEffect;
    PredictLine predictLine;
};

#endif // TESTSCENE_H
