#include "lua.hpp"
#include <iostream>
#include "ResourceManager.h"
#include <unistd.h>
#include "Texture.h"
#include "Event.h"
#include "Variant.h"
#include <functional> //std::hash
#include "globals.h"
#include "utility.h"

#include <chrono>
#define LINUX
char gFilePath[100];
eng::EventQueue gEventQueue;
int main()
{   


    eng::Event onExplode
    {   "onExplode",
        {"radius", "damage", "explosiveType"}, 
        { {eng::Variant::Type::INTEGER, 20},{eng::Variant::Type::DOUBLE, 2000},{"Grenade"} } 
    };

    eng::Event onExplode2
        {   "onExplode",
            {"radius"}, 
            { {eng::Variant::Type::INTEGER, 22} } 
        };


 
#ifdef LINUX
    if(readlink("/proc/self/exe", gFilePath, 100) == -1)
    {
        std::cerr << "Error: Dateipfad konnte nicht ermittelt werden" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "Pfad zur Datei:" << gFilePath << std::endl;
    }
#elif defined WINDOWS
        
#elif defined MAC
    
#endif
 sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        auto start_time = std::chrono::high_resolution_clock::now();


         for(int i = 0; i < 500; ++i)
         {
            gEventQueue.addEvent(&onExplode);
             
         }
        
     for(int i = 0; i < 500; ++i)
         {
            size_t& temp =gEventQueue.mEvents[i]->mEventName;
            temp == eng::util::toHash("onExplode");
            temp == eng::util::toHash("onExplo23de");
            temp == eng::util::toHash("43");
            temp == eng::util::toHash("onExp55lode");
            temp == eng::util::toHash("onExp43lode");
         }
       

        auto end_time = std::chrono::high_resolution_clock::now();

        std::cout << ":"<<std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << std::endl;


        gEventQueue.mEvents.clear();
        window.clear();

        window.display();
    }

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
   std::cout << "Engine runs on Linux" << std::endl;
#elif defined WINDOWS
   // std::cout << "IGIT" << std::endl;
#elif defined MAC
    //std::cout << "NAJA" << std::endl;
#endif
 








    /******************TEST AREA**********************************/
    eng::Variant a{"Error: Dateipfad konnte nicht ermittelt werden"};
    // std::cout << a.mValue.mAsStringId << std::endl;

    
    
    return 0;
}



/************************************
*Author:    Thomas Dost
*Datum:     22.12.2015
*Beschr.    
*Changelog:
*TODO:
*************************************/





