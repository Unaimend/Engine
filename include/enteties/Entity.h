/************************************
*Author:    Thomas Dost
*Datum:     15.06.2016
*Beschr.    Oberklasse fuer alle Entities
*Changelog:
19.06:2016
            Include Guards -> pragma once
            Auskommentiert
*TODO:
            Xml mData wird nicht kopiert im Assignment Operator
*************************************/



#include <SFML/Graphics.hpp> //sf::<kram>

#include "../luaApi/LuaState.h"     // lua::LuaState
#include "../graphicWrapper/Vector.h"   //eng::Vector
#include "../graphicWrapper/Rectangle.h"   //eng::Rectangle
#include "../xmlWrapper/Xml.h"          //eng::Xml
#include "../globals.h"             //gLuastate, gEventQueue

#include <iostream>
#pragma once
namespace eng
{
    class Entity
    {

    
    public:
        /**********************************************
         *Descr:   Konstruktor um Entity zu initialisieren
         *Param1:   Position der Entity
         *Param2:   LuaState indem die Entity ablaeuft
         *Param3:   XmlState fuers Laden und Speichern der Entity
         ***********************************************/
        Entity(const eng::Vector2f& vec, lua::LuaState& state, const eng::Xml& data);
        
        
        /**********************************************
         *Descr:   Copy-Konstruktor
        ***********************************************/
        Entity(const Entity& rhs);
        
        
        /**********************************************
         *Descr:    Copy-Assignment-Operator
         *Param1:   Zu kopierendes Objekt
         *Return:   Referenz aus *this;
         ***********************************************/
        Entity& operator=(const Entity& rhs);
        
        
        //Virtuelle Funktion fuer Vererbungsbaum
        virtual void render(sf::RenderWindow& window) const = 0;
        virtual void update(float framtime) = 0;
        virtual void eng_update(const eng::Event& event) = 0;
        virtual void sf_update(const sf::Event& event) = 0;

    private:
        //Position der Entity
        eng::Vector2f mPos{0,0};
        //Verweis auf den LuaState der jweiligen Entity
        lua::LuaState& mState;
        //Daten der Entity
        const eng::Xml& mData;
    
    };
    
    
//Wird NICHT Refactored da Test Entity
    class RecEntity : public Entity
    {
        
    public:
        RecEntity(const eng::Vector2f& vec, lua::LuaState& state, const eng::Xml& data)
        : Entity(vec,state,data), mRec(vec)
        {
//              std::cout << vec.x << std::endl;
            
        }
        
        Rectangle mRec;
        virtual void render(sf::RenderWindow& window) const override
        {
            mRec.draw(window);
        }
        virtual void update(float frametime) override
        {
//            static eng::Event ev1{"Bigger300", {"TEXT"}, { {eng::Variant::Type::INTEGER, 55} }};
//            if(mRec.mRectangle.getPosition().x > 300)
//            {
//                gEventQueue.addEvent(ev1);
//              
//            }
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



