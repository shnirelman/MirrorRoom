#include "Line.h"

Line::Line(Vector^ begin, Vector^ end)
{
    this->begin = begin;
    this->end = end;
}

Line::Line(Line^ other)
{
    begin = other->getBegin();
    end = other->getEnd();
}

Vector^ Line::getTangent(Vector^ position)
{
    return getNormal(position)->getNormal()->normalize();
}

void Line::update()
{}

void Line::reverse()
{
    Vector^ tmp = begin;
    begin = end;
    end = tmp;
}

Vector^ Line::getBegin()
{
    return begin;
}

void Line::setBegin(Vector^ pos)
{
    begin = pos;
}

Vector^ Line::getEnd()
{
    return end;
}

void Line::setEnd(Vector^ pos)
{
    end = pos;
}