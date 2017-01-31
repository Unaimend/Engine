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

TODO:
            Xml mData wird nicht kopiert im Assignment Operator
            sf::Sprite Wrapper schreiben und hier eine Sprite Variarble hinzufuegen.
*************************************/



#include <SFML/Graphics.hpp> //sf::<kram>
#include <iostream> //std::cerr

#include "../luaApi/LuaState.h"     // lua::LuaState
#include "../graphicWrapper/Vector.h"   //eng::Vector
#include "../graphicWrapper/Rectangle.h"   //eng::Rectangle
#include "../xmlWrapper/Xml.h"          //eng::Xml
#include "../globals.h"             //gLuastate, gEventQueue, SFML
#include "../eventSystem/Event.h"   //eng::Event
#include "../graphicWrapper/Sprite.h" //eng::Sprite

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
        
        
        //Virtuelle Funktion fuer Vererbungsbaum
        virtual void render(sf::RenderWindow& window) const = 0;
        virtual void update(float framtime) = 0;
        virtual void eng_event(const eng::Event &event) = 0;

#ifdef SFML
        virtual void sf_event(const sf::Event &event) = 0;
#endif
    private:
        eng::Sprite mSprite;
        //Position der Entity
        eng::Vector2f mPos{mSprite.getPosition().x,mSprite.getPosition().y};
        //Verweis auf den LuaState der jweiligen Entity
        //TODO Die Referenzen durch Pointer oder "normale" Varaiblen austauschen
        lua::LuaState& mState;
        //Daten der Entity
        const eng::Xml& mData;


    
    };


    static eng::Event ev1{"EntitiyDead",{"TEXT"},{ {eng::Variant::Type::INTEGER, 300} }};













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


        ~RecEntity()
        {
            gEventQueue.addEvent(ev1);
        }
        virtual void render(sf::RenderWindow& window) const override
        {
            mRec.draw(window);
        }


        virtual void update(float frametime) override
        {
            ;
        }
        virtual void eng_event(const eng::Event &event) override
        {
            ;
        }
        virtual void sf_event(const sf::Event &event) override
        {
            ;
        }
    };

}



