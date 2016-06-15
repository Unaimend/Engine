/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Datei fuer alle VUtility Funktionen
*Changelog:
			21.01.2016
*			Erstellt
            Varname Makro
*TODO:
			std::hash ersetzen
			bool ListenToGameEvent(std::string)
			void ListenToGameEvent(std::string, <Function>)	
				z.B Wird von Lua gecalled, gibt bool aus Lua Stack falls true <Function> ausfuehren	
					function LevelUpMessage (eventInfo)
    						 Say(nil, "Someone just leveled up!", false)
 					end
 
 					function Activate ()
    					 ListenToGameEvent("dota_player_gained_level", LevelUpMessage, nil)
 					end
*************************************/
#pragma once
#include <functional> //std::hash
#include <string>

#define VAR(var) (#var)//(var,"Q")
//#define VX(var) (#var)(var,"X")

namespace eng
{
	namespace util
	{
		/***********************************
		*Descri:	Hash Wrapper
		*Param1:	String der gehashed werden soll
		*Return:	String als hash
		************************************/
		inline size_t toHash(const std::string& string1)
		{
			return std::hash<std::string>()(string1);
		}

		inline bool listenToGameEvent(const std::string& eventName)
		{
			;
		}
        
        
	}
}
	