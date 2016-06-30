#include "/Users/thomasdost/Documents/dev/Engine/include/enteties/Entity.h"

eng::Entity::Entity(const eng::Vector2f& vec, lua::LuaState& state, const eng::Xml& data)
: mPos(vec), mState(state), mData(data) {}


eng::Entity::Entity(const Entity& rhs)
: mPos(rhs.mPos), mState(rhs.mState), mData(rhs.mData) {};

eng::Entity& eng::Entity::operator=(const Entity& rhs)
{
    mPos = rhs.mPos;
    mState = rhs.mState;
    //            mData = rhs.mData;
    std::cerr << "NICHT bentuzen: mData wird NICHT richtig kopiert" << std::endl;
    return *this;
}
