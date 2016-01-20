/************************************
*Author:        Thomas Dost
*Datum:         16.01.2016
*Beschr.        Klasse fuer standard Events
*Changelog:
                        16.01.2016
*                       Erstellt
*TODO:			
				Variant in EvenArgs Kapsel
				Konstruktoren loeschen fuer EventArg, Event
				Kommentieren

*************************************/


#pragma once
#include "EngineTypes.h"
#include "Variant.h"
#include <map>
#include <string>
#include <initializer_list>
#include <iostream>
	
namespace eng
{
	struct EventArg
	{
		Variant mArg;
	};

	class Event
	{
	public:
		/***********************************
		*Descri:	Konstruktor fuer Events
		*Param1:	Identifier fuer die Argumente
		*Param2:	Werte der Argumente
		*Return:
		************************************/
		Event(std::string EventName, std::initializer_list<std::string> identifiers, std::initializer_list<Variant> args)
		{
			mEventName = std::hash<std::string>()(EventName);
			if(identifiers.size() != args.size())
			{
				std::cout << "initializer_list do need to have the same size" << std::endl;
			}

			auto it = identifiers.begin();
			auto it2 = args.begin();
			
			for(; it < identifiers.end(); ++it, ++it2)
			{
				mArgs[*it] = *it2;
			}

			for(auto& it : mArgs)
			{
				std::cout << it.second << std::endl; 

			}
		}
	private:
	public:
	private:
		hash mEventName;
		//Map fuer Event Argument
		std::map<std::string, Variant> mArgs;
	};
}