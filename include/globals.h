/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Datei fuer alle Variablen die global in der Engine verwerndet werden
*Changelog:
			22.12.205
*			int8 gFilePath hinzugefuegt
*TODO:
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
	using namespace lua;

	extern LuaState gLuaState;
	extern eng::EventQueue gEventQueue;
}
