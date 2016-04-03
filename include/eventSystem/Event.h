/************************************
*Author:        Thomas Dost
*Datum:         16.01.2016
*Beschr.        Klasse fuer Standard Events
*Changelog:
                        16.01.2016
*                       Erstellt
						20.01.2016
						std::string mEventName hinzugefuegt um Events zu identifizieren
						21.01.2016
						utility.h included
*TODO:			
				Variant in EvenArgs Kapsel
				Konstruktoren loeschen fuer EventArg, Event
				Kommentieren
				Lua Event Api
*************************************/



/*
Ich schmeise Event in die Queue z.b der EntityManager schaut naach dem Event onPlayerKill(exp, target)
wenn er es findet gibt er dem spieler dia anzahl exp und entfern target.
Erstmall in C++ spaeter mit Hilfer der Lua Api exposen, damit man Events dynamisch erstellen kann(zur Laufzeit, von 3. benutzern.)
Lua Api erstmal komplett ingnogieren
*/

#pragma once

#include "../Variant.h"
#include <map>
#include <string>
#include <initializer_list>
#include <iostream>
#include "../EngineTypes.h"
#include "../utility.h"
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
			mEventName = eng::util::toHash(EventName);
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

		}
	private:

	public:
	
		//Event Name als Hash
		eng::hash mEventName;
		//Map fuer Event Argument
		std::map<std::string, Variant> mArgs;
	};
}