#ifndef CIRCLE_H
#define CIRCLE_H

#include "ofVec2f.h"
#include "ofColor.h"

class Circle
{
public:
    Circle(int _radius, ofVec2f _position, ofColor _color, bool _fill = true);
    virtual ~Circle() {}

    bool inside(ofVec2f point) const;
    bool inside(const Circle &other) const;

    void setRadius(float _radius);
    void setPosition(ofVec2f _position);
    void setColor(ofColor _color);
    void setFill(bool _fill);

    float   getRadius() const;
    ofVec2f getPosition() const;
    ofColor getColor() const;

    bool    isFill() const;

protected:
    float   radius;
    ofVec2f position;
    ofColor color;
    bool    fill;
};

#endif // CIRCLE_H
