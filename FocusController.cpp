#include "FocusController.h"
#include "ModeController.h"
#include "Ray.h"
#include <iostream>

FocusController^ FocusController::getInstance()
{
    if (instance)
        return instance;
    else
        return instance = gcnew FocusController();
}

void FocusController::onMouseDown(System::Windows::Forms::MouseEventArgs^ e)
{
    Vector^ pos = gcnew Vector(e->X, e->Y);
    
    mouseDown = true;

    if (ModeController::getInstance()->getMode() == ModeController::ModeType::RoomEditing) {
        System::Collections::Generic::List<Corner^>^ corners = Room::getInstance()->getCorners();
        for (int i = 0; i < corners->Count; i++) {
            if (pos->getDistance(corners[i]->getPosition()) < corners[i]->getRadius() + Vector::EPS) {
                longFocusedCorner = momentFocusedCorner = corners[i];
                longFocusedMirror = momentFocusedMirror = nullptr;
                return;
            }
        }

        System::Collections::Generic::List<Mirror^>^ mirrors = Room::getInstance()->getMirrors();
        for (int i = 0; i < mirrors->Count; i++) {
            if (mirrors[i]->getLine()->getDistance(pos) < Mirror::CollisionRadius) {
                longFocusedCorner = momentFocusedCorner = nullptr;
                longFocusedMirror = momentFocusedMirror = mirrors[i];
                return;
            }
        }
    
        momentFocusedCorner = nullptr;
        momentFocusedMirror = nullptr;
    
        longFocusedCorner = nullptr;
        longFocusedMirror = nullptr;
    }
    else if (ModeController::getInstance()->getMode() == ModeController::ModeType::RayCasting) {
        Ray::getInstance()->setStart(pos);
    }
    
}

void FocusController::onMouseUp(System::Windows::Forms::MouseEventArgs^ e)
{
    mouseDown = false;

    momentFocusedCorner = nullptr;
    momentFocusedMirror = nullptr;
}

void FocusController::onMouseMove(System::Windows::Forms::MouseEventArgs^ e)
{
    Vector^ pos = gcnew Vector(e->X, e->Y);
    
    if (mouseDown) {
        if (ModeController::getInstance()->getMode() == ModeController::ModeType::RoomEditing && 
            momentFocusedCorner) {
            if (pos->getX() < momentFocusedCorner->getRadius())
                pos->setX(momentFocusedCorner->getRadius());
            if (pos->getY() < momentFocusedCorner->getRadius())
                pos->setY(momentFocusedCorner->getRadius());

            if (pos->getX() + momentFocusedCorner->getRadius() > Room::getInstance()->getWidth())
                pos->setX(Room::getInstance()->getWidth() - momentFocusedCorner->getRadius());
            if (pos->getY() + momentFocusedCorner->getRadius() > Room::getInstance()->getHeight())
                pos->setY(Room::getInstance()->getHeight() - momentFocusedCorner->getRadius());
            momentFocusedCorner->setPosition(pos);
        }
        else if (ModeController::getInstance()->getMode() == ModeController::ModeType::RayCasting) {
            Ray::getInstance()->setStart(pos);
        }
    }
}


Corner^ FocusController::getFocusedCorner()
{
    if (ModeController::getInstance()->getMode() != ModeController::ModeType::RoomEditing)
        return nullptr;
    return longFocusedCorner;
}

Mirror^ FocusController::getFocusedMirror()
{
    if (ModeController::getInstance()->getMode() != ModeController::ModeType::RoomEditing)
        return nullptr;
    return longFocusedMirror;
}

bool FocusController::isMouseDown()
{
    return mouseDown;
}

FocusController::FocusController()
{
    momentFocusedCorner = nullptr;
    momentFocusedMirror = nullptr;

    longFocusedCorner = nullptr;
    longFocusedMirror = nullptr;
}
