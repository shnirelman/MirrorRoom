#include "Corner.h"
#include "FocusController.h"
#include "ModeController.h"

Corner::Corner(Vector^ position) : Focusable()
{
    this->position = position;
}

Vector^ Corner::getPosition()
{
    return position;
}

void Corner::setPosition(Vector^ position)
{
    this->position = position;
}

double Corner::getRadius()
{
    return radius;
}

void Corner::draw(System::Drawing::Graphics^ g)
{
    if (ModeController::getInstance()->getMode() != ModeController::ModeType::RoomEditing)
        return;

    g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red),
        System::Drawing::Rectangle(position->getX() - radius, position->getY() - radius,
            radius * 2, radius * 2));

    if (FocusController::getInstance()->getFocusedCorner() == this) {
        g->DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::Red),
            System::Drawing::Rectangle(position->getX() - radius * 1.6, position->getY() - radius * 1.6,
                radius * 3.2, radius * 3.2));
    }
}
