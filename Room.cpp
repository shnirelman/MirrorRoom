#include "Room.h"
#include "Mirror.h"
#include "FocusController.h"
#include <iostream>

Room^ Room::getInstance()
{
    if (instance)
        return instance;
    else
        return instance = gcnew Room();
}

void Room::draw(System::Drawing::Graphics^ g)
{
    for (int i = 0; i < mirrors->Count; i++) {
        Vector^ a = mirrors[i]->getBegin()->getPosition();
        Vector^ b = mirrors[i]->getEnd()->getPosition();
        mirrors[i]->draw(g);
    }

    for (int i = 0; i < corners->Count; i++)
        corners[i]->draw(g);    
}

void Room::addCorner(int pos, Corner^ corner)
{
    int mirPos = (pos == 0 ? corners->Count - 1 : pos - 1);
    Mirror^ newMir = mirrors[mirPos]->copy();
    mirrors[mirPos]->setEnd(corner);
    newMir->setBegin(corner);

    mirrors->Insert(pos, newMir);
    corners->Insert(pos, corner);
}

void Room::removeCorner(Corner^ corner)
{
    if (corners->Count <= 3)
        return;

    for (int i = 0; i < corners->Count; i++) {
        if (corners[i] == corner) {
            int mirPos = (i == 0 ? corners->Count - 1 : i - 1);
            int nxt = (i + 1 == corners->Count ? 0 : i + 1);

            std::cout << "remove corner " << i << " mirPos = " << mirPos << " nxt = " << nxt << std::endl;

            mirrors[mirPos]->setEnd(corners[nxt]);
            corners->RemoveAt(i);
            mirrors->RemoveAt(i);
            return;
        }
    }
}

System::Collections::Generic::List<Corner^>^ Room::getCorners()
{
    return corners;
}

System::Collections::Generic::List<Mirror^>^ Room::getMirrors()
{
    return mirrors;
}

double Room::getWidth()
{
    return width;
}

void Room::setWidth(double width)
{
    this->width = width;
}

double Room::getHeight()
{
    return height;
}

void Room::setHeight(double height)
{
    this->height = height;
}

void Room::update()
{
    for (int i = 0; i < mirrors->Count; i++)
        mirrors[i]->update();

    /*double area = 0;
    for (int i = 0; i < corners->Count; i++)
        area += corners[i]->getPosition()->vectorProduct(
            corners[(i + 1) % corners->Count]->getPosition());

    if (area < 0)
        reverse();*/
}

void Room::reverse()
{
    corners->Reverse();
    
    Mirror^ tmp = mirrors[mirrors->Count - 1];
    mirrors->RemoveAt(mirrors->Count - 1);
    mirrors->Reverse();
    mirrors->Add(tmp);

    for (int i = 0; i < mirrors->Count; i++)
        mirrors[i]->reverse();
}

void Room::divide()
{
    if (Mirror^ mirror = FocusController::getInstance()->getFocusedMirror()) {
        for (int i = 0; i < mirrors->Count; i++) {
            if (mirrors[i] == mirror) {
                addCorner(i + 1, gcnew Corner(
                    (mirror->getBegin()->getPosition() +
                        mirror->getEnd()->getPosition()) * 0.5));
            }
        }
    }
}

void Room::removeFocusedCorner()
{
    if (Corner^ corner = FocusController::getInstance()->getFocusedCorner()) {
        removeCorner(corner);
    }
}

Room::Room()
{
    corners = gcnew System::Collections::Generic::List<Corner^>();
    mirrors = gcnew System::Collections::Generic::List<Mirror^>();

    corners->Add(gcnew Corner(gcnew Vector(40, 40)));
    corners->Add(gcnew Corner(gcnew Vector(300, 40)));
    corners->Add(gcnew Corner(gcnew Vector(400, 400)));
    corners->Add(gcnew Corner(gcnew Vector(40, 300)));

    mirrors->Add(gcnew Mirror(corners[0], corners[1]));
    mirrors->Add(gcnew Mirror(corners[1], corners[2]));
    mirrors->Add(gcnew Mirror(corners[2], corners[3]));
    mirrors->Add(gcnew Mirror(corners[3], corners[0]));
}
