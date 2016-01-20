/************************************
*Author: 	Thomas Dost
*Datum: 	26.12.2015
*Beschr.	Klasse um Texturen zu verarbeiten, die im Speicher der 
			GPU liegen.
*Changelog:
			26.12.2015
			Erstellt 
			sf::Texture mTexture hinzugefuegt
*TODO:
			Hardgecodete Textur hinzufuegen
*************************************/
#pragma once
#include <SFML/Graphics.hpp> //sf::Texture
#include <iostream>
#include "EngineTypes.h"	//Typedefs



namespace eng
{
	class Texture
	{
	public:
		/**********************************************
		*Descr:	 Konstruktor fuer das initilisieren der Klasse.
		*Param1: Pfad zur Textur
		***********************************************/
		Texture(const filepath& path);
	private: 
		//Textur
		sf::Texture mTexture;
	};
}