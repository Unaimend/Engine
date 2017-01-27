#include "../../include/graphicWrapper/Rectangle.h"



eng::Rectangle::Rectangle() : Rectangle({0,0}, {DEFAULT_WIDTH,DEFAULT_HEIGHT}) {}


eng::Rectangle::Rectangle(float x, float y) : Rectangle({x,y},{DEFAULT_WIDTH, DEFAULT_HEIGHT}) {}


eng::Rectangle::Rectangle(const eng::Vector2f& pos) : Rectangle(pos,{DEFAULT_WIDTH, DEFAULT_HEIGHT}) {}


eng::Rectangle::Rectangle(const eng::Vector2f& pos, const eng::Vector2f& size)
{
    mRectangle.setPosition(pos.x, pos.y);
    mRectangle.setSize(sf::Vector2f(size.x,size.y));
}

eng::Rectangle::Rectangle(const Rectangle& rhs) : mRectangle(rhs.mRectangle){};


eng::Rectangle& eng::Rectangle::operator=(const eng::Rectangle& rhs)
{
    mRectangle = rhs.mRectangle;
    return *this;
}


void eng::Rectangle::draw(sf::RenderWindow& window) const
{
    window.draw(mRectangle);
}


void eng::Rectangle::move(const eng::Vector2f& vec)
{
        mRectangle.move(vec.x, vec.y);
}

#ifdef SFML
const sf::RectangleShape& eng::Rectangle::getSfRectangle() const
{
    return mRectangle;
}
#endif

const eng::Vector2f eng::Rectangle::getPosition() const
{
#ifdef SFML
    return {mRectangle.getPosition().x, mRectangle.getPosition().y};
#endif
}


