//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Beschr.	Wrapper fuer Vectors
//Changelog	: Erstellt
//			  22.01.2016
//            03.06.2016
//            Pragma once geaddet
//            15.06.2016
//            operator<< hinzueefuegt
//            2. Konstuktor gefixt
//TODO:
//			eng::Graphics.hpp hinzufuegen
//***************************************************************
#pragma once

#include "../EngineTypes.h"

namespace eng
{
	template<typename T>
	struct Vector2
	{
        friend std::ostream& operator<<(std::ostream& out, Vector2<T> vec);
        Vector2()
		: x(0),y(0){}; 
		Vector2(T x, T y)
		: x(x), y(y) {};

		//X-Koordinate
		T x;
		//Y-Koordinate
		T y;
	};

	using Vector2i = Vector2<int32>;
	using Vector2f = Vector2<float>;
    
    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Vector2<T>& vec)
    {
        std::cout << "xValue:" << vec.x << "yValue" << vec.y << std::endl;
    }
}