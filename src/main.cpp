#include "../include/lua/lua.hpp"
#include <iostream>
#include "../include/ResourceManager.h"
#include <unistd.h>
#include "../include/Texture.h"
#include "../include/eventSystem/Event.h"
#include "../include/Variant.h"
#include <functional> //std::hash
#include "../include/globals.h"
#include "../include/utility.h"
#include <chrono>
#include "../include/LuaApi/LuaState.h"
#include "../include/graphicWrapper/Rectangle.h"
#include "../include/graphicWrapper/Vector.h"
#include "../include/tinyXML/tinyxml2.h"
#include "../include/xmlWrapper/Xml.h"
#define MAC

#include <stdlib.h>                             /* For function exit() */
#include <stdio.h>




void bail(lua_State *L, char *msg){
    fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
            msg, lua_tostring(L, -1));
    exit(1);
}

namespace eng {
    Rectangle& createRectangle(int x, int y)
    {
        return *(new Rectangle{x,y});
    }
    
    static int myRect( lua_State *L, int x, int y)
    {
        printf ("Roses are Red\n");
    }
}
std::vector<eng::Rectangle> rects;
static int createRectangle(lua_State *L)
{
    int n = lua_gettop(L);
    int x = lua_tonumber(L, 1);
    int y = lua_tonumber(L,2);
    rects.emplace_back(x, y);
}

using std::endl;
using std::cout;





//
//namespace eng
//{
//    using namespace tinyxml2;
//    class Xml
//    {
//    public:
//        Xml(char* filepath)
//        {
//            if(mDoc.LoadFile(filepath) != XML_NO_ERROR)
//            {
////                if(mDoc.Parse(filepath) != XML_NO_ERROR)
////                {
////                    
////                }
////                else
////                {
////                    std::cerr << "Die Datei:" << filepath << "konnte nicht GEPARSED werden" << std::endl;
////                    std::cerr << mDoc.GetErrorStr1() << std::endl;
////                    std::cerr << mDoc.GetErrorStr2() << std::endl;
////                }
//            }
//            else
//            {
//                std::cerr << "Die Datei:" << filepath << "konnte nicht GELADEN werden" << std::endl;
//            }
//            
//        }
////        void print()
////        {
////            mDoc.Print();
////        }
//        
//    private:
//        XMLDocument mDoc;
//        
//        
//    };
//}

char gFilePath[100];
eng::EventQueue gEventQueue;
lua::LuaState gLuaState("/Users/thomasdost/Documents/dev/Engine/data/main.lua");


 static int l_sin(lua_State *L) 
    {
     std::cout << "HALLO AUS LUA" << std::endl;
      return 0;  /* number of results */
    }



eng::Event* onWindowClicked = new eng::Event
{   "onWindowClicked",
    {"Text"},
    { {eng::Variant::Type::INTEGER, 55} }
};



int main(int argc, char** argv)
{
#ifdef LINUX
    std::cout << "Engine runs on Linux" << std::endl;
#elif defined WINDOWS
     std::cout << "Engine runs on Windows" << std::endl;
#elif defined MAC
     std::cout << "Engine runs on Mac" << std::endl;
#endif
    
    
 
  

 
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
    strcpy(gFilePath, "/Users/thomasdost/Documents/dev/Engine");
    std::cout << "Pfad zur Engine:" << gFilePath << std::endl;
    
#endif
   
    //Options Xml laden, hier steht alles wichtige drinnen.
    eng::Xml xml{std::string(gFilePath) + "/data/options.xml"};
    
    
    
   //t//inyxml2::XMLElement* title = xml.mDoc.FirstChildElement( "options" )->FirstChildElement( "resX" );
    //title = title->NextSiblingElement();
    eng::XmlElement resX = xml.mDoc.FirstChildElement( "options" )->FirstChildElement( "resX" );
    eng::XmlElement resY = xml.mDoc.FirstChildElement( "options" )->FirstChildElement( "resY" );
  
    cout << xml.rootElement()["resX"].getValue() << endl;
   /*  ATTRIBUTES BEIIIIIIISPIEL
   eng::XmlElement test1 = xml.mDoc.FirstChildElement( "options" )->FirstChildElement("note");
    std::cout << test1.getNodeName() <<   test1.mNode->FirstAttribute()->Name() <<std::endl;
    */
    
    
  
 
    
    gLuaState["max"] = 5;
  
    
    sf::RenderWindow window(sf::VideoMode(std::stoi(resX.getValue()) , std::stoi(resY.getValue())), "SFML works!");
    
    
    
    

    
    gLuaState.runFile();
//    
//   lua::LuaValue aba = gLuaState["x"];
//    std::cout << aba << std::endl;
    
    
    
    lua_register(gLuaState.mState, "createRectangle", createRectangle);
    
    lua_getglobal(gLuaState.mState, "startUp");
//    gLuaState.stackDump();
//    gLuaState.callFunction();
//    std::cout << gLuaState["x"] << std::endl;
//    gLuaState.stackDump();
//    
    
    
    while (window.isOpen())
    {
//
        auto frame_start_time = std::chrono::high_resolution_clock::now();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::GainedFocus)
            {
               // gLuaState.runFile();
                gEventQueue.addEvent(onWindowClicked);
            }
        }
//        auto event_start_time = std::chrono::high_resolution_clock::now();
        for(const auto& it : gEventQueue.mEvents)
        {
            if(it->mEventName == eng::util::toHash("onWindowClicked"))
            {
                std::cout << it->mArgs["Text"].mValue.mAsInteger << std::endl;
               
            }
            //HIER WERDEN EVENTS UEBERGEBEN
        }
//        auto event_end_time = std::chrono::high_resolution_clock::now();
//        std::cout << ":EventQueueTime:"<<std::chrono::duration_cast<std::chrono::microseconds>(event_end_time - event_start_time).count() << std::endl;

        gEventQueue.mEvents.clear();
        
        
        //LUA UPDATE CALL
        lua_getglobal(gLuaState.mState, "update");
        if(!lua_isfunction(gLuaState.mState,-1))
        {
            std::cout << "Keine Lua update Funktion" << std::endl;
        }
        lua_pcall(gLuaState.mState, 0, 0, 0);
        
        
        
        //LUA RENDER CALL
        lua_getglobal(gLuaState.mState, "render");
        if(!lua_isfunction(gLuaState.mState,-1))
        {
            std::cout << "Keine Lua render Funktion" << std::endl;
        }
        lua_pcall(gLuaState.mState, 0, 0, 0);


        
        window.clear();
        
        for(auto it : rects)
        {
            it.draw(window);
        }
       
        window.display();
        auto frame_end_time = std::chrono::high_resolution_clock::now();
    }
    


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
    

    
    lua_getglobal(gLuaState.mState, "shutDown");
    if(!lua_isfunction(gLuaState.mState,-1))
    {
        std::cout << "Keine Lua shutDown Funktion" << std::endl;
    }
    lua_pcall(gLuaState.mState, 0, 0, 0);



    return 0;
}



/************************************
*Author:    Thomas Dost
*Datum:     22.12.2015
*Beschr.    
*Changelog:
*TODO:
*************************************/





//    std::cout << VAR(gLuaState) << std::endl;
//

// gLuaState.push(1,2,3);
//gLuaState.runFile();


// gLuaState.openLibs();

//    lua_getglobal(gLuaState.mState,"Main");

//    lua_getfield(gLuaState.mState, -1, "update");
//  if (lua_pcall(gLuaState.mState, 0, 0, 0))
//        bail(gLuaState.mState, "lua_pcall() failed");
//    lua_pcall(gLuaState.mState, 0, 0, 0);


//    lua_getglobal(gLuaState.mState, "update"); // or get 'banana' from person:Eat()
//    //lua_getfield(gLuaState.mState, -1, "chew");
//
//    if(!lua_isfunction(gLuaState.mState,-1))
//    {
//        std::cout << "WHY" << std::endl;
//    }
//
//    gLuaState.push(5);
//    gLuaState.push(1);
//
//    /* do the call (2 arguments, 1 result) */
//    if (lua_pcall(gLuaState.mState, 2, 1, 0) != 0) {
//        printf("error running function `f': %s\n",lua_tostring(gLuaState.mState, -1));
//        return -1;
//    }
//    lua_pcall(gLuaState.mState, 1, 0, 0);
//
//
//    lua_getglobal(gLuaState.mState, "tellme");
//    lua_pushinteger(gLuaState.mState, 22);
//    lua_pcall(gLuaState.mState, 1, 0, 0);


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







