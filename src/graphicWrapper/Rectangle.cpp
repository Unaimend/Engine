#include "../../include/graphicWrapper/Rectangle.h"

void eng::Rectangle::move(const eng::Vector2f& vec)
{
    mRectangle.move(vec.x, vec.y);
}
