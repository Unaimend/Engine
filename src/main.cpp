#include "lua.hpp"
#include <iostream>
#include "ResourceManager.h"
#include <unistd.h>
#include "Texture.h"
#include "Event.h"
#include "Variant.h"
#include <functional> //std::hash
#define LINUX
char gFilePath[100];

int main()
{   
 
#ifdef LINUX
    if(readlink("/proc/self/exe", gFilePath, 100) == -1)
    {
        std::cerr << "Error: Dateipfad konnte nicht ermittelt werden" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Pfad zwaur Datei:" << gFilePath << std::endl;
    }
#elif defined WINDOWS
        
#elif defined MAC
    
#endif
 sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

   
  /*  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }
*/
     // create new Lua state
    lua_State *lua_state;
    lua_state = luaL_newstate();

    // load Lua libraries
    static const luaL_Reg lualibs[] =
    {
        { "base", luaopen_base },
        { NULL, NULL}
    };

    const luaL_Reg *lib = lualibs;
    for(; lib->func != NULL; lib++)
    {
        lib->func(lua_state);
        lua_settop(lua_state, 0);
    }

    // run the Lua script
    luaL_dofile(lua_state, "hello.lua");

    // close the Lua state
    lua_close(lua_state);

#ifdef LINUX
    std::cout << "YAYY" << std::endl;
#elif defined WINDOWS
    std::cout << "IGIT" << std::endl;
#elif defined MAC
    std::cout << "NAJA" << std::endl;
#endif
 








    /******************TEST AREA**********************************/
    eng::Variant a{"Error: Dateipfad konnte nicht ermittelt werden"};
    std::cout << a.mValue.mAsStringId << std::endl;

    eng::Event test{ {"WAS DAS", "PETER"}, {eng::Variant{"HI"}, eng::Variant{"HIaws"}} };

    return 0;
}



/************************************
*Author:    Thomas Dost
*Datum:     22.12.2015
*Beschr.    
*Changelog:
*TODO:
*************************************/





