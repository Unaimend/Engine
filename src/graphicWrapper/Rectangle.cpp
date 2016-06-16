#include "../../include/graphicWrapper/Rectangle.h"
#include "../../include/eventSystem/Event.h"
#include "../../include/Variant.h"
#include "../../include/globals.h"
eng::Event* temp = new eng::Event({"Name"},{"Var1"},{{eng::Variant::Type::INTEGER, 55}});

void eng::Rectangle::move(const eng::Vector2f& vec)
{
    mRectangle.move(vec.x, vec.y);
    gEventQueue.addEvent(temp);
    
}
