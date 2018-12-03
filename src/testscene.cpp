#include "testscene.h"

TestScene::TestScene()
    : arena(10000)
    , unit(ofColor::green, 100.f, 10.f, 480.f)
    , unitManager(unit)
    , predictLine(unit)
{
    unit.add(new Shot(unit, 'q'));
    arena.add(unit);
    add(arena);
    add(unitManager);
    add(tapEffect);
    add(cameraManager);
    add(predictLine);
}
