/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Datei fuer alle Variablen die global in der Engine verwerndet werden
*Changelog:
			22.12.205
*			int8 gFilePath hinzugefuegt
			21.01.2016
			size_t hash() hinzugefuget
*TODO:
*************************************/

#include <stdint.h>
#include "EngineTypes.h"
#include <string>
//Gloable Variable fuer den Pfad zur ausfuehrbaren Datei
extern char gFilePath[100];
namespace eng
{
	size_t hash(const std::string& string1)
	{
		return std::hash<std::string>()(string1);
	}
}
