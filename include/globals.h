/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Datei fuer alle Variablen die global in der Engine verwerndet werden
*Changelog:
			22.12.205
*			int8 gFilePath hinzugefuegt
16.06.2016  
            ALles wieder im namespace, hat vergessen das erstellen auch in eng:: zu machen :)
*TODO:
            Auskommentieren
*************************************/

#pragma once

#include <stdint.h>
#include <string>
#include "EngineTypes.h"
#include "eventSystem/EventQueue.h"
#include "luaApi/LuaState.h"
//Gloable Variable fuer den Pfad zur ausfuehrbaren Datei
extern char gFilePath[100];

namespace eng
{
	extern EventQueue gEventQueue;
}
extern lua::LuaState gLuaState;
