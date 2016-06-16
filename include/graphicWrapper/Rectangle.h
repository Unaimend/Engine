//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Beschr.	Wrapper fuer Rectangles
//Changelog	: Erstellt
//			  22.01.2016
//           Grundfunktionalitaet hinzugefuegt
//15.06.2016
//           Rectangle(const eng::Vector2f& pos) hinzugefuegt
//
//TODO:
//			eng::Graphics.hpp hinzufuegen
//***************************************************************
#include <SFML/Graphics.hpp>

#include "Vector.h"
#include <iostream>
#pragma once
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
        Rectangle(const eng::Vector2f& pos)
        {
//           std::cout << "RECTAGLE CONSTRUKTOR"<< pos.x << " " << pos.y<<std::endl;
            mRectangle.setPosition(pos.x, pos.y);
            mRectangle.setSize(sf::Vector2f(20,20));
        }
        void draw(sf::RenderWindow& window) const
        {
            window.draw(mRectangle);
        }
        void move(const eng::Vector2f& vec);
    public:
        sf::RectangleShape mRectangle;
	};
    
    
    
}