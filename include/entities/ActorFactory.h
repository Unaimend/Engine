//
// Created by Thomas Dost on 05.03.17.
//

#ifndef ENGINE_ACTORFACTORY_H
#define ENGINE_ACTORFACTORY_H


#include <map>
#include "ActorComponent.h"
#include "Actor.h"


class ActorFactory {
    typedef ActorComponent *(*ActorComponentCreator)(void);
    typedef std::map<std::string, ActorComponentCreator> ActorComponentCreatorMap;

    typedef unsigned long ActorId;
    typedef std::shared_ptr<Actor> sharedActorPtr;
    typedef std::shared_ptr<ActorComponent> StrongActorComponentPtr;

    friend class Actor;
    ActorId mId;
protected:
    ActorComponentCreatorMap mActorCoponentCreators;

public:
    ActorFactory();
    std::shared_ptr createActor(const char* actorResource);

protected:
    virtual StrongActorComponentPtr createComponent(eng::Xml data) {
//        std::string name(data.Value());
//        StrongActorComponentPtr pComponent;
//        auto findIt = m_actorComponentCre.find(name);
//        if (findIt != m_actorComponentCreators.end()) {
//            ActorComponentCreator creator = findIt->second;
//            pComponent.reset(creator());
//        } else {
//            GCC_ERROR(“Couldn’t
//            find
//            ActorComponent named ” +name);
//            return StrongActorComponentPtr(); // fail }
//// initialize the component if we found one if (pComponent)
//            {
//                if (!pComponent->Init(pData)) {
//                    GCC_ERROR(“Component
//                    failed
//                    to
//                    initialize: ” +name);
//                    return StrongActorComponentPtr();
//                }
//            }
//// pComponent will be NULL if the component wasn’t found. This isn’t
//// necessarily an error since you might have a custom CreateComponent() // function in a subclass.
//            return pComponent;
//        }

    }



    sharedActorPtr ActorFactory::CreateActor(const char* actorResource)
    {
        // Grab the root XML node TiXmlElement* pRoot =
        eng::Xml actorData(actorResource);
        eng::XmlElement root = actorData.rootElement();

        if(root.isNotNull())
        {
            std::cerr << "Failed to create actor from" << std::endl;
            actorData.print();
            return std::shared_ptr<Actor>();

        }

        std::shared_ptr<Actor> actor(new Actor(getNextActorId()));
        if(!actor->init(root))
        {
            std::cerr << "Failed to create actor from" << std::endl;
            actorData.print();
            return std::shared_ptr<Actor>();
        }

        auto elem = root;
        while(elem.isNotNull())
        {
            std::shared_ptr<ActorComponent> component(createComponent(actorData));
            if (component)
            {
                actor->addComponents(component);
                component->setOwner(actor);
            }
            else
            {
                return sharedActorPtr();
            }

            actor->postInit();
            ++elem;
            return actor;
        }




    }

    private:
    ActorId getNextActorId(void) { ++mId; return mId; }
};




#endif //ENGINE_ACTORFACTORY_H
