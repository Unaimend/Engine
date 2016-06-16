#include "../../include/graphicWrapper/Rectangle.h"
#include "../../include/eventSystem/Event.h"
#include "../../include/Variant.h"
#include "../../include/globals.h"


void eng::Rectangle::move(const eng::Vector2f& vec)
{
        mRectangle.move(vec.x, vec.y);
}
