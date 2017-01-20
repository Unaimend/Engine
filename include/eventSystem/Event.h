/************************************
*Author:        Thomas Dost
*Datum:         16.01.2016
*Beschr.        Klasse fuer Standard Events
*Changelog:
            16.01.2016
*           Erstellt
			20.01.2016
			std::string mEventName hinzugefuegt um Events zu identifizieren
			21.01.2016
			utility.h included
19.06.2016      
            Alles auskommentiert
            In Cpp ausgelagert
            toHash hinzugefuegt
*TODO:			
				Konstruktoren loeschen fuer EventArg, Event
				Kommentieren
				Lua Event Api
                Copy und Assignment schreiben
                Ausgabe funktion hinzufuegen
*************************************/



/*
Ich schmeise Event in die Queue z.b der EntityManager schaut naach dem Event onPlayerKill(exp, target)
wenn er es findet gibt er dem spieler dia anzahl exp und entfern target.
Erstmall in C++ spaeter mit Hilfer der Lua Api exposen, damit man Events dynamisch erstellen kann(zur Laufzeit, von 3. benutzern.)
Lua Api erstmal komplett ingnogieren
*/

#pragma once
#include <map>          //std::map
#include <string>       //std::string
#include <initializer_list> //std::initiliaziler_list
#include <iostream> //std::cerr


#include "../Variant.h" //eng::Variant
#include "../EngineTypes.h" //in-Engine Types
#include "../utility.h" //eng::hash
namespace eng
{
	class Event
	{
	public:
		/***********************************
		*Descri:	Konstruktor fuer Events
		*Param1:	Identifier fuer die Argumente
		*Param2:	Werte der Argumente
		************************************/
        Event(const std::string& EventName, std::initializer_list<std::string> identifiers, std::initializer_list<Variant> args);
        
        
        /***********************************
         *Descri:	Konstruktor fuer Events
         *Return:	Event Name als Hash
         ************************************/
        hash getHash();

	private:
	
		//Event Name als Hash
		eng::hash mEventName;
		//Map fuer Event Argument
		std::map<std::string, Variant> mArgs;
	};
}