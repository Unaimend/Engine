/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Datei fuer alle Typedefs die global in der Engine verwerndet werden
*Changelog:
			22.12.205
*			Typedef fuer int8_t hinzugefuegt
*           Typedef fuer uint32_t hinzugefuegt.
*           14.06.2016
*           filepath von std::string zu const std::string& geaendert
*           01.02.2017
*           float distance, typedef const eng::Vector2f&  pos; erstellt
*TODO:
*************************************/


#pragma once
#include <string>


//Typedefs
typedef int_fast8_t int8;
typedef int_fast32_t int32;
typedef uint_fast32_t uint32;
typedef int_fast64_t int64;
typedef const std::string& filepath;

namespace eng
{
    typedef float distance;
	typedef size_t hash;
}
