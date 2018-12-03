#include "circle.h"

Circle::Circle(int _radius, ofVec2f _position, ofColor _color, bool _fill)
    : radius(_radius)
    , position(_position)
    , color(_color)
    , fill(_fill)
{

}

bool Circle::inside(ofVec2f point) const
{
    float distance = position.distance(point);
    return distance < radius;
}

bool Circle::inside(const Circle &other) const
{
    float distance = position.distance(other.getPosition());
    float radiusSum = radius + other.getRadius();
    return distance < radiusSum;
}

void Circle::setRadius(float _radius)
{
    radius = _radius;
}

void Circle::setPosition(ofVec2f _position)
{
    position = _position;
}

void Circle::setColor(ofColor _color)
{
    color = _color;
}

void Circle::setFill(bool _fill)
{
    fill = _fill;
}

float Circle::getRadius() const
{
    return radius;
}

ofVec2f Circle::getPosition() const
{
    return position;
}

ofColor Circle::getColor() const
{
    return color;
}

bool Circle::isFill() const
{
    return fill;
}
