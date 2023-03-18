#include "Focusable.h"

Focusable::Focusable()
{
    focused = false;
}

bool Focusable::isFocused()
{
    return focused;
}

void Focusable::setFocus(bool focused)
{
    this->focused = focused;
    if (focused) {

    }
}
