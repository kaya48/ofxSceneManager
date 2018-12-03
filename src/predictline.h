#ifndef PREDICTLINE_H
#define PREDICTLINE_H

#include "ofxobject.h"
#include "unit.h"


class PredictLine : public ofxObject
{
public:
    PredictLine(Unit &_unit);

    void draw();

    Unit &unit;

};

#endif // PREDICTLINE_H
