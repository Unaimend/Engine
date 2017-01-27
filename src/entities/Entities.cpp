#include "../../include/entities/Entity.h"

eng::Entity::Entity(const eng::Vector2f& pos, lua::LuaState& state, const eng::Xml& data)
: mPos(pos), mState(state), mData(data) {}




eng::Entity::Entity(const eng::Vector2f const& pos)
        : mPos(pos), mState(gLuaState), mData(std::string("")) {}


eng::Entity::Entity(const Entity& rhs)
: mPos(rhs.mPos), mState(rhs.mState), mData(rhs.mData) {};

//eng::Entity& eng::Entity::operator=(const Entity& rhs)
//{
//    mPos = rhs.mPos;
//    mState = rhs.mState;
//    //            mData = rhs.mData;
//    std::cerr << "NICHT bentuzen: mData wird NICHT richtig kopiert" << std::endl;
//    return *this;
//}
