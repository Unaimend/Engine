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
#include "LuaState.h"
#include "Rectangle.h"

#include "Vector.h"


#define LINUX
char gFilePath[100];
eng::EventQueue gEventQueue;
lua::LuaState gLuaState("hello.lua");


 static int l_sin(lua_State *L) 
    {
     std::cout << "HALLO AUS LUA" << std::endl;
      return 0;  /* number of results */
    }



int main()
{   
    eng::Event* onWindowClicked = new eng::Event
    {   "onWindowClicked",
        {"Text"}, 
        { {eng::Variant::Type::INTEGER, 55} } 
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
            if (event.type == sf::Event::Resized) 
            {
                 gEventQueue.addEvent(onWindowClicked);
            }
        }
        auto start_time = std::chrono::high_resolution_clock::now();
        for(const auto& it : gEventQueue.mEvents)
        {
            if(it->mEventName == eng::util::toHash("onWindowClicked"))
            {
                std::cout << it->mArgs["Text"].mValue.mAsInteger << std::endl;
            }
            //HIER WERDEN EVENTS UEBERGEBEN
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        //std::cout << ":EventQueueTime:"<<std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << std::endl;

        gEventQueue.mEvents.clear();
        


   
        window.clear();

        window.display();

    }
        


   
    
    gLuaState.push(1,2,3);
    gLuaState.runFile();


   

    /*


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
    */

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

     eng::Event* onExplode = new eng::Event
    {   "onExplode",
        {"radius", "damage", "explosiveType"}, 
        { {eng::Variant::Type::INTEGER, 20},{eng::Variant::Type::DOUBLE, 2000},{"Grenade"} } 
    };

 /*   eng::Event onExplode2
        {   "onExplode",
            {"radius"}, 
            { {eng::Variant::Type::INTEGER, 22} } 
        };

    
          for(int i = 0; i < 100; ++i)
          {
            
             
          }
        
     for(int i = 0; i < 100; ++i)
         {
            size_t& temp =gEventQueue.mEvents[i]->mEventName;

            if(temp == 123243243)
            {
                    ;
            }
            else if (temp == 43532432)
            {
                ;
            }
            else if (temp == 324234324324)
            {
                ;
            }
            else if (temp == 234325)
            {
                ;
            }
            else if (temp == 124432542532)
            {
                ;
            }
            else
            {
                ;
            }

           
         }
       

*/
       



    return 0;
}



/************************************
*Author:    Thomas Dost
*Datum:     22.12.2015
*Beschr.    
*Changelog:
*TODO:
*************************************/





