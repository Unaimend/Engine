//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Beschr.	Wrapper fuer Vectors
//Changelog	: Erstellt
//			  22.01.2016
//TODO:
//			eng::Graphics.hpp hinzufuegen
//***************************************************************
#include "EngineTypes.h"

namespace eng
{
	template<typename T>
	struct Vector2
	{
		Vector2() 
		: x(0),y(0){}; 
		Vector2(T x, T y)
		: x(0), y(0) {};

		//X-Koordinate
		T x;
		//Y-Koordinate
		T y;
	};

	using Vector2i = Vector2<int32>;
	using Vector2f = Vector2<float>;
}