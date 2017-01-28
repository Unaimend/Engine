/***************************************************************
*Author: Thomas Dost
*Version: 1.0.0
*Beschr.	Wrapper fuer Rectangles
*Changelog	: Erstellt
*			  22.01.2016
*           Grundfunktionalitaet hinzugefuegt
*15.06.2016
*           Rectangle(const eng::Vector2f& pos) hinzugefuegt
*19.06.2016
*           Funktionen in cpp ausgelagert
*           Alles auskommentiert
*           getPosition, getSfRectangle hinzugefuegt
*TODO:
*           Conversion Operator fuer SFML mit gloablen define
*           ob SFML genutzt wird.
***************************************************************/
#include <SFML/Graphics.hpp> //sf::Rectangle

#include "Vector.h" //eng::Vector

#include "../globals.h"


#pragma once
namespace eng
{
    class Rectangle
	{
    public:
        /**********************************************
         *Descr:    Default-Konstruktor
         ***********************************************/
        Rectangle();
       
        /**********************************************
         *Descr:    1. Konstruktor, delegiert and 3. Konstruktor
         *Param1:   X-Koordinate des Rechtecks
         *Param2:   Y-Koordinate des Rechtecks
        ***********************************************/
        Rectangle(float x, float y);
        
        
        /**********************************************
         *Descr:    2. Konstruktor, delegiert and 3. Konstruktor
         *Param1:   X und Y-Koordinate des Rechtecks
         ***********************************************/
        Rectangle(const eng::Vector2f& pos);
        
        
        /**********************************************
         *Descr:    3. Konstruktor
         *Param1:   X und Y-Koordinate des Rechtecks
         ***********************************************/
        Rectangle(const eng::Vector2f& pos, const eng::Vector2f& size);

        
        /**********************************************
         *Descr:    Copy-Konstuktor
         *Param1:   Zu kopierendes Objekt
         ***********************************************/
        Rectangle(const Rectangle& rhs);
        
        
        /**********************************************
         *Descr:    Copy-Assignment-Operator
         *Param1:   Zu kopierendes Objekt
         *Return:   Referenz aus *this;
         ***********************************************/
        Rectangle& operator=(const Rectangle& rhs);


#ifdef SFML
        /**********************************************
         *Descr:    Funktion um Rectangle zu drawn
         *Param1:   Fenster in das gedrawed werden soll
         ***********************************************/
        void draw(sf::RenderWindow& window) const;
#endif
        
        /**********************************************
         *Descr:    Funktion um Rechteck zu bewegen
         *Param1:   X und Y-Richtung in die bewegt werden soll
         ***********************************************/
        void move(const eng::Vector2f& vec);
        
#ifdef SFML
        /**********************************************
         *Descr:    Getter-Funktion
         *Return:   sf::Rectangle dieser Klasse
         ***********************************************/
        const sf::RectangleShape& getSfRectangle() const;
#endif

        /**********************************************
         *Descr:   Getter-Funktion
         *Return:  Position des sf::Rectangles
         ***********************************************/
        const eng::Vector2f getPosition() const;
        

    private:
        //Standardbreite
        const float DEFAULT_WIDTH = 20;
        //Standardhoehe
        const float DEFAULT_HEIGHT = 20;
#ifdef SFML
        //Das eigentliche Rechteck
        sf::RectangleShape mRectangle;
#endif

	};
    
    
    
}