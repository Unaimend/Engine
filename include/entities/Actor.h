//
// Created by Thomas Dost on 05.03.17.
//

#ifndef ENGINE_ACTOR_H
#define ENGINE_ACTOR_H


#include <memory>
#include <map>
#include "ActorComponent.h"
class ActorFactory;

class Actor {
    friend class ActorFactory;
    typedef long ComponentId;
    typedef long ActorId;
    typedef std::map<ComponentId, std::shared_ptr<ActorComponent>> ActorCoponents;

    ActorId mId;
    ActorCoponents mComponents;

public:
    Actor(ActorId id)
    {
        mId = id;
    }
    ~Actor(){};

    //Called by Factory
    bool init(const eng::XmlElement& data)
    {

    }

    //Called by Factory
    void postInit()
    {

    }


    void destroy()
    {

    }


    void update()
    {

    }

    ActorId getId() const {return mId;}

    template<typename ComponentType>
            std::weak_ptr<ComponentType> getComponent(ComponentId id)
    {
        ActorCoponents::iterator findIt = mComponents.find(id);

        if(findIt != mComponents.end())
        {
            std::shared_ptr<ActorComponent> base(findIt->second);
            std::weak_ptr<ComponentType> sub(base);

            return base;
        }
        else
        {
            return std::weak_ptr<ComponentType>();
        }
    }

private:
    void addComponents(std::shared_ptr<ActorComponent> component)
    {

    }
};


#endif //ENGINE_ACTOR_H
