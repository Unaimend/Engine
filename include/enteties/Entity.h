/************************************
 *Author:    Thomas Dost
 *Datum:     1506.2016
 *Beschr.    Oberklasse fuer alle Entities
 *Changelog:
 *TODO:
 *************************************/



#ifndef Entity_h
#define Entity_h
#include "../luaApi/LuaState.h"
#include "../graphicWrapper/Vector.h"
#include "../xmlWrapper/Xml.h"
#include "../globals.h"


namespace eng
{
    class Entity
    {

    
    public:
        /**********************************************
         *Descr:   Konstruktor um Entity zu initialisieren
         ***********************************************/
        Entity(const eng::Vector2f& vec, lua::LuaState& state, const eng::Xml& data)
        : mPos(vec), mState(state), mData(data)
        {
          
        }
        //Position der Entity
        eng::Vector2f mPos{0,0};
        //Verweis auf den LuaState der jweiligen Entity
        lua::LuaState& mState;
        //Daten der Entity
        const eng::Xml& mData;
    
        virtual void render(sf::RenderWindow& window) const = 0;
        virtual void update(float framtime) = 0;
        virtual void eng_update(const eng::Event& event) = 0;
        virtual void sf_update(const sf::Event& event) = 0;
    
    };
    
    
    class RecEntity : public Entity
    {
        
    public:
        RecEntity(const eng::Vector2f& vec, lua::LuaState& state, const eng::Xml& data)
        : Entity(vec,state,data), mRec(vec.x, vec.y)
        {
              std::cout << vec.x << std::endl;
            
        }
        
        eng::Rectangle mRec;
        virtual void render(sf::RenderWindow& window) const override
        {
            mRec.draw(window);
        }
        virtual void update(float frametime) override
        {
            static eng::Event ev1{"Bigger300", {"TEXT"}, { {eng::Variant::Type::INTEGER, 55} }};
            if(mRec.mRectangle.getPosition().x > 300)
            {
//                gEventQueue.addEvent(ev1);
              
            }
        }
        virtual void eng_update(const eng::Event& event) override
        {
            ;
        }
        virtual void sf_update(const sf::Event& event) override
        {
            ;
        }
    };
    
}


#endif /* Entity_h */
