//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Beschr.	Klasse um 2 Dimensionale Vektoren darzustellen
//Changelog	: Erstellt
//			  22.01.2016
//            03.06.2016
//            Pragma once geaddet
//            15.06.2016
//            operator<< hinzufuegt
//            2. Konstuktor gefixt
//         05.03.2017
//         operator+ und operator- hinzufuegt
//         Kommmentiert
//TODO:
//			eng::Graphics.hpp hinzufuegen
//          Auskommentieren
//***************************************************************
#pragma once

#include "../EngineTypes.h"
#include "../globals.h"

namespace eng
{
	template<typename T>
	struct Vector2
	{
    friend std::ostream& operator<<(std::ostream& out, Vector2<T> vec);
    //Default Konstruktor
    Vector2() : x(0),y(0){};


    /*******
    *Konstruktor
    *Para11: X-Koordinate des Vektors
    *Param2: Y-Koordinate des Vektors
    ***************/
		Vector2(T x, T y) : x(x), y(y) {};


    //Konversion-Funktion von sf::Vector zu eng::Vector
#ifdef SFML
		Vector2<T> (const sf::Vector2<T>& vec)
		{
			x = vec.x;
			y = vec.y;
		}
#endif
    /*******************
    *Add this vector to another one
    *Param1: the vector to add
    *Return: A new vector which components are ...
    ****************/
    const Vector2<T> operator+(const Vector2<T> rhs)
		{
			return Vector2<T>{x+ rhs.x, y + rhs.y};
		}

    /*******************
     *Subtracts this vector to another one
     *Param1: the vector to add
     *Return: A new vector which components are ...
     ****************/
    const Vector2<T> operator-(const Vector2<T> rhs)
		{
			return Vector2<T>{x - rhs.x, y - rhs.y};
		}

		//X-Koordinate
		T x;
		//Y-Koordinate
		T y;
	};

	using Vector2i = Vector2<int32>;
	using Vector2f = Vector2<float>;



//    template<typename T>
//    std::ostream& operator<<(std::ostream& out, const Vector2<T>& vec)
//    {
//        std::cout << "xValue:" << vec.x << "yValue" << vec.y << std::endl;
//    }
}
