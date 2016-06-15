//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Beschr.	Wrapper fuer Rectangles
//Changelog	: Erstellt
//			  22.01.2016
//           Grundfunktionalitaet hinzugefuegt
//TODO:
//			eng::Graphics.hpp hinzufuegen
//***************************************************************
//#include <SFML/

#include "Vector.h"
namespace eng
{
	class Rectangle
	{
    public:
        Rectangle(int x, int y)
        {
            mRectangle.setPosition(x, y);
            mRectangle.setSize(sf::Vector2f(20,20));
        }
        void draw(sf::RenderWindow& window)
        {
            window.draw(mRectangle);
        }
        void move(const eng::Vector2f vec)
        {
            mRectangle.move(vec.x, vec.y);
        }
    
    private:
        sf::RectangleShape mRectangle;
	};
    
    
    
}