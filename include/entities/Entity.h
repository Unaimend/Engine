/************************************
Author:    Thomas Dost
Datum:     15.06.2016
Beschr.    Oberklasse fuer alle Entities
Changelog:
19.06:2016
            Include Guards -> pragma once
            Auskommentiert
20.01.2016
            copy-assignment geloescht da er nicht korrekt funktioniert
27.01.2017
            Neuen Konstruktor hinzugefügt der nur eine Positon übernimmt
            #Ifdef SFML um void sf_event()
01.02.2016
            void move(distance x, distance y) hinzugefuegt
            draw(sf::RenderWindow &window) - >  draw(eng::Window &window)

TODO:
            Xml mData wird nicht kopiert im Assignment Operator
            sf::Sprite Wrapper schreiben und hier eine Sprite Variarble hinzufuegen.
*************************************/



#include <SFML/Graphics.hpp> //sf::<kram>
#include <iostream> //std::cerr

#include "../luaApi/LuaState.h"     // lua::LuaState
#include "../graphicWrapper/Vector.h"   //eng::Vector
#include "../graphicWrapper/Window.h"   //eng::Window
#include "../graphicWrapper/Rectangle.h"   //eng::Rectangle
#include "../../submodules/tinyxml2_wrapper/Xml.h"
#include "../globals.h"             //gLuastate, gEventQueue, SFML
#include "../eventSystem/Event.h"   //eng::Event
#include "../graphicWrapper/Sprite.h" //eng::Sprite
#include "../utility.h"   //eng::distance
#include <string>

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
        Entity(const eng::Vector2f& pos, lua::LuaState& state, const eng::Xml& data);


        /**********************************************
         *Descr:   Konstruktor um Entity zu initialisieren
         *Param1:   Position der Entity
         ***********************************************/
        Entity(const eng::Vector2f& pos);
        
        
        /**********************************************
         *Descr:   Copy-Konstruktor
        ***********************************************/
        Entity(const Entity& rhs);
        
        
        /**********************************************
         *Descr:    Copy-Assignment-Operator
         *Param1:   Zu kopierendes Objekt
         *Return:   Referenz aus *this;
         ***********************************************/
        Entity& operator=(const Entity& rhs) = delete;

        void draw(const eng::Window &window) const;

        virtual void move(eng::distance x, eng::distance y) = 0;

        virtual void update(float frametime) = 0;
        virtual void eng_event(const eng::Event &event) = 0;

#ifdef SFML
//@TODO Warum darf der Returnwert nicht const& sein
        const sf::Sprite getSprite() const
        {
            return mSprite.getSprite();
        }

        sf::Sprite getSprite()
        {
            return mSprite.getSprite();
        }

        void setScale(const eng::Vector2f& scale)
        {
            mSprite.setScale(scale);
        }
#endif

        void setPosition(const eng::Vector2f& pos)
        {
            mSprite.setPosition(pos);
        }

        const eng::Vector2f getPosition()
        {
            return mSprite.getPosition();
        }


    protected:
        eng::Sprite mSprite;
        //Position der Entity
        eng::Vector2f mPos{0,0};
        eng::Vector2f mVelocity{5,5};

        //Verweis auf den LuaState der jweiligen Entity
        //TODO Die Referenzen durch Pointer oder "normale" Varaiblen austauschen
        lua::LuaState& mState;
        //Daten der Entity
        const eng::Xml& mData;


    
    };


    static eng::Event ev1{"EntitiyDead",{"TEXT"},{ {eng::Variant::Type::INTEGER, 300} }};

}



