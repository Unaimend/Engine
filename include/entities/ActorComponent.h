//
// Created by Thomas Dost on 05.03.17.
//

#ifndef ENGINE_ACTORCOMPONENT_H
#define ENGINE_ACTORCOMPONENT_H

#include "../../submodules/tinyxml2_wrapper/Xml.h"


class Actor;
class ActorComponent
{
    typedef long ComponentId;
    friend class ActorFactory;
protected:
    std::shared_ptr<Actor> mOwner;
public:
    virtual ~ActorComponent(){}

    //These Functions are meant to be overridden by the implementation classes of the components.
    virtual bool init(const eng::Xml& data) = 0;
    virtual void postInit() {}
    virtual void update(double frametime) {}

    virtual ComponentId getComponent() const = 0;
private:
    void setOwner(std::shared_ptr<Actor> owner) { mOwner = owner;}
};


#endif //ENGINE_ACTORCOMPONENT_H
