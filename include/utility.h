/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Datei fuer alle VUtility Funktionen
*Changelog:
			21.01.2016
*			Erstellt
            Varname Makro
16.06.2016
            KeyChecker erstellt
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
            Static version
*************************************/
#pragma once
#include <functional> //std::hash
#include <string>

#include <SFML/Graphics.hpp>

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
        
        
        
        class KeyChecker
        {
        public:
            KeyChecker(const sf::Event& event)
            : mEvent(event)
            {
//                mEvent = event;
            }
           /* static*/ const sf::Event& mEvent;
            
            
            /*static*/ bool keyPressed(const sf::Keyboard::Key& key)
            {
                if((mEvent.type == sf::Event::KeyPressed) && mEvent.key.code == key)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        };
	}
}
	