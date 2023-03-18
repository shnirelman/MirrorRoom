#include "ModeController.h"
#include "Ray.h"

ModeController^ ModeController::getInstance()
{
    if (!instance)
        instance = gcnew ModeController();
    return instance;
}

ModeController::ModeType ModeController::getMode()
{
    return mode;
}

void ModeController::setMode(ModeController::ModeType mode)
{
    if (mode == ModeController::ModeType::RoomEditing) {

    } else if (mode == ModeController::ModeType::RayCasting) {
        Ray::getInstance()->makeValid();
        Ray::getInstance()->calcStart();
    }
    this->mode = mode;
}

ModeController::ModeController()
{
    
}
